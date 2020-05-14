/* SCCS  %W%---%E%--%U% */
/**************************************************************/
/*                                                            */
/*                       nsl_buffer.C 		              */
/*                                                            */
/**************************************************************/
#include "nsl_kernel.h"
#include "nsl_buffer.h"

nsl_buffer::nsl_buffer() 
{
}
nsl_buffer::~nsl_buffer()
{
}
void nsl_buffer::reset_stream()
{
	rewind_stream();
}
void nsl_buffer::rewind_stream()
{
//	sb->seekpos(streampos(0));
//	sb->seekoff(0,ios::beg,ios::in);
}
void nsl_buffer::putback(const char* str)
{
	cmd_stream.putback(str);
}
int nsl_buffer::print_status(std::ostream& out) const
{
	return cmd_stream.print_status(out);
}

