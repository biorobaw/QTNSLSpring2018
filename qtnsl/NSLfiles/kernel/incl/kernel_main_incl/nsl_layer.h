/* SCCS  @(#)nsl_layer.h	1.1---95/08/13--23:37:16 */
//
//	nsl_layer.h
//

#ifndef _NSL_LAYER_H
#define _NSL_LAYER_H
#include "nsl_public.h"
#include <iostream>

#ifndef _NSL_SET
class nsl_buffer;
class nsl_int_data;
class nsl_interpreter;
class nsl_int_data;
class nsl_interpreter;
#endif

class nsl_layer : public nsl_public
{
protected:
	int 	value_fg; // 0 - all (normal), 1 - single_value
	int 	region_fg; // 0 - all (normal), 1 - specific region
	int	layer_type; // 0 - layer, other for derived classes
	int*	size; // array of layer sizes
	int	size_fg; // size of 'size'
	int 	sub_layer_fg; // 0 - if layer, 1 - if sub layer

	nsl_public* _port;
public:
		nsl_layer(int = 0,int = 0,int = 1);
		nsl_layer(const char*,const char*,nsl_public* = 0,
			int = 0,int = 1,int = 1);
		virtual ~nsl_layer();

		void initialize(const char*,const char*,nsl_public* = 0,
			int = 0,int = 1,int = 1);

	void	set_layer_type(int l) { layer_type = l; }
	int	get_layer_type() { return layer_type; }

	void	set_port(nsl_public* p) { _port = p; }
	nsl_public*	get_port() { return _port; }

//	void	set_size(int,int);
	int 	get_size(int);
	int 	get_size_fg() { return size_fg; }

	void	set_region_fg(int fg) { region_fg = fg; }
	int 	get_region_fg() { return region_fg; }

	void	set_value_fg(int fg) { value_fg = fg; }
	int 	get_value_fg() { return value_fg; }

	int	init_layer(const char*,const char*,int=0);

	virtual nsl_layer* get_output() { return this; }

	virtual int run();
	virtual void send();
	virtual void receive();
	virtual void copy(nsl_layer*);

	virtual int 	nslPrint() const;
	int 	print_layer() const;
	virtual int 	nslStatus() const;
	int 	print_layer_status() const;

//inicio cambios EGR
	int show_variables(nsl_layer *layer) const;
//fin cambios EGR

	virtual int 	print(std::ostream&) const;
	int 	print_layer(std::ostream&) const;
	virtual int 	print_status(std::ostream&) const;
	int 	print_layer_status(std::ostream&) const;

	int 	reset_layer(nsl_buffer* = 0);
	virtual int 	reset(nsl_buffer* = 0);

	int 	write_layer(nsl_buffer&);
	virtual int 	write(nsl_buffer&);
	int 	read_layer(nsl_buffer&);
	virtual int 	read(nsl_buffer&);

	int 	write_layer(nsl_char_buf&);
	virtual int 	write(nsl_char_buf&);
	int 	read_layer(nsl_char_buf&);
	virtual int 	read(nsl_char_buf&);
};
#endif
