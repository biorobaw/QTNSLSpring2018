/* SCCS  @(#)xnsl_motif_menu.h	1.1---95/08/13--23:42:06 */
////////////////////////////////////////////////////////////////////////
//
// xnsl_motif_menu.h: Class that creates a motif pulldown menu
//                             widget.
//               
////////////////////////////////////////////////////////////////////////
#ifndef XNSL_MOTIF_MENU_H
#define XNSL_MOTIF_MENU_H
#include "xnsl_motif_panel_item.h"
class xnsl_motif_menu : public xnsl_motif_panel_item
{
   private:
      
   protected:

      // Nothing yet.

   public:

      	xnsl_motif_menu() { }; //temp define -bn7
      	virtual ~xnsl_motif_menu () { };

       virtual xnsl_widget* make_widget();

      	virtual xnsl_widget *create_widget(const char* = "", 
		xnsl_widget* = 0,int = 0, int = 0,int = 100, int = 100,
		int = 10, int = 10,const char* = "", const char* = "");

//      xnsl_widget *create_menu_widget(const char* = "",xnsl_widget* = 0);

      	virtual void set_env(const char * = "", int = 0, int = 0, 
		int = 100, int = 100,int = 10, int = 10,
		const char* = "", const char* = "");

//      void set_menu_env(const char * = "", int = 0, int = 0, 
//		int = 10, int = 10);

	void set_menu_item(const char*);
};

//extern void menu_proc (Widget, Str);
#endif

// End of file.
