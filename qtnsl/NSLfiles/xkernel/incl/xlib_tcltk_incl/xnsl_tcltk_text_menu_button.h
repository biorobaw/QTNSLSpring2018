/* SCCS  @(#)xnsl_tcltk_text_menu_button.h	1.1---95/08/13--23:42:11 */
//////////////////////////////////////////////////////////////////////////
//
// xnsl_tcltk_text_menu_button.h: Class that Creates the tcltk cascade
//                              button widget.
//               
//////////////////////////////////////////////////////////////////////////
#ifndef XNSL_TCLTK_TEXT_MENU_BUTTON_H
#define XNSL_TCLTK_TEXT_MENU_BUTTON_H
#include "xnsl_tcltk_panel_item.h"
class xnsl_tcltk_text_menu_button : public xnsl_tcltk_panel_item
{
   private:
      
   protected:

      // Nothing yet.

   public:

      xnsl_tcltk_text_menu_button  ();
      virtual  ~xnsl_tcltk_text_menu_button ();

      virtual xnsl_widget* make_widget();

      virtual xnsl_widget *create_widget(const char* = "", xnsl_widget* = 0,
		int = 0, int = 0,int = 100, int = 100,
		int = 0, int = 0,int = 100, int = 100,
		int = 10, int = 10,const char* = "", const char* = "");

      virtual void set_env(const char * = "", 
		int = 0, int = 0,int = 100, int = 100,
		int = 0, int = 0, int = 100, int = 100,int = 10, int = 10,
		const char* = "", const char* = "") { }; //TODO: never defined -bn7

      void set_menu(xnsl_widget*);
};
#endif

// End of file.
