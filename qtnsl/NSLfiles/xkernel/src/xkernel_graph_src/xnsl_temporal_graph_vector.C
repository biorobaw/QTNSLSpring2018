/* SCCS  %W%---%E%--%U% */
//
//	xnsl_temporal_graph_vector.C
//

#include "nsl_all_kernel_include.h"
#include "xkernel.h"

extern int TRAIN_FG;

extern void cmd_out(const char *, int);

xnsl_temporal_graph_vector::xnsl_temporal_graph_vector(xnsl_display_canvas* win,
	nsl_layer* m) : xnsl_temporal_graph(win)
{
	int id;
    set_type("temporal_graph_vector");

	if (m != NULL)
	{
		_layer = m;

		_imax = ((nsl_vector_layer*) _layer)->get_imax();

		id = m->get_type_id();
		if (id == 0)
			_layer0 = new NslFloat1(_imax);
		else if (id == 1)
			_layer0 = new NslFloat1(_imax);
		else if (id == 2)
			_layer0 = new NslFloat1(_imax);
		else
			cmd_out("Bad Type ID: ",id);

		_i0 = 0;
		_i1 = _imax - 1;
		_vec_type = NSL_ROW;
 	}
//	else
//		cmd_error("xnsl_temporal_graph_vec: NULL layer");
}
xnsl_temporal_graph_vector::~xnsl_temporal_graph_vector()
{
}
xnsl_widget * xnsl_temporal_graph_vector::make_widget()
{
    return new xnsl_temporal_graph_vector((xnsl_display_canvas*) m_parent,_layer);
}
int xnsl_temporal_graph_vector::display()
{
	display_temporal_graph(_widget,_wx0,_wy0,_wx1,_wy1,_wxs,_wys,_wymin,_wymax);
	 
	return 1;
}
int xnsl_temporal_graph_vector::display_temporal_graph(xnsl_widget* widget,
	int wx0,int wy0,int wx1,int wy1,int wxs,int wys,
	num_type wymin, num_type wymax) 
{
	float ts;
	float dt;
	int i;
	
	if (TRAIN_FG == 1) {
		ts = NSL_SYSTEM->getTrainAccumTime();
		dt = NSL_SYSTEM->getTrainDelta();
	} else {
		ts = NSL_SYSTEM->getSimTime();
		dt = NSL_SYSTEM->getSimDelta();
	}
	
//	nsl_num_vector* m0 = ((nsl_vector*) _layer0);
//	nsl_num_vector* m = ((nsl_vector*) _layer);
	int id = _layer->get_type_id();

//	draw_temporal_graph_vector(canvas,m,m0,
// 		wx0,wy0,wxs,wys,i0,i1,wymin,wymax,t0,t1,ts,dt,pulsefg,vec_type);

        if (_vec_type != NSL_ROW)
        {
                cmd_error("Unable to draw col vector");
                return 1;
        }

        int ux0,uy0;
        num_type u0,u1,v0,v1;
        num_type x,y,x0,y0;
        int xc,yc,xp,yp;

        num_type fx0 = get_t0();
        num_type fx1 = get_t1();

        num_type fy0 = wymin;
        num_type fy1 = wymax;

// AW98 following code computes points per pixel
/*	num_type delta_step = (fx1-fx0)/dt/wxs;
	num_type cur_step;
	int mod_step;

	if (delta_step > 1)
	{
		cur_step = ts/dt;
		mod_step = (int) cur_step % (int) delta_step;
		if (mod_step != 0)
			return 1;
	}
*/	

        for (i = _i0; i <= _i1; i++)
        {
//              if (breakfg == 1)
//                  return(1);

                if (ts >= 0.0)
                {
                    ux0 = wx0 + (i-_i0)*wxs;
                    uy0 = wy0;

                    u0 = (num_type) ux0;
                    u1 = (num_type) wxs;
                    v0 = (num_type) uy0;
                    v1 = (num_type) wys;

                    x = ts; 
//                    y = (*m)[i];
					if (id == 0) {
						y = (*((NslFloat1*) _layer))[i];
					} else if (id == 1) {
						y = (*((NslFloat1*) _layer))[i];
					} else if (id == 2) {
						y = (*((NslFloat1*) _layer))[i];
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
                        x0 = ts-dt;
 //                       y0 = (*m0)[i];
 						if (id == 0) {
							y0 = (*((NslFloat1*) _layer0))[i];
						} else if (id == 1) {
							y0 = (*((NslFloat1*) _layer0))[i];
						} else if (id == 2) {
							y0 = (*((NslFloat1*) _layer0))[i];
						} else
							cmd_out("Bad Type ID: ",id);
                        xp = coord_transform(x0,fx0,fx1,u0,u1);
                        yp = coord_transform(y0,fy0,fy1,v0,v1);
                    }
// AW98	    	    if (xp != xc || yp != yc)
	    	    {
	        	if (pulsefg == 1)
                {
                	draw_line(widget,xp,yp,xp,yc,1,i,0,0); // ni,nj
                	yp = yc;
                }
               draw_line(widget,xp,yp,xc,yc,1,i,0,0); // ni,nj //this call draws the data output for the graphs
	    	}
          }
        }

/*	for (i = 0; i < _imax; i++)
		(*m0)[i] = (*m)[i];
*/
//	*m0 = *m;

	  if (id == 0)
		*((NslFloat1*) _layer0) = *((NslFloat1*) _layer);
	  else if (id == 1)
		*((NslFloat1*) _layer0) = *((NslFloat1*) _layer);
	  else if (id == 2)
		*((NslFloat1*) _layer0) = *((NslFloat1*) _layer);
	  else
		cmd_out("Bad Type ID: ",id);

	  return 1;
}
int xnsl_temporal_graph_vector::read_from_database()
{
	return 1;
}
int xnsl_temporal_graph_vector::write_to_database()
{
	return 1;
}
int xnsl_temporal_graph_vector::print(ostream& out) const
{
	return 1;
}
