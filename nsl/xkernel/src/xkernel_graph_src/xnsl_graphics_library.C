/* SCCS  %W%---%E%--%U% */
//
//	xnsl_graphics_library.C
//

#include "nsl_kernel.h"
#include "xkernel.h"
#include <cmath>

// point view transformation
// overload coord_transform;
int coord_transform(num_type s,num_type s0,num_type s1,num_type vu0,num_type vu)
{
        s = vu0 + vu*(s-s0)/(s1-s0); // vu = vu1 - vu0
        return(rint(s));
}

// area level graph

void draw_area_level_element(xnsl_widget* canvas,num_type val,num_type val0,
	int wx0,int wy0,int wxs,int wys,num_type vmin,num_type vmax,int fg)
{
	if (val != val0 || fg == 1) // new different values only
	{
//	     if (val < val0 || val < 0)
//		clear_area_level(canvas,wx0,wy0,wxs,wys);
	     //draw_area_level_val(canvas,wx0,wy0,wxs,wys,val,vmin,vmax);
	}
}
void draw_area_level_vector(xnsl_widget* canvas,num_type* vec,num_type* vec0,
	int wx0,int wy0,int wxs,int wys,int i0,int i1,
	num_type vmin,num_type vmax,int fg,int vec_type)
{
	int i,ni;
	num_type val,val0;

	if (vec_type == 0)
	    for (i = wx0, ni = i0; ni <= i1; i = i + wxs, ni++)
	    {
		val = vec[ni];
	     	val0 = vec0[ni];
		if (val != val0 || fg == 1) // new different values only
		{
//	 	    if (val < val0 || val < 0)
//			clear_area_level(canvas,i,wy0,wxs,wys);
		    //draw_area_level_val(canvas,i,wy0,wxs,wys,val,vmin,vmax);
		}
	    }
	else
	    for (i = wy0, ni = i0; ni <= i1; i = i + wys, ni++)
	    {
		val = vec[ni];
	     	val0 = vec0[ni];
		if (val != val0 || fg == 1) /* new different values only */
		{
//	 	    if (val < val0 || val < 0)
//			clear_area_level(canvas,wx0,i,wxs,wys);
		    //draw_area_level_val(canvas,wx0,i,wxs,wys,val,vmin,vmax);
		}
	    }
}
void draw_area_level_matrix(xnsl_widget* canvas,num_type** mat,num_type** mat0,
	int wx0,int wy0,int wxs,int wys,int i0,int i1,int j0,int j1,
	num_type vmin,num_type vmax,int fg)
{
	int i,j,ni,nj;
	num_type val,val0;

/*	for (i = wx0, ni = x0; ni <= x1; i = i + wxs, ni++)
	    for (j = wy0, nj = y0; nj <= y1; j = j + wys, nj++)
*/	for (j = wy0, ni = i0; ni <= i1; j = j + wys, ni++)
	    for (i = wx0, nj = j0; nj <= j1; i = i + wxs, nj++)
	    {
		val = mat[ni][nj];
		val0 = mat0[ni][nj];
		if (val != val0 || fg == 1) /* new different values only */
		{
//	 	    if (val < val0 || val < 0)
//			clear_area_level(canvas,i,j,wxs,wys);
		    //draw_area_level_val(canvas,i,j,wxs,wys,val,vmin,vmax);
		}
	    }
}

// spatial graph 2

void draw_spatial_graph_2_par(xnsl_widget* canvas,num_type val,
	int wx0,int wy0,int wx1,int wy1,int wxs,int wys,
	num_type fmin,num_type fmax,int pulsefg)
{
	pulsefg = 0; wxs = 0; wys = 0;

	num_type u0 = (num_type) wx0;
	num_type u1 = (num_type) (wx1 - wx0);
	num_type v0 = (num_type) wy0;
	num_type v1 = (num_type) (wy1 - wy0);

	num_type fy0 = fmin;
	num_type fy1 = fmax;

	int yp = coord_transform(val,fy0,fy1,v0,v1);

        //draw_line(canvas,wx0,yp,wx1,yp);
}
void draw_spatial_graph_2_vector(xnsl_widget* canvas,num_type* vec,
	int wx0,int wy0,int wx1,int wy1,int wxs,int wys,int i0,int i1,
	num_type fmin,num_type fmax,int pulsefg,int vec_type)
{
	if (vec_type != 0)
	{
		cmd_error("Unable to draw col vector");
		return;
	}

	wys = 0;

	num_type x,y;
	int xp,yp,xc,yc;

	num_type fx0 = (num_type) i0;
	num_type fx1 = (num_type) i1;

	num_type u0 = (num_type) wx0;
	num_type u1 = (num_type) (wx1 - wx0);
	num_type v0 = (num_type) wy0;
	num_type v1 = (num_type) (wy1 - wy0);

	num_type fy0 = fmin;
	num_type fy1 = fmax;

	xp = wx0 + wxs/2;
	yp = coord_transform(vec[i0],fy0,fy1,v0,v1);

        //draw_line(canvas,wx0,yp,xp,yp);

      	for (int i = i0; i <= i1; i++)
        {
//	    	if (breakfg == 1)
//		    return(1);

		x = (num_type) i; 
		y = vec[i];

		xc = wx0 + (i-i0)*wxs + wxs/2;
		yc = coord_transform(y,fy0,fy1,v0,v1);
                if (pulsefg == 1)
		{
			xp = wx0 + (i-i0)*wxs;
			xc = wx0 + (i-i0+1)*wxs;
                	////draw_line(canvas,xp,yp,xp,yc);
 			yp = yc;
		}
                ////draw_line(canvas,xp,yp,xc,yc);
 		xp = xc;
		yp = yc;
        }
        ////draw_line(canvas,xp,yp,wx1,yp);
}

// data temporal graph

void draw_temporal_graph_data(xnsl_widget* parent_canvas,num_type m,num_type m0,
	int wx0,int wy0,int wxs,int wys,
	float fmin,float fmax,float t0,float t1,float ts,float dt,int pulsefg)
{
	int ux0,uy0;
	num_type u0,u1,v0,v1;
        num_type x,y;
	int xc,yc,xp,yp;

	num_type fx0 = t0;
	num_type fx1 = t1;

	num_type fy0 = fmin;
	num_type fy1 = fmax;

//	if (breakfg == 1)
//	    return(1);

	if (ts >= 0.0)
	{
	    ux0 = wx0;
	    uy0 = wy0;
	    u0 = (num_type) ux0;
	    u1 = (num_type) wxs;
	    v0 = (num_type) uy0;
	    v1 = (num_type) wys;

	    x = ts; 
	    y = m;
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
		y = m0;
		xp = coord_transform(x,fx0,fx1,u0,u1);
		yp = coord_transform(y,fy0,fy1,v0,v1);
            }
            if (pulsefg == 1)
            {
       		//draw_line(parent_canvas,xp,yp,xp,yc);
 		yp = yc;
            }
            //draw_line(parent_canvas,xp,yp,xc,yc);
	}
}

// vector temporal graph

void draw_temporal_graph_vector(xnsl_widget* parent_canvas,num_type* m,num_type* m0,
	int wx0,int wy0,int wxs,int wys,int i0,int i1,float fmin,float fmax,
	float t0,float t1,float ts,float dt,int pulsefg,int vec_type)
{
	if (vec_type != 0)
	{
		cmd_error("Unable to draw col vector");
		return;
	}

	int ux0,uy0;
	num_type u0,u1,v0,v1;
        num_type x,y;
	int xc,yc,xp,yp;

	num_type fx0 = t0;
	num_type fx1 = t1;

	num_type fy0 = fmin;
	num_type fy1 = fmax;

	for (int i = i0; i <= i1; i++)
	{
//	    	if (breakfg == 1)
//		    return(1);

		if (ts >= 0.0)
		{
		    ux0 = wx0 + (i-i0)*wxs;
		    uy0 = wy0;

		    u0 = (num_type) ux0;
		    u1 = (num_type) wxs;
		    v0 = (num_type) uy0;
		    v1 = (num_type) wys;

		    x = ts; 
		    y = m[i];
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
			y = m0[i];
			xp = coord_transform(x,fx0,fx1,u0,u1);
			yp = coord_transform(y,fy0,fy1,v0,v1);
	            }
	            if (pulsefg == 1)
	            {
	       		//draw_line(parent_canvas,xp,yp,xp,yc);
	 		yp = yc;
	            }
	            //draw_line(parent_canvas,xp,yp,xc,yc);
		}
	}
}

// matrix temporal graph

void draw_temporal_graph_matrix(xnsl_widget* parent_canvas,num_type** m,num_type** m0,
	int wx0,int wy0,int wxs,int wys,int i0,int i1,int j0,int j1,
	float fmin,float fmax,float t0,float t1,float ts,float dt,int pulsefg)
{
	int ux0,uy0;
	num_type u0,u1,v0,v1;
        num_type x,y;
	int xc,yc,xp,yp;

	num_type fx0 = t0;
	num_type fx1 = t1;

	num_type fy0 = fmin;
	num_type fy1 = fmax;

	for (int i = i0; i <= i1; i++)
	    for (int j = j0; j <= j1; j++)
	    {
//	    	if (breakfg == 1)
//		    return(1);

		if (ts >= 0.0)
		{
// x,y crossed
/*		    ux0 = wx0 + (i-i0)*wxs;
		    uy0 = wy0 + (j1-j)*wys;
//		    uy0 = wy0 + (j-j0)*wys;
*/
		    ux0 = wx0 + (j-j0)*wxs;
		    uy0 = wy0 + (i1-i)*wys;

		    u0 = (num_type) ux0;
		    u1 = (num_type) wxs;
		    v0 = (num_type) uy0;
		    v1 = (num_type) wys;

		    x = ts; 
		    y = m[i][j];
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
			y = m0[i][j];
			xp = coord_transform(x,fx0,fx1,u0,u1);
			yp = coord_transform(y,fy0,fy1,v0,v1);
	            }
	            if (pulsefg == 1)
	            {
	       		//draw_line(parent_canvas,xp,yp,xp,yc);
	 		yp = yc;
	            }
	            //draw_line(parent_canvas,xp,yp,xc,yc);
		}
	   }
}
