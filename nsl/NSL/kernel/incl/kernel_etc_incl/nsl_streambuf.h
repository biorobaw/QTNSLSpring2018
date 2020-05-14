/* SCCS  @(#)nsl_streambuf.h	1.2---95/10/30--16:01:11 */
/**************************************************************/
/*                                                            */
/*                       nsl_streambuf.h 		      */
/*                                                            */
/**************************************************************/

//	list->top--------bottom
//	       insert	   append
//
//		-- <index> ++
//
#ifndef _NSL_STREAMBUF_H
#define _NSL_STREAMBUF_H
#include "nsl_public.h"

#ifndef _NSL_SET
class nsl_char_buf;

#endif

class nsl_streambuf : public nsl_public
{
//	int status;		// 0: OK, -1: EOF
	nsl_list* sbuf_list;	// list of buffers
	nsl_char_buf* top_sbuf;	// holds top buffer 
	nsl_char_buf* bot_sbuf;	// holds bottom buffer 
	int top_index;		// buffer top char pointer
	int bot_index;		// buffer bottom char pointer
	int prev_top_index;	// buffer prev top char pointer
	int prev_char_cnt;	// buffer prev top char pointer
	int prev_str_cnt;	// buffer prev top char pointer
	int char_cnt;		// total char count
	int str_cnt;		// total string count
	int error_fg;		// 0 - error; 1 - OK
	int mode;		// 0 - retrieve, 1 - copy
	int state;		// 0 - str value, 1 - layer value

public:
		nsl_streambuf();
		~nsl_streambuf();

	nsl_char_buf* append();
	nsl_char_buf* insert();

	int get(char&);
	int put(const char&);
	int putback(const char&);
	int putback(const char*);

	int get_mode() { return mode; }
	void set_mode(int i) { mode = i; }

	int get_state() { return state; }
	void set_state(int i) { state = i; }

	void set_error_fg(int i) { error_fg = i; }
	int  get_error_fg() { return error_fg; }

	void reset_stream();
	void rewind_stream();

	void reset_all_cnt()
	{ str_cnt = 0; char_cnt = 0; }

	int get_rewind_marker() { return prev_top_index; }
	void reset_rewind_marker();
	void reset_read_marker();

	int get_str_cnt() { return str_cnt; }
	void reset_str_cnt() { str_cnt = 0; }
	void set_str_cnt(int i) { str_cnt = i; }
	int incr_str_cnt() { return ++str_cnt; }
	int decr_str_cnt() { return --str_cnt; }
	int incr_str_cnt(int i) { return (str_cnt += i); }
	int decr_str_cnt(int i) { return (str_cnt -= i); }

	int get_char_cnt() { return char_cnt; }
	void reset_char_cnt() { char_cnt = 0; }
	void set_char_cnt(int i) { char_cnt = i; }
	int incr_char_cnt() { return ++char_cnt; }
	int decr_char_cnt() { return --char_cnt; }
	int incr_char_cnt(int i) { return (char_cnt += i); }
	int decr_char_cnt(int i) { return (char_cnt -= i); }

	int print_status(std::ostream&) const;
};

#endif
