/* SCCS  @(#)xnsl_xview_cmd_message.h	1.1---95/08/13--23:44:23 */
//////////////////////////////////////////////////////////////////////////
//
// xnsl_xview_cmd_message.h:  Class that creates a xview label widget
//               
/////////////////////////////////////////////////////////////////////////
#ifndef XNSL_XVIEW_CMD_MESSAGE_H
#define XNSL_XVIEW_CMD_MESSAGE_H
#include "xnsl_xview_widget.h"
class xnsl_xview_cmd_message : public xnsl_xview_widget
{
   private:
  
   protected:

      // Nothing yet.

   public:

      xnsl_xview_cmd_message  ();
      virtual  ~xnsl_xview_cmd_message ();

      virtual xnsl_widget* make_widget();

      virtual xnsl_widget *create_widget(const char* = "", 
		xnsl_widget* = 0,int = 0, int = 0,int = 100, int = 100,
		int = 10, int = 10);

      virtual void set_env(const char* = "", int = 0, int = 0, 
				int = 100, int = 100, int = 10, int = 10);

      xnsl_widget* create_cmd_message_widget(const char* = "",
		xnsl_widget* = 0, int=0,int=0,int=100,int=100);

      void set_cmd_message_env (const char* = "", int=0,int=0,int=100,int=100);
};
#endif

// End of file.
