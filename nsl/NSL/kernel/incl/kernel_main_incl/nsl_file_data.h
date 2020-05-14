/* SCCS  @(#)nsl_file_data.h	1.1---95/08/13--23:37:21 */
//
//	nsl_file_data.h
//

#ifndef _NSL_FILE_DATA_H
#define _NSL_FILE_DATA_H
#include "nsl_data_layer.h"
class nsl_file_data : public nsl_data_layer
{
protected:
	file_enum sval;
public:
		nsl_file_data(int=0,int=0,int=1);
		nsl_file_data(const char*,nsl_public* = 0,int=0,int=0,int=1);
		nsl_file_data(const char*,const file_enum,nsl_public* = 0,
			int=0,int=0,int=1); 
		nsl_file_data(const nsl_file_data&,int=0,int=0,int=1);

		~nsl_file_data();

	int	init_file_data();

// get value
	const file_enum get_data() const { return sval; }
	const file_enum get_value() const { return sval; }
	file_enum elem() 	{ return sval; }

// set value
	file_enum	set_value(const file_enum);

// assignment
	file_enum 	operator=(const nsl_file_data&);
	file_enum	operator=(const file_enum);

// I/O
	virtual int	print(ostream&) const;
	int	print_file_data(ostream&) const;
	virtual int	print_status(ostream&) const;
	int	print_file_data_status(ostream&) const;

	int 	reset_file_data(nsl_buffer* = 0);
	virtual int 	reset(nsl_buffer* = 0);

	int 	write_file_data(nsl_buffer&);
	virtual int 	write(nsl_buffer&);
	int 	read_file_data(nsl_buffer&);
	virtual int 	read(nsl_buffer&);
};
#endif
