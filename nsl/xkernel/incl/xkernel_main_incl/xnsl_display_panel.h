/* SCCS  @(#)xnsl_display_panel.h	1.1---95/08/13--23:41:20 */
//
// 	xnsl_display_panel.h
//
#ifndef _XNSL_DISPLAY_PANEL_H
#define _XNSL_DISPLAY_PANEL_H
#include "xnsl_window.h"
class xnsl_display_panel : public xnsl_window
{
  	int item_x_loc, item_y_loc; 	// item location

public:
		xnsl_display_panel(xnsl_display_window*,char*);
		~xnsl_display_panel();

   	void	set_item_x_loc(int i) { item_x_loc = i; }
	int 	get_item_x_loc() { return item_x_loc; }
 
	void	set_item_y_loc(int i) { item_y_loc = i; }
	int 	get_item_y_loc() { return item_y_loc; }
 
// resize panel
	int	resize(int,int,int,int);
// reset
	virtual int 	reset(nsl_buffer* = (nsl_buffer*) 0);
// clear
	virtual int 	clear();
// init
	virtual int 	init();
// create
	int 	create();
	int	create(int,int,int,int);
// update 
	int 	update();
	int 	update(char*);
// display
	int	display();
	int	display(char*);
 
// read from database 
	int	read_from_database();
	int	write_to_database();
	int	read_from_database(char*);
	int	write_to_database(char*);

 // print items
	virtual int	print_status(std::ostream&) const;
	virtual int	print(std::ostream&) const;

 	int	print_display_panel_status(std::ostream&) const;
	int	print_display_panel(std::ostream&) const;

 	int	print_display_panel_status(std::ostream&,char*) const;
	int	print_display_panel_status(std::ostream&,int) const;
	int	print_display_panel(std::ostream&,char*) const;
	int	print_display_panel(std::ostream&,int) const;
};
#endif
/*
// sub panel

class xnsl_sub_panel : xnsl_window
{
protected:
	xnsl_panel* panel; // panel section
	int item_total;
	int item_x_loc,item_y_loc;
	int item0,item1;
public:
	xnsl_sub_panel();
	~xnsl_sub_panel();

	void	set_item_total(int i) { item_total = i; }
	int 	get_item_total() { return item_total; }

  	void	set_item_x_loc(int i) { item_x_loc = i; }
	int 	get_item_x_loc() { return item_x_loc; }
 
	void	set_item_y_loc(int i) { item_y_loc = i; }
	int 	get_item_y_loc() { return item_y_loc; }
 
	void	set_item0(int i) { item0 = i; }
	int 	get_item0() { return item0; }
 
	void	set_item1(int i) { item1 = i; }
	int 	get_item1() { return item1; }
 
	virtual void init_data();
	void init_sub_panel_data(xnsl_widget*,int=0,int=0);
};

class xnsl_top_panel : public xnsl_sub_panel
{
public:
	xnsl_top_panel();
	~xnsl_top_panel();

	virtual void init_data();
	void init_top_panel_data();
};

class xnsl_panel_data : public xnsl_sub_panel
{
public:
	xnsl_panel_data();
	~xnsl_panel_data();

	virtual void init_data();
	void init_panel_data();
};

class xnsl_panel_vector : public xnsl_panel_data
{
public:
	xnsl_panel_vector();
	~xnsl_panel_vector();

	virtual void init_data(int,int);
	void init_panel_vector();
};

class xnsl_panel_matrix : public xnsl_panel_vector
{
public:
	xnsl_panel_matrix();
	~xnsl_panel_matrix();

	virtual void init_data();
	void init_panel_matrix();
};

class xnsl_panel_area_level_graph : public xnsl_sub_panel
{
public:
	xnsl_panel_area_level_graph();
	~xnsl_panel_area_level_graph();

	virtual void init_data();
	void init_area_level_graph_data();
};

class xnsl_panel_spatial_graph_2 : public xnsl_sub_panel
{
public:
	xnsl_panel_spatial_graph_2();
	~xnsl_panel_spatial_graph_2();

	virtual void init_data();
	void init_spatial_graph_2_data();
};

class xnsl_panel_spatial_graph_3 : public xnsl_sub_panel
{
public:
	xnsl_panel_spatial_graph_3();
	~xnsl_panel_spatial_graph_3();

	virtual void init_data();
	void init_spatial_graph_3_data();
};

class xnsl_panel_temporal_graph : public xnsl_sub_panel
{
public:
	xnsl_panel_temporal_graph();
	~xnsl_panel_temporal_graph();

	virtual void init_data();
	void init_temporal_graph_data();
};

*/
