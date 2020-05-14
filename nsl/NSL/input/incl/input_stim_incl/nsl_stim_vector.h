/* SCCS  %W%---%E%--%U% */
//
//	nsl_stim_vector.h
//

#ifndef _NSL_STIM_VECTOR_H
#define _NSL_STIM_VECTOR_H
#include "nsl_stim.h"
#include "nsl_num_0.h"
#ifndef _NSL_SET
class nsl_input_vector;
#endif

class nsl_stim_vector : public nsl_stim
{
protected:
//      int type;               	// 0 - (xc),(dx)
                                   	// 1 - (x0),(dx)    
	NslFloat0 x0;			// stim original corner location
	NslFloat0 tx0;			// stim current corner location
	NslFloat0 xc;			// stim original center location
	NslFloat0 txc;			// stim current center location
	NslFloat0 dx; 			// stim size
	NslFloat0 vx; 			// stim speed
public:

	nsl_stim_vector(nsl_input_vector*);
  	~nsl_stim_vector();

// set
 	void	set_x0(float i) { x0 = i; }
	void	set_tx0(float i) { tx0 = i; }
	void	set_xc(float i) { xc = i; }
	void	set_txc(float i) { txc = i; }
	void	set_dx(float s) { dx = s; }
	void	set_vx(float s) { vx = s; }

// get
 	float	get_x0() { return x0.get_value(); }
	float	get_tx0() { return tx0.get_value(); }
	float	get_xc() { return xc.get_value(); }
	float	get_txc() { return txc.get_value(); }
	float	get_dx() { return dx.get_value(); }
	float	get_vx() { return vx.get_value(); }

	virtual int run();
	virtual int proc();

	virtual int print(std::ostream&) const;
	int print_stim_vector(std::ostream&) const;
	virtual int print_status(std::ostream&) const;
	int print_stim_vector_status(std::ostream&) const;
};
#endif
