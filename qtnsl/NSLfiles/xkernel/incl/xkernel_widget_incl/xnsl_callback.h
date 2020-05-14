/* SCCS  %W%---%E%--%U% */
/////////////////////////////////////////////////////////////////////////
//
// xnsl_callback.h: Class that acts as a superclass for all callbacks
//               
/////////////////////////////////////////////////////////////////////////
#ifndef XNSL_CALLBACK_H
#define XNSL_CALLBACK_H

class xnsl_callback 
{
   private:

      // Nothing yet      

   protected:
     
      // Nothing yet

   public:

      xnsl_callback  ();
      virtual ~xnsl_callback ();

      virtual void exec (void *, void *);
};
#endif

// End of file.
