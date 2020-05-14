/* SCCS  %W%---%E%--%U% */
//
//	nsl_icon_stim_vector.c
//

#include "nsl_icon_stim_vector.h"
#include "nsl_input_vector.h"
#include "nsl_input.h"
#include "nsl_num_library.h"
#include "nsl_data_math.h"
#include <stddef.h>

extern void cmd_error(const char *);
extern void cmd_out(const char *);

nsl_icon_stim_vector::nsl_icon_stim_vector(nsl_input_vector* l) 
	: nsl_stim_vector(l) 
{
	set_type("icon_stim_vector");

	icon = 0;
}
nsl_icon_stim_vector::~nsl_icon_stim_vector()
{
}

int nsl_icon_stim_vector::proc()
{
        int i,a;

	nsl_input_vector* Q;

	if (m_parent != NULL)
		Q = (nsl_input_vector*) m_parent->get_m_parent();
	else
		cmd_error("nsl_icon_stim_vectorx: NULL parent");
	
	if (Q == NULL)
	{
		cmd_error("nsl_icon_stim_vector: NULL parent lAYER");
		return 1;
	}

	int xz = Q->get_xz(); 	// axis x element center
	float mdx = Q->get_dx(); // distance between horizontal (x) elements

	int qimax = Q->get_imax();

	int imax = icon->get_imax();

	int qi0 = (int)(tx0.get_value()/mdx+0.5) + xz;  // int left corner // ??

	int qi1 = qi0 + imax;

	float k = (Q->get_input_layer()->get_overlapfg() == 1) ? 1.0 : 0.0;

        for (i = qi0; i <= qi1; i++)
        {
                a = i - qi0;
                if (0 <= a && a < qimax)
                    Q->elem(a) = k*Q->elem(a) + icon->elem(i);
        }

	return 1;
}
int nsl_icon_stim_vector::print(ostream& out) const
{
	return print_icon_stim_vector(out);
}
int nsl_icon_stim_vector::print_icon_stim_vector(ostream& out) const
{
 	if (icon != NULL)
		icon->print(out);
	else
		cmd_out("NULL icon");

	print_stim_vector(out);

	return 1;
}
int nsl_icon_stim_vector::print_status(ostream& out) const
{
	return print_icon_stim_vector_status(out);
}
int nsl_icon_stim_vector::print_icon_stim_vector_status(ostream& out) const
{
	return print_stim_vector_status(out);
}
