/* SCCS  @(#)nsl_row_col_data.h	1.1---95/08/13--23:37:21 */
//
//	nsl_row_col_data.h
//

#ifndef _NSL_ROW_COL_DATA_H
#define _NSL_ROW_COL_DATA_H
#include "nsl_data_layer.h"
class nsl_row_col_data : public nsl_data_layer
{
protected:
	row_col_enum sval;
public:
		nsl_row_col_data(int=0,int=0,int=1);
		nsl_row_col_data(const char*,nsl_model* = 0,int=0,int=0,int=1); 
		nsl_row_col_data(const char*,const row_col_enum,
			nsl_model* = 0,int=0,int=0,int=1); 
		nsl_row_col_data(const nsl_row_col_data&,int=0,int=0,int=1);

		~nsl_row_col_data();

	int	init_row_col_data();

// get value
	const row_col_enum get_data() const { return sval; }
	const row_col_enum get_value() const { return sval; }
	row_col_enum elem() 	{ return sval; }

// set value
	row_col_enum	set_value(const row_col_enum);

// assignment
	row_col_enum 	operator=(const nsl_row_col_data&);
	row_col_enum	operator=(const row_col_enum);

// I/O
	virtual int	print(std::ostream&) const;
	int	print_row_col_data(std::ostream&) const;
	virtual int	print_status(std::ostream&) const;
	int	print_row_col_data_status(std::ostream&) const;

	int 	reset_row_col_data(nsl_buffer* = 0);
	virtual int 	reset(nsl_buffer* = 0);

	int 	write_row_col_data(nsl_buffer&);
	virtual int 	write(nsl_buffer&);
	int 	read_row_col_data(nsl_buffer&);
	virtual int 	read(nsl_buffer&);
};

#endif
