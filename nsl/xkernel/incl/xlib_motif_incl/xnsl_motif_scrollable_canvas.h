/* SCCS  @(#)xnsl_motif_scrollable_canvas.h	1.1---95/08/13--23:42:09 */
//////////////////////////////////////////////////////////////////////////
//
// xnsl_motif_scrollable_canvas.h: Creates the motif drawing area widget.
//               
/////////////////////////////////////////////////////////////////////////
#ifndef XNSL_MOTIF_SCROLLABLE_CANVAS_H
#define XNSL_MOTIF_SCROLLABLE_CANVAS_H
#include "xnsl_motif_canvas.h"
class xnsl_motif_scrollable_canvas : public xnsl_motif_canvas
{
   private:
      
   protected:

      // Nothing yet.

   public:

      xnsl_motif_scrollable_canvas() { }; //temp define -bn7
      virtual ~xnsl_motif_scrollable_canvas () { };

      virtual xnsl_widget* make_widget();

      virtual xnsl_widget *create_widget(const char* = "", 
		xnsl_widget* = 0,int = 0, int = 0,int = 100, int = 100,
		int = 10, int = 10,const char* = "", const char* = "");

      virtual void set_env(const char * = "", int = 0, int = 0, 
		int = 100, int = 100,int = 10, int = 10,
		const char* = "", const char* = "");

//     xnsl_widget *create_scrollable_canvas_widget(const char* = "", 
//		xnsl_widget* = 0,int = 0, int = 0,int = 100, int = 100);

//      void set_scrollable_canvas_env(const char * = " ", 
//		int = 20, int = 20, int = 100, int = 100);
};
#endif

// End of file.










