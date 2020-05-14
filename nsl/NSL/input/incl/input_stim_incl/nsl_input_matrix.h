/* SCCS  %W%---%E%--%U% */
//
//	nsl_input_matrix.h
//

#ifndef _NSL_INPUT_MATRIX_H
#define _NSL_INPUT_MATRIX_H
#include "nsl_num_matrix.h"
#include "nsl_num.h"

#ifndef _NSL_SET
class nsl_num_data;
class nsl_num_matrix;
class nsl_input_layer;
#endif

class nsl_input_matrix : public nsl_num_2
{
protected:
	nsl_input_layer* input_layer;	// stim
	NslFloat0 xz;			// *** should be INT ***
	NslFloat0 yz;			// matrix zero elements
	NslFloat0 dx;
	NslFloat0 dy;			// adjacent elem distance
//	float erf;              	// erf - excit. receptive field (dia)
public:

	nsl_input_matrix(const char*,nsl_public*,const int,const int,
		int=0,int=1,int=1);
	~nsl_input_matrix();

	nsl_input_layer* get_input_layer() { return input_layer; }

// set
 	void	set_xz(int i) { xz = i; }
	void	set_yz(int i) { yz = i; }
	void	set_dx(float s) { dx = s; }
	void	set_dy(float s) { dy = s; }
// get
 	int	get_xz() { return (int) xz.get_value() + 0.5; }
	int	get_yz() { return (int) yz.get_value() + 0.5; }
	float	get_dx() { return dx.get_value(); }
	float	get_dy() { return dy.get_value(); }

// 	assignment
	NslFloat2& 	operator=(const nsl_input_matrix&);
	NslFloat2& 	operator=(const nsl_matrix&);
	NslFloat2& 	operator=(const nsl_data&);
 	NslFloat2& 	operator=(const num_type);
 	NslFloat2&  operator=(const NslFloat2& a);
 	NslFloat2&  operator=(const NslFloat0& a);
	NslFloat2& 	operator=(const int);

 	int run();

// print status
	virtual int print_status(ostream&) const;
	int print_input_matrix_status(ostream&) const;

	virtual int print(ostream&) const;
	virtual int print(ostream&,int) const;
};
#endif
