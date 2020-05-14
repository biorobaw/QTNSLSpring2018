/* SCCS  @(#)nsl_input_vector.C	1.1---95/08/13--20:55:06 */
//
//	nsl_input_vector.c
//

//# include "../../../../MAIN/src/sys_main_src/nsl_all_kernel_include.h"
//# include "../../incl/nsl_all_input_include.h"
#include <fstream>

#include "nsl_input_vector.h"
#include "nsl_num_vector.h"
#include "nsl_input.h"

extern void cmd_error(const char *);

nsl_input_vector::nsl_input_vector(const char* str,const int i,
	row_col_enum vtype,int fg,int rfg) : nsl_num_vector(str,i,vtype,fg,rfg)
{
	set_type("input_vector");

	layer_type = 1; // input layer
     	xz = 0;
	dx = 1.0;

	input_layer = new nsl_input_layer(str,this);
	m_children_list->append(input_layer);
}	
nsl_input_vector::~nsl_input_vector()
{
}

// input vector assignment (input_vector = vector is NOT derived !!)

num_type* nsl_input_vector::operator=(const nsl_input_vector& a)
{
	if (a.get_imax() != imax)
	{
		cmd_error("Error in nsl_input_vector::operator=");
 		a.print_status(std::cerr);
		this->print_status(std::cerr);
		cmd_error("Inconsistent vector sizes");
		return v;
	}

	num_type* av = a.get_vector();

	for (int i = 0; i < imax; i++)
		v[i] = av[i];

	return v;
}

num_type* nsl_input_vector::operator=(const nsl_num_vector& a)
{
	if (a.get_imax() != imax)
	{
		cmd_error("Error in nsl_input_vector::operator=");
 		a.print_status(std::cerr);
		this->print_status(std::cerr);
		cmd_error("Inconsistent vector sizes");
		return v;
	}

	num_type* av = a.get_vector();

	for (int i = 0; i < imax; i++)
		v[i] = av[i];

	return v;
}
num_type* nsl_input_vector::operator=(const nsl_num_0& a)
{
	int imx = get_imax();  

	num_type val = a.get_value();

	for (int i = 0; i < imx; i++)
		v[i] = val;

	return v;
}
num_type* nsl_input_vector::operator=(const num_type a)
{
	int imx = get_imax();

	for (int i = 0; i < imx; i++)
		v[i] = a;

	return v;
}
num_type* nsl_input_vector::operator=(const int a)
{
	int imx = get_imax();

	for (int i = 0; i < imx; i++)
		v[i] = (num_type) a;

	return v;
}
 
int nsl_input_vector::run()
{
	if (input_layer != NULL)
		input_layer->run();
	else
		cmd_error("NULL input stim");

	return 1;
}

// print status

int nsl_input_vector::print_status(std::ostream& out) const
{
	return print_input_vector_status(out);
}
int nsl_input_vector::print_input_vector_status(std::ostream& out) const
{
	nsl_num_vector::print_status(out);

	if (input_layer != NULL)
		input_layer->print_status(out);
	else
		cmd_error("NULL input stim");

	return 1;
}
int nsl_input_vector::print(std::ostream& out) const
{
	nsl_num_vector::print(out);

	out << "set input_layer xz " << xz << "\n";
	out << "set input_layer dx " << dx << "\n";
 
	out.flush();

	if (input_layer != NULL)
		input_layer->print(out);
	else
		cmd_error("NULL input stim");

  	return 1;
}
int nsl_input_vector::print(std::ostream& out,int i) const
{
	nsl_num_vector::print(out);

	out << "set input_layer xz " << xz << "\n";
	out << "set input_layer dx " << dx << "\n";
 
	out.flush();

	if (input_layer != NULL)
		input_layer->print(out,i);
	else
		cmd_error("NULL input stim");

  	return 1;
}
