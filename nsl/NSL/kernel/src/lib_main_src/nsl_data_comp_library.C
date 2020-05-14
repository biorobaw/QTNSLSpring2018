/* SCCS  @(#)nsl_data_comp_library.C	1.1---95/08/13--20:48:12 */
//
// nsl_data_comp_library.C
//

#include "nsl_num_data.h"
#include "nsl_num.h"
// comparator



int operator<(const nsl_num_0& a, const num_type b)
{
	if(a.get_data() < b)
		return 1;
	else
		return 0;
}



/*
int operator>(const nsl_num_0& a, const num_type b)
{
	if(a.get_data() > b)
		return 1;
	else
		return 0;
}
 *
int operator>(const nsl_num_0& a,const  nsl_num_0& b)
{
	if(a.get_data() > b.get_data())
		return 1;
	else
		return 0;
}

int operator<(const nsl_num_0& a, const nsl_num_0& b)
{
	if(a.get_data() < b.get_data())
		return 1;
	else
		return 0;
}
int operator>(const num_type a, const nsl_num_0& b)
{
	if(a > b.get_data())
		return 1;
	else
		return 0;
}

int operator<(const num_type a, const nsl_num_0& b)
{
	if(a < b.get_data())
		return 1;
	else
		return 0;
}

int operator==(const nsl_num_0& a, const num_type b)
{
	if(a.get_data() == b)
		return 1;
	else
		return 0;
}

*/

int operator>=(const nsl_num_0& a, const num_type b)
{
	if(a.get_data() >= b)
		return 1;
	else
		return 0;
}

int operator<=(const nsl_num_0& a, const num_type b)
{
	if(a.get_data() <= b)
		return 1;
	else
		return 0;
}

int operator>=(const nsl_num_0& a, const nsl_num_0& b)
{
	if(a.get_data() >= b.get_data())
		return 1;
	else
		return 0;
}

int operator<=(const nsl_num_0& a, const nsl_num_0& b)
{
	if(a.get_data() <= b.get_data())
		return 1;
	else
		return 0;
}
int operator>=(const num_type a, const nsl_num_0& b)
{
	if(a >= b.get_data())
		return 1;
	else
		return 0;
}

int operator<=(const num_type a, const nsl_num_0& b)
{
	if(a <= b.get_data())
		return 1;
	else
		return 0;
}

int operator==(const nsl_num_0& a, const nsl_num_0& b)
{
	if(a.get_data() >= b.get_data())
		return 1;
	else
		return 0;
}

int operator!=(const nsl_num_0& a, const num_type b)
{
	if(a.get_data() != b)
		return 1;
	else
		return 0;
}
int operator!=(const nsl_num_0& a, const nsl_num_0& b)
{
	if(a.get_data() != b.get_data())
		return 1;
	else
		return 0;
}
int operator==(const num_type a, const nsl_num_0& b)
{
	if(a < b.get_data())
		return 1;
	else
		return 0;
}

int operator!=(const num_type a, const nsl_num_0& b)
{
	if(a < b.get_data())
		return 1;
	else
		return 0;
}


