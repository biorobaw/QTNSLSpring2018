/* SCCS  @(#)xnsl_xview_menu.h	1.1---95/08/13--23:44:25 */
////////////////////////////////////////////////////////////////////////
//
// xnsl_xview_menu.h: Class that creates a xview pulldown menu
//                             widget.
//               
////////////////////////////////////////////////////////////////////////
#ifndef XNSL_XVIEW_MENU_H
#define XNSL_XVIEW_MENU_H
#include "xnsl_xview_panel_item.h"
class xnsl_xview_menu : public xnsl_xview_panel_item
{
   private:
      
	Menu _menu;

   protected:

      // Nothing yet.

   public:

      	xnsl_xview_menu  ();
      	virtual ~xnsl_xview_menu ();

        Menu get_menu() { return _menu;}

        virtual xnsl_widget* make_widget();

      	virtual xnsl_widget *create_widget(const char* = "", 
		xnsl_widget* = 0,int = 0, int = 0,int = 100, int = 100,
		int = 10, int = 10);

      	xnsl_widget *create_menu_widget(const char* = "",xnsl_widget* = 0);

      	virtual void set_env(const char * = "", int = 0, int = 0, 
				int = 100, int = 100, int = 10, int = 10);

      	void set_menu_env(const char * = "", int = 0, int = 0, 
				int = 100, int = 100);

	void set_menu_item(const char*);
};

//extern void menu_proc (Menu, Menu_item);
#endif

// End of file.
