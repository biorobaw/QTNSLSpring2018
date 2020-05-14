/* SCCS  @(#)nsl_base.h	1.1---95/08/13--23:36:35 */
//
//	nsl_base.h
//

#ifndef _NSL_BASE_H
#define _NSL_BASE_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include "../nsl.h"

//function forward declarations
void cmd_error(const char *);
void cmd_error(const char *, const char *);
void cmd_error(const char *, int);
void cmd_out(const char *);
void cmd_out(int);
//---------------------
class nsl_public;
class nsl_char_buf;
class nsl_base
{
private:
// base
	int LEVEL; // used to break base lists infinite instanatiation recursion
	int index;
	nsl_string name;
	nsl_string type; 
	nsl_string base_type;
	nsl_string abstract_type;
	int type_id;
	on_off_enum able_fg; 		// ON - enabled, OFF - disabled
	on_off_enum file_able_fg; 	// ON - enabled, OFF - disabled

	on_off_enum verbose_fg; 	// ON - run verbose
	on_off_enum print_time_fg;	// ON - print time 
	int time_fg; // 0 - all time, 1 - t = 0 only, 2 - t > 0 only
	int flag;	// user defined
	int status;
	
	friend class nsl_base_list;

protected:
	static nsl_system* SYSTEM;
	nsl_base* 	OBJ;
	static nsl_public* SYS_INTERFACE; // interface pointer for display
	static nsl_public* ASL_SYS; // asl pointer
	static nsl_interpreter* INTERPRETER;

// inheritance information
	nsl_base_list* 		i_parent_list;
	nsl_base_list* 		i_children_list;

// management information
	nsl_base* 		m_parent;
	nsl_base_list* 		m_children_list;

	nsl_base_list* 		data_list; // multi-purpose, mainly atttributes
	int data_total;

	nsl_base(const char*,int = 0);
	nsl_base(int = 0);
	virtual ~nsl_base();

public:
// set flags
	virtual void 	set_all_verbose_fg(on_off_enum) {}
	void 	set_verbose_fg(on_off_enum i) { verbose_fg = i; }
	void 	set_print_time_fg(on_off_enum i) { print_time_fg = i; }
	void 	set_time_fg(int i) { time_fg = i; }
	void	set_flag(int i) { flag = i; }
	void	set_status(int i) { status = i; }
// get flags
	on_off_enum  	get_verbose_fg() const { return verbose_fg; }
	on_off_enum 	get_print_time_fg() const { return print_time_fg; }
	int 	get_time_fg() const { return time_fg; }
	int 	get_flag() const { return flag; }
	int 	get_status() const { return status; }

	int get_type_id() { return type_id; }
	void set_type_id(int fg) { type_id = fg; }

	void set_ptr(nsl_base* b) { OBJ = b; }
	nsl_base* get_ptr() { return OBJ; }

//	void set_system(nsl_system* b) { SYSTEM = b; }
//	nsl_system* get_system() { return SYSTEM; }

	void	set_asl_system(nsl_public* b) { ASL_SYS = b; }
	nsl_public* get_asl_system() { return ASL_SYS; }

	void	set_system_interface(nsl_public* b) { SYS_INTERFACE = b; }
	nsl_public* get_system_interface() { return SYS_INTERFACE; }

	void set_interpreter(nsl_interpreter* b) { INTERPRETER = b; }
	nsl_interpreter* get_interpreter() { return INTERPRETER; }

	nsl_base_list* get_i_parent_list() const { return i_parent_list; }
	nsl_base_list* get_i_children_list() const { return i_children_list; }

	nsl_base* get_m_parent() const { return m_parent; }
	nsl_base_list* get_m_children_list() const { return m_children_list; }

	nsl_base_list* get_data_list() const { return data_list; }
	int get_data_total() { return data_total; }

	int add_data(nsl_base*); // add also index

	int set_data(const char*,double);

	nsl_base* get_data();
	nsl_base* get_data(const int);
	nsl_base* get_data(const char*);
	
	nsl_base& getDataRef(const char*);

	nsl_base* get_ip_data(const char*,nsl_base* = NULL); // get data from i_parent
	nsl_base* get_hier_object(const char*,nsl_base* = NULL); // get any object from hierarchy

	void append_m_child(nsl_base*);
	void append_i_child(nsl_base*);
	
	void set_m_parent(nsl_base* m) { m_parent = m; }

	void set_index(int i) { index = i; }
	int get_index() const { return index; }

	void set_name(const char* str) { strcpy(name,str); }
	const char* get_name() const { return name; }

	void set_type(const char* str) { strcpy(type,str); }
	const char* get_type() const { return type; }

	void set_base_type(const char* str) { strcpy(base_type,str); }
	const char* get_base_type() const { return base_type; }

	void set_abstract_type(const char* str) { strcpy(abstract_type,str); }
	const char* get_abstract_type() const { return abstract_type; }

// enable, disable
	void 	set_able_fg(on_off_enum i) { able_fg = i; }
	on_off_enum	get_able_fg() const { return able_fg; }

	int 	enable() { return able_fg = NSL_ON; }
	int 	disable() { return able_fg = NSL_OFF; }

	int 	enable_all();
	int 	disable_all();
// file enable, file disable
	void 	set_file_able_fg(on_off_enum i) { file_able_fg = i; }
	on_off_enum	get_file_able_fg() const { return file_able_fg; }

	int 	file_enable() { return file_able_fg = NSL_ON; }
	int 	file_disable() { return file_able_fg = NSL_OFF; }

	int 	file_enable_all();
	int 	file_disable_all();
// init
	virtual int init();
	int init_base(int);

// print
	int print_base() const;
	virtual int nslPrint() const;
	int print_base_status() const;
	virtual int nslStatus() const;

	int print_base_all() const;
	virtual int nslPrintAll() const;
	int print_base_all_status() const;
	virtual int nslStatusAll() const;

	int print_base(std::ostream&) const;
	virtual int print(std::ostream&) const;
	int print(std::fstream&) const;
	int print_base_status(std::ostream&) const;
	virtual int print_status(std::ostream&) const;

	int print_base_all(std::ostream&) const;
	virtual int print_all(std::ostream&) const;
	int print_base_all_status(std::ostream&) const;
	virtual int print_all_status(std::ostream&) const;

	int 	write_base(nsl_char_buf&);
	virtual int 	write(nsl_char_buf&);
	int 	read_base(nsl_char_buf&);
	virtual int 	read(nsl_char_buf&);

	int 	write_base(nsl_buffer&);
	virtual int 	write(nsl_buffer&);
	int 	read_base(nsl_buffer&);
	virtual int 	read(nsl_buffer&);

	int 	reset_base(nsl_buffer* = 0);
	virtual int 	reset(nsl_buffer* = 0);
};
#endif
