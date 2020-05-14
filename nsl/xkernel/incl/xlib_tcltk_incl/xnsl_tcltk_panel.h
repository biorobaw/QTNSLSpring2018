/* SCCS  @(#)xnsl_tcltk_panel.h	1.1---95/08/13--23:42:07 */
//////////////////////////////////////////////////////////////////////////
//
// xnsl_tcltk_panel.h: Class that creates a tcltk menu bar widget.
//               
/////////////////////////////////////////////////////////////////////////
#ifndef XNSL_TCLTK_PANEL_H
#define XNSL_TCLTK_PANEL_H
#include "xnsl_tcltk_widget.h"
class xnsl_tcltk_panel : public xnsl_tcltk_widget
{
   private:
      
   protected:

      // Nothing yet.

   public:

      xnsl_tcltk_panel  ();
 
      virtual ~xnsl_tcltk_panel ();

      virtual xnsl_widget *create_widget(const char* = "", xnsl_widget* = 0,
		int = 0, int = 0,int = 100, int = 100,
		int = 0, int = 0,int = 100, int = 100,
		int = 10, int = 10,const char* = "", const char* = "");

      virtual void set_env(const char * = "", 
		int = 0, int = 0,int = 100, int = 100,
		int = 0, int = 0, int = 100, int = 100,int = 10, int = 10,
		const char* = "", const char* = "") { }; //never defined -bn7

      virtual xnsl_widget* make_widget();
};
#endif

// End of file.









