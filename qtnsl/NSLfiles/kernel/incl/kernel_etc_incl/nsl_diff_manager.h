/* SCCS  @(#)nsl_diff_manager.h	1.1---95/08/13--23:36:37 */
/**************************************************************/
/*                                                            */
/*                       nsl_diff_manager.h 		      */
/*                                                            */
/**************************************************************/

#ifndef _NSL_DIFF_MANAGER_H
#define _NSL_DIFF_MANAGER_H
#include "nsl_public.h"
class nsl_diff_manager : public nsl_public
{
private:
	on_off_enum new_fg;	// ON - new method

	int diff_total;		// total number diff eq.
	nsl_list* diff_list;	// diff eq. list
protected:
	num_type dt;		// time step
	nsl_string method;	// method name
public:
		nsl_diff_manager(const char*,nsl_base*);
		~nsl_diff_manager();

	int	init_diff_manager(nsl_base*);

	int 	get_diff_total() { return diff_total; }
	nsl_list* get_diff_list() { return diff_list; }
	
	int	add_diff(nsl_diff*);
	int	update_all_diff();

	void 	set_dt(num_type f) { dt = f; }
	void 	set_delta(num_type f) { dt = f; }
	void	set_method(const char* m) { strcpy(method,m); }
 	void	set_new_fg(on_off_enum i) { new_fg = i; } 

	num_type get_dt() { return dt; }
	num_type get_delta() { return dt; }
	const char* get_method() { return method; }
 	on_off_enum	get_new_fg() const { return new_fg; }

// print
 	virtual int 	print(std::ostream&) const;
	int 	print_diff_manager(std::ostream&) const;
	virtual int 	print_status(std::ostream&) const;
	int 	print_diff_manager_status(std::ostream&) const;

	virtual int 	print_all(std::ostream&) const;
	int 	print_diff_manager_all(std::ostream&) const;
	virtual int 	print_all_status(std::ostream&) const;
	int 	print_diff_manager_all_status(std::ostream&) const;

	int 	write_diff_manager(nsl_buffer&);
	virtual int 	write(nsl_buffer&);
	int 	read_diff_manager(nsl_buffer&);
	virtual int 	read(nsl_buffer&);
};
#endif
