/* SCCS  %W%---%E%--%U% */
////////////////////////////////////////////////////////////////////////
//
//xnsl_cmd_message.h:Class that creates a generic message widget.
//
////////////////////////////////////////////////////////////////////////
#ifndef XNSL_CMD_MESSAGE_H
#define XNSL_CMD_MESSAGE_H

/////////////////////////////////////////////////////////////////////////
//
//Class defintion
//
/////////////////////////////////////////////////////////////////////////
#include "xnsl_widget.h"
class xnsl_cmd_message:public xnsl_widget
{
private:

protected:
	//Nothing yet.

public:

	xnsl_cmd_message();
	virtual ~xnsl_cmd_message();

	virtual xnsl_widget  *make_widget();

  	virtual xnsl_widget  *create_widget(const char* = "", xnsl_widget* = 0, 
		int = 0, int = 0, int = 100, int = 100,
		int=0, int=0, int=100, int=100,int=10,int=10,
		const char* = "",const char* = "");
        virtual void set_env(const char* = "", int = 0, int = 0,
		int = 100, int = 100, int=0, int=0, int=100, int=100,
		int=10,int=10,const char* = "",const char* = "") { }; //never defined -bn7
};
#endif

//End of file.
