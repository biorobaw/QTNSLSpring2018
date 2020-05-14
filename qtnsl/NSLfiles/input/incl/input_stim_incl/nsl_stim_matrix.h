/* SCCS  %W%---%E%--%U% */
//
//	nsl_stim_matrix.h
//

#ifndef _NSL_STIM_MATRIX_H
#define _NSL_STIM_MATRIX_H
#include "nsl_stim.h"
#include "nsl_num_0.h"
class nsl_input_matrix;
class nsl_stim_matrix : public nsl_stim
{
protected:
//        int type;               	// 0 - (xc,yc),(dx,dy)
                                   	// 1 - (x0,y0),(dx,dy)
	NslFloat0 x0,y0;		// stim current corner location
	NslFloat0 tx0,ty0;		// stim current corner location
	NslFloat0 xc,yc;		// stim original center location
	NslFloat0 txc,tyc;		// stim current center location
	NslFloat0 dx,dy; 		// stim size
	NslFloat0 vx,vy; 		// stim speed
public:

	nsl_stim_matrix(nsl_input_matrix*);
 	~nsl_stim_matrix();

// set
 	void	set_x0(float i) { x0 = i; }
	void	set_y0(float i) { y0 = i; }
	void	set_tx0(float i) { tx0 = i; }
	void	set_ty0(float i) { ty0 = i; }
	void	set_xc(float i) { xc = i; }
	void	set_yc(float i) { yc = i; }
	void	set_txc(float i) { txc = i; }
	void	set_tyc(float i) { tyc = i; }
	void	set_dx(float s) { dx = s; }
	void	set_dy(float s) { dy = s; }
	void	set_vx(float s) { vx = s; }
	void	set_vy(float s) { vy = s; }

// get
 	float	get_x0() { return x0.get_value(); }
	float	get_y0() { return y0.get_value(); }
	float	get_tx0() { return tx0.get_value(); }
	float	get_ty0() { return ty0.get_value(); }
	float	get_xc() { return xc.get_value(); }
	float	get_yc() { return yc.get_value(); }
	float	get_txc() { return txc.get_value(); }
	float	get_tyc() { return tyc.get_value(); }
	float	get_dx() { return dx.get_value(); }
	float	get_dy() { return dy.get_value(); }
	float	get_vx() { return vx.get_value(); }
	float	get_vy() { return vy.get_value(); }

	virtual int run();
	virtual int proc();

	virtual int print(std::ostream&) const;
	int print_stim_matrix(std::ostream&) const;
	virtual int print_status(std::ostream&) const;
	int print_stim_matrix_status(std::ostream&) const;
};
#endif
