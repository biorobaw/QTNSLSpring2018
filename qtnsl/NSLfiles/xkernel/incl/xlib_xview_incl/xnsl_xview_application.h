/* SCCS  @(#)xnsl_xview_application.h	1.1---95/08/13--23:44:20 */
//////////////////////////////////////////////////////////////////////////
//
// xnsl_xview_application.h: Class that initialises the Xview application.
//
//                           Also has the function which puts the
//                           program into the event loop.
//
//               
//////////////////////////////////////////////////////////////////////////
#ifndef XNSL_XVIEW_APPLICATION_H
#define XNSL_XVIEW_APPLICATION_H
#include "xnsl_xview_widget.h"
class xnsl_xview_application : public xnsl_xview_widget
{
   private:
      Frame _frame;
   protected:

      	// Nothing yet.

   public:

      	xnsl_xview_application();
       	virtual ~xnsl_xview_application();

	Frame get_frame() { return _frame; }

	virtual xnsl_widget *make_widget();

    	virtual xnsl_widget *create_widget(const char* = "", 
		xnsl_widget* = 0,int = 0, int = 0,int = 100, int = 100,
		int = 10, int = 10);

    	xnsl_widget *create_application_widget(const char* = "", 
		xnsl_widget* = 0,int = 0, int = 0,int = 100, int = 100);

	virtual void set_env(const char * = "", int = 0, int = 0, 
				int = 100, int = 100, int = 10, int = 10);

	void set_application_env(const char * = " ", int = 0, int = 0, 
				int = 100, int = 100);

      	void          	handle_events();
};
#endif

// End of file.








