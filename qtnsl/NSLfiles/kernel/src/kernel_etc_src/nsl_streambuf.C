/* SCCS  @(#)nsl_streambuf.C	1.1---95/10/13--16:37:08 */
/**************************************************************/
/*                                                            */
/*                       nsl_streambuf.C 		      */
/*                                                            */
/**************************************************************/

#include "nsl_streambuf.h"
#include "nsl_char_buf.h"
#include "nsl_base_list.h"

nsl_streambuf::nsl_streambuf() 
{
	sbuf_list = new nsl_list;

	mode = 0; // retrieve

	char_cnt = 0;
	str_cnt = 0;

	top_index = 0;
	bot_index = 0;

	top_sbuf = append();
	bot_sbuf = top_sbuf;

	top_sbuf->elem(0) = '\0';
}
nsl_streambuf::~nsl_streambuf()
{
}
nsl_char_buf* nsl_streambuf::append()
{
	nsl_char_buf* sbuf = new nsl_char_buf;
	sbuf_list->append(sbuf);

	return sbuf;
}
nsl_char_buf* nsl_streambuf::insert()  
{
 	nsl_char_buf* sbuf;
	if ((sbuf = (nsl_char_buf*) sbuf_list->get_prev()) != NULL)
		sbuf_list->prev(); // move one down
	else
	{
		sbuf = new nsl_char_buf;
		sbuf_list->insert(sbuf);
	}

	return sbuf;
}
void nsl_streambuf::reset_stream()
{
	rewind_stream();
	reset_all_cnt();	
}
void nsl_streambuf::rewind_stream()
{
}

void nsl_streambuf::reset_rewind_marker()
{
	prev_top_index = top_index;
	prev_char_cnt = char_cnt;
	prev_str_cnt = str_cnt;
}
void nsl_streambuf::reset_read_marker()
{
	top_index = prev_top_index;
	char_cnt = prev_char_cnt;
	str_cnt = prev_str_cnt;
}

// get char

int nsl_streambuf::get(char& c)
{
	int bstatus = 0;

	if (top_index > NSL_STREAMBUF_SIZE-1)
	{
		top_index = 0;
		// split "next" computation in two lines
		sbuf_list->next();
		top_sbuf = (nsl_char_buf*) sbuf_list->get_curr();
 	}	

	if (char_cnt < 0 || top_sbuf == NULL ||
		(top_sbuf == bot_sbuf && top_index > bot_index))
	{
		cmd_error("TRYING TO READ FROM EMPTY BUFFER");
		top_sbuf = bot_sbuf;
		top_index = bot_index;
		bstatus = -1;
	}
	else
	{
		c = top_sbuf->elem(top_index++);
		char_cnt--;
	}

	return bstatus;
}

// put char

int nsl_streambuf::put(const char& c)
{
	int bstatus = 0;

// only add buffers (currently no reuse)
	if (bot_index > NSL_STREAMBUF_SIZE-1)
	{
		bot_index = 0;
		bot_sbuf = append();
	}

	bot_sbuf->elem(bot_index++) = c; 
	char_cnt++;

	return bstatus;
}

// putback char

int nsl_streambuf::putback(const char& c)
{
	int bstatus = 0;
	static int str_fg = 0;

// create new buffer and set pointer for decreasing followingly
// only add buffers (currently no reuse)
	if (top_index <= 0)
	{
		top_index = NSL_STREAMBUF_SIZE;
 		top_sbuf = insert();
 	}

	top_sbuf->elem(--top_index) = c; // decrease point and then add char
	char_cnt++;
	// compute str_cnt according to number of strings putback
	if (str_fg == 0 && (c != ' ' && c != '\t' && c != '\0'))
	{
		str_cnt++;
		str_fg = 1;
	}
	else if (str_fg == 1 && (c == ' ' || c == '\t' || c == '\0'))
		str_fg = 0;

	return bstatus;
}
int nsl_streambuf::putback(const char* str)
{
	putback('\0');
	for (int i=strlen(str)-1; i >= 0 ; i--) // putback in reverse order
		putback(str[i]);

	return 1;
}
int nsl_streambuf::print_status(std::ostream& out) const
{
	print_base(out);
	out << "\n";
	out << "// str_cnt " << str_cnt << endl;
	out << "// char_cnt " << char_cnt << endl;
	out << endl;
	for (int i=top_index; i <= bot_index; i++)
		out << top_sbuf->elem(i);
	out << endl;

	out.flush();

	return 1;
}

