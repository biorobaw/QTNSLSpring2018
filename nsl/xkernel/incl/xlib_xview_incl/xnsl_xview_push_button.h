/* SCCS  @(#)xnsl_xview_push_button.h	1.1---95/08/13--23:44:27 */
//////////////////////////////////////////////////////////////////////////
//
// xnsl_xview_push_button.h: Class that Creates the xview push
//                              button widget.
//               
//////////////////////////////////////////////////////////////////////////
#ifndef XNSL_XVIEW_PUSH_BUTTON_H
#define XNSL_XVIEW_PUSH_BUTTON_H
#include "xnsl_xview_panel_item.h"
class xnsl_xview_push_button : public xnsl_xview_panel_item
{
   private:
      
   protected:

      // Nothing yet.

   public:

      xnsl_xview_push_button  ();
      virtual  ~xnsl_xview_push_button ();

      virtual xnsl_widget* make_widget();

      virtual xnsl_widget *create_widget(const char* = "", 
		xnsl_widget* = 0,int = 0, int = 0,int = 100, int = 100,
		int = 10, int = 10);

      virtual void set_env(const char * = "", int = 0, int = 0, 
				int = 100, int = 100, int = 10, int = 10);

      xnsl_widget*  create_push_button_widget (const char * = "", 
		xnsl_widget * = 0, const char * = "");

      void set_push_button_env (const char *  ="",const char * = "");
};
#endif

// End of file.
