/* SCCS  @(#)nsl_file.C	1.1---95/08/13--19:20:53 */
/**************************************************************/
/*                                                            */
/*                       nsl_file.C 		              */
/*                                                            */
/**************************************************************/
#include <fstream>
#include <istream>
#include "nsl.h"
#include "nsl_kernel.h"
#include "nsl_file.h"

extern void cmd_out(const char *);
extern void cmd_out(const char *, const char *);

using namespace std;

nsl_file::nsl_file(const char* fullstr,nsl_public* m) :
	nsl_public("file")
{
	m_parent = m;
	init_file(fullstr,"");
}
nsl_file::nsl_file(const char* fullstr,const char* s0) : 
	nsl_public("file")
{
	init_file(fullstr,s0);
}
nsl_file::nsl_file(const int) // fg
{
	set_base_type("file");

	strcpy(dname,".");
	strcpy(filename,"TMP");
	set_name("TMP.nsl");
	sprintf(fullname,"%s/%s",dname,get_name());
}
nsl_file::nsl_file()
{
//	m_parent = NULL;
}
nsl_file::~nsl_file()
{
	if (file != NULL)
		close_file();
}
int nsl_file::init_file(const char* fullstr,const char* s0)
{
	const char *str,*fname0;
	nsl_string ss,ss0;

	set_base_type("file");

 	int len = strlen(fullstr);

      	if ((str = (char *) strrchr(fullstr,'/')) != NULL)
	{
		fname0 = str + 1; // pointer 1 after sname
		int len0 = strlen(str);
		strncpy(dname,fullstr,len-len0);
		dname[len-len0]='\0';
	}
	else
	{
		fname0 = fullstr;
		strcpy(dname,".");
		dname[1]='\0';
	}

	if (strcmp(s0,"") == 0) // other than ".nsl"
	{
		set_name(fname0);
	}
	else
	{
	    set_suffix(s0);
	    sprintf(ss,".%s",s0); // .suffix
      	    if ((str = (char *) strchr(fname0,'.')) != NULL)
	    {
	    	if (strncmp(str,ss,4) == 0)
	    	{
			set_name(fname0);
			int tlen = strlen(fname0)-strlen(str);
			strncpy(filename,fname0,tlen);
			filename[tlen]='\0';
	    	}
	    	else
	    	{
			cmd_error("Unknown file type: ",fname0);
			return -1;
		}
	    }
	    else
	    {
	    	sprintf(ss0,"%s%s",fname0,ss);
	    	set_name(ss0);
	    	strcpy(filename,fname0);
	    }
	}

	sprintf(fullname,"%s/%s",dname,get_name());

	return 1;
}
int nsl_file::new_file(const char* fname,in_out_enum i,file_type_enum ft,on_off_enum en)
{
	init_file(fname,"");
	open_file(i,ft,en);

	return 1;
}
int nsl_file::new_file(NslStr0& fname,in_out_enum i,file_type_enum ft,on_off_enum en)
{
	init_file(fname.elem(),"");
	open_file(i,ft,en);

	return 1;
}
nsl_file* nsl_file::create(const char* str)
{
	return new nsl_file(str);
}
void nsl_file::set_fullname()
{
	sprintf(fullname,"%s/%s.%s.%d",dname,filename,suffix,version_num);
}

int nsl_file::read(unsigned char& var)
{
//	fstream* fs;
	int s = sizeof( var );
/*//get() is called badly -bn7
	if (file != NULL) // && file->eof() == 0) //  && file.bad() != 1)
		//file->get((unsigned char&) var); // , s); // file->get(var); // (*fs) >> data;
	else {
		cmd_error("NULL fstream in nsl_file");
		return -1;
	}*/

//	*this >> var;

	return 1;
}
int nsl_file::write(unsigned char& var)
{
	int s = sizeof( var );

	if (file != NULL) //  && file->eof() == 0) //  && file.bad() != 1)
		file->put((char&) var); // , s); // file->get(var); // (*fs) >> data;
	else {
		cmd_error("NULL fstream in nsl_file");
		return -1;
	}

//	*this << var;

	return 1;
}

int nsl_file::read(char& var)
{
	int s = sizeof( var );

	if (file != NULL) //  && file->eof() == 0) //  && file.bad() != 1)
		file->get((char&) var); // , s); // file->get(var); // (*fs) >> data;
	else {
		cmd_error("NULL fstream in nsl_file");
		return -1;
	}

//	*this >> var;

	return 1;
}
int nsl_file::write(char& var)
{
	*this << var;

	return 1;
}

int nsl_file::read(char* var)
{
	*this >> var;

	return 1;
}
int nsl_file::write(char* var)
{
	*this << var;

	return 1;
}
int nsl_file::read(int& var)
{
/*	int s = sizeof( var );
	char* svar = new char[s];

	if (file != NULL) { // && file->eof() == 0) //  && file.bad() != 1)
		file->read((char*) svar,s); // , s); // file->get(var); // (*fs) >> data;
		var = atoi(svar);
	}
	else {
		cmd_error("NULL fstream in nsl_file");
		return -1;
	}
*/
	*this >> var;

	return 1;
}
int nsl_file::write(int& var)
{
	*this << var;

	return 1;
}

int nsl_file::read(float& var)
{
/*	int s = sizeof( var );
	char* svar = new char[s];

	if (file != NULL) { // && file->eof() == 0) //  && file.bad() != 1)
		file->read((char*) svar,s); // , s); // file->get(var); // (*fs) >> data;
		var = atof(svar);
	}
	else {
		cmd_error("NULL fstream in nsl_file");
		return -1;
	}
*/
	*this >> var;

	return 1;
}
int nsl_file::write(float& var)
{
	*this << var;

	return 1;
}

int nsl_file::read(NslFloat0& var)
{
	*this >> var.elem();

	return 1;
}
int nsl_file::write(NslFloat0& var)
{
	*this << var.elem();

	return 1;
}

int nsl_file::read(NslString0& var)
{
	*this >> var.elem();

	return 1;
}
int nsl_file::write(NslString0& var)
{
	*this << var.elem();

	return 1;
}
int nsl_file::load_file(file_type_enum ft,on_off_enum en)
{
	int fg;

	if ((fg = open_file(NSL_INPUT,ft,en)) == NSL_INPUT)
	{
		read_file();
		close_file(en);
	}

	return 1;
}
int nsl_file::read_file()
{
	status = 1;
	char c = 0;

	if (!file)
	{
		cmd_error("Cannot read file: ",fullname);
		return -1;
	}

        while (file && file->peek() != EOF && status == 1) // read all file
 	{
 		file->get(c);
		cout << c;
 	}

 	return 1;
}
int nsl_file::write_file()
{
	status = 1;

	switch (file->rdstate())
	{
	case 0: // _good
		set_able_fg(NSL_ON);
		status = 1;
		break;
	case 1: // _eof
		break;
	case 2: // _fail
		cmd_error("Cannot write file: ",fullname);
		set_able_fg(NSL_OFF);
		status = -1;
		break;
	case 3: // _bad
		break;
	default:
		cmd_error("Unknown open file state");
	}

	return status;
}
int nsl_file::open_file(in_out_enum i,file_type_enum ft,on_off_enum en)
{
	set_io_type(i); 
	set_file_type(ft);
 
	file = new fstream;

	status = 1;

	if (file == NULL)
	{
		cmd_out("// Bad file pointer");
		return -1;
	}
	
	if (io_type == NSL_INPUT)
	{
		if (file_type == NSL_TEXT) {
#ifdef NSL_PC
			file->open(fullname,ios::in);//O_RDONLY	//file->open(fullname,input);
#elif __cplusplus
			//file->open(fullname,input); //TODO: input, output are invalid symbols -bn7
#else
			file->open(fullname,0);
#endif
		} else {
#ifdef NSL_PC
			file->open(fullname,ios::in | ios::binary);//O_RDONLY	//file->open(fullname,input);
#elif __cplusplus
			//file->open(fullname,input);
#else
			file->open(fullname,0);
#endif
		}
		if (en == NSL_ON)
			cmd_out("// Opening input file: ",fullname);
	}
	else if (io_type == NSL_OUTPUT)
	{
#ifdef NSL_PC
		file->open(fullname,ios::out);// O_WRONLY//file->open(fullname,output);
#elif __cplusplus
		//file->open(fullname,output);
#else//
		file->open(fullname,1);
#endif
		if (en == NSL_ON)
			cmd_out("// Opening output file: ",fullname);
	}
	else
	{
		cmd_error("Unknown file io_type: ",(int)io_type);
	}

	if (en == NSL_ON)
	{
	    switch (file->rdstate())
	    {
	    case 0: // _good
		set_able_fg(NSL_ON);
		status = 1;
		break;
	    case 1: // _eof
		status = 0;
		break;
	    case 2: // _fail
		cmd_error("Cannot open file: ",fullname);
		set_able_fg(NSL_OFF);
		status = -1;
		break;
	    case 3: // _bad
		break;
	    default:
		cmd_error("Unknown open file state");
	    }
	}
	set_able_fg(NSL_ON);

	return status;
}
int nsl_file::close_file(on_off_enum en)
{
	file->close();

	if (io_type == NSL_INPUT)
	{
		if (en == NSL_ON)
			cmd_out("// Closing input file: ",fullname);
	}
	else if (io_type == NSL_OUTPUT)
	{
		if (en == NSL_ON)
			cmd_out("// Closing output file: ",fullname);
	}
	else
	{
		cmd_error("Unknown file io_type: ",(int) io_type);
	}
	set_able_fg(NSL_OFF);

	return 1;
}
int nsl_file::attach_stdout()
{
#ifndef __GNUG__ // __cplusplus
	file->attach(1); // standard output
#else
	//((filebuf *)file->ios::_strbuf)->attach(1);
#endif
	return 1;
}
int nsl_file::attach_stdin()
{
#ifndef __GNUG__ // __cplusplus
	file->attach(0); // standard input
#else
	//((filebuf *)file->ios::_strbuf)->attach(0);
#endif
	return 1;
}
int nsl_file::print(ostream& out) const
{
	print_file(out);

	return 1;
}
int nsl_file::print_file(ostream& out) const
{
	print_file_status(out);

	return 1;
}
int nsl_file::print_status(ostream& out) const
{
	print_file_status(out);

	return 1;
}
int nsl_file::print_file_status(ostream& out) const
{
	print_base_status(out);

	out << "// dir name:\t\t" << dname << "\n";
 	if (io_type == NSL_INPUT)
		out << "// i/o type:\t\tINPUT\n";
	else if (io_type == NSL_OUTPUT)
		out << "// i/o type:\t\tOUTPUT\n";
	else
		out << "// unknown type: " << io_type << "\n";

	out.flush();

	return 1;
}

// read, write buf

int nsl_file::write_file(nsl_buffer&)
{
	return 1;
}
int nsl_file::write(nsl_buffer& buf)
{
	write_file(buf);
	return 1;
}
int nsl_file::read_file(nsl_buffer&)
{
	return 1;
}
int nsl_file::read(nsl_buffer& buf)
{
	read_file(buf);
	return 1;
}

// read, write model

int nsl_file::write_file(nsl_model*)
{
	return 1;
}
int nsl_file::write(nsl_model* model)
{
	write_file(model);
	return 1;
}
int nsl_file::read_file(nsl_model*)
{
	return 1;
}
int nsl_file::read(nsl_model* model)
{
	read_file(model);
	return 1;
}
