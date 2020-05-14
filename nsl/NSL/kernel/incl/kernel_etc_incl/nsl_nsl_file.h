/* SCCS  @(#)nsl_nsl_file.h	1.1---95/08/13--23:36:39 */
/**************************************************************/
/*                                                            */
/*                       nsl_nsl_file.h 		      */
/*                                                            */
/**************************************************************/

#include "nsl_file.h"
#ifndef _NSL_NSL_FILE_H
#define _NSL_NSL_FILE_H
class nsl_nsl_file : public nsl_file
{
public:
		nsl_nsl_file(const char*);
		nsl_nsl_file(const int);
 		~nsl_nsl_file();

	int init_nsl_file();

	virtual nsl_file* create(const char*);

	int read_file();

	int print_nsl_file(std::ostream&) const;
	virtual int print(std::ostream&) const;
	int print_nsl_file_status(std::ostream&) const;
	virtual int print_status(std::ostream&) const;

	int 	write_nsl_file(nsl_buffer&);
	virtual int 	write(nsl_buffer&);
	int 	read_nsl_file(nsl_buffer&);
	virtual int 	read(nsl_buffer&);

	int 	write_nsl_file(nsl_model*);
	virtual int 	write(nsl_model*);
	int 	read_nsl_file(nsl_model*);
	virtual int 	read(nsl_model*);
};

#endif
