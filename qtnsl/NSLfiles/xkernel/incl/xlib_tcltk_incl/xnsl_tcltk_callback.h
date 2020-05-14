/* SCCS  @(#)xnsl_tcltk_callback.h	1.1---95/08/13--23:41:53 */
 ///////////////////////////////////////////////////////////////////////////
//
// xnsl_tcltk_callback.h: Class that creates a tcltk push button widget.
//               
//////////////////////////////////////////////////////////////////////////
#ifndef XNSL_TCLTK_CALLBACK_H
#define XNSL_TCLTK_CALLBACK_H
#include "xnsl_tcltk_widget.h"
class xnsl_tcltk_callback : public xnsl_tcltk_widget
{
   private:
//        void (*cback)(Panel_item, XEvent*);
    
   protected:

      // Nothing yet.

   public:

//      xnsl_tcltk_callback(void(*)(Panel_item, XEvent *));
      virtual ~xnsl_tcltk_callback ();

//      set_tcltk_callback(void(*cb)(Panel_item, XEvent *)) { cback = cb; }

      virtual void exec();
};
#endif

// End of file.










