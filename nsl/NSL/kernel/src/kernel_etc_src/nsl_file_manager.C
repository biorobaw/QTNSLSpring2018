/* SCCS  @(#)nsl_file_manager.C	1.1---95/08/13--19:20:54 */
/**************************************************************/
/*                                                            */
/*                       nsl_file_manager.C 		      */
/*                                                            */
/**************************************************************/
#include "nsl_kernel.h"
#include "nsl_file_manager.h"
#include "nsl_file.h"
#include "nsl_base.h"
#include "nsl_base_list.h"

typedef nsl_base_list nsl_list;

nsl_file_manager::nsl_file_manager() : nsl_public("file_manager")
{
	init_file_manager();
}
nsl_file_manager::~nsl_file_manager()
{
//	nsl_file* file;
	
//	file_list->wind_up();

//	while ((file = (nsl_file*) file_list->next()) != NULL)
//		delete file;

	delete file_list;
}

int nsl_file_manager::init_file_manager()
{
	set_base_type("file_manager");

 	file_total = 0;
	file_list = new nsl_list("file");

	m_children_list->append(file_list);

	return 1;
}
int nsl_file_manager::add_file(nsl_file* d)
{
	d->set_index(++file_total);
	file_list->append(d);
//	d->set_m_parent(this);

	return file_total;
}
nsl_file* nsl_file_manager::get_file(const char* str)
{
	if (file_list != NULL)
		return (nsl_file*) file_list->get_by_name(str);

	return 0;
}
nsl_file* nsl_file_manager::get_file(const int i)
{
	if (file_list != NULL)
		return (nsl_file*) file_list->get_by_index(i);

	return 0;
}
nsl_file* nsl_file_manager::delete_file(const int i)
{
	if (file_list != NULL)
		return (nsl_file*) file_list->delete_by_index(i);

	return 0;
}
nsl_file* nsl_file_manager::delete_file(const char* str)
{
	if (file_list != NULL)
		return  (nsl_file*) file_list->delete_by_name(str);

	return 0;
}

// print 

int nsl_file_manager::print_file_manager_status(std::ostream& out) const
{
	print_base(out);

	out << "\n// file_total:\t" << file_total;
	out.flush();

	return 1;
}
int nsl_file_manager::print_status(std::ostream& out)  const // virtual
{
	print_file_manager_status(out);
	return 1;
}
int nsl_file_manager::print_file_manager(std::ostream& out) const
{
	print_base(out);
	
	out << "\n// file_total:\t" << file_total;
	out.flush();

	return 1;
}
int nsl_file_manager::print(std::ostream& out) const // virtual
{
	print_file_manager(out);
	return 1;
}

// print all

int nsl_file_manager::print_file_manager_all_status(std::ostream& out) const
{
	print_file_manager_status(out);
 
	return 1;
}
int nsl_file_manager::print_all_status(std::ostream& out)  const // virtual
{
	print_file_manager_all_status(out);
	if (file_list != NULL)
		file_list->print_all_status(out);

	return 1;
}
int nsl_file_manager::print_file_manager_all(std::ostream& out) const
{
	print_file_manager(out);
 
	return 1;
}
int nsl_file_manager::print_all(std::ostream& out) const // virtual
{
	print_file_manager_all(out);
	if (file_list != NULL)
		file_list->print_all(out);

	return 1;
}

// read, write

int nsl_file_manager::write_file_manager(nsl_buffer&)
{
	return 1;
}
int nsl_file_manager::write(nsl_buffer& buf)
{
	write_file_manager(buf);
	return 1;
}
int nsl_file_manager::read_file_manager(nsl_buffer&)
{
	return 1;
}
int nsl_file_manager::read(nsl_buffer& buf)
{
	read_file_manager(buf);
	return 1;
}

