/* SCCS  @(#)nsl_base_list.h	1.1---95/08/13--23:36:35 */
//
//	nsl_base_list.h
//

#ifndef NSL_BASE_LIST_H
#define NSL_BASE_LIST_H
#include <iostream>


#include "nsl_base.h"
#include "nsl_base_list.h"
#include "nsl_base_node.h"
#include "nsl_public.h"

class nsl_base_list : public nsl_public
{
private:
	nsl_base_node *top;
	nsl_base_node *cur;
	nsl_base_node *bot;
protected:
	int total;
public:
	nsl_base_list(const int = 0);
	nsl_base_list(const char*,int = 0);
	~nsl_base_list();
	
	int init_base_list(const char*);

	int get_total() 	{ return total; }

	int insert(nsl_base*);		// insert after current element
	int append(nsl_base*);		// append to end

	int clear();			// clear all elements
	int clear(const int,const int);	// clear partial elements
	int clear_cur();		// delete current element

	nsl_base* delete_by_index(const int);
	nsl_base* delete_by_name(const char*);

	nsl_base* return_cur();		// return current element (pop)

	void wind(const int);		// go to the node from top
	void wind_up() 	 	{ cur = top; }
	void wind_down() 	{ cur = bot; }

	nsl_base* next(); // returns current and then goes to next
	nsl_base* prev(); // returns current and then goes to prev

	nsl_base* get_next(); // get next element
	nsl_base* get_prev(); // get prev element

	nsl_base* get_top() const	{ return top->ptr; }	// get top
	nsl_base* get_bot() const	{ return bot->ptr; }	// get bottom

	nsl_base* get_curr();
	nsl_base* get();

	nsl_base* get_by_index(const int);
	nsl_base* get_by_name(const char*);
	nsl_base* get_by_type(const char*);

	nsl_base* get_by_type_and_name(const char*,const char*);
	nsl_base* get_by_type_and_index(const char*,const int);

	nsl_base* get_i_by_index(const int);
	nsl_base* get_i_by_name(const char*);
	nsl_base* get_i_by_type(const char*);

	nsl_base* get_i_by_type_and_name(const char*,const char*);
	nsl_base* get_i_by_type_and_index(const char*,const int);

	nsl_base* get_m_by_index(const int);
	nsl_base* get_m_by_name(const char*);
	nsl_base* get_m_by_type(const char*);

	nsl_base* get_m_by_type_and_name(const char*,const char*);
	nsl_base* get_m_by_type_and_index(const char*,const int);

	nsl_base* get_mi_by_index(const int);
	nsl_base* get_mi_by_name(const char*);
	nsl_base* get_mi_by_type(const char*);

	nsl_base* get_mi_by_type_and_name(const char*,const char*);
	nsl_base* get_mi_by_type_and_index(const char*,const int);

	int enable_all();
	int disable_all();

	int print_base_list(std::ostream&) const;	// print top list
	virtual int print(std::ostream&) const;	// print virtual list
	int print_base_list_all(std::ostream&) const; // print top list
	virtual int print_all(std::ostream&) const;	// print virtual list
	int print_by_name(std::ostream&,char*);	// print by name
	int print_by_index(std::ostream&,int);	// print by index

	int print_base_list_status(std::ostream&) const;	// print top list
	virtual int print_status(std::ostream&) const;	// print virtual list
	int print_base_list_all_status(std::ostream&) const;	// print top list
	virtual int print_all_status(std::ostream&) const;	// print virtual list
	int print_status_by_name(std::ostream&,char*);	// print by name
	int print_status_by_index(std::ostream&,int);	// print by index

	int 	write_base_list(nsl_buffer&);
	virtual int 	write(nsl_buffer&);
	int 	read_base_list(nsl_buffer&);
	virtual int 	read(nsl_buffer&);
};
#endif
