/* SCCS  @(#)xnsl_lib_widget.h	1.1---95/08/13--23:43:10 */
///////////////////////////////////////////////////////////////////////
//
// xnsl_lib_widget.h: Base class for ANY type of widget, irrespective of
//                user interface toolkit used.
//               
///////////////////////////////////////////////////////////////////////
#ifndef XNSL_LIB_WIDGET_H
#define XNSL_LIB_WIDGET_H
#include "xnsl_widget.h"
class xnsl_lib_widget : public xnsl_widget
{
   private:
 
	// Nothing yet.
  
   protected:


   public:

      	xnsl_lib_widget();
      	virtual ~xnsl_lib_widget();

       	virtual xnsl_widget *make_widget();

      	virtual xnsl_widget *create_widget(const char* = "", xnsl_widget* = 0, 
		int = 0, int = 0, int = 100, int = 100,
		int = 0, int = 0,int = 100, int = 100,
		int=10,int=10,const char* = "",const char* = "");

	virtual void  show_widget();
	virtual void  unshow_widget();
	virtual void  destroy_widget();

        virtual int display();

        virtual void redraw();

        virtual int xflush();

      	virtual int clear_area(xnsl_widget* = 0,int = 0,int = 0, int = 100, int = 100,
			int=0,int=0,int=1,int = 0);
      	virtual int fill_rectangle(xnsl_widget* = 0,int = 0,int = 0, int = 100, int = 100,
			int=0,int=0,int=1,int=0);
      	virtual int draw_line(xnsl_widget* = 0,int = 0,int = 0, int = 100, int = 100,
			int = 0,int = 0, int = 0, int = 1,const char* = "",int = 0);
      	virtual int draw_grid(xnsl_widget* = 0,int = 0,int = 0, int = 100, int = 100,
      		int = 100, int = 100,
		num_type = 0,num_type = 0, num_type = 1, num_type = 1,
      		num_type = 1, num_type = 1, int = 0);
        virtual int draw_text(xnsl_widget* = 0,int = 0,int = 0, const char* = "");

        virtual int read_from_database();
        virtual int write_to_database();

	virtual void set_value(const char*){}
	virtual void set_menu_item(const char*){}
	virtual void set_menu(xnsl_widget*) {}
	virtual void set_bitmap(const char*, int, int) {}
//	virtual void set_callback(xnsl_callback*) {}

	virtual void handle_events() {}

	virtual void clear_widget(int=0,int=0) {}

	virtual int output(char*);
};
#endif

// End of file.










