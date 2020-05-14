/* SCCS  %W%---%E%--%U% */
//////////////////////////////////////////////////////////////////////////
//
// xnsl_xlib_widget.h:  Class that creates a xlib widget
//               
/////////////////////////////////////////////////////////////////////////
 #ifndef _XNSL_XLIB_WIDGET_H
 #define _XNSL_XLIB_WIDGET_H
 #include "xnsl_lib_widget.h"
class xnsl_xlib_widget : public xnsl_lib_widget
{
   /*protected:
        Display  *_dpy;
        Window  _xwin;
        GC _gc;
	Screen *_sc;
	int _scnum;
	int _depth;
	Pixmap _pixmap;

   public:

	Display* get_display() { return _dpy; }
	Window get_window() { return _xwin; }
	GC get_GC() { return _gc; }
	Screen* get_screen() { return _sc; }
	int get_screen_num() { return _scnum; }
	int get_depth() { return _depth; }
	Pixmap get_pixmap() { return _pixmap; }

	void set_display(Display* d) { _dpy = d; }
	void set_window(Window w) { _xwin = w; }
	void set_GC(GC g) { _gc = g; }
	void set_screen(Screen* sc) { _sc = sc; }
	void set_screen_num(int n) { _scnum = n; }
	void set_depth(int n) { _depth = n; }
	void set_pixmap(Pixmap pix) { _pixmap = pix; } */
public:
      xnsl_xlib_widget();
      virtual  ~xnsl_xlib_widget();

      virtual int display();

      virtual int xflush();
      virtual int clear_area(xnsl_widget* = 0,int = 0,int = 0, int = 100, int = 100,
		int=0,int=0,int=1,int = 0);
      virtual int fill_rectangle(xnsl_widget* = 0,int = 0,int = 0, int = 100, int = 100,
		int=0,int=0,int=1,int=0);
      virtual int draw_line(xnsl_widget* = 0,int = 0,int = 0, int = 100, int = 100,
		int = 0,int = 0, int = 0, int = 1,const char* = "",int = 0);

      virtual xnsl_widget* make_widget();

      virtual xnsl_widget* create_widget(const char * = "",xnsl_widget* = 0,
		int=0,int=0,int=100,int=100,
		int=0,int=0,int=100,int=100,
		int = 10, int = 10,const char* = "",const char* = "");

};
 #endif
