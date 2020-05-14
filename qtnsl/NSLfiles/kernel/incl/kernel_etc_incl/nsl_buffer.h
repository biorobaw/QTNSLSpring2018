/* SCCS  @(#)nsl_buffer.h	1.1---95/08/13--23:36:36 */
/*                                                            */
/*                       nsl_buffer.h 		              */
/*                                                            */
/**************************************************************/

//static char SccsId[] = "@(#)nsl_buffer.h	1.1  8/13/95"; /* SCCS */

#ifndef _NSL_BUFFER_H
#define _NSL_BUFFER_H
#include "nsl_public.h"
#include "nsl_streambuf.h"

#ifndef _NSL_SET
class nsl_streambuf;
#endif

class nsl_buffer : public nsl_public
{
//	int status;		// 0: no chars, 1: chars in buffer
	int eof_fg;		// -1: EOF, 0: OK, 
//	int line;		// line number
	int line_fg;		// 0: same line, 1: new line
	int error_fg;		// 0: OK, 1: error
	nsl_streambuf cmd_stream;	// NSL string stream
	int macro_str_cnt;	// macro string number in buffer
				// used for computing log output

public:
		nsl_buffer();
		~nsl_buffer();

//	int get_status() { return status; }
//	void set_status(int i) { status = i; }

	int get_state() { return cmd_stream.get_state(); }
	void set_state(int i) { cmd_stream.set_state(i); }

	int get_eof_fg() { return eof_fg; }
	void set_eof_fg(int i) { eof_fg = i; }

	int get_line_fg() { return line_fg; }
	void set_line_fg(int i) { line_fg = i; }

	int get_error_fg() { return error_fg; }
	void set_error_fg(int i) { error_fg = i; }

	void reset_stream();
	void rewind_stream();
	void putback(const char* );

	int get_rewind_marker() { return cmd_stream.get_rewind_marker(); }
	void reset_rewind_marker() { cmd_stream.reset_rewind_marker(); }
	void reset_read_marker() { cmd_stream.reset_read_marker(); }

	nsl_streambuf& get_stream() { return cmd_stream; }
	int get_str_cnt() { return cmd_stream.get_str_cnt(); }
	int get_char_cnt() { return cmd_stream.get_char_cnt(); }

	void set_macro_str_cnt(int n) { macro_str_cnt = n; }
	int get_macro_str_cnt() { return macro_str_cnt; }

	int print_status(ostream&) const;
};
#endif
