/* SCCS  @(#)xnsl_tcltk_widget.h	1.1---95/08/13--23:42:11 */
////////////////////////////////////////////////////////////////////////
//
//xnsl_tcltk_widget.h:Base class for tcltk widgets.
//
///////////////////////////////////////////////////////////////////////

#ifndef XNSL_TCLTK_WIDGET_H
#define XNSL_TCLTK_WIDGET_H
#include "xnsl_xlib_widget.h"
class xnsl_tcltk_widget : public xnsl_xlib_widget
{
private:

protected:

	//Tk_Window _tkmain, _tkwin;
	//Tcl_Interp*	_interp;

	unsigned long _white;
	unsigned long _black;
	//XColor* _xcolorwhite;
	//XColor* _xcolorblack;

public:

	xnsl_tcltk_widget();
	virtual ~xnsl_tcltk_widget();

	void init_widget(char*) { };

	//Tk_Window get_tkmain() { return _tkmain; }
	//Tk_Window get_tkwin() { return _tkwin; }

	unsigned long get_white() { return _white; }
	unsigned long get_black() { return _black; }

	//void set_tkmain(Tk_Window tm) { _tkmain = tm; }
	//void set_tkwin(Tk_Window tw) { _tkwin = tw; }

    virtual xnsl_widget* make_widget();

   	virtual xnsl_widget *create_widget(const char* = "", 
		xnsl_widget* = 0,int = 0, int = 0,int = 100, int = 100,
		int = 0, int = 0,int = 100, int = 100,
		int = 10, int = 10,const char* = "", const char* = "");

	virtual void            show_widget();
	virtual void            unshow_widget();
	virtual void            destroy_widget();

	virtual void		redraw();

	virtual int clear_area(xnsl_widget*,
		int = 0, int = 0, int = 100, int = 100, int=0, int=0, int = 1,int = 0)
	{ return 0; }
	
	virtual void handle_events() {}

	//Tcl_Interp*	get_interp() { return (_interp); }
	//void 		set_interp(Tcl_Interp* interp) { _interp = interp; }

	int get_env_width();
	int get_env_height();

       	void set_env_x(int x);
      	void set_env_y(int y);
      	void set_env_width(int width);
      	void set_env_height(int height);
      	void set_env_name(const char *name);
};
#endif

//End of file.
