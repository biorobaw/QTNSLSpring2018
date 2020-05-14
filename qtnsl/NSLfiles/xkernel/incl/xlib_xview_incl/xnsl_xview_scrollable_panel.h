/* SCCS  @(#)xnsl_xview_scrollable_panel.h	1.1---95/08/13--23:44:27 */
//////////////////////////////////////////////////////////////////////////
//
// xnsl_xview_scrollable_panel.h: Class that creates a xview menu bar widget.
//               
/////////////////////////////////////////////////////////////////////////
#ifndef XNSL_XVIEW_SCROLLABLE_PANEL_H
#define XNSL_XVIEW_SCROLLABLE_PANEL_H
#include "xnsl_xview_panel.h"
class xnsl_xview_scrollable_panel : public xnsl_xview_panel
{
   private:
      
   protected:

      // Nothing yet.

   public:

      xnsl_xview_scrollable_panel  ();
 
      virtual ~xnsl_xview_scrollable_panel ();

      virtual xnsl_widget *create_widget(const char* = "", 
		xnsl_widget* = 0,int = 0, int = 0,int = 100, int = 100,
		int = 10, int = 10);

      xnsl_widget* create_scrollable_panel_widget(const char * = "", 
		xnsl_widget* = 0,int = 0, int = 0,int = 100, int = 100);

      virtual xnsl_widget* make_widget();

      virtual void set_env(const char * = "", int = 0, int = 0, 
				int = 100, int = 100, int = 10, int = 10);

      void set_scrollable_panel_env (const char * = "", 
		int=0, int=0, int=100, int=100);
};
#endif

// End of file.










