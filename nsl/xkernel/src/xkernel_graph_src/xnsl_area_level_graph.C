/* SCCS  %W%---%E%--%U% */
//
//	xnsl_area_level_graph.C
//

#include "xkernel.h"
#include "nsl_kernel.h" 

extern int TK_DRAW;
extern int nsl_rint(num_type s);

xnsl_area_level_graph::xnsl_area_level_graph(xnsl_display_canvas* win) : 
	xnsl_graph(win) 
{
        set_type("area_level_graph");
}
xnsl_area_level_graph::~xnsl_area_level_graph()  
{
}

xnsl_widget * xnsl_area_level_graph::make_widget()
{
	cmd_error("xnsl_area_level_graph: CANNOT create widget");
        return 0;
}

int xnsl_area_level_graph::clear()
{
 	return 1;
}
int xnsl_area_level_graph::display()
{
//      display_area_level_graph(_widget,_wx0,_wy0,_wxs,_wys,_wymin,_wymax);
         
//      xflush();
         
      	return 1;
}
int xnsl_area_level_graph::display_area_level_graph(xnsl_widget*,
	int,int,int,int,num_type, num_type,int,int,int)
{
 	return 1;
}
int xnsl_area_level_graph::display_area_level_graph_val(xnsl_widget* widget,
	int wx0,int wy0,int wxs,int wys,
	num_type val,num_type val0,num_type vmin, num_type vmax,int ni,int nj) 
{
        int wxc,wyc,i0,j0,ic,jc;
        num_type s;
		int pos = 1; // black fill
		int fg = 0; //tk draw: 1, xdraw: 0

		// if (TK_DRAW == 1) then always draw if values are different
		if (TK_DRAW == 1 && val == val0) 
			return 1;

			clear_area(widget,wx0+1,wy0+1,wxs-1,wys-1,ni,nj,0,fg);  // always clear first
//        else
        {
            if (vmin > 0.0)
                vmin = 0.0;
            if (vmax < 0.0)
                vmax = 0.0;
            if (vmin == 0.0 && vmax == 0.0)
                vmax = 1.0;

            if ((val>=vmax && vmax > 0.0) || (val<=vmin && vmin < 0.0))
            {
                wxc = wxs;
                wyc = wys;
            }
            else
            {
                s = 0.0;
                if (val > 0.0 && vmax > 0.0)
                    s = val/vmax;
                else if (val < 0.0 && vmin < 0.0)
                    s = val/vmin;

                wxc = (int) nsl_rint(s*wxs);
                wyc = (int) nsl_rint(s*wys);
            }
            ic = (wxs - wxc)/2;	  // x length to be taken out from half area
            jc = (wys - wyc)/2;	  // y length to be taken out from half area
            i0 = ic + wx0;	  // x starting point for new graph
            j0 = jc + wy0;	  // y starting point for new graph
			wxc = wx0 + wxs - i0 - ic; // make sure x area is symmetric
			wyc = wy0 + wys - j0 - jc; // make sure y are is symmetric
            if (TK_DRAW == 1 || (wxc-1 > 0 && wyc-1 > 0)) {
				if (val <= 0.0)
					pos = -1;
				if (val == 0) {
					i0 = 0;
					j0 = 0;
					wxc = 0;
					wyc = 0;
				}
//				fill_rectangle(widget,i0+1,j0,wxc-1,wyc-1,ni,nj,pos); 
				fill_rectangle(widget,i0,j0,wxc,wyc,ni,nj,pos,fg); 
			}
//          
//            {
//                if (wxc-3 > 0 && wyc-3 > 0)
//					clear_area(widget,i0+2,j0+1,wxc-3,wyc-3); 
//            }
//
        }

	return 1;
}
int xnsl_area_level_graph::read_from_database()
{
	return 1;
}
int xnsl_area_level_graph::write_to_database()
{
	return 1;
}
int xnsl_area_level_graph::input(int,int,int)
{
	return 1;
}
int xnsl_area_level_graph::output(int,int)
{
	return 1;
}
int xnsl_area_level_graph::print(ostream&) const
{
	return 1;
}
