/* SCCS  @(#)xnsl_tcltk_text_label_panel.h	1.1---95/08/13--23:42:10 */
//////////////////////////////////////////////////////////////////////////
//
// xnsl_tcltk_text_label_panel.h:  Class that creates a tcltk label widget
//               
/////////////////////////////////////////////////////////////////////////
#ifndef XNSL_TCLTK_TEXT_LABEL_PANEL_H
#define XNSL_TCLTK_TEXT_LABEL_PANEL_H
#include "xnsl_tcltk_panel_item.h"
class xnsl_tcltk_text_label_panel : public xnsl_tcltk_panel_item
{
   private:
       
   protected:

      // Nothing yet.

   public:

      xnsl_tcltk_text_label_panel  ();
      virtual  ~xnsl_tcltk_text_label_panel ();

      virtual xnsl_widget* make_widget();

      virtual xnsl_widget *create_widget(const char* = "", xnsl_widget* = 0,
		int = 0, int = 0,int = 100, int = 100,
		int = 0, int = 0,int = 100, int = 100,
		int = 10, int = 10,const char* = "", const char* = "");

      virtual void set_env(const char * = "", 
		int = 0, int = 0,int = 100, int = 100,
		int = 0, int = 0, int = 100, int = 100,int = 10, int = 10,
		const char* = "", const char* = "") { }; //never defined -bn7

      virtual int get_env(char*) { return 0; }; //NEVER DEFINED TODO: -bn7
};
#endif

// End of file.
