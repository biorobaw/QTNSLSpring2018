/* SCCS  %W%---%E%--%U% */
//
//	nsl_block_stim_vector.c
//
#include "nsl_input.h"
#include "nsl_block_stim_vector.h"
#include "nsl_input_vector.h"
#include "nsl_input_layer.h"

extern void cmd_error(const char *);

nsl_block_stim_vector::nsl_block_stim_vector(nsl_input_vector* l) 
	: nsl_stim_vector(l)
{
	set_type("block_stim_vector");
}
nsl_block_stim_vector::~nsl_block_stim_vector()
{
}

int nsl_block_stim_vector::proc()
{
 	int i,a;
	int qi0,qic;

	nsl_input_vector* Q;

	if (m_parent != NULL)
		Q = (nsl_input_vector*) m_parent->get_m_parent();
	else
		cmd_error("nsl_block_stim_vector: NULL parent");
	
	if (Q == NULL)
	{
		cmd_error("nsl_block_stim_vector: NULL parent layer");
		return 1;
	}

	int xz = Q->get_xz(); // zero x element
	float mdx = Q->get_dx(); // x interval 

	int idx = (int)(dx.get_value()/mdx+0.5); // int width

	idx = (idx >= 1) ? idx-1 : 0; // >= 0

	int qimax = Q->get_imax();

	if (spec_type == NSL_CENTER) // reference xc
	{
		qic = (int)(txc.get_value()/mdx+0.5) + xz;  // int left corner
		qi0 = qic - idx/2;
	}
	else // reference x0
	{
		qi0 = (int)(tx0.get_value()/mdx+0.5) + xz;  // int left corner
	}

	int qi1 = qi0 + idx;

	float k = (Q->get_input_layer()->get_overlapfg() == 1) ? 1.0 : 0.0;

        for (i = qi0; i <= qi1; i++)
    	{
//              a = i - qi0;
                a = i;
                if (0 <= a && a < qimax)
                   Q->elem(a) = k*Q->elem(a) + val;
	}

	return 1;
}
int nsl_block_stim_vector::print(std::ostream& out) const
{
	return print_block_stim_vector(out);
}
int nsl_block_stim_vector::print_block_stim_vector(std::ostream& out) const
{
 	out << "set stim val " << val << "\n";
	//out << "set stim dx " << dx << "\n";
	out.flush();

	print_stim_vector(out);

	return 1;
}
int nsl_block_stim_vector::print_status(std::ostream& out) const
{
	return print_block_stim_vector_status(out);
}
int nsl_block_stim_vector::print_block_stim_vector_status(std::ostream& out) const
{
	return print_stim_vector_status(out);
}
 

