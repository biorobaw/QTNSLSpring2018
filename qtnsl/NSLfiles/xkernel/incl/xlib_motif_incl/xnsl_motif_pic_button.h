/* SCCS  @(#)xnsl_motif_pic_button.h	1.1---95/08/13--23:42:08 */
///////////////////////////////////////////////////////////////////////////
//
// xnsl_motif_pic_button.h: Class that creates a motif push button widget.
//               
//////////////////////////////////////////////////////////////////////////
#ifndef XNSL_MOTIF_PIC_BUTTON_H
#define XNSL_MOTIF_PIC_BUTTON_H
#include "xnsl_motif_panel_item.h"
class xnsl_motif_pic_button : public xnsl_motif_panel_item
{
   private:
      
   protected:

      // Nothing yet.

   public:

      xnsl_motif_pic_button() { }; //temp define -bn7
      virtual ~xnsl_motif_pic_button () { };

      virtual xnsl_widget* make_widget();

      virtual xnsl_widget *create_widget(const char* = "", 
		xnsl_widget* = 0,int = 0, int = 0,int = 100, int = 100,
		int = 10, int = 10,const char* = "", const char* = "");

      virtual void set_env(const char* = "", int = 0, int = 0, 
		int = 100, int = 100,int = 10, int = 10,
		const char* = "", const char* = "");

//      xnsl_widget*  create_pic_button_widget (const char* = "", 
//		xnsl_widget* = 0, int=0, int=0, xnsl_callback* = 0,
//		int=10,int=10,const char* = "");

//      void set_pic_button_env (const char * = "", 
//		int=0, int=0,xnsl_callback* = 0,int=10,int=10,const char* = "");
};
#endif

// End of file.










