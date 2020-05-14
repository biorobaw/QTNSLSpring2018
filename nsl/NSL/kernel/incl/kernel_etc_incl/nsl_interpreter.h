/* SCCS  @(#)nsl_interpreter.h	1.1---95/08/13--23:36:39 */
/**************************************************************/
/*                                                            */
/*                       nsl_interpreter.h                    */
/*                                                            */
/**************************************************************/

#ifndef _NSL_INTERPRETER_H
#define _NSL_INTERPRETER_H
#include "nsl_public.h"
#include "nsl_buffer.h"
#include "nsl_base_stack.h"
#include "nsl_stream.h"
#include "nsl_char_buf.h"
#include <fstream>

#ifndef _NSL_SET
class nsl_buffer;
class nsl_base_stack;
typedef nsl_base_stack nsl_stack;
#endif
class nsl_interpreter : public nsl_public
{
private:
	int cmd_status;		// 1 - OK 0- quit
	int cmd_mode;		// 0 - read + discard
				// 1 - read + rewind
	nsl_buffer cmd_buffer;	// buffer for all input
	nsl_char_buf char_buffer;	// buffer for output
	file_enum in_type;	// CIN - cin, FIN - file
 
// new objects
	int object_total; 		// total number of objects
	nsl_list* object_list; 		// pointer to all objects

// input
	istream* in_stream;	// input stream
 
// in files
	nsl_stack in_file_stack;// input file stack
	nsl_file* in_file;	// input file 
 	on_off_enum in_file_able_fg; // ON - enabled, OFF - disabled

// out files
 	nsl_stack out_file_stack;    // pointer to open out file list
	nsl_file* out_file;
 	on_off_enum out_file_able_fg; // ON - enabled, OFF - disabled

// log files
 	nsl_stack log_file_stack;    	// pointer to open log file list
	nsl_file* log_file;		// cmd log file
 	on_off_enum log_file_able_fg; 	// ON - enabled, OFF - disabled

// status output
 	fstream log0;			// log for cmd output

// shell
	nsl_list* shell_list;	// shell command list
	int shell_fg;		// 0 - normal, 1 - first read in new shell
	int shell_index;	// 

public:
		nsl_interpreter();
		~nsl_interpreter();

	int init_interpreter();

// objects
	int 	get_object_total() { return object_total; }
	nsl_list* get_object_list() { return object_list; }

	int		add_object(nsl_base*);
	nsl_base*	get_object(const char*);	// name search
	nsl_base*	get_object(const int);		// index search

	void set_input_type(file_enum i) { in_type = i; }
	file_enum get_input_type() { return in_type; }

	void set_cmd_mode(int i) { cmd_mode = i; }
	int get_cmd_mode() { return cmd_mode; }

	nsl_buffer& get_buffer() { return cmd_buffer; }
	nsl_char_buf& get_char_buffer() { return char_buffer; }

// in file
	int push_input_file(nsl_file*);
	nsl_file* pop_input_file();

	void set_input_file(nsl_file* file) { in_file = file; }
	nsl_file* get_input_file() { return in_file; }

 	void 	set_input_able_fg(on_off_enum i) { in_file_able_fg = i; }
	on_off_enum	get_input_able_fg() const { return in_file_able_fg; }

	int 	in_enable() { return in_file_able_fg = NSL_ON; }
	int 	in_disable() { return in_file_able_fg = NSL_OFF; }

// output files
	int push_output_file(nsl_file*);
	nsl_file* pop_output_file();

	void set_output_file(nsl_file* file) { out_file = file; }
	nsl_file* get_output_file() { return out_file; }

 	void 	set_output_able_fg(on_off_enum i) { out_file_able_fg = i; }
	on_off_enum	get_output_able_fg() const { return out_file_able_fg; }

	int 	out_enable() { return out_file_able_fg = NSL_ON; }
	int 	out_disable() { return out_file_able_fg = NSL_OFF; }

// log files
	int push_log_file(nsl_file*);
	nsl_file* pop_log_file();

	void set_log_file(nsl_file* file) { log_file = file; }
	nsl_file* get_log_file() { return log_file; }

 	void 	set_log_able_fg(on_off_enum i) { log_file_able_fg = i; }
	on_off_enum	get_log_able_fg() const { return log_file_able_fg; }

	int 	log_enable() { return log_file_able_fg = NSL_ON; }
	int 	log_disable() { return log_file_able_fg = NSL_OFF; }

// log0
 	fstream&	get_log0() { return log0; }

// shell
//	void set_shell(nsl_shell* s) { shell = s; }
	void add_shell(nsl_shell*);

	nsl_list* get_shell_list() { return shell_list; }

	int get_str_cnt() { return cmd_buffer.get_str_cnt(); }
	int get_char_cnt() { return cmd_buffer.get_char_cnt(); }

	int get_line_fg() { return cmd_buffer.get_line_fg(); }
	void set_line_fg(int i) { cmd_buffer.set_line_fg(i); }

	int get_eof_fg() { return cmd_buffer.get_eof_fg(); }
	void set_eof_fg(int i) { cmd_buffer.set_eof_fg(i); }

	int putback(const char*,int = 0);

	int init_input(); 	// read cin/file
	int end_input();	// reset flags 

	int init();		// init shells
	int run();		// execute all input cmds
	int step();		// execute one input cmd
	int exec(char*);	// execute a command string

// print
	virtual int 	print(std::ostream&) const;
	int 	print_interpreter(std::ostream&) const;
	virtual int 	print_status(std::ostream&) const;
	int 	print_interpreter_status(std::ostream&) const;
};
#endif

