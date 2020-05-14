/* SCCS  @(#)nsl_file.h	1.1---95/08/13--23:36:38 */
/**************************************************************/
/*                                                            */
/*                       nsl_file.h 		              */
/*                                                            */
/**************************************************************/
#include "nsl_public.h"
#ifndef _NSL_FILE_H
#define _NSL_FILE_H
class nsl_file : public nsl_public
{
protected:
	nsl_string dname;	// directory name
 	nsl_string filename;	// file name (w/o file ending)
 	nsl_string fullname;	// full name including dir and file
	fstream* file;		// stream file
	int fd;			// file descriptor
	in_out_enum io_type; 	// 0 - INPUT, 1 - OUTPUT
	file_type_enum file_type; // 0 - TEXT, 1 - BINARY
 	nsl_string suffix;	// nsl,
	int status;
	int auto_index_fg; 	// auto indexing
	int version_num;	// version number
	int level_num;		// suffix level
public:
		nsl_file(const char*,nsl_public*);
		nsl_file(const char*,const char* = "");
		nsl_file(const int);
		nsl_file();
		virtual ~nsl_file();

	int	init_file(const char*,const char*);
 	int	new_file(const char*,in_out_enum = NSL_OUTPUT,file_type_enum = NSL_TEXT,on_off_enum = NSL_ON);
 	int	new_file(NslStr0&,in_out_enum = NSL_OUTPUT,file_type_enum = NSL_TEXT,on_off_enum = NSL_ON);

	virtual nsl_file* create(const char*);

	void set_dname(char* str) { strcpy(dname,str); }
	char* get_dname() { return dname; }

 	void set_filename(char* str) { strcpy(filename,str); }
	char* get_filename() { return filename; }

	void set_fullname(char* str) { strcpy(fullname,str); }
	void set_fullname(); // set according to all pars
	char* get_fullname() { return fullname; }

	void set_file_stream(fstream* f) { file = f; }
	fstream* get_file_stream() { return file; }

	void set_io_type(in_out_enum i) { io_type = i; }
	in_out_enum  get_io_type() { return io_type; }

	void set_file_type(file_type_enum i) { file_type = i; }
	file_type_enum  get_file_type() { return file_type; }

 	void set_suffix(const char* str) { strcpy(suffix,str); }
	const char*  get_suffix() { return suffix; }

	int read(char&);
	int write(char&);

	int read(unsigned char&);
	int write(unsigned char&);

	int read(char*);
	int write(char*);

	int read(int&);
	int write(int&);

	int read(float&);
	int write(float&);

	int read(NslFloat0&);
	int write(NslFloat0&);

	int read(NslString0&);
	int write(NslString0&);

	virtual int load_file(file_type_enum = NSL_TEXT,on_off_enum = NSL_ON);
	virtual int read_file();
	virtual int write_file();
	virtual int open_file(in_out_enum = NSL_OUTPUT,file_type_enum = NSL_TEXT,on_off_enum = NSL_ON);
	virtual int close_file(on_off_enum = NSL_ON);

	int attach_stdin();
	int attach_stdout();

	int print_file(ostream&) const;
	virtual int print(ostream&) const;
	int print_file_status(ostream&) const;
	virtual int print_status(ostream&) const;

	int 	write_file(nsl_buffer&);
	virtual int 	write(nsl_buffer&);
	int 	read_file(nsl_buffer&);
	virtual int 	read(nsl_buffer&);

	int 	write_file(nsl_model*);
	virtual int 	write(nsl_model*);
	int 	read_file(nsl_model*);
	virtual int 	read(nsl_model*);
};
#endif
