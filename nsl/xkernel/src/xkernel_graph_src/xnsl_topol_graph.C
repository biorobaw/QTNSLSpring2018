/* SCCS  %W%---%E%--%U% */
// draw the topology of two matrices
#include "nsl_num.h"
#include "xnsl_canvas.h"

extern int coord_transform(num_type s,num_type s0,num_type s1,num_type vu0,num_type vu);

void draw_matrix_topology(xnsl_canvas parent_canvas,float** m1,float** m2, int wx0, int wy0, int wx1, int wy1, int i0, int i1, int j0, int j1,
	float m1min, float m1max, float m2min, float m2max)
{
	int x1,y1,x2,y2;

	num_type ux0 = wx0;	//coord of the drawing window in pixels
	num_type ux1 = wx1;
	num_type uy0 = wy0;
	num_type uy1 = wy1;

	num_type fx0 = m1min;	//coord of the drawing window in scale
	num_type fx1 = m1max;
	num_type fy0 = m2min;
	num_type fy1 = m2max;

	for (int i = j0; i <= i1; i++)
	    for (int j = j0; j <= j1-1; j++)
	    {
		x1 = coord_transform(m1[i][j],fx0,fx1,ux0,ux1);
		y1 = coord_transform(m2[i][j],fy0,fy1,uy0,uy1);
		x2 = coord_transform(m1[i][j+1],fx0,fx1,ux0,ux1);
		y2 = coord_transform(m2[i][j+1],fy0,fy1,uy0,uy1);
		//draw_line(parent_canvas,x1,y1,x2,y2);
	    }

	for (int j = j0; j <= j1; j++)
	    for (int i = i0; i <= i1-1; i++)
	    {
		x1 = coord_transform(m1[i][j],fx0,fx1,ux0,ux1);
		y1 = coord_transform(m2[i][j],fy0,fy1,uy0,uy1);
		x2 = coord_transform(m1[i+1][j],fx0,fx1,ux0,ux1);
		y2 = coord_transform(m2[i+1][j],fy0,fy1,uy0,uy1);
		//draw_line(parent_canvas,x1,y1,x2,y2);
	    }
}		    
