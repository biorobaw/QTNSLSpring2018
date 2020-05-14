/* SCCS  @(#)nsl_dump_data.h	1.1---95/08/13--23:37:21 */
//
//	nsl_dump_data.h
//

#ifndef _NSL_DUMP_DATA_H
#define _NSL_DUMP_DATA_H
#include "nsl_data_layer.h"
class nsl_dump_data : public nsl_data_layer
{
protected:
	dump_enum sval;
public:
		nsl_dump_data(int=0,int=0,int=1);
		nsl_dump_data(const char*,nsl_public* = 0,int=0,int=0,int=1);
		nsl_dump_data(const char*,const dump_enum,
			nsl_public* = 0,int=0,int=0,int=1);
		nsl_dump_data(const nsl_dump_data&,int=0,int=0,int=1);

		~nsl_dump_data();

	int	init_dump_data();

// get value
	const dump_enum get_data() const { return sval; }
	const dump_enum get_value() const { return sval; }
	dump_enum elem() 	{ return sval; }

// set value
	dump_enum	set_value(const dump_enum);

// assignment
	dump_enum 	operator=(const nsl_dump_data&);
	dump_enum	operator=(const dump_enum);

// I/O
	virtual int	print(std::ostream&) const;
	int	print_dump_data(std::ostream&) const;
	virtual int	print_status(std::ostream&) const;
	int	print_dump_data_status(std::ostream&) const;

	int 	reset_dump_data(nsl_buffer* = 0);
	virtual int 	reset(nsl_buffer* = 0);

	int 	write_dump_data(nsl_buffer&);
	virtual int 	write(nsl_buffer&);
	int 	read_dump_data(nsl_buffer&);
	virtual int 	read(nsl_buffer&);
};
#endif
