/* SCCS  @(#)xnsl_tcltk_cmd_message.h	1.1---95/08/13--23:42:03 */
//////////////////////////////////////////////////////////////////////////
//
// xnsl_tcltk_cmd_message.h:  Class that creates a tcltk label widget
//               
/////////////////////////////////////////////////////////////////////////
#ifndef XNSL_TCLTK_CMD_MESSAGE_H
#define XNSL_TCLTK_CMD_MESSAGE_H
#include "xnsl_tcltk_widget.h"
class xnsl_tcltk_cmd_message : public xnsl_tcltk_widget
{
   private:
  
   protected:

      // Nothing yet.

   public:

      xnsl_tcltk_cmd_message  ();
      virtual  ~xnsl_tcltk_cmd_message ();

      virtual xnsl_widget* make_widget();

      virtual xnsl_widget *create_widget(const char* = "", xnsl_widget* = 0,
		int = 0, int = 0,int = 100, int = 100,
		int = 0, int = 0,int = 100, int = 100,
		int = 10, int = 10,const char* = "", const char* = "");

      virtual void set_env(const char * = "", 
		int = 0, int = 0,int = 100, int = 100,
		int = 0, int = 0, int = 100, int = 100,int = 10, int = 10,
		const char* = "", const char* = "") { }; //never defined -bn7
 
      virtual void set_message (const char* = "");
};
#endif

// End of file.
