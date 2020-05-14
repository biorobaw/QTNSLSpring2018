/* SCCS  @(#)nsl_file_manager.h	1.1---95/08/13--23:36:38 */
/**************************************************************/
/*                                                            */
/*                       nsl_file_manager.h 		      */
/*                                                            */
/**************************************************************/

#ifndef _NSL_FILE_MANAGER_H
#define _NSL_FILE_MANAGER_H
#include "nsl_public.h"

#ifndef _NSL_SET
class nsl_buffer;
#endif

class nsl_file_manager : public nsl_public
{
private:
 	int file_total;		// total number file
	nsl_list* file_list;	// file list
 
public:
		nsl_file_manager();
		~nsl_file_manager();

	int	init_file_manager();

	int 	get_file_total() { return file_total; }
	nsl_list* get_file_list() { return file_list; }
	
	int	add_file(nsl_file*);
	nsl_file* get_file(const char*);
	nsl_file* get_file(const int);

	nsl_file* delete_file(const char*);
	nsl_file* delete_file(const int);

// print
 	virtual int 	print(std::ostream&) const;
	int 	print_file_manager(std::ostream&) const;
	virtual int 	print_status(std::ostream&) const;
	int 	print_file_manager_status(std::ostream&) const;

	virtual int 	print_all(std::ostream&) const;
	int 	print_file_manager_all(std::ostream&) const;
	virtual int 	print_all_status(std::ostream&) const;
	int 	print_file_manager_all_status(std::ostream&) const;

	int 	write_file_manager(nsl_buffer&);
	virtual int 	write(nsl_buffer&);
	int 	read_file_manager(nsl_buffer&);
	virtual int 	read(nsl_buffer&);
};

#endif
