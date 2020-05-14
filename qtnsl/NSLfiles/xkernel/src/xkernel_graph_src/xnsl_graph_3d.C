/* SCCS  %W%---%E%--%U% */
/*                                                            	*/
/*                       graph_3d.c                        	*/
/*                                                            	*/
/* by Alfredo Weitzenfeld				      	*/
/*                                                            	*/
/****************************************************************/

static char SccsId[] = "%W%  %G%"; /* SCCS */

#include "xkernel.h"
# include <math.h>

//extern "C" char* ctime(...);

# define vmax(x,y) (x > y ? x : y)
# define vmin(x,y) (x < y ? x : y)

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

/*   global variables  */

float xcale,ycale,zcale;
float xa,xb,xc,ya,yb,yc,za,zb,zc;
float great = 1.E20;
float rxx[2],ryy[2],rzz[2];
float xm, ym;
float scx,scy;
float xm3,ym3,zm3;
float zi;
float xnew, ynew, znew;
float aax,bby,ccz;

/**********************************************************/

float  d3on2d(float x, float y, float z, float a, float b, float c)
{
  	return((float)(a*x + b*y + c*z));
}

/********************************************************/

float d3on2dsc(float x, float y, float z, float a, float b, float c)
{
    	xnew = xcale*(x - xm3) + xm3;
   	ynew = ycale*(y - ym3) + ym3;
   	znew = zcale*(z - zm3) + zm3;

 	return((float)(a*xnew + b*ynew + c*znew));
}

/****************************************************/    

void d3scal (int width2, int height2)
{
	float rrmaxx,rrmaxy,trmaxx,trmaxy;
	int i,j,k;

	rrmaxx = -great;
	rrmaxy = -great;
	for (i = 0; i < 2; i++)
	   for (j = 0; j < 2; j++)
		for(k = 0; k < 2; k++)
	   	{
		    trmaxx = fabs(d3on2d(rxx[i],ryy[j],rzz[k],xa,xb,xc)-xm);
		    if (trmaxx > rrmaxx)
			rrmaxx = trmaxx;
		    trmaxy = fabs(d3on2d(rxx[i],ryy[j],rzz[k],ya,yb,yc)-ym);
		    if (trmaxy > rrmaxy)
			rrmaxy = trmaxy;
	   	}
   	scx = width2/rrmaxx;
   	scy = height2/rrmaxy;
}

/*******************************************************/
   
void d3to2d (float a, float b, float c)
{
	float dd,d,e;

    	dd = a*a + b*b;
    	d = -1.0/((float)sqrt(dd));
    	e = 1.0/((float)sqrt(dd + c*c));
    	xa = -b*d;
    	xb = a*d;
    	xc = 0.0;
    	ya = a*c*d*e;
    	yb = b*c*d*e;
    	yc = -dd*d*e;
    	za = a*e;
    	zb = b*e;
    	zc = c*e;
}

/*****************************************************/

void d3to2doo()
{
    	xa = 1.0;
    	xb = 0.0;
    	xc = 0.0;
    	ya = 0.0;
    	yb = 1.0;
    	yc = 0.0;
    	za = 0.0;
    	zb = 0.0;
    	zc = 1.0;
}

/****************************************************/

void d3midl(float rx0, float rx1, float ry0, float ry1, float rz0, float rz1)
{
  	rxx[0] = rx0;
  	rxx[1] = rx1;
  	ryy[0] = ry0;
  	ryy[1] = ry1;
  	rzz[0] = rz0;
  	rzz[1] = rz1;
  	xm3 = 0.5 * (rx0 + rx1);
  	ym3 = 0.5 * (ry0 + ry1);
  	zm3 = 0.5 * (rz0 + rz1);
  	xm = (float) d3on2d(xm3,ym3,zm3,xa,xb,xc);
  	ym = (float) d3on2d(xm3,ym3,zm3,ya,yb,yc);
}

/******************************************************/

void draw_3D_axis(
xnsl_canvas win,
float rmin,float rmax,
int i0,int i1,int j0,int j1,
int x_mid,int y_mid )
{
	float rx0,rx1,ry0,ry1,delx,dely;

	delx = 1.0;
	dely = 1.0;

	rx0 = j0*delx;
	ry0 = i0*dely;
	rx1 = j1*delx;
	ry1 = i1*dely;
	/*draw_3D_single_axis(win,x_mid,y_mid,rx1,ry0,0.0,rx0,ry0,0.0); //no such functions defined -bn7
	draw_3D_text(win,x_mid,y_mid,rx1,ry0,0.0,"X");
	draw_3D_single_axis(win,x_mid,y_mid,rx0,ry1,0.0,rx0,ry0,0.0);
	draw_3D_text(win,x_mid,y_mid,rx0,ry1,0.0,"Y");
	draw_3D_single_axis(win,x_mid,y_mid,rx0,ry0,rmax,rx0,ry0,rmin);
	draw_3D_text(win,x_mid,y_mid,rx0,ry0,rmax,"Z");*/
}

void draw_3D_single_axis(
xnsl_canvas win,
float x3,float y3,float z3,float ox3,float oy3,float oz3,
int canvas_x_mid,int canvas_y_mid)
{
	float x,y;
	int oxi,oyi,xi,yi;

	x = ((float) d3on2dsc(ox3,oy3,oz3,xa,xb,xc)-xm)*scx;
	y = ((float) d3on2dsc(ox3,oy3,oz3,ya,yb,yc)-ym)*scy;
        oxi = rint(x) + canvas_x_mid;
        oyi = rint(y) + canvas_y_mid;
	x = ((float) d3on2dsc(x3,y3,z3,xa,xb,xc)-xm)*scx;
	y = ((float) d3on2dsc(x3,y3,z3,ya,yb,yc)-ym)*scy;
        xi = rint(x) + canvas_x_mid;
        yi = rint(y) + canvas_y_mid;
	//draw_line(win,oxi,oyi,xi,yi);
}

void draw_3D_text(
xnsl_canvas win,
float x3,float y3,float z3,
int canvas_x_mid,int canvas_y_mid,
char *str)
{
	float x,y;
	int xi,yi;

	x = ((float) d3on2dsc(x3,y3,z3,xa,xb,xc)-xm)*scx;
	y = ((float) d3on2dsc(x3,y3,z3,ya,yb,yc)-ym)*scy;
        xi = rint(x) + canvas_x_mid;
        yi = rint(y) + canvas_y_mid;
	//set_text_label(win,xi,yi,str);
}

/*  ****************************************************  */

void plt3d(
int i0, int i1, int j0, int j1,
float sx,float sy,float sz,float ax,float by,float cz,float rmin,float rmax,
int canvas_x_mid,int canvas_y_mid)
{
	float rx0,rx1,ry0,ry1;

  	xcale = sx;
  	ycale = sy;
  	zcale = sz;

  	if ((ax == 0.0) && (by == 0.0))  
		d3to2doo();
  	else
		d3to2d(ax,by,cz);
 
	rx0 = (float) j0;
	rx1 = (float) j1;
	ry0 = (float) i0;
	ry1 = (float) i1;

	aax = ax;
	bby = by;
	ccz = cz;

  	d3midl(rx0,rx1,ry0,ry1,rmin,rmax);
	d3scal(canvas_x_mid,canvas_y_mid);
}
/*
set_3D_canvas_grid(win)
xnsl_canvas win;
{
	float rmin,rmax;
	int x0,x1,y0,y1,wx0,wx1,wy0,wy1;
	int width,height,kx1,kx2,ky1,ky2,s;
	int canvas_x_mid,canvas_y_mid;

	s = 5;

	width = (wx1 - wx0)/s;
	height = (wy1 - wy0)/s;

	set_3D_transformation(win,width,height);

	kx1 = 7; kx2 = 8;
	ky1 = 7; ky2 = 8;

	canvas_x_mid = wx0 + kx1*(wx1 - wx0)/kx2;

	if (x1-x0 > y1-y0)
		canvas_y_mid = wy0 + ky1*(wy1 - wy0)/ky2;
	else
		canvas_y_mid = wy0 + (wy1 - wy0)/ky2;

	draw_3D_axis(win,canvas_x_mid,canvas_y_mid,x0,x1,y0,y1,rmin,rmax);
}

*/
void old_d3ntrp(
xnsl_canvas win,
float **mat,
int i0,int i1,int j0, int j1,
int canvas_x_mid,int canvas_y_mid)
{
	int i,j,xi,yi,oxi,oyi;
	float x3,y3,z3,x,y,delx,dely;

	delx = 1.0;
	dely = 1.0;

 	for (i = i0; i <= i1; i++) 
	{ 
	   for (j = j0; j <= j1; j++)  
	   { 	/* crossed x,y */
     		x3 = j*delx;
     		y3 = i*dely;
     		z3 = mat[i][j];
		x = ((float) d3on2dsc(x3,y3,z3,xa,xb,xc)-xm)*scx;
		y = ((float) d3on2dsc(x3,y3,z3,ya,yb,yc)-ym)*scy;
        	xi = rint(x) + canvas_x_mid;
                yi = rint(y) + canvas_y_mid;
		if (j != j0); //<--remove ; for draw_line call -bn7
			//draw_line(win,oxi,oyi,xi,yi);
		oxi = xi;
		oyi = yi;
 	   }
	}
	for (j = j0; j <= j1; j++)  
	{ 
 	   for (i = i0; i <= i1; i++)  
	   {	/* crossed x,y */
     		x3 = j*delx;
     		y3 = i*dely;
     		z3 = mat[i][j];
		x = ((float) d3on2dsc(x3,y3,z3,xa,xb,xc)-xm)*scx;
		y = ((float) d3on2dsc(x3,y3,z3,ya,yb,yc)-ym)*scy;
        	xi = rint(x) + canvas_x_mid;
                yi = rint(y) + canvas_y_mid;
		if (i != i0) {} //<--
			//draw_line(win,oxi,oyi,xi,yi);
		oxi = xi;
		oyi = yi;
 	   }
	}
}

# define  MAX_SIZE 1200      /* resolution of the screen */
int   incsz = 1;             /* interpolation increment  */

/**********************************************************************/
/* This subroutine is called to draw a line with hidden parts not     */
/* shown.  The hidden line algorithm implemented is a Floating Horizon*/
/* algorithm.  The line to draw is split into n segments to be drawn  */
/* (n is determined by the interpolation increment).  Linear Interpol-*/
/* ation is used to calculate the endpoints of the n segments.  These */
/* segments are small enough so that by determining the visibility of */
/* the endpoints, the visibility of the entire segment can be         */
/* determined.                                                        */
/**********************************************************************/

void dodraw (
xnsl_canvas win,
float **mat,
int oxi, int oyi, int xi, int yi,
int *uppr, int *lowr)
{
  int oxx,oyy,xx,yy,xxint,yyint,xxinc,cflag,pflag,last;
  float slope;

  if ((xi - oxi) != 0)                    /* if the slope is not infinite */
    {
      if ((xi - oxi) < 0)                 /* negative slope ?             */
	xxinc = -1*incsz;
      else
	xxinc = incsz;
      //visibility(oxi,oyi,uppr,lowr,&pflag); /* determine visibility of the*/ //visibility no such definition -bn7
                                            /* first point                */
      slope = ((float)(yi - oyi)) / ((float)(xi - oxi)); /*calc slope     */
      yy = oyi;
      xx = oxi + xxinc;                   /* incr x coord by interpol incr*/
      oyy = oyi;
      oxx = oxi;
      last = 0;                           /* flag to determine if we're   */
                                          /* finished with interpolation  */
      if (((xxinc > 0) && (xx > xi)) ||   /* see if the interpolation incr*/
	  ((xxinc < 0) && (xx < xi)))     /* put us past the line's last  */
	{                                 /* point                        */
	  xx = xi;                        /* if so, just interpolate to   */
	  last = 1;                       /* end point & indicate this is */
	}                                 /* the last time for interpolatn*/
      while (last <= 1)                   /* while we need to interpolate */
	{
	  yy = rint(slope*(xx - oxi) + oyi);/* calc new y for incr'd x val*/
	 // visibility(xx,yy,uppr,lowr,&cflag);/* det visibilty of new coord*/
	  if (cflag == pflag)                /* if visibility of prev &   */
	    {                                /* new coords are the same   */
	      if ((cflag == 1) || (cflag == -1)) /* if the new point is   */
                                                 /* visible above upper   */
                                                 /* horizon or below lower*/
		{                                /* horizon               */
		 // draw_line(win,oxx,oyy,xx,yy);  /* print entire segment  */
		 // horizon(oxx,oyy,xx,yy,uppr,lowr); /* update the horizons*/
		}                             
	    }
	  else                                /* old & new coords have    */
	    {                                 /* different visibilities   */
	      if (cflag == 0)                 /* if new coord is invisible*/
		{
		  //if (pflag == 1)             /* if prev coord visible    */
                                              /* above upper horizon      */
		  //  intersect(oxx,oyy,xx,yy,uppr,&xxint,&yyint);
                                              /* calc intersection of the */
                                              /* segment with upper horizn*/
		 // else                        /* prev coor visible below  */
                                              /* the lower horizon        */
		  //  intersect(oxx,oyy,xx,yy,lowr,&xxint,&yyint);
                                              /* calc intersection of the */
                                              /* segment with lower horizn*/
		  //draw_line(win,oxx,oyy,xxint,yyint); /* print line from  */
                                              /* prev coord to intersectn */
		  //horizon(oxx,oyy,xxint,yyint,uppr,lowr); /*upd horizons  */
		}
	      else                            /* new coord is visible     */
		{
		  if (cflag == 1)             /* new coord visible above  */
		    {                         /* upper horizon            */
		      if (pflag == 0)         /* previous coord is invisbl*/
			{
			//  intersect(oxx,oyy,xx,yy,lowr,&xxint,&yyint);
                                              /* calc intersection of the */
                                              /* segment with lower horizn*/
			 // draw_line(win,xxint,yyint,xx,yy); /* print line */
                                              /* from intstcn to new coord*/
			  //horizon(xxint,yyint,xx,yy,uppr,lowr);/*upd horiz*/
			}
		      else                    /* previous coord is visible*/
			{
			  //intersect(oxx,oyy,xx,yy,lowr,&xxint,&yyint);
                                              /* calc intersection of the */
                                              /* segment with lower horizn*/
			  //draw_line(win,oxx,oyy,xxint,yyint); /* print frm*/
                                              /* prev coord to intersectn */
			  //horizon(oxx,oyy,xxint,yyint,uppr,lowr);
			  //intersect(oxx,oyy,xx,yy,uppr,&xxint,&yyint);
                                              /* calc intersection of the */
                                              /* segment with uppr horizn */
			  //draw_line(win,xxint,yyint,xx,yy); /* print from */
                                              /* int point to new coord   */
			  //horizon(xxint,yyint,xx,yy,uppr,lowr);/* upd horz*/
			}
		    }
		  else                        /* new coord is visible     */
		    {                         /* below lower horizon      */
		      if (pflag == 0)         /* if prev coord is invisibl*/
			{
			 // intersect(oxx,oyy,xx,yy,lowr,&xxint,&yyint);
                                              /* calc intersection of the */
                                              /* segment with lower horizn*/
			 // draw_line(win,xxint,yyint,xx,yy);/* print line  */
                                              /* int point to new coord   */
			 // horizon(xxint,yyint,xx,yy,uppr,lowr); /*upd horz*/
			}
		      else                    /* prev coord is visible    */
			{
			//  intersect(oxx,oyy,xx,yy,uppr,&xxint,&yyint);
                                              /* calc intersection of the */
                                              /* segment with upper horizn*/
			 // draw_line(win,oxx,oyy,xxint,yyint);/* print line*/
                                              /* from prev coord to int pt*/
			 // horizon(oxx,oyy,xxint,yyint,uppr,lowr);/*upd hrz*/
			  //intersect(oxx,oyy,xx,yy,lowr,&xxint,&yyint);
                                              /* calc intersection of the */
                                              /* segment with lower horizn*/
			  //draw_line(win,xxint,yyint,xx,yy);/*print line   */
                                              /* int point to new coord   */
			 // horizon(xxint,yyint,xx,yy,uppr,lowr);/*upd horiz*/
			}
		    }
		}         /* end cflag != 0 */
	    }             /* end cflag != pflag */
	  oxx = xx;       /* set prev coord = new coord*/
	  oyy = yy;
	  pflag = cflag;  /* set visibility of prev coord */
	  xx = xx + xxinc;/* increment x by interpolation increment*/
	  if (last == 0)  /* if this wasn't the last time to interpolate*/
	    {
	      if (((xxinc > 0) && (xx > xi)) || /* if new interpolation pt */
		  ((xxinc < 0) && (xx < xi)))   /* takes us past end point */
		{
		  xx = xi;                      /* just do end point       */
		  last = 1;                     /* indicate this is the    */
		}                               /* last interpolation      */
	    }
	  else                                  /* if this was last interpl*/
	    last = 2;                           /* indicate exit loop      */
	}                  /* end while loop */
    }                      /* end processing for non-infinite slope */
  else                     /* processing for infinite slope         */
    {
      uppr[xi] = vmax(uppr[xi],yi);
      lowr[xi] = vmin(lowr[xi],yi);
    }
}

/***************************************************************************/
/* This routine calculates the visiblity of a given point.  A point can be */
/* either visible above the upper horizon, visible below the lower horizon */
/* or invisible.                                                           */
/***************************************************************************/

void visibility(
int vx, int vy,
int *uppr, int*lowr,
int *vflag)

{
  if ((vy < uppr[vx]) && (vy > lowr[vx]))       /* if point is below upper */
                                                /* & above lower horizon   */
    *vflag = 0;                                 /* indicate it's invisible */
  else
    {
      if (vy >= uppr[vx])                       /* if point is above upper */
	*vflag = 1;                             /* indicate it's visible   */
                                                /* above upper horizon     */
      else
	*vflag = -1;                            /* indicate it's visible   */
                                                /* below lower horizon     */
    }
}

/***************************************************************************/
/* This routine updates the upper and lower horizons whenever a line is    */
/* printed.                                                                */
/***************************************************************************/

void horizon (
int x1,int y1,int x2,int y2,
int *uppr, int *lowr)
{
  float slope;
  int xinc,newx,newy;

  if ((x2-x1) == 0)                        /* if slope is infinite         */
    {
      uppr[x2] = vmax(uppr[x2],y2);         /* set upper horizon            */
      lowr[x2] = vmin(lowr[x2],y2);         /* set lower horizon            */
    }
  else
    {
      slope = ((float)(y2 - y1)) / ((float)(x2 - x1)); /* calculate slope  */
      if ((x2 - x1) < 0)                   /* if going back along x-axis   */
	xinc = -1;                         /* x-increment is neg           */
      else
	xinc = 1;                          /* x-increment is pos           */
                                           /* update the horizon arrays for*/
                                           /* all points between endpoints */
      for (newx = x1; newx != x2; newx = newx + xinc)
	{
	  newy = rint((slope*(newx - x1) + y1));
	  uppr[newx] = vmax(uppr[newx],newy);
	  lowr[newx] = vmin(lowr[newx],newy);
	}
      newx = x2;
      newy = rint((slope*(x2 - x1) + y1));
      uppr[newx] = vmax(uppr[newx],newy);
      lowr[newx] = vmin(lowr[newx],newy);
    }
}

/***************************************************************************/
/* This routine calculates the intersection of a line segment with a given */
/* horizon.  This way, a line segment's visible part can be drawn and the  */
/* invisible parts remain hidden.                                          */
/***************************************************************************/

void intersect(
int x1,int y1, int x2,int y2,
int *arr,
int *xint, int *yint)
{
  int xinc,ysign,newysign;
  float slope;

  if ((x2 - x1) == 0)                   /* if the slope is infinite        */
    {
      *xint = x2;                       /* x-intersect point is the end pt */
      *yint = arr[x2];                  /* y-intersect point is horizon val*/
    }                                   /* for the corr x-point            */
  else                                  /* slope is not infinite           */
    {
      if ((y1 - arr[x1]) == 0)          /* if 1st coord is already on the  */
	{                               /* horizon, return them as the int-*/
	  *xint = x1;                   /* ersection points                */
	  *yint = y1;
	}
      else                              /* 1st coord not on horizon        */
	{
	  if ((x2 - x1) < 0)            /* if moving back along x-axis     */
	    xinc = -1;                  /* set x-increment to neg          */
	  else                          /* moving forward along x-axis     */
	    xinc = 1;                   /* set x-increment to pos          */
	  slope = ((float)(y2 - y1)) / ((float)(x2 - x1)); /*calc slope    */
	  ysign = ((y1 - arr[x1]) >= 0) ? 1: 0; /* det which side of horizn*/
                                                /* the 1st coord is        */
	  newysign = ysign;
	  *xint = x1;
	  while ((newysign == ysign) && (*xint != x2)) /* while still on   */
	    {                           /* same side of the horizon line   */
	      *xint = *xint + xinc;     /* move along x-axis               */
	      *yint = rint(slope*(*xint - x1) + y1); /* calc new y         */
	      newysign = ((*yint - arr[*xint]) >= 0) ? 1: 0; /* see which  */
                                        /* side of the horizon the new     */
                                        /* coord is (above or below)       */
	    }
	}
    }
}

/***************************************************************************/
/* This routine initializes the horizon arrays.  The upper horizon is      */
/* initialized to 0 and the lower horizon is initialized to the resolution */
/* of the screen (vertically).                                             */
/***************************************************************************/

void init_arrs(
int *uppr,int *lowr)
{
  int i;

  for (i = 0; i <= MAX_SIZE-1; i++)
    {
      uppr[i] = 0;
      lowr[i] = MAX_SIZE;
    }
}

/**************************************************************************/
/* This subroutine determines from which point the drawing of the graph   */
/* should begin.  This determination is based on the rotation variables.  */
/* In order for the hidden line algorithm to work correctly, the graph    */
/* must be drawn from the bottom up.  Therefore, this routine will        */
/* calculate where the bottom of the graph is after rotation.  Then the   */
/* drawing can begin from there and the horizon arrays which are used to  */
/* remove hidden lines will be updated correctly.                         */
/**************************************************************************/

void detview(
int x0,int x1,int y0,int y1,
int *istart,int *jstart,int *ilim,int *jlim,int *iincr,int *jincr,int *iend,int *loopx)
{
  if ((aax <= 0) && (bby <= 0) && (ccz <= 0))
    {
      *istart = y1;
      *jstart = x1;
      *ilim = y0 - 1;
      *jlim = x0 - 1;
      *iincr = -1;
      *jincr = -1;
      *iend = y0;
      *loopx = 0;
      return;
    }
  if ((aax <= 0) && (bby <= 0) && (ccz > 0))
    {
      *istart = x0;
      *jstart = y0;
      *ilim = x1 + 1;
      *jlim = y1 + 1;
      *iincr = 1;
      *jincr = 1;
      *iend = x1;
      *loopx = 1;
      return;
    }
  if ((aax <= 0) && (bby > 0) && (ccz <= 0))
    {
      *istart = x1;
      *jstart = y0;
      *ilim = x0 - 1;
      *jlim = y1 + 1;
      *iincr = -1;
      *jincr = 1;
      *iend = x0;
      *loopx = 1;
      return;
    }
  if ((aax <= 0) && (bby > 0) && (ccz > 0))
    {
      *istart = y1;
      *jstart = x0;
      *ilim = y0 - 1;
      *jlim = x1 + 1;
      *iincr = -1;
      *jincr = 1;
      *iend = y0;
      *loopx = 0;
      return;
    }
  if ((aax > 0) && (bby <= 0) && (ccz <= 0))
    {
      *istart = x0;
      *jstart = y1;
      *ilim = x1 + 1;
      *jlim = y0 - 1;
      *iincr = 1;
      *jincr = -1;
      *iend = x1;
      *loopx = 1;
      return;
    }
  if ((aax > 0) && (bby <= 0) && (ccz > 0))
    {
      *istart = y0;
      *jstart = x1;
      *ilim = y1 + 1;
      *jlim = x0 - 1;
      *iincr = 1;
      *jincr = -1;
      *iend = y1;
      *loopx = 0;
      return;
    }
  if ((aax > 0) && (bby > 0) && (ccz <= 0))
    {
      *istart = y0;
      *jstart = x0;
      *ilim = y1 + 1;
      *jlim = x1 + 1;
      *iincr = 1;
      *jincr = 1;
      *iend = y1;
      *loopx = 0;
      return;
    }
  if ((aax > 0) && (bby > 0) && (ccz > 0))
    {
      *istart = x1;
      *jstart = y1;
      *ilim = x0 - 1;
      *jlim = y0 - 1;
      *iincr = -1;
      *jincr = -1;
      *iend = x0;
      *loopx = 1;
      return;
    }
}

void new_d3ntrp(
xnsl_canvas win,
float **mat,
int i0,int i1,int j0,int j1,
int canvas_x_mid,int canvas_y_mid)
{
	int i,j,k,klim,xi,yi,oxi,oyi;
	float x3,y3,z3,x,y,delx,dely;
	int uppr[MAX_SIZE], lowr[MAX_SIZE];
	int istart, jstart, ilim, jlim, iincr, jincr, iend, loopx;

	init_arrs(uppr,lowr);
	delx = 1.0;
	dely = 1.0;
	detview(i0,i1,j0,j1,&istart,&jstart,&ilim,&jlim,&iincr,&jincr,&iend,&loopx);
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
     		z3 = mat[i][j];
	       }
	     else
	       { /* switched x,y */
     		x3 = i*delx;
     		y3 = j*dely;
     		z3 = mat[j][i];
	       }

		x = ((float) d3on2dsc(x3,y3,z3,xa,xb,xc)-xm)*scx;
		y = ((float) d3on2dsc(x3,y3,z3,ya,yb,yc)-ym)*scy;
        	xi = rint(x) + canvas_x_mid;
                yi = rint(y) + canvas_y_mid;
		if (j != jstart)
			dodraw(win,mat,oxi,oyi,xi,yi,uppr,lowr);
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
			   z3 = mat[k][j];
			 }
		       else
			 {/* switched x,y */
			   x3 = k*delx;
			   y3 = j*dely;
			   z3 = mat[j][k];
			 }
		       x = ((float) d3on2dsc(x3,y3,z3,xa,xb,xc)-xm)*scx;
		       y = ((float) d3on2dsc(x3,y3,z3,ya,yb,yc)-ym)*scy;
		       xi = rint(x) + canvas_x_mid;
		       yi = rint(y) + canvas_y_mid;
		       if (i != k)
			 dodraw(win,mat,oxi,oyi,xi,yi,uppr,lowr);
		       oxi = xi;
		       oyi = yi;
		       k = k + iincr;
		     }                                   /* next k */
		   j = j + jincr;
	         }                                       /* next j */
             }	                                         /* endif not last i */
	   i = i + iincr;
	}                                                /* next i */

/* 	for (i = i1; i >= i0; i--) 
	{ 
	   for (j = j0; j <= j1; j++)  
	   {
     		x3 = j*delx;
     		y3 = i*dely;
     		z3 = mat[i][j];
		x = ((float) d3on2dsc(x3,y3,z3,xa,xb,xc)-xm)*scx;
		y = ((float) d3on2dsc(x3,y3,z3,ya,yb,yc)-ym)*scy;
        	xi = rint(x) + canvas_x_mid;
                yi = rint(y) + canvas_y_mid;
		if (j != j0)
			dodraw(win,mat,oxi,oyi,xi,yi,uppr,lowr);
		oxi = xi;
		oyi = yi;
 	   }
           if (i != i0)
	     {
	       for (j = j0; j <= j1; j++)
		 {
		   klim = i-1;
		   for (k = i; k >= klim; k--)
        	     {
		       x3 = j*delx;
		       y3 = k*dely;
		       z3 = mat[k][j];
		       x = ((float) d3on2dsc(x3,y3,z3,xa,xb,xc)-xm)*scx;
		       y = ((float) d3on2dsc(x3,y3,z3,ya,yb,yc)-ym)*scy;
		       xi = rint(x) + canvas_x_mid;
		       yi = rint(y) + canvas_y_mid;
		       if (i != k)
			 dodraw(win,mat,oxi,oyi,xi,yi,uppr,lowr);
		       oxi = xi;
		       oyi = yi;
		     }  
	         }    
             }	  
	}  */         
}
