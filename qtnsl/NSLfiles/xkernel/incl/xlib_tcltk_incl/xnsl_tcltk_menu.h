/* SCCS  @(#)xnsl_tcltk_menu.h	1.1---95/08/13--23:42:06 */
////////////////////////////////////////////////////////////////////////
//
// xnsl_tcltk_menu.h: Class that creates a tcltk pulldown menu
//                             widget.
//               
////////////////////////////////////////////////////////////////////////
#ifndef XNSL_TCLTK_MENU_H
#define XNSL_TCLTK_MENU_H
#include "xnsl_tcltk_panel_item.h"
class xnsl_tcltk_menu : public xnsl_tcltk_panel_item
{
   private:
      
   protected:

      // Nothing yet.

   public:

      	xnsl_tcltk_menu  ();
      	virtual ~xnsl_tcltk_menu ();

       virtual xnsl_widget* make_widget();

      	virtual xnsl_widget *create_widget(const char* = "", xnsl_widget* = 0,
		int = 0, int = 0,int = 100, int = 100,
		int = 0, int = 0,int = 100, int = 100,
		int = 10, int = 10,const char* = "", const char* = "");

	void set_menu_item(const char*);
};

//extern void menu_proc (Widget, Str);
#endif

// End of file.
