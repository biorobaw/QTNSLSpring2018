/* SCCS  @(#)xnsl_motif_push_button.h	1.1---95/08/13--23:42:08 */
//////////////////////////////////////////////////////////////////////////
//
// xnsl_motif_push_button.h: Class that Creates the motif push
//                              button widget.
//               
//////////////////////////////////////////////////////////////////////////
#ifndef XNSL_MOTIF_PUSH_BUTTON_H
#define XNSL_MOTIF_PUSH_BUTTON_H
#include "xnsl_motif_panel_item.h"
class xnsl_motif_push_button : public xnsl_motif_panel_item
{
   private:
      
   protected:

      // Nothing yet.

   public:

      xnsl_motif_push_button() { }; //temp define -bn7
      virtual  ~xnsl_motif_push_button () { };

      virtual xnsl_widget* make_widget();

      virtual xnsl_widget *create_widget(const char* = "", 
		xnsl_widget* = 0,int = 0, int = 0,int = 100, int = 100,
		int = 10, int = 10,const char* = "", const char* = "");

      virtual void set_env(const char * = "", int = 0, int = 0, 
		int = 100, int = 100,int = 10, int = 10,
		const char* = "", const char* = "");

//      xnsl_widget*  create_push_button_widget (const char * = "", 
//		xnsl_widget * = 0, const char * = "");

//      void set_push_button_env (const char *  ="",const char * = "");
};
#endif

// End of file.
