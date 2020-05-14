/* SCCS  @(#)xnsl_application.h	1.1---95/08/13--23:43:06 */
/////////////////////////////////////////////////////////////////////////
//
// xnsl_application.h:
//               
/////////////////////////////////////////////////////////////////////////

#ifndef _XNSL_APPLICATION_H
#define _XNSL_APPLICATION_H
#include "xnsl_widget.h"
class xnsl_application : public xnsl_widget
{
   private:

      // Nothing yet      

   protected:
     
      // Nothing yet

   public:

      xnsl_application();
      virtual ~xnsl_application();

	virtual xnsl_widget  *make_widget();

  	virtual xnsl_widget  *create_widget(const char* = "", xnsl_widget* = 0, 
		int = 0, int = 0, int = 100, int = 100,
		int=0, int=0, int=100, int=100,int=10,int=10,
		const char* = "",const char* = "");
        virtual void set_env(const char* = "", int = 0, int = 0,
		int = 100, int = 100, int=0,int=0,int=100,int=100,
		int=10,int=10,const char* = "",const char* = "") { }; //never defined -bn7

      virtual void handle_events();

	int output(char*);
};
#endif
