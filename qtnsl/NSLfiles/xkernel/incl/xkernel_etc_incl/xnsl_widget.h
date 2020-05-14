/* SCCS  @(#)xnsl_widget.h	1.1---95/08/13--23:43:28 */
///////////////////////////////////////////////////////////////////////
//
// xnsl_widget.h: Base class for ANY type of widget, irrespective of
//                user interface toolkit used.
//               
///////////////////////////////////////////////////////////////////////

#ifndef _XNSL_WIDGET_H
#define _XNSL_WIDGET_H
#include "xnsl_xpublic.h"
class xnsl_lib_widget;
class xnsl_widget : public xnsl_xpublic
{
   protected:

   	nsl_string _wname;
	nsl_string _wlabel;
	nsl_string _wmessage;

    int    _X0;
   	int    _Y0;
   	int    _width;
   	int    _height;

  	xnsl_lib_widget *_pxnsl_lib_widget;

	int _init_fg;
  
   
   public:

      xnsl_widget();
      virtual ~xnsl_widget();

	  int get_init_fg() { return _init_fg; }
	  void set_init_fg(int fg) { _init_fg = fg; }

      virtual xnsl_widget  *make_widget();

      virtual xnsl_widget *create_widget(const char* = "", 
		xnsl_widget* = 0, int = 0, int = 0,int = 100, int = 100,
		int = 0, int = 0,int = 100, int = 100,
		int = 10,int = 10,const char* = "",const char* = "");

      virtual void  show_widget();
      virtual void  unshow_widget();
      virtual void  destroy_widget();

      virtual int display();
      virtual int read_from_database();
      virtual int write_to_database();

	void	set_X0(int x) { _X0=x; }
	void	set_Y0(int y) { _Y0=y; }
	void	set_width(int x) { _width=x; }
	void	set_height(int y) { _height=y; }

      void set_wname(const char* l = "") { strcpy(_wname,l); }
      void set_wlabel(const char* l = "") { strcpy(_wlabel,l); }
      void set_wmessage(const char* l = "") { strcpy(_wmessage,l); }

 	int	get_X0() { return _X0; }
	int	get_Y0() { return _Y0; }
	int	get_width() { return _width; }
	int	get_height() { return _height; }

      char* get_wname() { return _wname; }
      char* get_wlabel() { return _wlabel; }
      char* get_wmessage() { return _wmessage; }

      void set_lib_widget (xnsl_lib_widget *lb)
		{_pxnsl_lib_widget = lb;}

      xnsl_lib_widget* get_lib_widget ()
		{ return _pxnsl_lib_widget; }

	virtual	int print(ostream&) const;
 	virtual	int print_status(ostream&) const;
};
#endif









