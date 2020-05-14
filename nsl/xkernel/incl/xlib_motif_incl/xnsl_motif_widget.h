/* SCCS  @(#)xnsl_motif_widget.h	1.1---95/08/13--23:42:11 */
////////////////////////////////////////////////////////////////////////
//
//xnsl_motif_widget.h:Base class for motif widgets.
//
///////////////////////////////////////////////////////////////////////

#ifndef XNSL_MOTIF_WIDGET_H
#define XNSL_MOTIF_WIDGET_H
#include "xnsl_xlib_widget.h"
class xnsl_motif_widget : public xnsl_xlib_widget
{
private:

protected:

	//Widget	_object;

public:

	xnsl_motif_widget() { }; //temp def -bn7
	virtual ~xnsl_motif_widget() { };

        virtual xnsl_widget* make_widget();

   	virtual xnsl_widget *create_widget(const char* = "", 
		xnsl_widget* = 0,int = 0, int = 0,int = 100, int = 100,
		int = 10, int = 10,const char* = "", const char* = "");

	virtual void set_env(const char * = "", int = 0, int = 0, 
		int = 100, int = 100,int = 10, int = 10,
		const char* = "", const char* = "");

	virtual int get_env(char *);

	virtual void            show_widget() { }; //never defined -bn7
	virtual void            unshow_widget() { }; //never defined -bn7
	virtual void            destroy_widget() { }; //never defined -bn7

	virtual void		redraw() { }; //never defined -bn7

	virtual int clear_area(int,int,int,int) { return 0; }
	
	virtual void handle_events() {}

	//Widget	get_object() { return (_object); }

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
