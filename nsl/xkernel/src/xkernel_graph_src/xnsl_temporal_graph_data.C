/* SCCS  @(#)xnsl_temporal_graph_data.C	1.1---96/02/20--19:21:45 */
//
//	xnsl_temporal_graph_data.C
//

#include "nsl_kernel.h"
#include "xkernel.h"

extern int TRAIN_FG;

xnsl_temporal_graph_data::xnsl_temporal_graph_data(xnsl_display_canvas* win,
	nsl_layer* m) : xnsl_temporal_graph(win)
{
	int id;

	set_type("temporal_graph_data");

	if (m != NULL)
	{
		_layer = m;
		id = m->get_type_id();
		if (id == 0)
			_layer0 = new NslFloat0();
		else if (id == 1)
			_layer0 = new NslFloat0();
		else if (id == 2)
			_layer0 = new NslFloat0();
		else
			cmd_out("Bad Type ID: ",id);
	}
//	else
//		cmd_error("xnsl_temporal_graph_dat: NULL layer");
}
xnsl_temporal_graph_data::~xnsl_temporal_graph_data()
{
}
xnsl_widget * xnsl_temporal_graph_data::make_widget()
{
    return new xnsl_temporal_graph_data((xnsl_display_canvas*) m_parent,_layer);
}
int xnsl_temporal_graph_data::display()
{
	display_temporal_graph(_widget,_wx0,_wy0,_wx1,_wy1,_wxs,_wys,_wymin,_wymax);
 
	return 1;
}
int xnsl_temporal_graph_data::display_temporal_graph(xnsl_widget* widget,
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
	
//	num_type m0 = ((nsl_num_0*) _layer0)->get_data();
//	num_type m = ((nsl_num_0*) _layer)->get_data();
	int id = _layer->get_type_id();

/* aa 95/4/23 b 
       if (m<wymin) {
               m=wymin;
       }
       else if (m>wymax) m=wymax;
aa 95/4/23 e */


//	draw_temporal_graph_data(canvas,m,m0,
//		wx0,wy0,wxs,wys,wymin,wymax,t0,t1,ts,dt,pulsefg);

        int ux0,uy0;
        num_type u0,u1,v0,v1;
        num_type x,y;
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
//      if (breakfg == 1)
//          return(1);

        if (ts >= 0.0)
        {
            ux0 = wx0;
            uy0 = wy0;
            u0 = (num_type) ux0;
            u1 = (num_type) wxs;
            v0 = (num_type) uy0;
            v1 = (num_type) wys;

            x = ts; 
 //           y = m;
			if (id == 0) {
				y = ((NslFloat0*) _layer)->get_value();
			} else if (id == 1) {
				y = ((NslFloat0*) _layer)->get_value(); 
			} else if (id == 2) {
				y = ((NslFloat0*) _layer)->get_value(); 
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
//                y = m0;
				if (id == 0) {
					y = ((NslFloat0*) _layer0)->get_value();
				} else if (id == 1) {
					y = ((NslFloat0*) _layer0)->get_value(); 
				} else if (id == 2) {
					y = ((NslFloat0*) _layer0)->get_value(); 
				} else
					cmd_out("Bad Type ID: ",id);

				xp = coord_transform(x,fx0,fx1,u0,u1);
                yp = coord_transform(y,fy0,fy1,v0,v1);
            }
// AW98	    if (xp != xc || yp != yc)
	    {
	        if (pulsefg == 1)
                {
                	draw_line(widget,xp,yp,xp,yc,1);
                	yp = yc;
                }
                draw_line(widget,xp,yp,xc,yc,1);
	    }
        }

//	((NslFloat0*) _layer0)->set_value(m);
 
	if (id == 0) 
		*((NslFloat0*) _layer0) = *((NslFloat0*) _layer);
	else if (id == 1)
		*((NslFloat0*) _layer0) = *((NslFloat0*) _layer);
	else if (id == 2)
		*((NslFloat0*) _layer0) = *((NslFloat0*) _layer);
	else
		cmd_out("Bad Type ID: ",id);

	return 1;
}

int xnsl_temporal_graph_data::read_from_database()
{
	return 1;
}
int xnsl_temporal_graph_data::write_to_database()
{
	return 1;
}
int xnsl_temporal_graph_data::print(ostream& out) const
{
	xnsl_temporal_graph::print(out);

	return 1;
}

