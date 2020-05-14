/* SCCS  @(#)nsl_cmd_file.C	1.1---95/10/13--16:36:32 */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_file.C                           */
/*                                                            */
/**************************************************************/
#include "nsl_kernel.h"
#include "nsl_file_manager.h"
#include "nsl_cmd_file.h"
#include "nsl_nsl_file.h"
#include "nsl_in_out_data.h"
#include "nsl_on_off_data.h"

extern fstream* NSL_FILE;

extern void cmd_out(const char *, const char *);

nsl_cmd_file::nsl_cmd_file(const char* ltype) : nsl_cmd_type(ltype)
{
	set_base_type(ltype);
	init_cmd_file();
}

nsl_cmd_file::~nsl_cmd_file()
{
}

int nsl_cmd_file::init_cmd_file()
{
	set_base_type("file");

	return set_cmd_file();
}
int nsl_cmd_file::set_cmd_file()
{
 	if (SYSTEM == NULL)
	{
		cmd_error("CMD FILE: Null File Cmd");
		return 1;
	}

	return 1;
}

int nsl_cmd_file::cmd_close(nsl_interpreter& nsl)
{
	nsl_string str;
	int fg = 2;
	nsl_file* file;
	const char* filename;
	nsl_layer* dobj;
 
       	if ((dobj = (nsl_layer*) data_list->get_by_name("name")) != 0)
                filename = ((nsl_str_data*) dobj)->get_value();

	if (nsl.get_str_cnt() > 0)
 	{
	    nsl >> str;
	    filename = str;
	}

  	nsl_file_manager* fm = SYSTEM->get_file_manager();
	if (fm != NULL)
	{
		if ((file = fm->get_file(filename)) != NULL)
		{
			fg = 1; 
			fm->delete_file(filename);
			delete file;
		}
		else
			cmd_error("Unknown file: ",filename);
	}
	else
		cmd_error("nsl_cmd_file: NULL file manager");
  
 	return fg;
}
int nsl_cmd_file::cmd_cont(nsl_interpreter& nsl)
{
	if (nsl.get_input_file() != NULL)
		nsl.set_input_type(NSL_FIN);
	else
		cmd_error("cmd_file: NULL input file");

	return 1;
}
int nsl_cmd_file::cmd_create(nsl_interpreter& nsl)
{
	return 1;
}
int nsl_cmd_file::cmd_init(nsl_interpreter& nsl)
{
 	cmd_type_init(nsl);

 	return 1;
}
int nsl_cmd_file::cmd_load(nsl_interpreter& nsl)
{
	nsl_string str;
	int fg = 2;
	
	nsl >> str; // file name

	nsl_file* file = new nsl_nsl_file(str); // create file obj
	if (file != NULL)
	{
		extern int NslLoad(char*);

		char* fname = file->get_fullname();

		if (fname != NULL)
			fg = NslLoad(fname);
		else
			cmd_out("nsl_cmd_file: Bad File Name: ", fname);

/*AW98		if (file->open_file(NSL_INPUT) == -1) // try to open file
		{
			delete file;
			return -1;
		}
		nsl.set_input_type(NSL_FIN); // file
		nsl.push_input_file(file);
  		fg = 1;
*/	}
	else
		cmd_error("nsl_cmd_file: Bad File String Name: ", str);

	return fg;
}
int nsl_cmd_file::cmd_open(nsl_interpreter& nsl)
{
        nsl_string str,ftype;
        int fg = 2;
        int findex = 0;
        nsl_string fname,dname,file_name,fullname;
        in_out_enum iotype = NSL_OUTPUT;
        nsl_layer* dobj;
        on_off_enum fauto = NSL_ON;
        nsl_model* model;

	strcpy(file_name,"");

        if (nsl.get_str_cnt() != 0)
        {
            	nsl >> str;
		strcpy(fname,str);
        }
	else
	{
            if ((model = SYSTEM->get_model()) != NULL)
                strcpy(fname,model->get_name());
            else
                strcpy(fname,"TMP");
	}

        if ((dobj = (nsl_layer*) data_list->get_by_name("io_type")) != NULL)
		iotype = ((nsl_in_out_data*) dobj)->get_value();
	else
		cmd_error("cmd_file: Unkown io_type");

        if ((dobj = (nsl_layer*) data_list->get_by_name("auto")) != NULL)
		fauto = ((nsl_on_off_data*) dobj)->get_value();
	else
		cmd_error("cmd_file: Unknown auto");

        if (fauto == NSL_ON)
	{
	    if ((dobj = (nsl_layer*) data_list->get_by_name("index")) != 0)
	    {
                findex = ((nsl_int_data*) dobj)->get_value();
                sprintf(file_name,"%s.nsl.%d",fname,findex++);
                ((nsl_int_data*) dobj)->set_value(findex);
	    }
	    else
		cmd_error("cmd_file: Unknown index");
        }
	else
	    strcpy(file_name,fname);
		
	if ((dobj = (nsl_layer*) data_list->get_by_name("name")) != 0)
                ((nsl_str_data*) dobj)->set_value(file_name);
	else
	{
		strcpy(file_name,"TMP.nsl");
		cmd_error("cmd_file: Unknown name");
	}

	if ((dobj = (nsl_layer*) data_list->get_by_name("dname")) != 0)
                strcpy(dname,((nsl_str_data*) dobj)->get_value());
	else
	{
		strcpy(dname,".");
		cmd_error("cmd_file: Unknown name");
	}
	
	sprintf(fullname,"%s/%s",dname,file_name);

	if ((dobj = (nsl_layer*) data_list->get_by_name("ftype")) != 0)
                strcpy(ftype,((nsl_str_data*) dobj)->get_value());
	else
	{
		strcpy(ftype,"nsl_file");
		cmd_error("cmd_file: Unknown ftype");
	}
	
//  nsl_file* file = new nsl_nsl_file(fullname);
	nsl_file* bfile = (nsl_file*) SYSTEM->get_file_type_list()->get_by_type(ftype);
	nsl_file* file = (nsl_file*) bfile->create(fullname);
    if (file != NULL)
    {
         SYSTEM->get_file_manager()->add_file(file);
         if (iotype == NSL_INPUT)
         {
              nsl.push_input_file(file);
              nsl.set_input_able_fg(NSL_ON);
         }
         else if (iotype == NSL_OUTPUT)
         {
              nsl.push_output_file(file);
              nsl.set_output_able_fg(NSL_ON);
         }
         fg = file->open_file(iotype); // pass 'nsl' to 'open'
		 NSL_FILE = file->get_file_stream();
    }
    else
         cmd_error("Unknown file: ",str);

 	return 1;
}
int nsl_cmd_file::cmd_print(nsl_interpreter& nsl)
{
	cmd_type_print(nsl);

	return 1;
}
int nsl_cmd_file::cmd_read(nsl_interpreter&)
{
//	cmd_type_read(nsl);

	return 1;
}
int nsl_cmd_file::cmd_set(nsl_interpreter& nsl)
{
	cmd_type_set(nsl); // set new values

 	return 1;
}
int nsl_cmd_file::cmd_status(nsl_interpreter& nsl)
{
	cmd_type_status(nsl);

 	return 1;
}
int nsl_cmd_file::cmd_stop(nsl_interpreter& nsl)
{
	cmd_out("// Stopped reading from file\n");
	nsl.set_input_type(NSL_CIN);

	return 1;
}
int nsl_cmd_file::cmd_update(nsl_interpreter& nsl)
{
	cmd_type_update(nsl);

	return 1;
}
int nsl_cmd_file::cmd_write(nsl_interpreter& nsl)
{
	cmd_type_write(nsl);

	return 1;
}

// local print

int nsl_cmd_file::print_cmd_file(std::ostream& out) const
{
	print_cmd_type(out);
	i_children_list->print(out);
	return 1;
}
int nsl_cmd_file::print(std::ostream& out) const // virtual
{
	print_cmd_file(out);
	return 1;
}

