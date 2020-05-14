/* SCCS  %W%---%E%--%U% */
//
//	nsl_input_data.c
//
#include "nsl_input.h"
#include "nsl_input_data.h"
#include "nsl_base.h"
#include "nsl_num_data.h"
#include "nsl_input_layer.h"
#include "nsl_base_list.h"

extern void cmd_error( const char *);

nsl_input_data::nsl_input_data(const char* str,int fg,int rfg) 
	: nsl_num_data(str,fg,rfg)
{
	set_type("input_data");
	
	layer_type = 1; // input layer

	input_layer = new nsl_input_layer(str,this);
	m_children_list->append(input_layer);
}	
nsl_input_data::~nsl_input_data()
{
}

// input data assignment (input_data = data is NOT derived !!)

num_type nsl_input_data::operator=(const nsl_input_data& a)
{
	return v = a.get_data();
}
num_type nsl_input_data::operator=(const nsl_num_data& a)
{
	return v = a.get_data();
}
num_type nsl_input_data::operator=(const num_type a)
{
	return v = a;
}
num_type nsl_input_data::operator=(const int a)
{
        return v = (num_type) a;
}

int nsl_input_data::run()
{
	if (input_layer != NULL)
		input_layer->run();
	else
		cmd_error("NULL input stim");

	return 1;
}
 
// print status

int nsl_input_data::print_status(std::ostream& out) const
{
	return print_input_data_status(out);
}
int nsl_input_data::print_input_data_status(std::ostream& out) const
{
	nsl_num_data::print_status(out);

	if (input_layer != NULL)
		input_layer->print_status(out);
	else
		cmd_error("NULL input stim");

	return 1;
}
int nsl_input_data::print(std::ostream& out) const
{
	nsl_num_data::print(out);

	if (input_layer != NULL)
		input_layer->print(out);
	else
		cmd_error("NULL input stim");

	return 1;
}
int nsl_input_data::print(std::ostream& out,int i) const
{
	nsl_num_data::print(out);

	if (input_layer != NULL)
		input_layer->print(out,i);
	else
		cmd_error("NULL input stim");

	return 1;
}
