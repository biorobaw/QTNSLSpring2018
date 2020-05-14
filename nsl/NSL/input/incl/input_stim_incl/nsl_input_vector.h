/* SCCS  @(#)nsl_input_vector.h	1.1---95/08/13--23:45:45 */
//
//	nsl_input_vector.h
//
#ifndef _NSL_INPUT_VECTOR_H
#define _NSL_INPUT_VECTOR_H
#include <iostream>
#include "nsl_num_vector.h"

#ifndef _NSL_SET
class nsl_input_layer;
class nsl_num_data;
#endif

class nsl_input_vector : public nsl_num_vector
{
protected:
	nsl_input_layer* input_layer;	// stim info
	int xz;				// matrix zero elements
	float dx;			// adjacent elem distance
//	float erf;              	// erf - excit. receptive field (dia)
public:

	nsl_input_vector(const char*,const int,row_col_enum = NSL_ROW,
		int=0,int=0);
	~nsl_input_vector();

	nsl_input_layer* get_input_layer() { return input_layer; }

// set
 	void	set_xz(int i) { xz = i; }
	void	set_dx(float s) { dx = s; }
// get
 	int	get_xz() { return xz; }
	float	get_dx() { return dx; }

// assignment
	num_type* 	operator=(const nsl_input_vector&);
	num_type* 	operator=(const nsl_num_vector&);
	num_type* 	operator=(const nsl_num_0&);
 	num_type* 	operator=(const num_type);
 	num_type* 	operator=(const int);

 	int run();

// print status
	virtual int print_status(std::ostream&) const;
	int print_input_vector_status(std::ostream&) const;

	virtual int print(std::ostream&) const;
	virtual int print(std::ostream&,int) const;
};
#endif
