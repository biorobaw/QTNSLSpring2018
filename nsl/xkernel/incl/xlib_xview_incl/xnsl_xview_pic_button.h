/* SCCS  @(#)xnsl_xview_pic_button.h	1.1---95/08/13--23:44:26 */
///////////////////////////////////////////////////////////////////////////
//
// xnsl_xview_pic_button.h: Class that creates a xview push button widget.
//               
//////////////////////////////////////////////////////////////////////////
#ifndef XNSL_XVIEW_PIC_BUTTON_H
#define XNSL_XVIEW_PIC_BUTTON_H
#include "xnsl_xview_panel_item.h"
class xnsl_xview_pic_button : public xnsl_xview_panel_item
{
   private:
      
   protected:

      // Nothing yet.

   public:

      xnsl_xview_pic_button  ();
      virtual ~xnsl_xview_pic_button ();

      virtual xnsl_widget* make_widget();

      virtual xnsl_widget *create_widget(const char* = "", 
	xnsl_widget* = 0,int = 0, int = 0,int = 100, int = 100,
	int = 10, int = 10);

      virtual void set_env(const char* = "", int = 0, int = 0, 
	int = 100, int = 100, int = 10, int = 10);

      xnsl_widget*  create_pic_button_widget (const char* = "", 
	xnsl_widget* = 0, int=0, int=0, xnsl_callback* = 0,
	int=10,int=10,const char* = "");

      void set_pic_button_env (const char * = "", 
	int=0, int=0,xnsl_callback* = 0,int=10,int=10,const char* = "");
};
#endif

// End of file.










