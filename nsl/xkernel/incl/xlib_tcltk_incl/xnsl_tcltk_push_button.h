/* SCCS  @(#)xnsl_tcltk_push_button.h	1.1---95/08/13--23:42:08 */
//////////////////////////////////////////////////////////////////////////
//
// xnsl_tcltk_push_button.h: Class that Creates the tcltk push
//                              button widget.
//               
//////////////////////////////////////////////////////////////////////////
#ifndef XNSL_TCLTK_PUSH_BUTTON_H
#define XNSL_TCLTK_PUSH_BUTTON_H
#include "xnsl_tcltk_panel_item.h"
class xnsl_tcltk_push_button : public xnsl_tcltk_panel_item
{
   private:
      
   protected:

      // Nothing yet.

   public:

      xnsl_tcltk_push_button  ();
      virtual  ~xnsl_tcltk_push_button ();

      virtual xnsl_widget* make_widget();

      virtual xnsl_widget *create_widget(const char* = "", xnsl_widget* = 0,
		int = 0, int = 0,int = 100, int = 100,
		int = 0, int = 0,int = 100, int = 100,
		int = 10, int = 10,const char* = "", const char* = "");

};
#endif

// End of file.
