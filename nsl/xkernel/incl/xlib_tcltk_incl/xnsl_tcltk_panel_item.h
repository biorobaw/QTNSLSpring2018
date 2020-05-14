/* SCCS  @(#)xnsl_tcltk_panel_item.h	1.1---95/08/13--23:42:07 */
///////////////////////////////////////////////////////////////////////////
//
// xnsl_tcltk_panel_item.h: Class that creates a tcltk push button widget.
//               
//////////////////////////////////////////////////////////////////////////
#ifndef XNSL_TCLTK_PANEL_ITEM_H
#define XNSL_TCLTK_PANEL_ITEM_H
#include "xnsl_tcltk_widget.h"
#include "xnsl_callback.h"
class xnsl_tcltk_panel_item : public xnsl_tcltk_widget
{
   protected:
      
        char		*_value;
  	xnsl_callback	*_callback;
	char		*_bitmap;
	xnsl_widget	*_menu;

   public:

      xnsl_tcltk_panel_item();
      virtual ~xnsl_tcltk_panel_item();

      virtual xnsl_widget* make_widget();

      virtual xnsl_widget *create_widget(const char* = "", xnsl_widget* = 0,
		int = 0, int = 0,int = 100, int = 100,
		int = 0, int = 0,int = 100, int = 100,int = 10, int = 10,
		const char* = "", const char* = "");

      virtual void set_env(const char * = "", 
		int = 0, int = 0,int = 100, int = 100,
		int = 0, int = 0,int = 100, int = 100,int = 10, int = 10,
		const char* = "", const char* = "") { }; //never defined -bn7

      virtual int get_env(char *); // { };  -bn7

      virtual void set_bitmap (const char *, int, int);
      virtual void set_callback (xnsl_callback*);
      virtual void set_menu (xnsl_widget * m);
      virtual void set_value (const char*);
};
#endif

// End of file.










