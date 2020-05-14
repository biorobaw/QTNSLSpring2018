/* SCCS  %W%---%E%--%U% */
//////////////////////////////////////////////////////////////////////////
//
//xnsl_line.C:Class that creates a generic line
//
//////////////////////////////////////////////////////////////////////////

#include "xkernel.h"
#include "nsl_kernel.h" 

xnsl_line::xnsl_line(xnsl_display_canvas* win,float s0, float s1)
	: xnsl_widget_graph(win)
{
	set_type("line");
	_f0 = s0;
	_f1 = s1;
	_dir_type = 1;  // horizontal line
	_line_type = 1; // broken line
}

xnsl_line::~xnsl_line()
{
}

xnsl_widget * xnsl_line::make_widget()
{
	return new xnsl_line;
}

xnsl_widget * xnsl_line::create_widget (const char *wname,
 	xnsl_widget * pxnsl_widget,int x,int y,int width,int height,
	int wx0, int wy0, int wx1, int wy1, int wx, int wy,
	const char* label,const char* message)
{
	xnsl_manager	*pxnsl_manager;
 
	strcpy(_wname,wname);
	_X0 = x;
	_Y0 = y;
	_width = width;
	_height = height;

	_wx0 = wx0;
	_wy0 = wy0;
	_wx1 = wx1;
	_wy1 = wy1;
	_wxs = wx;
	_wys = wy;

	if (pxnsl_widget == NULL)
	{
		cmd_error("line: NULL parent");
		return this;
	}

	pxnsl_manager = XSYSTEM->get_xnsl_manager();
	_pxnsl_lib_widget = (xnsl_lib_widget*) 
		pxnsl_manager->create_manager_widget(
			"graph", pxnsl_widget,wname,x,y,width,height,
			wx0,wy0,wx1,wy1,wx,wy,label,message);

 	if (_pxnsl_lib_widget == NULL )
		cerr << "create_line_widget failed.\n";
  
	return this;
} 

int xnsl_line::display()
{
//      set_env("",_X0,_Y0,_width,_height,_wx0,_wy0,_wx1,_wy1,_wxs,_wys); 

	if (_wxs == 0 || _wys == 0 || _wx0 == _wx1 || _wy0 == _wy1)
	{
		cmd_error("xnsl_line::display: Bad set of wx/wy values");
		return 1;
	}

//	draw_broken_line(_widget,x0,y0,x1,y1); // only one line
	nsl_string color;
	strcpy(color,"blue");

	int sx,wx;
	int sy,wy;

        int ys = 5;
        int ym = 3;

        int xs = 5;
        int xm = 3;

//	if (able_fg == 0 || redraw_fg == 0)
//		return;

	if (_dir_type == 1) // horizontal, f0 = f1
	{
	  for (wy = _wy0; wy <= _wy1 - _wys; wy = wy + _wys)
	  {
      	    //sy = coord_transform(_f0,_wymin,_wymax,(float)wy,(float)_wys); //undefined -bn7
	    if (sy > wy && sy < wy + _wys)
	    {
//		if (_line_type = 1) // broken 
  	        for (wx = _wx0; wx < _wx1 - xs; wx = wx + xs)
                	draw_line(_widget,wx,sy,wx+xs,sy,0,0,0,1,color,1);
        	draw_line(_widget,wx,sy,_wx1,sy,0,0,0,1,color,1);
	    }
	  }
	}
	else if (_dir_type == 2) // vertical, f0 = f1
	{
	  for (wx = _wx0; wx <= _wx1 - _wxs; wx = wx + _wxs)
	  {
  	    //sx = coord_transform(_f0,_wymin,_wymax,(float)wx,(float)_wxs);
	    if (sx > wx && sx < wx + _wxs)
	    {
//		if (line_type = 1) // broken 
 	        for (wy = _wy0; wy < _wy1 - ys; wy = wy + ys)
                	draw_line(_widget,sx,wy,sx,wy+ys,0,0,0,1,color,1);
        	draw_line(_widget,sx,wy,sx,_wy1,0,0,0,1,color,1);
	    }
	  }
	}
	else
	  cmd_error("xnsl_line::display: Unable to draw line");

	xflush();
	
	return 1;
} 


