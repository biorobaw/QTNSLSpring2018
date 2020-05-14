/* SCCS  %W%---%E%--%U% */
//
//	xnsl_temporal_graph_matrix.C
//

#include "nsl_all_kernel_include.h"
#include "xkernel.h"
#include "xnsl_temporal_graph_matrix.h"

extern int TRAIN_FG;

extern void cmd_out(const char *, int);

xnsl_temporal_graph_matrix::xnsl_temporal_graph_matrix(xnsl_display_canvas* win,
	nsl_layer* m) : xnsl_temporal_graph(win)
{
	int id;

	set_type("temporal_graph_matrix");

	if (m != NULL)
	{
		_layer = m;

		_imax = ((nsl_matrix_layer*) _layer)->get_imax();
		_jmax = ((nsl_matrix_layer*) _layer)->get_jmax();

		id = m->get_type_id();
		if (id == 0)
			_layer0 = new NslFloat2(_imax,_jmax);
		else if (id == 1)
			_layer0 = new NslFloat2(_imax,_jmax);
		else if (id == 2)
			_layer0 = new NslFloat2(_imax,_jmax);
		else
			cmd_out("Bad Type ID: ",id);

		_i0 = 0;
		_j0 = 0;
		_i1 = _imax - 1;
		_j1 = _jmax - 1;
 	}
//	else
//		cmd_error("xnsl_temporal_graph_mat: NULL layer");
}
xnsl_temporal_graph_matrix::~xnsl_temporal_graph_matrix()
{
}
xnsl_widget * xnsl_temporal_graph_matrix::make_widget()
{
    return new xnsl_temporal_graph_matrix((xnsl_display_canvas*) m_parent,_layer);
}
int xnsl_temporal_graph_matrix::display()
{
 	display_temporal_graph(_widget,_wx0,_wy0,_wx1,_wy1,_wxs,_wys,_wymin,_wymax);
 	
	return 1;
}
int xnsl_temporal_graph_matrix::display_temporal_graph(xnsl_widget* widget,
	int wx0,int wy0,int wx1,int wy1,int wxs,int wys,
	num_type wymin, num_type wymax) 
{
	float ts;
	float dt;
	
	if (TRAIN_FG == 1) {
		ts = NSL_SYSTEM->getTrainAccumTime();
		dt = NSL_SYSTEM->getTrainDelta();
	} else {
		ts = NSL_SYSTEM->getSimTime();
		dt = NSL_SYSTEM->getSimDelta();
	}
	
//	nsl_num_matrix* m0 = ((nsl_num_2*) _layer0);
//	nsl_num_matrix* m = ((nsl_num_2*) _layer);
	int id = _layer->get_type_id();

//	draw_temporal_graph_matrix(canvas,m,m0,
//		wx0,wy0,wxs,wys,i0,i1,j0,j1,wymin,wymax,t0,t1,ts,dt,pulsefg);

        int ux0,uy0;
        num_type u0,u1,v0,v1;
        num_type x,y;
        int xc,yc,xp,yp;

        num_type fx0 = get_t0();
        num_type fx1 = get_t1();

        num_type fy0 = wymin;
        num_type fy1 = wymax;

		int i,j;

        for (i = _i0; i <= _i1; i++)
            for (j = _j0; j <= _j1; j++)
            {
//              if (breakfg == 1)
//                  return(1);

                if (ts >= 0.0)
                {
// x,y crossed
/*                  ux0 = wx0 + (i-i0)*wxs;
                    uy0 = wy0 + (j1-j)*wys;
//                  uy0 = wy0 + (j-j0)*wys;
*/
                    ux0 = wx0 + (j-_j0)*wxs;
                    uy0 = wy0 + (_i1-i)*wys;

                    u0 = (num_type) ux0;
                    u1 = (num_type) wxs;
                    v0 = (num_type) uy0;
                    v1 = (num_type) wys;

                    x = ts; 
//                    y = (*m)[i][j];

					if (id == 0) {
						y = (*((NslFloat2*) _layer))[i][j];
					} else if (id == 1) {
						y = (*((NslFloat2*) _layer))[i][j]; 
					} else if (id == 2) {
						y = (*((NslFloat2*) _layer))[i][j]; 
					} else
						cmd_out("Bad Type ID: ",id);

					xc = coord_transform(x,fx0,fx1,u0,u1);
                    yc = coord_transform(y,fy0,fy1,v0,v1);
                    if (ts == 0.0)
                    {
                        xp = coord_transform(x,fx0,fx1,u0,u1);
                        yp = coord_transform(y,fy0,fy1,v0,v1);
                    }
                    else
                    {
                        x = ts-dt;
//                        y = (*m0)[i][j];
 						if (id == 0) {
							y = (*((NslFloat2*) _layer0))[i][j];
						} else if (id == 1) {
							y = (*((NslFloat2*) _layer0))[i][j]; 
						} else if (id == 2) {
							y = (*((NslFloat2*) _layer0))[i][j]; 
						} else
							cmd_out("Bad Type ID: ",id);

                        xp = coord_transform(x,fx0,fx1,u0,u1);
                        yp = coord_transform(y,fy0,fy1,v0,v1);
                    }
// AW98	    	    if (xp != xc || yp != yc)
	    			{
	        			if (pulsefg == 1)
						{
                			//draw_line(widget,xp,yp,xp,yc,1);
                			yp = yc;
						}
                    	//draw_line(widget,xp,yp,xc,yc,1);
	    			}
                }
           }
/*
	for (i = 0; i < _imax; i++)
	   for (j = 0; j < _jmax; j++)
		(*m0)[i][j] = (*m)[i][j];
*/
//	*m0 = *m;
	if (id == 0) 
		*((NslFloat2*) _layer0) = *((NslFloat2*) _layer);
	else if (id == 1)
		*((NslFloat2*) _layer0) = *((NslFloat2*) _layer);
	else if (id == 2)
		*((NslFloat2*) _layer0) = *((NslFloat2*) _layer);
	else
		cmd_out("Bad Type ID: ",id);

	return 1;
}

