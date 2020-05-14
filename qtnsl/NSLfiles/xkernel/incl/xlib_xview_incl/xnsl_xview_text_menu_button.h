/* SCCS  @(#)xnsl_xview_text_menu_button.h	1.1---95/08/13--23:44:29 */
//////////////////////////////////////////////////////////////////////////
//
// xnsl_xview_text_menu_button.h: Class that Creates the xview cascade
//                              button widget.
//               
//////////////////////////////////////////////////////////////////////////
#ifndef XNSL_XVIEW_TEXT_MENU_BUTTON_H
#define XNSL_XVIEW_TEXT_MENU_BUTTON_H
#include "xnsl_xview_panel_item.h"
class xnsl_xview_text_menu_button : public xnsl_xview_panel_item
{
   private:
      
   protected:

      // Nothing yet.

   public:

      xnsl_xview_text_menu_button  ();
      virtual  ~xnsl_xview_text_menu_button ();

      virtual xnsl_widget* make_widget();

      virtual xnsl_widget *create_widget(const char* = "", 
		xnsl_widget* = 0,int = 0, int = 0,int = 100, int = 100,
		int = 10, int = 10);

      virtual void set_env(const char * = "", int = 0, int = 0, 
				int = 100, int = 100, int = 10, int = 10);

      xnsl_widget* create_text_menu_button_widget(const char* = "",
	xnsl_widget* = 0, xnsl_widget* = 0,const char* = "");

      void set_text_menu_button_env (const char* = "", 
		xnsl_widget* = 0,const char* = "");

      void set_menu(xnsl_widget*);
};
#endif

// End of file.
