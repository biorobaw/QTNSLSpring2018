/* SCCS  @(#)nsl_data_layer.h	1.1---95/08/13--23:37:14 */
//
//	nsl_data_layer.h
//

#ifndef _NSL_DATA_LAYER_H
#define _NSL_DATA_LAYER_H
#include "nsl_layer.h"
class nsl_data_layer : public nsl_layer
{
public:
		nsl_data_layer(int = 0,int=0,int = 1);
		nsl_data_layer(const char *, const char *, int = 0,int=0,int = 1); //remove ambiguity -bn7

		nsl_data_layer(const char*,const char*,nsl_public* = 0,
			int = 0,int = 0,int = 1); 	

		virtual ~nsl_data_layer();

	void initialize(const char*,const char*,nsl_public* = 0,
			int = 0,int = 0,int = 1);

	int	init_data_layer();

	virtual int	nslPrint() const;
	int	print_data_layer() const;
	virtual int	nslStatus() const;
	int	print_data_layer_status() const;

	virtual int	print(std::ostream&) const;
	int	print_data_layer(std::ostream&) const;
	virtual int	print_status(std::ostream&) const;
	int	print_data_layer_status(std::ostream&) const;

	int 	reset_data_layer(nsl_buffer* = 0);
	virtual int 	reset(nsl_buffer* = 0);

	int 	write_data_layer(nsl_buffer&);
	virtual int 	write(nsl_buffer&);
	int 	read_data_layer(nsl_buffer&);
	virtual int 	read(nsl_buffer&);
};
#endif
