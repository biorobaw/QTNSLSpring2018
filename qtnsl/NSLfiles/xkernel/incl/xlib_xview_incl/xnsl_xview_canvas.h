/* SCCS  @(#)xnsl_xview_canvas.h	1.1---95/08/13--23:44:22 */
//////////////////////////////////////////////////////////////////////////
//
// xnsl_xview_canvas.h: Creates the xview drawing area widget.
//               
/////////////////////////////////////////////////////////////////////////
#ifndef XNSL_XVIEW_CANVAS_H
#define XNSL_XVIEW_CANVAS_H
#include "xnsl_xview_widget.h"
class xnsl_xview_canvas : public xnsl_xview_widget
{
   private: 
	Canvas _canvas; 
       
   protected:

      // Nothing yet.

   public:

      xnsl_xview_canvas  ();
      virtual ~xnsl_xview_canvas ();

	Canvas get_canvas() { return _canvas;}

      virtual xnsl_widget* make_widget();

      virtual xnsl_widget *create_widget(const char* = "", 
		xnsl_widget* = 0,int = 0, int = 0,int = 100, int = 100,
		int = 10, int = 10);

      virtual void set_env(const char* = "", int = 0, int = 0, 
				int = 100, int = 100, int = 10, int = 10);

      xnsl_widget *create_canvas_widget(const char* = "", 
		xnsl_widget* = 0,int = 0, int = 0,int = 100, int = 100);

      void set_canvas_env(const char * = " ", int = 0, int = 0, 
				int = 100, int = 100);
};
#endif

// End of file.










