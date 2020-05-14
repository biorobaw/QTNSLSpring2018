/* SCCS  %W%---%E%--%U% */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_buf.h                            */
/*                                                            */
/**************************************************************/

// the next entry serves multiple purposes
// - contains a list of pointers for each "current" object in the interpreter
// - buffers for updating and creating new objects of the same type
// - a hierarchical tree of one object per class structure

#ifndef _NSL_CMD_BUF_H
#define _NSL_CMD_BUF_H

#include "nsl_shell.h"
class nsl_cmd_buf : public nsl_shell
{
protected:
	nsl_list* macro_list; // macros
	int macro_total;

	nsl_list* cmd_list; // first level
	int cmd_total;

	nsl_list* type_list; // second level
	int type_total;
public:
		nsl_cmd_buf();
		~nsl_cmd_buf();

	int get_macro_total() { return macro_total; }
	nsl_list* get_macro_list() { return macro_list; }

	int get_cmd_total() { return cmd_total; }
	nsl_list* get_cmd_list() { return cmd_list; }

	int get_type_total() { return type_total; }
	nsl_list* get_type_list() { return type_list; }

// process
	int init();
	int run(nsl_interpreter*);

// macro list: 
	int add_macro(nsl_cmd_macro*);
// cmd list: create, etc.
	int add_cmd(nsl_cmd_exec*);
	int add_cmd_children(nsl_cmd_exec*,const char*);
	nsl_cmd_exec* get_cmd(const int);
	nsl_cmd_exec* get_cmd(const char*);
// type list: layer, etc.
	int add_type(nsl_cmd_type*);
	int add_type_m_parent(nsl_cmd_type*,const char*);
	int add_type_m_children(nsl_cmd_type*,const char*);
	int add_type_i_parent(nsl_cmd_type*,const char*);
	int add_type_i_children(nsl_cmd_type*,const char*);
	nsl_cmd_type* get_type_cmd(const int);
	nsl_cmd_type* get_type_cmd(const char*);

// print
	int print_type(std::ostream&);
	int print_cmd(std::ostream&);

	virtual int print_cmd_buf(std::ostream&) const;
	virtual int print(std::ostream&) const;
};
#endif
