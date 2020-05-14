/* SCCS  @(#)xnsl_tcltk_widget.h	1.1---95/08/13--23:42:11 */
#ifndef XNSL_QT_WIDGET_H
#define XNSL_QT_WIDGET_H
#include "xnsl_xlib_widget.h"
#include <QGuiApplication>
class xnsl_qt_widget : public xnsl_xlib_widget
/*this class is the super class that links between the xkernel part of the qt vis
*/
{
private:

protected:
	unsigned long _white;
	unsigned long _black;

	QWidget *widget; //this is the qt object that a xnsl_qt_widget points to that actually does the real vis work

public:

	QWidget *GetWidget() { return widget; };

	xnsl_qt_widget();
	virtual ~xnsl_qt_widget();

	void init_widget(char*) { };

	unsigned long get_white() { return _white; }
	unsigned long get_black() { return _black; }

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

	int get_env_width() { return _width; };
	int get_env_height() { return _height; };

       	void set_env_x(int x);
      	void set_env_y(int y);
      	void set_env_width(int width);
      	void set_env_height(int height);
      	void set_env_name(const char *name);
};
#endif

//End of file.
