/* SCCS  @(#)xnsl_tcltk_scrollable_canvas.h	1.1---95/08/13--23:42:09 */
//////////////////////////////////////////////////////////////////////////
//
// xnsl_tcltk_scrollable_canvas.h: Creates the tcltk drawing area widget.
//               
/////////////////////////////////////////////////////////////////////////
#ifndef XNSL_TCLTK_SCROLLABLE_CANVAS_H
#define XNSL_TCLTK_SCROLLABLE_CANVAS_H
#include "xnsl_tcltk_canvas.h"
class xnsl_tcltk_scrollable_canvas : public xnsl_tcltk_canvas
{
   private:
      
   protected:

      // Nothing yet.

   public:

      xnsl_tcltk_scrollable_canvas  ();
      virtual ~xnsl_tcltk_scrollable_canvas ();

      virtual xnsl_widget* make_widget();

      virtual xnsl_widget *create_widget(const char* = "", xnsl_widget* = 0,
		int = 0, int = 0,int = 100, int = 100,
		int = 0, int = 0,int = 100, int = 100,
		int = 10, int = 10,const char* = "", const char* = "");

      virtual void set_env(const char * = "", 
		int = 0, int = 0,int = 100, int = 100,
		int = 0, int = 0, int = 100, int = 100,int = 10, int = 10,
		const char* = "", const char* = "") { }; //never defined -bn7
};
#endif

// End of file.










