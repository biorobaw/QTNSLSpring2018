/* SCCS  %W%---%E%--%U% */
//
// 	xnsl_line.h
//

// regular line

#ifndef _XNSL_LINE_H
#define _XNSL_LINE_H
#include "xnsl_graph.h"
class xnsl_display_canvas;
class xnsl_line : public xnsl_widget_graph
{
	float _f0,_f1;
	int _dir_type; // 0 - slanted, 1 - horizontal, 2 - vertical
	int _line_type; // 0 - solid, 1 - broken
public:
	xnsl_line(xnsl_display_canvas* = 0,num_type = 0, num_type = 0);
	virtual ~xnsl_line();

	// set
	void set_f0(float s) { _f0 = s; }
	void set_f1(float s) { _f1 = s; }
	void set_dir_type(int i) { _dir_type = i; }
	void set_line_type(int i) { _line_type = i; }
	// get
	float get_f0() { return _f0; }
	float get_f1() { return _f1; }
	int get_dir_type() { return _dir_type; }
	int get_line_type() { return _line_type; }

       	virtual xnsl_widget *make_widget();

      	virtual int display();

    	virtual xnsl_widget *create_widget(const char* = "", xnsl_widget* = 0,
		int = 0, int = 0, int = 100, int = 100,
		int = 0, int = 0,int = 100, int = 100,
		int=10,int=10,const char* = "",const char* = "");
};
#endif
