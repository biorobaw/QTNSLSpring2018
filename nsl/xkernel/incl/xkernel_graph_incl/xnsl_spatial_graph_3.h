/* SCCS  %W%---%E%--%U% */
//
// 	xnsl_spatial_graph_3.h
//

# define vmax(x,y) (x > y ? x : y)
# define vmin(x,y) (x < y ? x : y)
# define  MAX_SIZE 1200      /* resolution of the screen */

/* 
   This is the C version of the updatted subroutine for plotting 
   3d projections.

   There are some subroutines added that have to be modified to 
   adapt the program to Sunview.

-----------------------------------------

   Alfredo Weitzenfeld      May-86

   Marcelo Mintz            May-89

   Peiman Navid		    Nov-90

------------------------------------------

Purpose:  This soubroutine makes a two dimensional picture of a 
        function of two arguments, the hidden parts of the surface 
        not shown.  This soubroutine uses subroutine blocks 
        extracted from plt3dm to simplify the 3-d graphics and
        make it more versatile. To do that we use a 3-d common
        block d3 which includes the variable necessary to transfer 
        among the various routines.

Space:  The 3-d space is defined as follows:      | Z
                                                  |
                                                 / \
                                              Y /   \ X
                                                
Method: The routine first finds the point nearest to the
        viewer's eye. Then determines the center of the picture 
        and projects this to the point of the viewing 
        space of the routine which spans max integer units in 
        the X direction and max integer units in the Y direction
        Lines in the foreground closest to the viewer, are plotted
        first. If a line lies outside the visibility area, the line
        is not drawn. Linear interpolaion is used to plot the 
        lines that cross the edge of the visibility area. The 
        edges of the visibility area are stored in the array MASK
        which is updated each time a line was written.

Arguments:
       MAT: matrix of two dimensions mat = mat[x][y] that must be
            input to the program.
       XLO,
       XHI: bounds of the x-interval.
       YLO,
       YHI: bounds of the y-interval.
     A,B,C: viewer's eye position in three space.
            These are defined as coordinates on the unit cube
            eg .. 1,1,.25 where the viewer lies on the .25 above
            the XY plane diagonal.
    NLINES: number of lines on the surfacen (typically 60-100)
      NPTS: number of points per-line (less than 198 )
            ( In program defined as 100 ).
       IDI: code for direction of 3-D lines.
            = 1 - Lines are drawn parallel to Y-direction
            = 2 - Lines are drawn parallel to X-direction
            = 3 - Lines are drawn in both directions

Subroutines:
     d3axes: Draw the 3-d axes at the base of the picture cube
     d3cord: Get the new data values for the next line to plot
     d3draw: Move the cursor or draw a line to the projected 
             3-d point.
     d3edge: Determine the sector edge of visibility points.
     d3hide: Determine 2-d point location relative to visibility area
     d3incf: X and Y increment for 3-d function values
     d3init: Initialize the 3-d common block variables and data file
     d3lnfn: get the new function values for the next line to plot
     d3mask: Update the 3-d mask of visibility
     d3midl: Compute the center of the picture
     d3mimx: Obtain the minimax data in 3d
     d3ntrp: Interpolate and project a 3-d line.
     d3plot: Plot a line with hidden parts not shown.
     d3scal: Compute scaling factors for 3-d
     d3on2d: Rotate and project 3-d onto 2-d     
     d3szfn: Determine the 3-d function extremum
     d3to2d: Compute the 3-d to 2-d rotation and projection
             coefficients
        MAT: mat[x][y]  { function to plot in array form }
     iniarr: Initialize an array
     d3sgmt: draw a line segment from (ixi,iyi) to (ixl, iyl)

Internal Variables:
    icord(,1) - X values of the lines
    icord(,2) - Y values of the lines
   mask(ix,1) - The lower bound of the bound of visibility
   mask(ix,2) - The upper bound of the bound of visibility
*/
#ifndef _XNSL_SPATIAL_GRAPH_3_H
#define _XNSL_SPATIAL_GRAPH_3_H
#include "xnsl_graph.h"
class xnsl_display_canvas;
class xnsl_spatial_graph_3 : public xnsl_graph
{
protected:
	int hidden_fg;		// 1 - hidden line removal, 0 - otherwise
	num_type sx,sy,sz;	// scaling for 3D graphs 
	num_type ax,by,cz;	// rotation for 3D graphs

	num_type xcale,ycale,zcale;
	num_type xa,xb,xc,ya,yb,yc,za,zb,zc;
	num_type great; // = 1.E20;
	num_type rxx[2],ryy[2],rzz[2];
	num_type xm, ym;
	num_type scx,scy;
	num_type xm3,ym3,zm3;
	num_type zi;
	num_type xnew, ynew, znew;
	num_type aax,bby,ccz;

	int   incsz; // = 1;             // interpolation increment
public:
	xnsl_spatial_graph_3(xnsl_display_canvas* = 0);
	virtual ~xnsl_spatial_graph_3();
	
	void set_ax(num_type s) { ax = s; }
	void set_by(num_type s) { by = s; }
	void set_cz(num_type s) { cz = s; }
	void set_sx(num_type s) { sx = s; }
	void set_sy(num_type s) { sy = s; }
	void set_sz(num_type s) { sz = s; }
	void set_hidden_fg(int s) { hidden_fg = s; }

	num_type get_ax() { return ax; }
	num_type get_by() { return by; }
	num_type get_cz() { return cz; }
	num_type get_sx() { return sx; }
	num_type get_sy() { return sy; }
	num_type get_sz() { return sz; }
	int get_hidden_fg() { return hidden_fg; }
	
        virtual xnsl_widget *make_widget();

        virtual int display();
        virtual int display_spatial_graph_3(xnsl_widget* = 0,int=0,int=0,int=10,int=10,
		num_type = 0.0, num_type = 1.0);
 
	virtual int	read_from_database();
	virtual int	write_to_database();
	virtual int	print(ostream&) const;
 	virtual	int	input(int,int,int);
	virtual	int	output(int,int);

	num_type d3on2d(num_type,num_type,num_type,
		num_type,num_type,num_type);
	num_type d3on2dsc(num_type,num_type,num_type,
		num_type,num_type,num_type);

	int d3to2d(num_type,num_type,num_type);
	int d3to2doo();

	int d3scal(int,int);

	int d3midl(num_type,num_type,num_type,
		num_type,num_type,num_type);

	int draw_3D_single_axis(xnsl_widget*,int,int,num_type,num_type,
		num_type,num_type,num_type,num_type);
	int draw_3D_text(xnsl_widget*,int,int,num_type,num_type,num_type,const char*);

	int dodraw(xnsl_widget*,int,int,int,int,int*,int*);

	int visibility(int,int,int*,int*,int*);
	int horizon(int,int,int,int,int*,int*);
	int intersect(int,int,int,int,int*,int*,int*);
	int init_arrs(int*,int*);
	int detview(int,int,int,int,int*,int*,int*,int*,int*,int*,int*,int*);
};
#endif
