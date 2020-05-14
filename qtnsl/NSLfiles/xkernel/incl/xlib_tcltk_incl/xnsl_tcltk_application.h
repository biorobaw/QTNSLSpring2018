/* SCCS  @(#)xnsl_tcltk_application.h	1.1---95/08/13--23:41:52 */
//////////////////////////////////////////////////////////////////////////
//
// xnsl_tcltk_application.h: Class that initialises the Xview application.
//
//                           Also has the function which puts the
//                           program into the event loop.
//
//               
//////////////////////////////////////////////////////////////////////////
#ifndef XNSL_TCLTK_APPLICATION_H
#define XNSL_TCLTK_APPLICATION_H
#include "xnsl_tcltk_widget.h"
class xnsl_tcltk_application : public xnsl_tcltk_widget
{
   private:
	int	*_argc;     
	char	**_argv;
   protected:

      	// Nothing yet.

   public:

      	xnsl_tcltk_application();
       	virtual ~xnsl_tcltk_application();

	virtual xnsl_widget *make_widget();

    	virtual xnsl_widget *create_widget(const char* = "", xnsl_widget* = 0,
		int = 0, int = 0,int = 100, int = 100,
		int = 0, int = 0,int = 100, int = 100,
		int = 10, int = 10,const char* = "", const char* = "");

	virtual void set_env(const char * = "", 
		int = 0, int = 0, int = 100, int = 100,
		int = 0, int = 0, int = 100, int = 100,int = 10, int = 10,
		const char* = "", const char* = "") { }; //never defined -bn7

      	void  handle_events();

	int output(char*);
};
#endif

// End of file.








