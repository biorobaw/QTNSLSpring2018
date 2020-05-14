/* SCCS  %W%---%E%--%U% */
//
//	nsl_icon_stim_matrix.c
//
#include "nsl_input.h"
#include "nsl_icon_stim_matrix.h"
#include "nsl_input_matrix.h"
#include "nsl_base.h"
#include "nsl_data_math.h"

nsl_icon_stim_matrix::nsl_icon_stim_matrix(nsl_input_matrix* l) 
	: nsl_stim_matrix(l)
{
	set_type("icon_stim_matrix");

	icon = 0;
}
nsl_icon_stim_matrix::~nsl_icon_stim_matrix()
{
}

int nsl_icon_stim_matrix::proc()
{
        int i,j,a,b;

	nsl_input_matrix* Q;

	if (m_parent != NULL)
		Q = (nsl_input_matrix*) m_parent->get_m_parent();
	else
		cmd_error("nsl_icon_stim_matrix: NULL parent");
	
	if (Q == NULL)
	{
		cmd_error("nsl_icon_stim_matrix: NULL parent layer");
		return 1;
	}

	int xz = Q->get_xz(); 	// axis x element center
	int yz = Q->get_yz(); 	// axis y element center
	float mdx = Q->get_dx(); // distance between horizontal (x) elements
	float mdy = Q->get_dy(); // distance between vertical (y) elements

	int qimax = Q->get_imax();
	int qjmax = Q->get_jmax();

	int imax = icon->get_imax();
	int jmax = icon->get_jmax();

	int qj0 = (int)(tx0.get_value()/mdx+0.5) + xz;  // int left corner // ??
	int qi0 = (int)(ty0.get_value()/mdy+0.5) + yz;  // int top corner // ??

	int qi1 = qi0 + imax;
	int qj1 = qj0 + jmax;

	float k = (Q->get_input_layer()->get_overlapfg() == 1) ? 1.0 : 0.0;

        for (i = qi0; i <= qi1; i++)
            for (j = qj0; j <= qj1; j++)
            {
                a = i - qi0;
                b = j - qj0;
                if (0 <= a && a < qimax && 0 <= b && b < qjmax)
                    Q->elem(a,b) = k*Q->elem(a,b) + icon->elem(i,j);
            }

	return 1;
}

int nsl_icon_stim_matrix::print(std::ostream& out) const
{
	return print_icon_stim_matrix(out);
}
int nsl_icon_stim_matrix::print_icon_stim_matrix(std::ostream& out) const
{
 	if (icon != NULL)
		icon->print(out);
	else
		cmd_out("NULL icon");

	print_stim_matrix(out);

	return 1;
}
int nsl_icon_stim_matrix::print_status(std::ostream& out) const
{
	return print_icon_stim_matrix_status(out);
}
int nsl_icon_stim_matrix::print_icon_stim_matrix_status(std::ostream& out) const
{
	return print_stim_matrix_status(out);
}
 
