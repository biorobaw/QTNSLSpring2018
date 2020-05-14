// SCCS  %W%---%E%--%U% 
//
//	xnsl_spatial_graph_3.C
//
//

#include "xkernel.h"
#include "nsl_kernel.h" 
#include <cmath>

extern int nsl_rint(num_type s);

xnsl_spatial_graph_3::xnsl_spatial_graph_3(xnsl_display_canvas* win) : 
	xnsl_graph(win)
{
        set_type("spatial_graph_3");

	sx = sy = sz = 1;
	ax = by = cz = 1;
	hidden_fg = 1;
	
//	if (win != NULL)
//		win->set_clear_fg(NSL_ON);
//	clear_fg = 1;

	great = 1.E20;
	incsz = 1;

//	set_menu_canvas_events(canvas);
}
xnsl_spatial_graph_3::~xnsl_spatial_graph_3()  
{
}

xnsl_widget * xnsl_spatial_graph_3::make_widget()
{
	cmd_error("xnsl_spatial_graph_3: CANNOT create widget");
        return 0;
}

int xnsl_spatial_graph_3::display()
{
//      display_spatial_graph_3(_widget,_wx0,_wy0,_wx1,_wy1,_wymin,_wymax);
 	return 1;
}
int xnsl_spatial_graph_3::display_spatial_graph_3(xnsl_widget*,
	int,int,int,int,
	num_type, num_type)
{
 	return 1;
}

int xnsl_spatial_graph_3::read_from_database()
{
	return 1;
}
int xnsl_spatial_graph_3::write_to_database()
{
//	xnsl_graph::write_to_database();

	return 1;
}
int xnsl_spatial_graph_3::input(int x_pos,int y_pos,int fg)
{
	return 1;
}
int xnsl_spatial_graph_3::output(int x_pos,int y_pos)
{
	return 1;
}
int xnsl_spatial_graph_3::print(ostream& out) const
{
	return 1;
}

num_type xnsl_spatial_graph_3::d3on2d(num_type x,num_type y,num_type z,
	num_type a,num_type b,num_type c)
{
  	return((num_type)(a*x + b*y + c*z));
}
num_type xnsl_spatial_graph_3::d3on2dsc(num_type x,num_type y,num_type z,
	num_type a,num_type b,num_type c)
{
    	xnew = xcale*(x - xm3) + xm3;
   	ynew = ycale*(y - ym3) + ym3;
   	znew = zcale*(z - zm3) + zm3;

 	return((num_type)(a*xnew + b*ynew + c*znew));
}
int xnsl_spatial_graph_3::d3to2d(num_type a,num_type b,num_type c)
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

	return 1;
}
int xnsl_spatial_graph_3::d3to2doo()
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

	return 1;
}
int xnsl_spatial_graph_3::d3scal(int width2,int height2)
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

	return 1;
}
int xnsl_spatial_graph_3::d3midl(num_type rx0,num_type rx1,
	num_type ry0,num_type ry1,num_type rz0,num_type rz1)
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

	return 1;
}
int xnsl_spatial_graph_3::draw_3D_single_axis(xnsl_widget* widget,int canvas_x_mid,int canvas_y_mid,
	num_type x3,num_type y3,num_type z3,
	num_type ox3,num_type oy3,num_type oz3)
{
	num_type x,y;
	int oxi,oyi,xi,yi;

	x = ((float) d3on2dsc(ox3,oy3,oz3,xa,xb,xc)-xm)*scx;
	y = ((float) d3on2dsc(ox3,oy3,oz3,ya,yb,yc)-ym)*scy;
        oxi = nsl_rint(x) + canvas_x_mid;
        oyi = nsl_rint(y) + canvas_y_mid;
	x = ((float) d3on2dsc(x3,y3,z3,xa,xb,xc)-xm)*scx;
	y = ((float) d3on2dsc(x3,y3,z3,ya,yb,yc)-ym)*scy;
        xi = nsl_rint(x) + canvas_x_mid;
        yi = nsl_rint(y) + canvas_y_mid;
	draw_line(widget,oxi,oyi,xi,yi);

	return 1;
}
int xnsl_spatial_graph_3::draw_3D_text(xnsl_widget* widget,int canvas_x_mid,int canvas_y_mid,
	num_type x3,num_type y3,num_type z3,const char* str)
{
	float x,y;
	int xi,yi;

	x = ((float) d3on2dsc(x3,y3,z3,xa,xb,xc)-xm)*scx;
	y = ((float) d3on2dsc(x3,y3,z3,ya,yb,yc)-ym)*scy;
        xi = nsl_rint(x) + canvas_x_mid;
        yi = nsl_rint(y) + canvas_y_mid;
//	set_text_label(xi,yi,str);

	return 1;
}

//
// This subroutine is called to draw a line with hidden parts not     
// shown.  The hidden line algorithm implemented is a Floating Horizon
// algorithm.  The line to draw is split into n segments to be drawn  
// (n is determined by the interpolation increment).  Linear Interpol-
// ation is used to calculate the endpoints of the n segments.  These 
// segments are small enough so that by determining the visibility of 
// the endpoints, the visibility of the entire segment can be         
// determined.                                                        
//

int xnsl_spatial_graph_3::dodraw(xnsl_widget* widget,int oxi,int oyi,int xi,int yi,
	int *uppr,int *lowr)
{
  int oxx,oyy,xx,yy,xxint,yyint,xxinc,cflag,pflag,last;
  float slope;

  if ((xi - oxi) != 0)                    // if the slope is not infinite 
    {
      if ((xi - oxi) < 0)                 // negative slope ?             
	xxinc = -1*incsz;
      else
	xxinc = incsz;
      visibility(oxi,oyi,uppr,lowr,&pflag); // determine visibility of the
                                            // first point               
      slope = ((float)(yi - oyi)) / ((float)(xi - oxi)); //calc slope     
      yy = oyi;
      xx = oxi + xxinc;                   // incr x coord by interpol incr
      oyy = oyi;
      oxx = oxi;
      last = 0;                           // flag to determine if we're   
                                          // finished with interpolation  
      if (((xxinc > 0) && (xx > xi)) ||   // see if the interpolation incr
	  ((xxinc < 0) && (xx < xi)))     // put us past the line's last  
	{                                 // point                        
	  xx = xi;                        // if so, just interpolate to   
	  last = 1;                       // end point & indicate this is 
	}                                 // the last time for interpolatn
      while (last <= 1)                   // while we need to interpolate 
	{
	  yy = nsl_rint(slope*(xx - oxi) + oyi);// calc new y for incr'd x val
	  visibility(xx,yy,uppr,lowr,&cflag);// det visibilty of new coord
	  if (cflag == pflag)                // if visibility of prev &   
	    {                                // new coords are the same   
	      if ((cflag == 1) || (cflag == -1)) // if the new point is   
                                                 // visible above upper   
                                                 // horizon or below lower
		{                                // horizon               
		  draw_line(widget,oxx,oyy,xx,yy);  // print entire segment  
		  horizon(oxx,oyy,xx,yy,uppr,lowr); // update the horizons
		}                             
	    }
	  else                                // old & new coords have    
	    {                                 // different visibilities   
	      if (cflag == 0)                 // if new coord is invisible
		{
		  if (pflag == 1)             // if prev coord visible    
                                              // above upper horizon      
		    intersect(oxx,oyy,xx,yy,uppr,&xxint,&yyint);
                                              // calc intersection of the 
                                              // segment with upper horizn
		  else                        // prev coor visible below  
                                              // the lower horizon        
		    intersect(oxx,oyy,xx,yy,lowr,&xxint,&yyint);
                                              // calc intersection of the 
                                              // segment with lower horizn
		  draw_line(widget,oxx,oyy,xxint,yyint); // print line from  
                                              // prev coord to intersectn 
		  horizon(oxx,oyy,xxint,yyint,uppr,lowr); //upd horizons  
		}
	      else                            // new coord is visible     
		{
		  if (cflag == 1)             // new coord visible above  
		    {                         // upper horizon            
		      if (pflag == 0)         // previous coord is invisbl
			{
			  intersect(oxx,oyy,xx,yy,lowr,&xxint,&yyint);
                                              // calc intersection of the 
                                              // segment with lower horizn
			  draw_line(widget,xxint,yyint,xx,yy); // print line 
                                              // from intstcn to new coord
			  horizon(xxint,yyint,xx,yy,uppr,lowr);//upd horiz
			}
		      else                    // previous coord is visible
			{
			  intersect(oxx,oyy,xx,yy,lowr,&xxint,&yyint);
                                              // calc intersection of the 
                                              // segment with lower horizn
			  draw_line(widget,oxx,oyy,xxint,yyint); // print frm
                                              // prev coord to intersectn 
			  horizon(oxx,oyy,xxint,yyint,uppr,lowr);
			  intersect(oxx,oyy,xx,yy,uppr,&xxint,&yyint);
                                              // calc intersection of the 
                                              // segment with uppr horizn 
			  draw_line(widget,xxint,yyint,xx,yy); // print from 
                                              // int point to new coord   
			  horizon(xxint,yyint,xx,yy,uppr,lowr);// upd horz
			}
		    }
		  else                        // new coord is visible     
		    {                         // below lower horizon      
		      if (pflag == 0)         // if prev coord is invisibl
			{
			  intersect(oxx,oyy,xx,yy,lowr,&xxint,&yyint);
                                              // calc intersection of the 
                                              // segment with lower horizn
			  draw_line(widget,xxint,yyint,xx,yy);// print line  
                                              // int point to new coord   
			  horizon(xxint,yyint,xx,yy,uppr,lowr); //upd horz
			}
		      else                    // prev coord is visible    
			{
			  intersect(oxx,oyy,xx,yy,uppr,&xxint,&yyint);
                                              // calc intersection of the 
                                              // segment with upper horizn
			  draw_line(widget,oxx,oyy,xxint,yyint);// print line
                                              // from prev coord to int pt
			  horizon(oxx,oyy,xxint,yyint,uppr,lowr);//upd hrz
			  intersect(oxx,oyy,xx,yy,lowr,&xxint,&yyint);
                                              // calc intersection of the 
                                              // segment with lower horizn
			  draw_line(widget,xxint,yyint,xx,yy);//print line   
                                              // int point to new coord   
			  horizon(xxint,yyint,xx,yy,uppr,lowr);//upd horiz
			}
		    }
		}         // end cflag != 0 
	    }             // end cflag != pflag 
	  oxx = xx;       // set prev coord = new coord
	  oyy = yy;
	  pflag = cflag;  // set visibility of prev coord 
	  xx = xx + xxinc;// increment x by interpolation increment
	  if (last == 0)  // if this wasn't the last time to interpolate
	    {
	      if (((xxinc > 0) && (xx > xi)) || // if new interpolation pt 
		  ((xxinc < 0) && (xx < xi)))   // takes us past end point 
		{
		  xx = xi;                      // just do end point       
		  last = 1;                     // indicate this is the    
		}                               // last interpolation      
	    }
	  else                                  // if this was last interpl
	    last = 2;                           // indicate exit loop      
	}                  // end while loop 
    }                      // end processing for non-infinite slope 
  else                     // processing for infinite slope         
    {
      uppr[xi] = vmax(uppr[xi],yi);
      lowr[xi] = vmin(lowr[xi],yi);
    }

	return 1;
}

//*************************************************************************
// This routine calculates the visiblity of a given point.  A point can be 
// either visible above the upper horizon, visible below the lower horizon 
// or invisible.                                                           
//*************************************************************************

int xnsl_spatial_graph_3::visibility(int vx,int vy,
	int *uppr,int *lowr,int *vflag)
{
  if ((vy < uppr[vx]) && (vy > lowr[vx]))       // if point is below upper 
                                                // & above lower horizon   
    *vflag = 0;                                 // indicate it's invisible 
  else
    {
      if (vy >= uppr[vx])                       // if point is above upper 
	*vflag = 1;                             // indicate it's visible   
                                                // above upper horizon     
      else
	*vflag = -1;                            // indicate it's visible   
                                                // below lower horizon     
    }
	return 1;
}

//*************************************************************************
// This routine updates the upper and lower horizons whenever a line is    
// printed.                                                                
//*************************************************************************

int xnsl_spatial_graph_3::horizon(int x1,int y1,int x2,int y2,
	int *uppr,int *lowr)
{
  float slope;
  int xinc,newx,newy;

  if ((x2-x1) == 0)                        // if slope is infinite         
    {
      uppr[x2] = vmax(uppr[x2],y2);         // set upper horizon            
      lowr[x2] = vmin(lowr[x2],y2);         // set lower horizon            
    }
  else
    {
      slope = ((float)(y2 - y1)) / ((float)(x2 - x1)); // calculate slope  
      if ((x2 - x1) < 0)                   // if going back along x-axis   
	xinc = -1;                         // x-increment is neg           
      else
	xinc = 1;                          // x-increment is pos           
                                           // update the horizon arrays for
                                           // all points between endpoints 
      for (newx = x1; newx != x2; newx = newx + xinc)
	{
	  newy = nsl_rint((slope*(newx - x1) + y1));
	  uppr[newx] = vmax(uppr[newx],newy);
	  lowr[newx] = vmin(lowr[newx],newy);
	}
      newx = x2;
      newy = nsl_rint((slope*(x2 - x1) + y1));
      uppr[newx] = vmax(uppr[newx],newy);
      lowr[newx] = vmin(lowr[newx],newy);
    }
	return 1;
}

//*************************************************************************
// This routine calculates the intersection of a line segment with a given 
// horizon.  This way, a line segment's visible part can be drawn and the  
// invisible parts remain hidden.                                          
//*************************************************************************

int xnsl_spatial_graph_3::intersect(int x1,int y1,int x2,int y2,
	int *arr,int *xint,int *yint)
{
  int xinc,ysign,newysign;
  float slope;

  if ((x2 - x1) == 0)                   // if the slope is infinite        
    {
      *xint = x2;                       // x-intersect point is the end pt 
      *yint = arr[x2];                  // y-intersect point is horizon val
    }                                   // for the corr x-point            
  else                                  // slope is not infinite           
    {
      if ((y1 - arr[x1]) == 0)          // if 1st coord is already on the  
	{                               // horizon, return them as the int-
	  *xint = x1;                   // ersection points                
	  *yint = y1;
	}
      else                              // 1st coord not on horizon        
	{
	  if ((x2 - x1) < 0)            // if moving back along x-axis     
	    xinc = -1;                  // set x-increment to neg          
	  else                          // moving forward along x-axis     
	    xinc = 1;                   // set x-increment to pos          
	  slope = ((float)(y2 - y1)) / ((float)(x2 - x1)); //calc slope    
	  ysign = ((y1 - arr[x1]) >= 0) ? 1: 0; // det which side of horizn
                                                // the 1st coord is        
	  newysign = ysign;
	  *xint = x1;
	  while ((newysign == ysign) && (*xint != x2)) // while still on   
	    {                           // same side of the horizon line   
	      *xint = *xint + xinc;     // move along x-axis               
	      *yint = nsl_rint(slope*(*xint - x1) + y1); // calc new y     
	      newysign = ((*yint - arr[*xint]) >= 0) ? 1: 0; // see which  
                                        // side of the horizon the new     
                                        // coord is (above or below)       
	    }
	}
    }
	return 1;
}

//*************************************************************************
// This routine initializes the horizon arrays.  The upper horizon is      
// initialized to 0 and the lower horizon is initialized to the resolution 
// of the screen (vertically).                                             
//*************************************************************************

int xnsl_spatial_graph_3::init_arrs(int *uppr,int *lowr)
{
  int i;

  for (i = 0; i <= MAX_SIZE-1; i++)
    {
      uppr[i] = 0;
      lowr[i] = MAX_SIZE;
    }
	return 1;
}

//************************************************************************
// This subroutine determines from which point the drawing of the graph   
// should begin.  This determination is based on the rotation variables.  
// In order for the hidden line algorithm to work correctly, the graph    
// must be drawn from the bottom up.  Therefore, this routine will        
// calculate where the bottom of the graph is after rotation.  Then the   
// drawing can begin from there and the horizon arrays which are used to  
// remove hidden lines will be updated correctly.                         
//************************************************************************

int xnsl_spatial_graph_3::detview(int x0,int x1,int y0,int y1,
	int *istart,int *jstart,int *ilim,int *jlim,int *iincr,int *jincr,
	int *iend,int *loopx)
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
      return 1;
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
      return 1;
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
      return 1;
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
      return 1;
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
      return 1;
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
      return 1;
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
      return 1;
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
      return 1;
    }
	return 1;
}

