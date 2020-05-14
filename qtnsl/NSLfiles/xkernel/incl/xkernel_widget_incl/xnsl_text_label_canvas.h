/* SCCS  %W%---%E%--%U% */
////////////////////////////////////////////////////////////////////////
//
//xnsl_text_label_canvas.h:Class that creates a text_label_canvas widget.
//
////////////////////////////////////////////////////////////////////////

#ifndef _XNSL_TEXT_LABEL_CANVAS_H
#define _XNSL_TEXT_LABEL_CANVAS_H
#include "xnsl_graph.h"
class xnsl_display_canvas;
class xnsl_text_label_canvas : public xnsl_widget_graph
{
private:
protected:
	nsl_string _value;
 
public:

	xnsl_text_label_canvas(xnsl_display_canvas* = 0);
	virtual ~xnsl_text_label_canvas();

	void set_widget_value(const char* str) { strcpy(_value,str); }
	char* get_widget_value() { return _value; }

 	xnsl_widget    *make_widget();

	virtual int display();

	virtual int read_from_database();
	virtual int write_to_database();

  	virtual xnsl_widget  *create_widget(const char* = "", xnsl_widget* = 0, 
		int = 0, int = 0, int = 100, int = 100,
		int=0, int=0, int=100, int=100,int=10,int=10,
		const char* = "",const char* = "");

};
 
class xnsl_int_label_canvas : public xnsl_text_label_canvas
{
public:

	xnsl_int_label_canvas(xnsl_display_canvas* = 0);
	virtual ~xnsl_int_label_canvas();

 	xnsl_widget    *make_widget();

 	virtual int read_from_database();
	virtual int write_to_database();
};

class xnsl_num_label_canvas : public xnsl_text_label_canvas
{
public:

	xnsl_num_label_canvas(xnsl_display_canvas* = 0);
	virtual ~xnsl_num_label_canvas();

 	xnsl_widget    *make_widget();

 	virtual int read_from_database();
	virtual int write_to_database();
};

class xnsl_str_label_canvas : public xnsl_text_label_canvas
{
public:

	xnsl_str_label_canvas(xnsl_display_canvas* = 0);
	virtual ~xnsl_str_label_canvas();

 	xnsl_widget    *make_widget();

 	virtual int read_from_database();
	virtual int write_to_database();
};
#endif

