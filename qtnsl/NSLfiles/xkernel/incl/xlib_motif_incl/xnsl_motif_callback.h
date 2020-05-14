/* SCCS  @(#)xnsl_motif_callback.h	1.1---95/08/13--23:41:53 */
 ///////////////////////////////////////////////////////////////////////////
//
// xnsl_motif_callback.h: Class that creates a motif push button widget.
//               
//////////////////////////////////////////////////////////////////////////
#ifndef XNSL_MOTIF_CALLBACK_H
#define XNSL_MOTIF_CALLBACK_H
#include "xnsl_motif_widget.h"
class xnsl_motif_callback : public xnsl_motif_widget
{
   private:
//        void (*cback)(Panel_item, XEvent*);
    
   protected:

      // Nothing yet.

   public:

//      xnsl_motif_callback(void(*)(Panel_item, XEvent *));
      virtual ~xnsl_motif_callback ();

//      set_motif_callback(void(*cb)(Panel_item, XEvent *)) { cback = cb; }

      virtual void exec();
};
#endif

// End of file.










