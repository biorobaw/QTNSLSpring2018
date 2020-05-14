/* SCCS  @(#)xnsl_xview_panel_item.h	1.1---95/08/13--23:44:26 */
///////////////////////////////////////////////////////////////////////////
//
// xnsl_xview_panel_item.h: Class that creates a xview push button widget.
//               
//////////////////////////////////////////////////////////////////////////
#ifndef XNSL_XVIEW_PANEL_ITEM_H
#define XNSL_XVIEW_PANEL_ITEM_H
#include "xnsl_xview_widget.h"
class xnsl_xview_panel_item : public xnsl_xview_widget
{
   protected:
      
	Panel_item _panel_item;

        nsl_string 	_value;
	xnsl_callback	*_callback;
	nsl_string 	_bitmap;
	xnsl_widget	*_menu;

   public:

      xnsl_xview_panel_item();
      virtual ~xnsl_xview_panel_item();

        Panel_item get_panel_item() { return _panel_item;}

      virtual xnsl_widget* make_widget();

      virtual xnsl_widget *create_widget(const char* = "", 
		xnsl_widget* = 0,int = 0, int = 0,int = 100, int = 100,
		int = 10, int = 10);

      xnsl_widget *create_panel_item_widget(const char* = "", 
		xnsl_widget* = 0,int = 0, int = 0,int = 100, int = 100);

      virtual void set_env(const char * = "", int = 0, int = 0, 
				int = 100, int = 100, int = 10, int = 10);

      void set_panel_item_env(const char * = "", int = 0, int = 0, 
				int = 100, int = 100);

      virtual void set_bitmap (const char *, int, int);
      virtual void set_callback (xnsl_callback*);
      virtual void set_menu (xnsl_widget * m);
      virtual void set_value (const char*);

      void set_env_label (const char*);
};
#endif

// End of file.










