/* SCCS  %W%---%E%--%U% */
//
//	nsl_block_stim_matrix.c
//
#include "nsl_input.h"
#include "nsl_block_stim_matrix.h"
#include "nsl_stim.h"
#include "nsl_input_matrix.h"
#include "nsl_input_layer.h"
#include <stddef.h>

extern void cmd_error(const char *);



nsl_block_stim_matrix::nsl_block_stim_matrix(nsl_input_matrix* l) 
	: nsl_stim_matrix(l)
{
	set_type("block_stim_matrix");
}
nsl_block_stim_matrix::~nsl_block_stim_matrix()
{
}

int nsl_block_stim_matrix::proc()
{
 	int i,j,a,b;
	int qi0,qj0,qic,qjc;

	nsl_input_matrix* Q;

	if (m_parent != NULL)
		Q = (nsl_input_matrix*) m_parent->get_m_parent();
	else
		cmd_error("nsl_block_stim_matrix: NULL parent");
	
	if (Q == NULL)
	{
		cmd_error("nsl_block_stim_matrix: NULL parent layer");
		return 1;
	}

	int xz = Q->get_xz(); // zero x element
	int yz = Q->get_yz(); // zero y element
	float mdx = Q->get_dx(); // x interval 
	float mdy = Q->get_dy(); // y interval

	int idx = (int)(dx.getValue()/mdx+0.5); // int width
	int idy = (int)(dy.getValue()/mdy+0.5); // int height

	idx = (idx >= 1) ? idx-1 : 0; // >= 0
	idy = (idy >= 1) ? idy-1 : 0; // >= 0

	int qimax = Q->get_imax();
	int qjmax = Q->get_jmax();

	if (spec_type == NSL_CENTER) // reference xc,yc
	{
		qjc = (int)(txc.getValue()/mdx+0.5) + xz;  // int left corner
		qic = (int)(tyc.getValue()/mdy+0.5) + yz;  // int top corner
		qj0 = qjc - idx/2;
		qi0 = qic - idy/2;
	}
	else // reference x0,y0
	{
		qj0 = (int)(tx0.getValue()/mdx+0.5) + xz;  // int left corner
		qi0 = (int)(ty0.getValue()/mdy+0.5) + yz;  // int top corner
	}

	int qj1 = qj0 + idx;
	int qi1 = qi0 + idy;

	float k = (Q->get_input_layer()->get_overlapfg() == 1) ? 1.0 : 0.0;

        for (i = qi0; i <= qi1; i++)
            for (j = qj0; j <= qj1; j++)
            {
//               a = i - qi0;
//               b = j - qj0;
                a = i;
                b = j;
                if (0 <= a && a < qimax && 0 <= b && b < qjmax)
                   Q->elem(a,b) = k*Q->elem(a,b) + val;
	    }

	return 1;
}

int nsl_block_stim_matrix::print(std::ostream& out) const
{
	return print_block_stim_matrix(out);
}
int nsl_block_stim_matrix::print_block_stim_matrix(std::ostream& out) const
{
 	out << "set stim val " << val << "\n";
	out << "set stim dx " << dx.get_value() << "\n";
	out << "set stim dy " << dy.get_value() << "\n";
	out.flush();

	print_stim_matrix(out);

	return 1;
}
int nsl_block_stim_matrix::print_status(std::ostream& out) const
{
	return print_block_stim_matrix_status(out);
}
int nsl_block_stim_matrix::print_block_stim_matrix_status(std::ostream& out) const
{
	return print_stim_matrix_status(out);
}
 
