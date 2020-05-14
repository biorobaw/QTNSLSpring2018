//
//	nsl_misc_library.C
//

//# include "kallincl.h" //no such header,-bn7

// NSLmax
#include <cmath>
#include "nsl_neuron.h"
#include "nsl_num_vector.h"
#include "nsl_num_data.h"
#include "nsl_num.h"

extern void cmd_error(const char*);

num_type NSLmax(const nsl_num_vector& a)
{
	int s1 = a.get_imax();

	num_type* av = a.get_vector();

	num_type c = 0;

	for (int i = 0; i < s1; i++)
		if (av[i] > c)
			c = av[i];

	return c;
}

// if a > b then a else b
//changed nsl_num_1 return type to nsl_num_vector

nsl_num_vector NSLmax(const nsl_num_vector& a,const nsl_num_vector& b)
{
	int s1 = a.get_imax();
	nsl_num_vector c(s1);

	if (a.get_imax() != b.get_imax())
	{
		cmd_error("*** NSLsat ***");
		cmd_error("Exit with the following status");
		cmd_error("imax1: ",a.get_imax());
		cmd_error("imax2: ",b.get_imax());
		cmd_error("bad vector sector");
		return c;
	}

	num_type* av = a.get_vector();
	num_type* bv = b.get_vector();
	num_type* cv = c.get_vector();

	for (int i = 0; i < s1; i++)
		if (av[i] > bv[i])
			cv[i] = av[i];
		else
			cv[i] = bv[i];
	return c;
}
nsl_num_vector NSLmax(const nsl_num_vector& a,const nsl_num_0& b)
{
	int s1 = a.get_imax();
	nsl_num_vector c(s1);

	num_type* av = a.get_vector();
	num_type bv = b.get_data();
	num_type* cv = c.get_vector();

	for (int i = 0; i < s1; i++)
		if (av[i] > bv)
			cv[i] = av[i];
		else
			cv[i] = bv;
	return c;
}
nsl_num_vector NSLmax(const nsl_num_vector& a,const num_type b)
{
	int s1 = a.get_imax();
	nsl_num_vector c(s1);

	num_type* av = a.get_vector();
	num_type* cv = c.get_vector();

	for (int i = 0; i < s1; i++)
		if (av[i] > b)
			cv[i] = av[i];
		else
			cv[i] = b;
	return c;
}

// NSLmin

num_type NSLmin(const nsl_num_vector& a)
{
	int s1 = a.get_imax();

	num_type* av = a.get_vector();

	num_type c = 0;

	for (int i = 0; i < s1; i++)
		if (av[i] < c)
			c = av[i];

	return c;
}

// if a < b then a else b

nsl_num_vector NSLmin(const nsl_num_vector& a,const nsl_num_vector& b)
{
	int s1 = a.get_imax();
	nsl_num_vector c(s1);

	if (a.get_imax() != b.get_imax())
	{
		cmd_error("*** NSLsat ***");
		cmd_error("Exit with the following status");
		cmd_error("imax1: ",a.get_imax());
		cmd_error("imax2: ",b.get_imax());
		cmd_error("bad vector sector");
		return c;
	}

	num_type* av = a.get_vector();
	num_type* bv = b.get_vector();
	num_type* cv = c.get_vector();

	for (int i = 0; i < s1; i++)
		if (av[i] < bv[i])
			cv[i] = av[i];
		else
			cv[i] = bv[i];
	return c;
}
nsl_num_vector NSLmin(const nsl_num_vector& a,const nsl_num_0& b)
{
	int s1 = a.get_imax();
	nsl_num_vector c(s1);

	num_type* av = a.get_vector();
	num_type bv = b.get_data();
	num_type* cv = c.get_vector();

	for (int i = 0; i < s1; i++)
		if (av[i] < bv)
			cv[i] = av[i];
		else
			cv[i] = bv;
	return c;
}
nsl_num_vector NSLmin(const nsl_num_vector& a,const num_type b)
{
	int s1 = a.get_imax();
	nsl_num_vector c(s1);

	num_type* av = a.get_vector();
	num_type* cv = c.get_vector();

	for (int i = 0; i < s1; i++)
		if (av[i] < b)
			cv[i] = av[i];
		else
			cv[i] = b;
	return c;
}

// gaussian 
/*this was already defined -bn7
nsl_num_1 NSLgauss(const nsl_num_0& sig,const int xn)
{
	nsl_num_1 c(xn);
	float m = xn/2;

	for (int i=0; i < xn; i++)
	    c.elem(i) = (float) exp(-(i-m)*(i-m)/
			(2*sig.get_data()*sig.get_data()));

	return c;
}
*/
