/* SCCS  %W%---%E%--%U% */
//
// nsl_streambuf_stream_library.C
//
#include "nsl_streambuf.h"

// operators

// << char >>

nsl_streambuf& operator>>(nsl_streambuf& buf,char& c)
{
	buf.get(c);

	return buf;
}
nsl_streambuf& operator<<(nsl_streambuf& buf,char c)
{
	buf.put(c); 

	return buf;
}

// << string >>

nsl_streambuf& operator<<(nsl_streambuf& buf,const char* str)
{
	int i = 0;

	int len = strlen(str);

	while (i <= len)
		buf << str[i++];

	if (len > 0)
		buf.incr_str_cnt();
		
	return buf;
}
nsl_streambuf& operator>>(nsl_streambuf& buf,char* str)
{
	int start_char_cnt = buf.get_char_cnt(); // initial char count

	char c = 0;
	int i = 0;

	buf >> c;
	while (c != '\0' && c != ' ' && c != '\t')
	{
		str[i++] = c;
		buf >> c;
	}
	str[i] = '\0'; // finish string

	int mode = buf.get_mode();
	if (i > 0)
	{
	    if (mode == 0) // retrieve 
		buf.decr_str_cnt();
	    else if (mode == 1) // keep old count 
		buf.set_char_cnt(start_char_cnt);
	}

	return buf;
}

