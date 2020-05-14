/* SCCS  @(#)xnsl_xview_widget.h	1.1---95/08/13--23:44:29 */
////////////////////////////////////////////////////////////////////////
//
//xnsl_xview_widget.h:Base class for xview widgets.
//
///////////////////////////////////////////////////////////////////////

#ifndef XNSL_XVIEW_WIDGET_H
#define XNSL_XVIEW_WIDGET_H
#include "xnsl_xlib_widget.h"
class xnsl_xview_widget : public xnsl_xlib_widget
{
private:

protected:

	Xv_object	_object;

public:

	xnsl_xview_widget();
	virtual ~xnsl_xview_widget();

        virtual xnsl_widget* make_widget();

   	virtual xnsl_widget *create_widget(const char* = "", 
		xnsl_widget* = 0,int = 0, int = 0,int = 100, int = 100,
		int = 10, int = 10);

	virtual void set_env(const char* = "", int = 0, int = 0, 
				int = 100, int = 100, int = 10, int = 10);

	virtual void            show_widget();
	virtual void            unshow_widget();
	virtual void            destroy_widget();

	virtual void handle_events() {}

	Xv_object	get_object() { return (_object); }

	int get_env_width();
	int get_env_height();
	
	void set_env_x(int);
	void set_env_y(int);
	void set_env_width(int);
	void set_env_height(int);
	void set_env_name(const char*);
};
#endif

//End of file.
