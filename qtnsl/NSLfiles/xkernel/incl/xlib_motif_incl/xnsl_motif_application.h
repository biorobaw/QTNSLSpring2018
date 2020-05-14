/* SCCS  @(#)xnsl_motif_application.h	1.1---95/08/13--23:41:52 */
//////////////////////////////////////////////////////////////////////////
//
// xnsl_motif_application.h: Class that initialises the Xview application.
//
//                           Also has the function which puts the
//                           program into the event loop.
//
//               
//////////////////////////////////////////////////////////////////////////
#ifndef XNSL_MOTIF_APPLICATION_H
#define XNSL_MOTIF_APPLICATION_H
#include "xnsl_motif_widget.h"
class xnsl_motif_application : public xnsl_motif_widget
{
   private:
	int	*_argc;     
	char	**_argv;
	//XtAppContext _context;
   protected:

      	// Nothing yet.

   public:

      	xnsl_motif_application() { };	//temp defining these -bn7
       	virtual ~xnsl_motif_application() { };

	virtual xnsl_widget *make_widget();

    	virtual xnsl_widget *create_widget(const char* = "", 
		xnsl_widget* = 0,int = 0, int = 0,int = 100, int = 100,
		int = 10, int = 10,const char* = "", const char* = "");

//    	xnsl_widget *create_application_widget(const char* = "", 
//		xnsl_widget* = 0,int = 0, int = 0,int = 100, int = 100);

	virtual void set_env(const char * = "", int = 0, int = 0, 
		int = 100, int = 100,int = 10, int = 10,
		const char* = "", const char* = "");

//	void set_application_env(const char * = "", int = 0, int = 0, 
//		int = 100, int = 100);

      	void  handle_events();

	int output(char*);
};
#endif

// End of file.








