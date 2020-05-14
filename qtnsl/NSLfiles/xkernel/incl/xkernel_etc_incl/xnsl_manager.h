/* SCCS  %W%---%E%--%U% */
////////////////////////////////////////////////////////////////////////
//
// xnsl_manager.h: Base class for all managers
//               
////////////////////////////////////////////////////////////////////////
#ifndef XNSL_MANAGER_H
#define XNSL_MANAGER_H
#include "xnsl_widget.h"
class nsl_base_list;
typedef nsl_base_list nsl_list;
class xnsl_manager : public xnsl_widget
{
   private:
      nsl_list* widget_list;
      nsl_list* lib_widget_list;
   protected:

   public:

      xnsl_manager  ();
      virtual ~xnsl_manager ();
      
      virtual xnsl_widget *make_widget();

      virtual xnsl_widget *create_widget(const char* = "", xnsl_widget* = 0,
		int = 0, int = 0, int = 100, int =100,
		int = 0,int = 0,int = 100,int = 100,int=10,int=10,
		const char* = "",const char* = "");

      xnsl_widget *create_manager_widget(const char* = "",
		xnsl_widget* = 0,const char* = "",
		int = 0, int = 0, int = 100, int = 100,
		int=0,int=0,int=100,int=100,int=10,int=10,
		const char* = "",const char* = "");

      void add_manager_widget (xnsl_widget* = 0);
      xnsl_widget *get_manager_widget(const char* = "");

      void add_manager_lib_widget (xnsl_lib_widget* = 0);
      xnsl_lib_widget *get_manager_lib_widget(const char* = "");
};
#endif

// End of file.

