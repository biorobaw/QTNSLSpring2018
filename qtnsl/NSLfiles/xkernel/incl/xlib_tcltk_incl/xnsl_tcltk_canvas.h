/* SCCS  @(#)xnsl_tcltk_canvas.h	1.1---95/08/13--23:41:57 */
//////////////////////////////////////////////////////////////////////////
//
// xnsl_tcltk_canvas.h: Creates the tcltk drawing area widget.
//               
/////////////////////////////////////////////////////////////////////////
#ifndef XNSL_TCLTK_CANVAS_H
#define XNSL_TCLTK_CANVAS_H
#include "xnsl_tcltk_widget.h"
class xnsl_tcltk_canvas : public xnsl_tcltk_widget
{
   private:
      
   protected:

      // Nothing yet.

   public:

      xnsl_tcltk_canvas  ();
      virtual ~xnsl_tcltk_canvas ();

      virtual xnsl_widget* make_widget();

      virtual xnsl_widget *create_widget(const char* = "", xnsl_widget* = 0,
		int = 0, int = 0,int = 100, int = 100,
		int = 0, int = 0,int = 100, int = 100,
		int = 10, int = 10,const char* = "", const char* = "");

      virtual void redraw();
      virtual int clear_area(xnsl_widget* = 0,int = 0, int = 0,int = 100, int = 100,
		int = 0, int = 0, int = 1, int = 0);
};
#endif

// End of file.










