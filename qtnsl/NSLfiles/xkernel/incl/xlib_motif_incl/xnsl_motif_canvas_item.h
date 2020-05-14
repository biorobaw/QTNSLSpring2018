/* SCCS  @(#)xnsl_motif_canvas_item.h	1.1---95/08/13--23:42:02 */
///////////////////////////////////////////////////////////////////////////
//
// xnsl_motif_canvas_item.h: Class that creates a motif push button widget.
//               
//////////////////////////////////////////////////////////////////////////
#ifndef XNSL_MOTIF_CANVAS_ITEM_H
#define XNSL_MOTIF_CANVAS_ITEM_H
#include "xnsl_motif_widget.h"
class xnsl_motif_canvas_item : public xnsl_motif_widget
{
   protected:
      
 	xnsl_callback	*_callback;
 	xnsl_lib_widget	*_menu;

   public:

      xnsl_motif_canvas_item  ();
      virtual ~xnsl_motif_canvas_item ();

      virtual xnsl_widget* make_widget();

      virtual xnsl_widget *create_widget(const char* = "", 
		xnsl_widget* = 0,int = 0, int = 0,int = 100, int = 100,
		int = 10, int = 10,const char* = "", const char* = "");

//      xnsl_widget *create_canvas_item_widget(const char* = "", 
//		xnsl_widget* = 0,int = 0, int = 0,int = 100, int = 100);

      virtual void set_env(const char * = "", int = 0, int = 0, 
		int = 100, int = 100,int = 10, int = 10,
		const char* = "", const char* = "");

//      void set_canvas_item_env(const char * = "", int = 0, int = 0, 
//		int = 100, int = 100);

      virtual void set_callback (xnsl_callback*);
      virtual void set_menu (xnsl_widget *);

};
#endif

// End of file.










