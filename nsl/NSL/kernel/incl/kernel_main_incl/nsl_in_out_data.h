/* SCCS  @(#)nsl_in_out_data.h	1.1---95/08/13--23:37:21 */
//
//	nsl_in_out_data.h
//

#ifndef _NSL_IN_OUT_DATA_H
#define _NSL_IN_OUT_DATA_H
#include "nsl_data_layer.h"
class nsl_in_out_data : public nsl_data_layer
{
protected:
	in_out_enum sval;
public:
		nsl_in_out_data(int=0,int=0,int=1);
		nsl_in_out_data(const char*,nsl_model* = 0,int=0,int=0,int=1); 
		nsl_in_out_data(const char*,const in_out_enum,nsl_model* = 0,
			int=0,int=0,int=1); 
		nsl_in_out_data(const nsl_in_out_data&,int=0,int=0,int=1);

		~nsl_in_out_data();

	int	init_in_out_data();

// get value
	const in_out_enum get_data() const { return sval; }
	const in_out_enum get_value() const { return sval; }
	in_out_enum elem() 	{ return sval; }

// set value
	in_out_enum	set_value(const in_out_enum);

// assignment
	in_out_enum 	operator=(const nsl_in_out_data&);
	in_out_enum	operator=(const in_out_enum);

// I/O
	virtual int	print(std::ostream&) const;
	int	print_in_out_data(std::ostream&) const;
	virtual int	print_status(std::ostream&) const;
	int	print_in_out_data_status(std::ostream&) const;

	int 	reset_in_out_data(nsl_buffer* = 0);
	virtual int 	reset(nsl_buffer* = 0);

	int 	write_in_out_data(nsl_buffer&);
	virtual int 	write(nsl_buffer&);
	int 	read_in_out_data(nsl_buffer&);
	virtual int 	read(nsl_buffer&);
};
#endif
