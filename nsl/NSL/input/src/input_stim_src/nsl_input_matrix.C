/* SCCS  @(#)nsl_input_matrix.C	1.1---95/08/13--20:55:05 */
//
//	nsl_input_matrix.c
//
#include "nsl_input.h"
#include "nsl_input_matrix.h"
#include "nsl_input_layer.h"
#include "nsl_num_data.h"
#include "nsl_num_matrix.h"
#include "nsl_base_list.h"
#include "nsl_base.h"

extern void cmd_error(const char *);

nsl_input_matrix::nsl_input_matrix(const char* str,nsl_public* parent,
	const int imx,const int jmx,int sfg,int fg,int rfg) :
	nsl_num_2(str,parent,imx,jmx,sfg,fg,0), // rfg
	xz("xz",this),	// *** should be INT ***
	yz("yz",this),	// matrix zero elements
	dx("dx",this),
	dy("dy",this)	// adjacent elem distance
{
	set_type("input_matrix");

	layer_type = 1; // input layer
    xz = 0;
	yz = 0;
	dx = 1.0;
	dy = 1.0;

	input_layer = new nsl_input_layer("component",this);

	if (m_children_list == NULL)
		m_children_list = new nsl_base_list(1);
	m_children_list->append(input_layer);
}
nsl_input_matrix::~nsl_input_matrix()
{
}

// input matrix assignment (input_matrix = matrix is NOT derived !!)

NslFloat2& nsl_input_matrix::operator=(const nsl_input_matrix& a)
{
	if (a.get_imax() != imax || a.get_jmax() != jmax)
	{
		cmd_error("Error in nsl_input_matrix::operator=");
 		a.print_status(cerr);
		this->print_status(cerr);
		cmd_error("Inconsistent matrix sizes");
		return *this;
	}

	for (int i = 0; i < imax; i++)
	   for (int j = 0; j < jmax; j++)
		v[i][j] = a[i][j];

	return *this;
}
NslFloat2& nsl_input_matrix::operator=(const NslFloat2& a)
{
	if (a.get_imax() != imax || a.get_jmax() != jmax)
	{
		cmd_error("Error in nsl_input_matrix::operator=");
		a.print_status(cerr);
		this->print_status(cerr);
		cmd_error("Inconsistent matrix sizes");
		return *this;
	}

	for (int i = 0; i < imax; i++)
	   for (int j = 0; j < jmax; j++)
		v[i][j] = a[i][j];

	return *this;
}
NslFloat2& nsl_input_matrix::operator=(const NslFloat0& a)
{
	int imx = get_imax();
	int jmx = get_jmax();

	num_type val = a.get_value();

	for (int i = 0; i < imx; i++)
	   for (int j = 0; j < jmx; j++)
		v[i][j] = val;

	return *this;
}
NslFloat2& nsl_input_matrix::operator=(const num_type a)
{
	int imx = get_imax();
	int jmx = get_jmax();

	for (int i = 0; i < imx; i++)
	   for (int j = 0; j < jmx; j++)
		v[i][j] = a;

	return *this;
}
NslFloat2& nsl_input_matrix::operator=(const int a)
{
	int imx = get_imax();
	int jmx = get_jmax();

	for (int i = 0; i < imx; i++)
	   for (int j = 0; j < jmx; j++)
		v[i][j] = (num_type) a;

	return *this;
}

int nsl_input_matrix::run()
{
	if (input_layer != NULL)
		input_layer->run();
	else
		cmd_error("NULL input stim");

	return 1;
}

// print status

int nsl_input_matrix::print_status(ostream& out) const
{
	return print_input_matrix_status(out);
}
int nsl_input_matrix::print_input_matrix_status(ostream& out) const
{
 	print_status(out);

	if (input_layer != NULL)
		input_layer->print_status(out);
	else
		cmd_error("NULL input stim");

	return 1;
}
int nsl_input_matrix::print(ostream& out) const
{
	print(out);

  	out << "set input_layer xz " << xz.get_value() << "\n";
	out << "set input_layer yz " << yz.get_value() << "\n";
	out << "set input_layer dx " << dx.get_value() << "\n";
	out << "set input_layer dy " << dy.get_value() << "\n";

	out.flush();

	if (input_layer != NULL)
		input_layer->print(out);
	else
		cmd_error("NULL input stim");

	return 1;
}
int nsl_input_matrix::print(ostream& out,int i) const
{
	print(out);

  	out << "set input_layer xz " << xz.get_value() << "\n";
	out << "set input_layer yz " << yz.get_value() << "\n";
	out << "set input_layer dx " << dx.get_value() << "\n";
	out << "set input_layer dy " << dy.get_value() << "\n";
 
	out.flush();

	if (input_layer != NULL)
		input_layer->print(out,i);
	else
		cmd_error("NULL input stim");

	return 1;
}
