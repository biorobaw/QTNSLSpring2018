/* SCCS  %W%---%E%--%U% */
//
//	xnsl_spatial_graph_3_matrix.C
//

#include "xkernel.h"
#include "nsl_kernel.h" 
#include "xnsl_spatial_graph_3_matrix.h"

extern int nsl_rint(num_type s);

xnsl_spatial_graph_3_matrix::xnsl_spatial_graph_3_matrix(
	xnsl_display_canvas* win,nsl_layer* m) : xnsl_spatial_graph_3(win)
{
        set_type("spatial_graph_3_matrix");

	if (m != NULL)
	{
		_layer = m;
		_layer0 = m;

		_imax = ((nsl_matrix_layer*) _layer)->get_imax();
		_jmax = ((nsl_matrix_layer*) _layer)->get_jmax();
		_i0 = 0;
		_j0 = 0;
		_i1 = _imax - 1;
		_j1 = _jmax - 1;
 	}
//	else
//		cmd_error("xnsl_spatial_graph_3_mat: NULL layer");
}
xnsl_spatial_graph_3_matrix::~xnsl_spatial_graph_3_matrix()
{
}
xnsl_widget * xnsl_spatial_graph_3_matrix::make_widget()
{
        return new xnsl_spatial_graph_3_matrix((xnsl_display_canvas*) m_parent,_layer);
}
int xnsl_spatial_graph_3_matrix::display()
{
//	set_env("",_X0,_Y0,_width,_height,_wx0,_wy0,_wx1,_wy1,_wxs,_wys);
	display_spatial_graph_3(_widget,_wx0,_wy0,_wx1,_wy1,_wymin,_wymax);
	 
	return 1;
}

int xnsl_spatial_graph_3_matrix::display_spatial_graph_3(xnsl_widget* widget,
	int wx0,int wy0,int wx1,int wy1,
	num_type wymin, num_type wymax) 
{
	clear_area(widget,wx0+1,wy0+1,wx1-wx0-1,wy1-wy0-1,0);  // always clear first

	int graph_x_mid = (wx1 - wx0)/2;
	int graph_y_mid = (wy1 - wy0)/2;

	int win_x_mid = graph_x_mid + wx0;
	int win_y_mid = graph_y_mid + wy0;

// plt3d(graph_x_mid,graph_y_mid,i0,i1,j0,j1,ax,by,cz,sx,sy,sz,wymin,wymax);

	float rx0,rx1,ry0,ry1;

  	xcale = sx;
  	ycale = sy;
  	zcale = sz;

  	if ((ax == 0.0) && (by == 0.0))  
		d3to2doo();
  	else
		d3to2d(ax,by,cz);
 
	rx0 = (float) _j0;
	rx1 = (float) _j1;
	ry0 = (float) _i0;
	ry1 = (float) _i1;

	aax = ax;
	bby = by;
	ccz = cz;

  	d3midl(rx0,rx1,ry0,ry1,wymin,wymax);
	d3scal(graph_x_mid,graph_y_mid);

	if (hidden_fg == 1)
		draw_hide(widget,win_x_mid,win_y_mid);
 	else
		draw_no_hide(widget,win_x_mid,win_y_mid);

	return 1;
}

int xnsl_spatial_graph_3_matrix::read_from_database()
{
	return 1;
}
int xnsl_spatial_graph_3_matrix::write_to_database()
{
	xnsl_spatial_graph_3::write_to_database();

	return 1;
}
int xnsl_spatial_graph_3_matrix::print(ostream& out) const
{
	xnsl_spatial_graph_3::print(out);

	return 1;
}

int xnsl_spatial_graph_3_matrix::draw_3D_axis(xnsl_widget* widget,int x_mid,int y_mid,
	num_type rmin,num_type rmax)
{
	num_type rx0,rx1,ry0,ry1,delx,dely;

	delx = 1.0;
	dely = 1.0;
	
 	rx0 = _j0*delx;
	ry0 = _i0*dely;
	rx1 = _j1*delx;
	ry1 = _i1*dely;
	draw_3D_single_axis(widget,x_mid,y_mid,rx1,ry0,0.0,rx0,ry0,0.0);
	draw_3D_text(widget,x_mid,y_mid,rx1,ry0,0.0,"X");
	draw_3D_single_axis(widget,x_mid,y_mid,rx0,ry1,0.0,rx0,ry0,0.0);
	draw_3D_text(widget,x_mid,y_mid,rx0,ry1,0.0,"Y");
	draw_3D_single_axis(widget,x_mid,y_mid,rx0,ry0,rmax,rx0,ry0,rmin);
	draw_3D_text(widget,x_mid,y_mid,rx0,ry0,rmax,"Z");

	return 1;
}

int xnsl_spatial_graph_3_matrix::draw_hide(xnsl_widget* widget,int canvas_x_mid,int canvas_y_mid)
{
	int i,j,k,klim,xi,yi,oxi = 0,oyi = 0;
	float x3,y3,z3,x,y,delx,dely;
	int uppr[MAX_SIZE], lowr[MAX_SIZE];
	int istart, jstart, ilim, jlim, iincr, jincr, iend, loopx;

//	nsl_num_matrix* mat = ((nsl_num_2*) _layer);
	int id = _layer->get_type_id();

	init_arrs(uppr,lowr);
	delx = 1.0;
	dely = 1.0;
	detview(_i0,_i1,_j0,_j1,
		&istart,&jstart,&ilim,&jlim,&iincr,&jincr,&iend,&loopx);
	i = istart;
	while (i != ilim)
	{ 
	   j = jstart;
	   while (j != jlim)
	   {
       	   if (loopx == 1)
	       { /* switched x,y */
     		x3 = j*delx;
     		y3 = i*dely;
 //    		z3 = (*mat)[i][j];
			if (id == 0) {
				z3 = (*((NslFloat2*) _layer))[i][j];
			} else if (id == 1) {
				z3 = (*((NslFloat2*) _layer))[i][j]; 
			} else if (id == 2) {
				z3 = (*((NslFloat2*) _layer))[i][j]; 
			} else
				cmd_out("Bad Type ID: ",id);
	       }
	     else
	       { /* switched x,y */
     		x3 = i*delx;
     		y3 = j*dely;
//     		z3 = (*mat)[j][i];
			if (id == 0) {
				z3 = (*((NslFloat2*) _layer))[j][i];
			} else if (id == 1) {
				z3 = (*((NslFloat2*) _layer))[j][i]; 
			} else if (id == 2) {
				z3 = (*((NslFloat2*) _layer))[j][i]; 
			} else
				cmd_out("Bad Type ID: ",id);
	       }

		x = ((float) d3on2dsc(x3,y3,z3,xa,xb,xc)-xm)*scx;
		y = ((float) d3on2dsc(x3,y3,z3,ya,yb,yc)-ym)*scy;
        	xi = nsl_rint(x) + canvas_x_mid;
                yi = nsl_rint(y) + canvas_y_mid;
		///if (j != jstart)
			//dodraw(widget,oxi,oyi,xi,yi,uppr,lowr);
		oxi = xi;
		oyi = yi;
	        j = j + jincr;
 	   }
           if (i != iend)
	     {
	       j = jstart;
	       while (j != jlim)
		 {
		   klim = i + 2*iincr;
		   k = i;
		   while (k != klim)
        	     {
		       if (loopx == 1)
			 { /* switched x,y */
			   x3 = j*delx;
			   y3 = k*dely;
//			   z3 = (*mat)[k][j];
				if (id == 0) {
					z3 = (*((NslFloat2*) _layer))[k][j];
				} else if (id == 1) {
					z3 = (*((NslFloat2*) _layer))[k][j]; 
				} else if (id == 2) {
					z3 = (*((NslFloat2*) _layer))[k][j]; 
				} else
					cmd_out("Bad Type ID: ",id);
			 }
		       else
			 {/* switched x,y */
			   x3 = k*delx;
			   y3 = j*dely;
//			   z3 = (*mat)[j][k];
				if (id == 0) {
					z3 = (*((NslFloat2*) _layer))[j][k];
				} else if (id == 1) {
					z3 = (*((NslFloat2*) _layer))[j][k]; 
				} else if (id == 2) {
					z3 = (*((NslFloat2*) _layer))[j][k]; 
				} else
					cmd_out("Bad Type ID: ",id);
			 }
		       x = ((float) d3on2dsc(x3,y3,z3,xa,xb,xc)-xm)*scx;
		       y = ((float) d3on2dsc(x3,y3,z3,ya,yb,yc)-ym)*scy;
		       xi = nsl_rint(x) + canvas_x_mid;
		       yi = nsl_rint(y) + canvas_y_mid;
		       if (i != k)
			 //dodraw(widget,oxi,oyi,xi,yi,uppr,lowr);
		       oxi = xi;
		       oyi = yi;
		       k = k + iincr;
		     }                                   /* next k */
		   j = j + jincr;
	         }                                       /* next j */
             }	                                         /* endif not last i */
	   i = i + iincr;
	}                                                /* next i */

	return 1;
}
int xnsl_spatial_graph_3_matrix::draw_no_hide(xnsl_widget* widget,int canvas_x_mid,int canvas_y_mid)
{
	int i,j,xi,yi,oxi,oyi;
	float x3,y3,z3,x,y,delx,dely;

	delx = 1.0;
	dely = 1.0;

//	nsl_num_matrix* mat = ((nsl_num_2*) _layer);
	int id = _layer->get_type_id();

 	for (i = _i0; i <= _i1; i++) 
	{ 
	   for (j = _j0; j <= _j1; j++)  
	   { 	/* crossed x,y */
     		x3 = j*delx;
     		y3 = i*dely;
 //    		z3 = (*mat)[i][j];
			if (id == 0) {
				z3 = (*((NslFloat2*) _layer))[i][j];
			} else if (id == 1) {
				z3 = (*((NslFloat2*) _layer))[i][j]; 
			} else if (id == 2) {
				z3 = (*((NslFloat2*) _layer))[i][j]; 
			} else
				cmd_out("Bad Type ID: ",id);
			x = ((float) d3on2dsc(x3,y3,z3,xa,xb,xc)-xm)*scx;
			y = ((float) d3on2dsc(x3,y3,z3,ya,yb,yc)-ym)*scy;
        	xi = nsl_rint(x) + canvas_x_mid;
            yi = nsl_rint(y) + canvas_y_mid;
			if (j != _j0)
				draw_line(widget,oxi,oyi,xi,yi,0,i,j,0);
			oxi = xi;
			oyi = yi;
 	   }
	}
	for (j = _j0; j <= _j1; j++)  
	{ 
 	   for (i = _i0; i <= _i1; i++)  
	   {	/* crossed x,y */
     		x3 = j*delx;
     		y3 = i*dely;
 //    		z3 = (*mat)[i][j];
			if (id == 0) {
				z3 = (*((NslFloat2*) _layer))[i][j];
			} else if (id == 1) {
				z3 = (*((NslFloat2*) _layer))[i][j]; 
			} else if (id == 2) {
				z3 = (*((NslFloat2*) _layer))[i][j]; 
			} else
				cmd_out("Bad Type ID: ",id);
			x = ((float) d3on2dsc(x3,y3,z3,xa,xb,xc)-xm)*scx;
			y = ((float) d3on2dsc(x3,y3,z3,ya,yb,yc)-ym)*scy;
        	xi = nsl_rint(x) + canvas_x_mid;
            yi = nsl_rint(y) + canvas_y_mid;
			if (i != _i0)
			draw_line(widget,oxi,oyi,xi,yi,0,i,j,0);
			oxi = xi;
			oyi = yi;
 	   }
	}

	return 1;
}

