/* SCCS  @(#)nsl_streambuf_stream_library.h	1.1---95/08/13--23:38:36 */
//
// nsl_streambuf_stream_library.h
//
class nsl_streambuf;

extern 	nsl_streambuf& operator>>(nsl_streambuf&,char&);
extern 	nsl_streambuf& operator>>(nsl_streambuf&,char*); // str

extern 	nsl_streambuf& operator<<(nsl_streambuf&,char);
extern 	nsl_streambuf& operator<<(nsl_streambuf&,const char*); // str

