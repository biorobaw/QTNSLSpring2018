/* SCCS  @(#)xnsl_xview_text_label_input.h	1.1---95/08/13--23:44:28 */
//////////////////////////////////////////////////////////////////////////
//
// xnsl_xview_text_label_input.h:  Class that creates a xview label widget
//               
/////////////////////////////////////////////////////////////////////////
#ifndef XNSL_XVIEW_LABEL_H
#define XNSL_XVIEW_LABEL_H
#include "xnsl_xview_panel_item.h"
class xnsl_xview_text_label_input : public xnsl_xview_panel_item
{
   private:
       
   protected:

      // Nothing yet.

   public:

      xnsl_xview_text_label_input  ();
      virtual  ~xnsl_xview_text_label_input ();

      virtual xnsl_widget* make_widget();

      virtual xnsl_widget *create_widget(const char* = "", 
		xnsl_widget* = 0,int = 0, int = 0,int = 100, int = 100,
		int = 10, int = 10);

      virtual void set_env(const char * = "", int = 0, int = 0, 
				int = 100, int = 100, int = 10, int = 10);

      xnsl_widget*  create_text_label_input_widget (const char * = "",
	xnsl_widget * = 0, int=0, int=0, const char * = "", const char * = "");
  
      void set_text_label_input_env (const char * = "", 
		int=0, int=0, const char * = "", const char * = "");
 };
#endif

// End of file.
