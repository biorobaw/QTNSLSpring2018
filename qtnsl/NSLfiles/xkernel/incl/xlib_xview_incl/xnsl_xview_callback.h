/* SCCS  @(#)xnsl_xview_callback.h	1.1---95/08/13--23:44:21 */
 ///////////////////////////////////////////////////////////////////////////
//
// xnsl_xview_callback.h: Class that creates a xview push button widget.
//               
//////////////////////////////////////////////////////////////////////////
#ifndef XNSL_XVIEW_CALLBACK_H
#define XNSL_XVIEW_CALLBACK_H
#include "xnsl_xview_widget.h"
class xnsl_xview_callback : public xnsl_xview_widget
{
   private:
        void (*cback)(Panel_item, Event*);
    
   protected:

      // Nothing yet.

   public:

      xnsl_xview_callback(void(*)(Panel_item, Event *));
      virtual ~xnsl_xview_callback ();

//      set_xview_callback(void(*cb)(Panel_item, Event *)) { cback = cb; }

      virtual void exec();
};
#endif

// End of file.










