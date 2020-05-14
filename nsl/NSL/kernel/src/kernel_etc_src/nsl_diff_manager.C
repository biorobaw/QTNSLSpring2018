/* SCCS  %W%---%E%--%U% */
/**************************************************************/
/*                                                            */
/*                       nsl_diff_manager.C 		      */
/*                                                            */
/**************************************************************/
#include "nsl_kernel.h"
#include "nsl_diff_manager.h"
#include "nsl_diff.h"
#include "nsl_buffer.h"
#include "nsl_base_list.h"

typedef nsl_base_list nsl_list;

nsl_diff_manager::nsl_diff_manager(const char* mname,nsl_base* parent) :
	nsl_public("diff_manager")
{
	set_name(mname);
	set_base_type("diff_manager");

	init_diff_manager(parent);
}
nsl_diff_manager::~nsl_diff_manager()
{
}

int nsl_diff_manager::init_diff_manager(nsl_base* parent)
{
	m_parent = parent;

	set_new_fg(NSL_ON);  // new method
	dt = 0.1;
	set_method("euler");

	diff_total = 0;
	diff_list = new nsl_list("diff");

	m_children_list->append(diff_list);

	return 1;
}
int nsl_diff_manager::add_diff(nsl_diff* d)
{
	d->set_index(++diff_total);
	diff_list->append(d);
//	d->set_m_parent(this);

	return diff_total;
}
int nsl_diff_manager::update_all_diff()
{
	if (diff_list != NULL)
	{
		diff_list->wind_up();
		nsl_diff* d;
		while (d = (nsl_diff*) diff_list->next())
			d->set_update_fg(NSL_ON);
	}

	return 1;
}

// print 

int nsl_diff_manager::print_diff_manager_status(std::ostream& out) const
{
//	print_base(out);

	out << "\n";
	out << "set diff delta\t\t" << dt << "\n";
	out << "set diff integration\t" << method << "\n";

	out.flush();

	return 1;
}
int nsl_diff_manager::print_status(std::ostream& out)  const // virtual
{
	print_diff_manager_status(out);
	return 1;
}
int nsl_diff_manager::print_diff_manager(std::ostream& out) const
{
//	print_base(out);

	print_diff_manager_status(out);

	return 1;
}
int nsl_diff_manager::print(std::ostream& out) const // virtual
{
	print_diff_manager(out);
	return 1;
}

// print all

int nsl_diff_manager::print_diff_manager_all_status(std::ostream& out) const
{
	print_diff_manager_status(out);
	print_base_all_status(out);
	return 1;
}
int nsl_diff_manager::print_all_status(std::ostream& out)  const // virtual
{
	print_diff_manager_all_status(out);
	return 1;
}
int nsl_diff_manager::print_diff_manager_all(std::ostream& out) const
{
	print_diff_manager(out);
	print_base_all(out);
	return 1;
}
int nsl_diff_manager::print_all(std::ostream& out) const // virtual
{
	print_diff_manager_all(out);
	return 1;
}

// read, write

int nsl_diff_manager::write_diff_manager(nsl_buffer&)
{
	return 1;
}
int nsl_diff_manager::write(nsl_buffer& buf)
{
	write_diff_manager(buf);
	return 1;
}
int nsl_diff_manager::read_diff_manager(nsl_buffer&)
{
	return 1;
}
int nsl_diff_manager::read(nsl_buffer& buf)
{
	read_diff_manager(buf);
	return 1;
}

