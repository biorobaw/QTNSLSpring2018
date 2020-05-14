/* SCCS  @(#)xnsl_xview_canvas_item.h	1.1---95/08/13--23:44:23 */
///////////////////////////////////////////////////////////////////////////
//
// xnsl_xview_canvas_item.h: Class that creates a xview push button widget.
//               
//////////////////////////////////////////////////////////////////////////
#ifndef XNSL_XVIEW_PANEL_ITEM_H
#define XNSL_XVIEW_PANEL_ITEM_H
#include "xnsl_xview_widget.h"
class xnsl_xview_canvas_item : public xnsl_xview_widget
{
   protected:
      
	xnsl_callback	*_callback;
 	xnsl_lib_widget	*_menu;

   public:

      xnsl_xview_canvas_item  ();
      virtual ~xnsl_xview_canvas_item ();

      virtual xnsl_widget* make_widget();

      virtual xnsl_widget *create_widget(const char* = "", 
		xnsl_widget* = 0,int = 0, int = 0,int = 100, int = 100,
		int = 10, int = 10);

      xnsl_widget *create_canvas_item_widget(const char* = "", 
		xnsl_widget* = 0,int = 0, int = 0,int = 100, int = 100);

      virtual void set_env(const char * = "", int = 0, int = 0, 
				int = 100, int = 100, int = 10, int = 10);

      void set_canvas_item_env(const char * = "", int = 0, int = 0, 
				int = 100, int = 100);

      virtual void set_callback (xnsl_callback*);
      virtual void set_menu (xnsl_widget * m);

};
#endif

// End of file.










