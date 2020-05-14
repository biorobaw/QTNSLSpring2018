/* SCCS  @(#)xnsl_motif_scrollable_panel.h	1.1---95/08/13--23:42:09 */
//////////////////////////////////////////////////////////////////////////
//
// xnsl_motif_scrollable_panel.h: Class that creates a motif menu bar widget.
//               
/////////////////////////////////////////////////////////////////////////
#ifndef XNSL_MOTIF_SCROLLABLE_PANEL_H
#define XNSL_MOTIF_SCROLLABLE_PANEL_H
#include "xnsl_motif_panel.h"
class xnsl_motif_scrollable_panel : public xnsl_motif_panel
{
   private:
      
   protected:

      // Nothing yet.

   public:

      xnsl_motif_scrollable_panel() { }; //temp define -bn7
 
      virtual ~xnsl_motif_scrollable_panel () { };

      virtual xnsl_widget *create_widget(const char* = "", 
		xnsl_widget* = 0,int = 0, int = 0,int = 100, int = 100,
		int = 10, int = 10,const char* = "", const char* = "");

//      xnsl_widget* create_scrollable_panel_widget(const char * = "", 
//		xnsl_widget* = 0,int = 0, int = 0,int = 100, int = 100);

      virtual xnsl_widget* make_widget();

       virtual void set_env(const char * = "", int = 0, int = 0, 
		int = 100, int = 100,int = 10, int = 10,
		const char* = "", const char* = "");

//      void set_scrollable_panel_env (const char * = "", 
//		int=20, int=20, int=100, int=100);
};
#endif

// End of file.










