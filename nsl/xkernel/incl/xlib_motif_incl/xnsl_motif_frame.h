/* SCCS  @(#)xnsl_motif_frame.h	1.1---95/08/13--23:42:04 */
////////////////////////////////////////////////////////////////////////
//
// xnsl_motif_frame.h: Class that creates a motif bulletin board widget.
//               
////////////////////////////////////////////////////////////////////////
#ifndef XNSL_MOTIF_FRAME_H
#define XNSL_MOTIF_FRAME_H
#include "xnsl_motif_widget.h"
class xnsl_motif_frame : public xnsl_motif_widget
{
   private:

	// Nothing yet.
   protected:

      // Nothing yet.      

   public:

      xnsl_motif_frame() { }; //temp define -bn7

      virtual ~xnsl_motif_frame () { };

      virtual xnsl_widget *create_widget(const char* = "", 
		xnsl_widget* = 0,int = 0, int = 0,int = 100, int = 100,
		int = 10, int = 10,const char* = "", const char* = "");

//      xnsl_widget* create_frame_widget(const char* = "", 
//		xnsl_widget* = 0,int = 0, int = 0,int = 100, int = 100);

      virtual xnsl_widget* make_widget();

      virtual void set_env(const char * = "", int = 0, int = 0, 
		int = 100, int = 100,int = 10, int = 10,
		const char* = "", const char* = "");

//      void set_frame_env(const char * = "", 
//		int=20, int=20, int=100, int=100);
};
#endif

// End of file.
