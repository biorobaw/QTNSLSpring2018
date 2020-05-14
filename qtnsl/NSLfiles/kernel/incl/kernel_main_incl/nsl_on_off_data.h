/* SCCS  @(#)nsl_on_off_data.h	1.1---95/08/13--23:37:21 */
//
//	nsl_on_off_data.h
//

#ifndef _NSL_ON_OFF_DATA_H
#define _NSL_ON_OFF_DATA_H

#include "nsl_data_layer.h"
class nsl_on_off_data : public nsl_data_layer
{
protected:
	on_off_enum sval;
public:
		nsl_on_off_data(int=0,int=0,int=1);
		nsl_on_off_data(const char*,nsl_model* = 0,int=0,int=0,int=1); 
		nsl_on_off_data(const char*,const on_off_enum,nsl_model* = 0,
			int=0,int=0,int=1); 
		nsl_on_off_data(const nsl_on_off_data&,int=0,int=0,int=1);

		~nsl_on_off_data();

	int	init_on_off_data();

// get value
	const on_off_enum get_data() const { return sval; }
	const on_off_enum get_value() const { return sval; }
	on_off_enum elem() 	{ return sval; }

// set value
	on_off_enum	set_value(const on_off_enum);

// assignment
	on_off_enum 	operator=(const nsl_on_off_data&);
	on_off_enum	operator=(const on_off_enum);

// I/O
	virtual int	print(std::ostream&) const;
	int	print_on_off_data(std::ostream&) const;
	virtual int	print_status(std::ostream&) const;
	int	print_on_off_data_status(std::ostream&) const;

	int 	reset_on_off_data(nsl_buffer* = 0);
	virtual int 	reset(nsl_buffer* = 0);

	int 	write_on_off_data(nsl_buffer&);
	virtual int 	write(nsl_buffer&);
	int 	read_on_off_data(nsl_buffer&);
	virtual int 	read(nsl_buffer&);
};
#endif
