/* SCCS  @(#)xnsl_motif_panel_item.h	1.1---95/08/13--23:42:07 */
///////////////////////////////////////////////////////////////////////////
//
// xnsl_motif_panel_item.h: Class that creates a motif push button widget.
//               
//////////////////////////////////////////////////////////////////////////
#ifndef XNSL_MOTIF_PANEL_ITEM_H
#define XNSL_MOTIF_PANEL_ITEM_H
#include "xnsl_motif_panel_item.h"
class xnsl_motif_panel_item : public xnsl_motif_widget
{
   protected:
      
        char		*_value;
  	xnsl_callback	*_callback;
	char		*_bitmap;
	xnsl_widget	*_menu;

   public:

      xnsl_motif_panel_item() { } //-temp bn7
      virtual ~xnsl_motif_panel_item()  { };

      virtual xnsl_widget* make_widget();

      virtual xnsl_widget *create_widget(const char* = "", 
		xnsl_widget* = 0,int = 0, int = 0,int = 100, int = 100,
		int = 10, int = 10,const char* = "", const char* = "");

      virtual void set_env(const char * = "", int = 0, int = 0, 
		int = 100, int = 100,int = 10, int = 10,
		const char* = "", const char* = "");

      virtual int get_env(char *); 

      virtual void set_bitmap (const char *, int, int);
      virtual void set_callback (xnsl_callback*);
      virtual void set_menu (xnsl_widget * m);
      virtual void set_value (const char*);
};
#endif

// End of file.










