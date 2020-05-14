/* SCCS  %W%---%E%--%U% */
//
//	xnsl_spatial_graph_2_vector.C
//

#include "xkernel.h"
#include "nsl_kernel.h" 

xnsl_spatial_graph_2_vector::xnsl_spatial_graph_2_vector(
	xnsl_display_canvas* win,nsl_layer* m) : xnsl_spatial_graph_2(win)
{
        set_type("spatial_graph_2_vector");

	if (m != NULL)
	{
		_layer = m;
		_layer0 = m;

		_imax = ((nsl_vector_layer*) _layer)->get_imax();
		_i0 = 0;
		_i1 = _imax - 1;
		_vec_type = NSL_ROW;
 	}
//	else
//		cmd_error("xnsl_spatial_graph_2_vec: NULL layer");
}
xnsl_spatial_graph_2_vector::~xnsl_spatial_graph_2_vector()  
{
}
xnsl_widget * xnsl_spatial_graph_2_vector::make_widget()
{
    return new xnsl_spatial_graph_2_vector((xnsl_display_canvas*) m_parent,_layer);
}
int xnsl_spatial_graph_2_vector::display()
{
//	set_env("",_X0,_Y0,_width,_height,_wx0,_wy0,_wx1,_wy1,_wxs,_wys);
	display_spatial_graph_2(_widget,_wx0,_wy0,_wx1,_wy1,_wxs,_wys,_wymin,_wymax);
 
	return 1;
}
int xnsl_spatial_graph_2_vector::display_spatial_graph_2(xnsl_widget* widget,
	int wx0,int wy0,int wx1,int wy1,int wxs,int wys,
	num_type wymin, num_type wymax) 
{
 	int id = _layer->get_type_id();

       if (_vec_type != NSL_ROW)
        {
                cmd_error("xnsl_spatial_graph_2_vec:Unable to draw col vector");
                return 1;
        }

//		nsl_num_vector* m = ((nsl_num_1*) _layer);

        num_type x,y;
        int xp,yp,xc,yc;

        num_type fx0 = (num_type) _i0;
        num_type fx1 = (num_type) _i1;

        num_type u0 = (num_type) wx0;
        num_type u1 = (num_type) (wx1 - wx0);
        num_type v0 = (num_type) wy0;
        num_type v1 = (num_type) (wy1 - wy0);

        num_type fy0 = wymin;
        num_type fy1 = wymax;

        xp = wx0 + wxs/2;
//        yp = coord_transform((*m)[_i0],fy0,fy1,v0,v1);
		if (id == 0) 
			yp = coord_transform((*((NslFloat1*) _layer))[_i0],fy0,fy1,v0,v1);
		else if (id == 1)
			yp = coord_transform((*((NslFloat1*) _layer))[_i0],fy0,fy1,v0,v1);
		else if (id == 2)
			yp = coord_transform((*((NslFloat1*) _layer))[_i0],fy0,fy1,v0,v1);
		else
			cmd_out("Bad Type ID: ",id);

		int pos = 0;

// AW98 added to avoid full canvas clear
//	    clear_area(widget,wx0+1,wy0+1,wx1-wx0-1,wy1-wy0-1,pos);  // always clear first

	    draw_line(widget,wx0,yp,xp,yp,0,_i0-1,0,0);

        for (int i = _i0; i <= _i1; i++)
        {
// AW99 added to avoid full canvas clear
				int wxi0 = wx0+i*wxs+1;
				int wyi0 = wy0+1;
//				int wxi1 = wx0+(i+1)*wxs-1;
//				int wyi1 = wy1-1;
				clear_area(widget,wxi0,wyi0,wxs-1,wys-1,pos);
//				clear_area(widget,wxi0,wyi0,wxi1,wyi1,pos);
//				clear_area(widget,wx0+i*(wxs+1)+1,wy0+1,wx0+(i+1)*(wxs-1),wy1-1,pos);

//              if (breakfg == 1)
//                  return(1);

                x = (num_type) i; 
//                y = (*m)[i];
				if (id == 0) {
					y = (*((NslFloat1*) _layer))[i];
				} else if (id == 1) {
					y = (*((NslFloat1*) _layer))[i]; 
				} else if (id == 2) {
					y = (*((NslFloat1*) _layer))[i]; 
				} else
					cmd_out("Bad Type ID: ",id);

                xc = wx0 + (i-_i0)*wxs + wxs/2;
                yc = coord_transform(y,fy0,fy1,v0,v1);
                if (pulsefg == 1)
                {
                        xp = wx0 + (i-_i0)*wxs;
                        xc = wx0 + (i-_i0+1)*wxs;
                        draw_line(widget,xp,yp,xp,yc);
                        yp = yc;
                }
                draw_line(widget,xp,yp,xc,yc,0,i,0,0);
                xp = xc;
                yp = yc;
        }
        //draw_line(widget,xp,yp,wx1,yp,0,i,0,0);

	return 1;
}

int xnsl_spatial_graph_2_vector::read_from_database()
{
	return 1;
}
int xnsl_spatial_graph_2_vector::write_to_database()
{
	xnsl_spatial_graph_2::write_to_database();

	return 1;
}
int xnsl_spatial_graph_2_vector::print(ostream& out) const
{
	xnsl_spatial_graph_2::print(out);

	return 1;
}

