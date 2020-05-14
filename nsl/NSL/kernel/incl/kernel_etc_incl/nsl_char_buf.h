/* SCCS  %W%---%E%--%U% */
/**************************************************************/
/*                                                            */
/*                       nsl_char_buf.h 		      */
/*                                                            */
/**************************************************************/

#ifndef _NSL_CHAR_BUF_H
#define _NSL_CHAR_BUF_H
#include "nsl_public.h"
class nsl_char_buf : public nsl_public
{
	char sbuf[NSL_STREAMBUF_SIZE];
public:
	nsl_char_buf();
	~nsl_char_buf();

	char* get_sbuf() { return sbuf; }
	char& operator[](int i)
	{
//	    if (i < NSL_STREAMBUF_SIZE-1)
		return (char&) sbuf[i];
	}
	char& elem(int i)
	{
//	    if (i < NSL_STREAMBUF_SIZE-1)
		return (char&) sbuf[i];
	}
};
#endif
