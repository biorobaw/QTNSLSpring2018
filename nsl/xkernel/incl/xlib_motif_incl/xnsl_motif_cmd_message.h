/* SCCS  @(#)xnsl_motif_cmd_message.h	1.1---95/08/13--23:42:03 */
//////////////////////////////////////////////////////////////////////////
//
// xnsl_motif_cmd_message.h:  Class that creates a motif label widget
//               
/////////////////////////////////////////////////////////////////////////
#ifndef XNSL_MOTIF_CMD_MESSAGE_H
#define XNSL_MOTIF_CMD_MESSAGE_H
#include "xnsl_motif_widget.h"
class xnsl_motif_cmd_message : public xnsl_motif_widget
{
   private:
  
   protected:

      // Nothing yet.

   public:

      xnsl_motif_cmd_message  ();
      virtual  ~xnsl_motif_cmd_message ();

      virtual xnsl_widget* make_widget();

      virtual xnsl_widget *create_widget(const char* = "", 
		xnsl_widget* = 0,int = 0, int = 0,int = 100, int = 100,
		int = 10, int = 10,const char* = "", const char* = "");

      virtual void set_env(const char * = "", int = 0, int = 0, 
		int = 100, int = 100,int = 10, int = 10,
		const char* = "", const char* = "");

//      xnsl_widget* create_cmd_message_widget(const char* = "",
//		xnsl_widget* = 0, int=0,int=0,int=100,int=100);

//      void set_cmd_message_env (const char* = "", 
//		int=0,int=0,int=100,int=100);
    
      virtual void set_message (const char* = "");
};
#endif

// End of file.
