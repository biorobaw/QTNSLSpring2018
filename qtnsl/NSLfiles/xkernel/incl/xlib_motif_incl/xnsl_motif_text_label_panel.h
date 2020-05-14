/* SCCS  @(#)xnsl_motif_text_label_panel.h	1.1---95/08/13--23:42:10 */
//////////////////////////////////////////////////////////////////////////
//
// xnsl_motif_text_label_panel.h:  Class that creates a motif label widget
//               
/////////////////////////////////////////////////////////////////////////
#ifndef XNSL_MOTIF_TEXT_LABEL_PANEL_H
#define XNSL_MOTIF_TEXT_LABEL_PANEL_H
#include "xnsl_motif_panel_item.h"
class xnsl_motif_text_label_panel : public xnsl_motif_panel_item
{
   private:
       
   protected:

      // Nothing yet.

   public:

      xnsl_motif_text_label_panel()  { }; //temp define -bn7
      virtual  ~xnsl_motif_text_label_panel () { };

      virtual xnsl_widget* make_widget();

      virtual xnsl_widget *create_widget(const char* = "", 
		xnsl_widget* = 0,int = 0, int = 0,int = 100, int = 100,
		int = 10, int = 10,const char* = "", const char* = "");

      virtual void set_env(const char * = "", int = 0, int = 0, 
		int = 100, int = 100,int = 10, int = 10,
		const char* = "", const char* = "");

      virtual int get_env(char*);
};
#endif

// End of file.
