/* SCCS  @(#)xnsl_tcltk_graph.C	1.1---95/08/13--21:05:31 */
//
//	xnsl_tcltk_graph.C
//
// cj 13/Oct/98
// Es necesario crear un contexto grafico (GC) en la PC con valores
// de omision para usar las funciones de Xlib. La mascara es
// un cero indicando que no hay cambio en ninguno de los 
// miembros de la estructura y el apuntador a los nuevos valores
// es nulo (pues no existen tales).
//			_gc = XCreateGC(_dpy, _xwin, 0, NULL);

#include "xkernel.h"
#include "nsl_kernel.h" 
# include "xnsl_tcltk_include.h"
#include "xnsl_tcltk_graph.h"

// update tasks every display step 
//int NSL_TK_FLUSH = 1; // 1: update idletasks, 0: no intermmediate updates;

// general draw (1: TK, 0: XLIB)
int TK_DRAW = 1; // should be set to "0" for efficiency
int TK_DRAW_LINE = 1; // 1: only Xlib
int TK_DRAW_TLINE = 0; // 1: do t lines with historical Tk values

xnsl_tcltk_graph::xnsl_tcltk_graph() : xnsl_tcltk_widget()
{
        set_type("graph");
        set_abstract_type("graph");
}
xnsl_tcltk_graph::~xnsl_tcltk_graph()
{
}
xnsl_widget* xnsl_tcltk_graph::make_widget()
{
	return new xnsl_tcltk_graph;
}

int xnsl_tcltk_graph::display()
{
	return 1;
}
int xnsl_tcltk_graph::xflush()
{
	//if (NSL_TK_FLUSH == 1)
		//Tcl_Eval(NSL_TCL_INTERP,"update idletasks");

	return 1;
}

int xnsl_tcltk_graph::clear_area(xnsl_widget* widget,int wx0,int wy0,int wx1,int wy1,
	int ni,int nj,int pos,int fg)
{
//	(wx0,wy0) is lower left corner.
//	 wx1: width, wy1: height

	//nsl_long_string str;

	if (TK_DRAW == 1)
		fg = 1;

	if (fg == 1) {
		char c = ' '; // 'p';

// avoid new rect creations by modifying existing one with itemconfigure, move, or ...
//		sprintf(str,"%s itemconfigure %s %d%c %d%c %d%c %d%c -fill white -outline white",_wname,_wname,wx0,c,wy0,c,wx0+wx1-1,c,wy0+wy1-1);
//		sprintf(str,"%s delete %s",_wname,istr);
//		Tcl_Eval(NSL_TCL_INTERP,str);

//		sprintf(str,"%s create rectangle %d%c %d%c %d%c %d%c -fill white -outline white",_wname,wx0,c,wy0,c,wx0+wx1-1,c,wy0+wy1-1,c);

//		Tcl_Eval(NSL_TCL_INTERP,str);
	}
	/*	else
	{
		sprintf(str,"%s",_wname);

			_tkmain = ((xnsl_tcltk_widget*) widget)->get_tkmain(); // Tk_MainWindow(NSL_TCL_INTERP);

			if (_tkmain != NULL)
				_tkwin = ((xnsl_tcltk_widget*) widget)->get_tkwin(); // Tk_NameToWindow(NSL_TCL_INTERP,str,_tkmain);
			else
				cmd_error(" xnsl_tcltk_graph::draw_line NULL tkmain");

			if (_tkmain != NULL && _tkwin != NULL) 
			{
				_sc = ((xnsl_tcltk_widget*) widget)->get_screen(); // Tk_Screen(_tkwin);
				_scnum = ((xnsl_tcltk_widget*) widget)->get_screen_num(); // Tk_ScreenNumber(_tkwin);
				_dpy = ((xnsl_tcltk_widget*) widget)->get_display(); // Tk_Display(_tkwin);
				_white = ((xnsl_tcltk_widget*) widget)->get_white(); 
				_black = ((xnsl_tcltk_widget*) widget)->get_black(); 
				_xwin = Tk_WindowId(_tkwin);
				_gc = ((xnsl_tcltk_widget*) widget)->get_GC(); // DefaultGC(_dpy, DefaultScreen(_dpy));
			
				XSetForeground(_dpy,_gc,_white); // SET GC WHITE FOR DRAWING
				XFillRectangle(_dpy,_xwin,_gc,wx0,wy0,wx1,wy1);
//				XFillRectangle(_dpy,_pixmap,_gc,wx0,wy0,wx1,wy1);
			}
			else
				cmd_error(" xnsl_tcltk_graph::clear_area NULL tkwin"); */
	//}

	return 1;
}

int xnsl_tcltk_graph::fill_rectangle(xnsl_widget* widget,int wx0,int wy0,int wx1,int wy1,
	int ni,int nj,int pos,int fg)
{
//	(wx0,wy0) is lower left corner.
//	 wx1: width, wy1: height
/*
	if (TK_DRAW == 1)
		fg = 1;

	nsl_long_string str;

	if (fg == 1) {
		nsl_string pos_str;
		char c = ' '; // 'p';

		if (pos == 1)
			sprintf(pos_str," -fill black -outline black");
		else
			sprintf(pos_str," -fill white -outline black");

		// resize existing rectangles if tags already exist, else create new
		nsl_string istr;
		sprintf(istr,"%s.%d.%d",_wname,ni,nj);

		sprintf(str,"%s gettags %s",_wname,istr);
		Tcl_Eval(NSL_TCL_INTERP,str);
		char* stmp0 = Tcl_GetStringResult(NSL_TCL_INTERP);

		if (strcmp(stmp0,"") == 0) {

			// create new rectangles
			sprintf(str,"%s create rectangle %d%c %d%c %d%c %d%c %s -tags %s",
				_wname,wx0,c,wy0,c,wx0+wx1,c,wy0+wy1,c,pos_str,istr);
			Tcl_Eval(NSL_TCL_INTERP,str);

		} else {

			// avoid new rect creations by modifying existing one with itemconfigure, move, or ...
			sprintf(str,"%s itemconfigure %s %s",_wname,istr,pos_str);
			//sprintf(str,"%s delete %s",_wname,istr);
			Tcl_Eval(NSL_TCL_INTERP,str);

			sprintf(str,"%s coords %s %d%c %d%c %d%c %d%c",_wname,istr,wx0,c,wy0,c,wx0+wx1,c,wy0+wy1,c);
			Tcl_Eval(NSL_TCL_INTERP,str);
		}

	} else {
			sprintf(str,"%s",_wname); 

			_tkmain = ((xnsl_tcltk_widget*) widget)->get_tkmain(); // Tk_MainWindow(NSL_TCL_INTERP);

			if (_tkmain != NULL)
				_tkwin = ((xnsl_tcltk_widget*) widget)->get_tkwin(); // Tk_NameToWindow(NSL_TCL_INTERP,str,_tkmain);
			else
				cmd_error(" xnsl_tcltk_graph::draw_line NULL tkmain");

			if (_tkmain != NULL && _tkwin != NULL) 
			{
				_sc = ((xnsl_tcltk_widget*) widget)->get_screen(); // Tk_Screen(_tkwin);
				_scnum = ((xnsl_tcltk_widget*) widget)->get_screen_num(); // Tk_ScreenNumber(_tkwin);
				_dpy = ((xnsl_tcltk_widget*) widget)->get_display(); // Tk_Display(_tkwin);
//				_xwin = ((xnsl_tcltk_widget*) widget)->get_window(); 
				_xwin = Tk_WindowId(_tkwin);
				_white = ((xnsl_tcltk_widget*) widget)->get_white(); 
				_black = ((xnsl_tcltk_widget*) widget)->get_black(); 
				_gc = ((xnsl_tcltk_widget*) widget)->get_GC(); // DefaultGC(_dpy, DefaultScreen(_dpy));
		
				XSetForeground(_dpy,_gc,_black); // SET GC BLACK FOR DRAWING
       			XFillRectangle(_dpy,_xwin,_gc,wx0,wy0,wx1,wy1);

				if (pos == -1) // -fill white -outline black
				{
					XSetForeground(_dpy,_gc,_white); // SET GC WHITE FOR DRAWING
					XFillRectangle(_dpy,_xwin,_gc,wx0+1,wy0+1,wx1-2,wy1-2);
				}

			}
			else
				cmd_error(" xnsl_tcltk_graph::fill_rectangle NULL tkwin");
	} */

	return 1;
}
int xnsl_tcltk_graph::draw_line(xnsl_widget* widget,int wx0,int wy0,int wx1,int wy1,
	int tt,int ni,int nj,int pos,const char* color,int fg)
{
	/*
	nsl_long_string str;
	nsl_very_long_string str0;
	nsl_long_string str1;
	nsl_long_string str2;
	nsl_very_long_string str3;
	nsl_string line_color;

//	sprintf(str,"%s",_wname); 

	if (TK_DRAW == 1)
		fg = 1;

	if (TK_DRAW_LINE == 1 && tt == 1)
		fg = 0;

	if (fg == 1)
	{
		char c = ' '; // 'p';

		if (color != 0 && strcmp(color,"") != 0) // color != "" 
		{
			sprintf(line_color,"-fill %s",color); //strcpy(line_color,color);
		}
		else
		{
			sprintf(line_color,"-fill black"); //strcpy(line_color,"black");
		}

		if (pos == 1) {

			sprintf(str,"%s create line %d%c %d%c %d%c %d%c %s",
				_wname,wx0,c,_height-wy0,c,wx1,c,_height-wy1,c,line_color);

			Tcl_Eval(NSL_TCL_INTERP,str);

		} else {

			// resize existing line if tags already exist, else create new
			nsl_string istr;
			sprintf(istr,"%s.%d.%d",_wname,ni,nj);

			sprintf(str,"%s gettags %s",_wname,istr);
			Tcl_Eval(NSL_TCL_INTERP,str);
			char* stmp0 = Tcl_GetStringResult(NSL_TCL_INTERP);

			if (strcmp(stmp0,"") == 0) {

//				sprintf(str2,"%s create line %d%c %d%c %d%c %d%c %s",
//					_wname,wx0,c,_height-wy0,c,wx1,c,_height-wy1,c,line_color);

				// create new line
				sprintf(str1,"%s create line %d%c %d%c %d%c %d%c %s -tags %s",
					_wname,wx0,c,_height-wy0,c,wx1,c,_height-wy1,c,line_color,istr);
				Tcl_Eval(NSL_TCL_INTERP,str1);

			} else {

				// avoid new rect creations by modifying existing one with itemconfigure, move, or ...
//				sprintf(str,"%s itemconfigure %s %s",_wname,istr,line_color);
				//sprintf(str,"%s delete %s",_wname,istr);
//				Tcl_Eval(NSL_TCL_INTERP,str);

				if (TK_DRAW_TLINE == 1) {
					sprintf(str2,"%s coords %s",_wname,istr);
					Tcl_Eval(NSL_TCL_INTERP,str2);
					char* stmp1 = Tcl_GetStringResult(NSL_TCL_INTERP);
					strcpy(str0,stmp1);

					sprintf(str3,"%s coords %s %s %f%c %f%c",_wname,istr,str0,(float)wx1,c,(float)_height-wy1,c);
				} 
				else
					sprintf(str3,"%s coords %s %d%c %d%c %d%c %d%c",_wname,istr,wx0,c,_height-wy0,c,wx1,c,_height-wy1,c);

				Tcl_Eval(NSL_TCL_INTERP,str3);
			}
		}
	}
	else if (widget != NULL)
	{
			_tkmain = ((xnsl_tcltk_widget*) widget)->get_tkmain(); // Tk_MainWindow(NSL_TCL_INTERP);

			if (_tkmain != NULL)
				_tkwin = ((xnsl_tcltk_widget*) widget)->get_tkwin(); // Tk_NameToWindow(NSL_TCL_INTERP,str,_tkmain);
			else
				cmd_error(" xnsl_tcltk_graph::draw_line NULL tkmain");

			if (_tkmain != NULL && _tkwin != NULL) 
			{
				_sc = ((xnsl_tcltk_widget*) widget)->get_screen(); // Tk_Screen(_tkwin);
				_scnum = ((xnsl_tcltk_widget*) widget)->get_screen_num(); // Tk_ScreenNumber(_tkwin);
				_dpy = ((xnsl_tcltk_widget*) widget)->get_display(); // Tk_Display(_tkwin);
//				_xwin = ((xnsl_tcltk_widget*) widget)->get_window(); 
				_xwin = Tk_WindowId(_tkwin);
				_white = ((xnsl_tcltk_widget*) widget)->get_white(); 
				_black = ((xnsl_tcltk_widget*) widget)->get_black(); 
				_gc = ((xnsl_tcltk_widget*) widget)->get_GC(); 

				XSetForeground(_dpy,_gc,_black); 
				XDrawLine(_dpy,_xwin,_gc,wx0,_height-wy0,wx1,_height-wy1);
//				XDrawLine(_dpy,_pixmap,_gc,wx0,_height-wy0,wx1,_height-wy1);
			}
			else
				cmd_error(" xnsl_tcltk_graph::draw_line NULL tkwin");
	}
	else
		cmd_error(" xnsl_tcltk_graph::draw_line NULL widget");
	*/
	return 1;
}
int xnsl_tcltk_graph::draw_grid(xnsl_widget* widget,int wx0,int wy0,int wx1,int wy1,
	int wxs,int wys,num_type x0, num_type y0, num_type x1, num_type y1, 
	num_type xs, num_type ys,int fg)
{
	/*
	if (TK_DRAW == 1)
		fg = 1;

	if (fg == 1)
	{
		char c = ' '; // 'p';

		nsl_long_string str;
	
//	if (fg == 0) {
		sprintf(str,"gridArray %s %d %d %d %d %d %d",_wname,wx0,wy0,wx1,wy1,wxs,wys);
//	else // for single temporal graph
//		sprintf(str,"grid %s %d %d %d %d %f %f %f %f %f %f %c",
//			_wname,wx0,wy0,wx1,wy1,x0,y0,x1,y1,xs,ys,c);
//
		Tcl_Eval(NSL_TCL_INTERP,str);
	}
	else 
	{
		for (int x = wx0; x <= wx1; x += wxs)
   			draw_line(widget,x,wy0,x,wy1,0,0,0,1,"black",0); 
		for (int y = wy1; y >= wy0; y -= wys)
			draw_line(widget,wx0,y,wx1,y,0,0,0,1,"black",0); 
    }
*/
	return 1;
}
int xnsl_tcltk_graph::draw_text(xnsl_widget* ,int ,int ,const char* )
{
	/*
	nsl_long_string str;
	char c = 'p';

	sprintf(str,"%s create text %d%c %d%c -text %s -anchor sw",_wname,wx,c,_height-wy,c,text);

	Tcl_Eval(NSL_TCL_INTERP,str);
*/
	return 1;
}

xnsl_widget* xnsl_tcltk_graph::create_widget(const char *wname,
	xnsl_widget* pxnsl_widget,int x,int y,int w,int h,
	int,int,int,int,int,int,const char*,const char*)
{
	strcpy(_wname,wname);
	_X0 = x;
	_Y0 = y;
	_width = w;
	_height = h;

	return this;
}

int xnsl_tcltk_graph::print(ostream&) const
{
	return 1;
}


