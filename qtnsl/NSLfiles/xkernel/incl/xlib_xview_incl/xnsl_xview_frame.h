/* SCCS  @(#)xnsl_xview_frame.h	1.1---95/08/13--23:44:24 */
////////////////////////////////////////////////////////////////////////
//
// xnsl_xview_frame.h: Class that creates a xview bulletin board widget.
//               
////////////////////////////////////////////////////////////////////////
#ifndef XNSL_XVIEW_FRAME_H
#define XNSL_XVIEW_FRAME_H
#include "xnsl_xview_widget.h"
class xnsl_xview_frame : public xnsl_xview_widget
{
   private:

	Frame _frame;
   protected:

      // Nothing yet.      

   public:

      xnsl_xview_frame  ();

      virtual ~xnsl_xview_frame ();

	Frame get_frame() { return _frame; }

      virtual xnsl_widget *create_widget(const char* = "", 
		xnsl_widget* = 0,int = 0, int = 0,int = 100, int = 100,
		int = 10, int = 10);

      xnsl_widget* create_frame_widget(const char* = "", 
		xnsl_widget* = 0,int = 0, int = 0,int = 100, int = 100);

      virtual xnsl_widget* make_widget();

      virtual void set_env(const char * = "", int = 0, int = 0, 
			int = 100, int = 100, int = 10, int = 10);

      void set_frame_env(const char * = "", 
			int=0, int=0, int=100, int=100);
};
#endif

// End of file.
