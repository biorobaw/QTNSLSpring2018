/* SCCS  @(#)nsl_base.C	1.1---95/10/13--16:36:56 */
//
// nsl_base.C
//

//# include "../../../../MAIN/src/sys_main_src/nsl_all_kernel_include.h"
#include "nsl_kernel.h"
#include "nsl_base.h"
#include "nsl_base_list.h"
#include "nsl_buffer.h"

extern int NSLoutput(const char* str);
extern int NSLoutput(const char* str,std::ostream& out);
extern int NSLoutput(const char* str1,const char* str2);

nsl_base::nsl_base(const char* str,int level)
{
	set_type(str);
	init_base(level);
}
nsl_base::nsl_base(int level)
{
	set_type("");
	init_base(level);
}
int nsl_base::init()
{
	return 1;
}
int nsl_base::init_base(int level)
{
	LEVEL = level;
//		i_parent_list = 0;
//		i_children_list = 0;
		m_parent = 0;

	if (level == 0)
		m_children_list = new nsl_base_list(level+1);
	else
		m_children_list = 0;
		
	set_name("");
	set_index(0);
	OBJ = 0;
	set_able_fg(NSL_ON); 
	set_file_able_fg(NSL_ON); 
	data_total = 0;
	data_list = 0;
 
 	set_verbose_fg(NSL_ON); 	// 1 - run verbose
	set_print_time_fg(NSL_ON);	// '1' - print time 
	set_time_fg(0); 	// 0 - all time, 1 - t = 0 only, 2 - t > 0 only
	set_flag(0);		// user defined
	set_status(1);	
	
	return 1;
}
nsl_base::~nsl_base()
{
}
void nsl_base::append_m_child(nsl_base* b)
{
	m_children_list->append(b);
}
void nsl_base::append_i_child(nsl_base* b)
{
	i_children_list->append(b);
}

// enable, disable

int nsl_base::enable_all()
{
	enable();
	if (m_children_list != NULL)
		m_children_list->enable_all();
	return get_able_fg();
}	
int nsl_base::disable_all()
{
	disable();
	if (m_children_list != NULL)
		m_children_list->disable_all();
	return get_able_fg();
}	

// data

int nsl_base::add_data(nsl_base* obj)
{
	if (obj != NULL) {
		obj->set_index(++data_total);
		if (data_list == NULL)
			data_list = new nsl_list("data");
		data_list->append(obj);
	} else
		cmd_error("nsl_base::add_data: NULL object");

	return data_total;
}
int nsl_base::set_data(const char* str,double val)
{
	NslFloat0* b;
	if ((b = (NslFloat0*) get_hier_object(str,this)) != NULL)
		b->set_value(val);

	return 1;
}
nsl_base* nsl_base::get_data()
{
	if (data_list == NULL)
		return 0;

	return data_list->get_by_index(1);
}
nsl_base* nsl_base::get_data(const int bindex)
{
	if (data_list == NULL)
		return 0;

	return data_list->get_by_index(bindex);
}
nsl_base* nsl_base::get_data(const char* bname)
{
	if (data_list == NULL)
		return 0;

	return data_list->get_by_name(bname);
}
nsl_base& nsl_base::getDataRef(const char* bname)
{
	if (data_list == NULL) {
		cmd_error("nsl_base::getDataRef: NULL data_list");
		exit(-1); // return *this;
	}

	return *(data_list->get_by_name(bname));
}
nsl_base* nsl_base::get_ip_data(const char* str,nsl_base* obj)
{
	nsl_base* data = 0;
	nsl_base_list* dlist = 0;

	if (obj == NULL)
		return NULL;

	if ((dlist = obj->get_data_list()) == NULL ||
		(data = dlist->get_by_name(str)) == NULL)
	{
		nsl_list* iplist = obj->get_i_parent_list();
		nsl_base* ipobj = 0;
		if (iplist == NULL)
			return NULL;
		iplist->wind_up(); // rewind parent list
		while ((ipobj = iplist->next()) != NULL)
		{
			if ((data = get_ip_data(str,ipobj)) != NULL)
				break;
		}
	}

	return data;
}

nsl_base* nsl_base::get_hier_object(const char* fullstr,nsl_base* base)
{
	nsl_string mname;
	const char *str,*pname;
	nsl_base *mbase = 0,*ret_base = 0;

	if (base == NULL)
		base = NSL_SYSTEM;

 	int mlen = strlen(fullstr); // full length

    if ((str = (char *) strchr(fullstr,'.')) != NULL)
	{
		pname = str + 1; 	// path after first model name
		int plen = strlen(str); // extra path length
		strncpy(mname,fullstr,mlen-plen); // model name
		mname[mlen-plen]='\0';
	}
	else
	{
		strcpy(mname,fullstr);
		pname = 0;
	}

	// look from SYSTEM or from current path if mname != "system"
	if (strcmp("system",mname) == 0)
		ret_base = get_hier_object(pname,0);
	else {
		nsl_list* mlist = base->get_m_children_list();
		// search all data and lists
		if (mlist != NULL) {
		    mlist->wind_up();
        	    while (mbase == 0 && (base = (nsl_base*) mlist->next()) != NULL)
         		if (strcmp(mname,base->get_name()) == 0)
                	   mbase = base;
       	    		else if (strcmp(base->get_type(),"list") == 0)
			   mbase = ((nsl_base_list*) base)->get_by_name(mname);
       	    		else if (strcmp(base->get_name(),"component") == 0)
			   mbase = get_hier_object(mname,base);
			else
			   mbase = NULL;
		}

		if (pname == NULL)
			ret_base = mbase;
		else if (mbase != NULL)
			ret_base = get_hier_object(pname,mbase);
		else
			ret_base = NULL;
	}

	return ret_base;
}

// file enable, file disable

int nsl_base::file_enable_all()
{
	file_enable();
	if (m_children_list != NULL)
		m_children_list->file_enable_all();
	return get_file_able_fg();
}	
int nsl_base::file_disable_all()
{
	file_disable();
	if (m_children_list != NULL)
		m_children_list->file_disable_all();
	return get_file_able_fg();
}	

// print 

int nsl_base::print_base() const
{
	NSLoutput("\nset ",get_abstract_type());
	NSLoutput(" name ", get_name());

 	return 1;
}
int nsl_base::nslPrint() const
{
	print_base();

 	return 1;
}
int nsl_base::print_base_status() const
{
	//NSLoutput("\n# name:\t\t",get_name());
	NSLoutput("\n# type:\t\t" ,get_type());
	NSLoutput("\n# base_type:\t\t",get_base_type());
	NSLoutput("\n# abstract_type:\t",get_abstract_type());
	//NSLoutput("\n# index:\t\t",get_index());
	NSLoutput("\n# able_fg:\t\t");
	if (get_able_fg() == 1)
		NSLoutput(" ON");
	else
		NSLoutput(" OFF");
	NSLoutput("\n# file_able_fg:\t");
	if (get_file_able_fg() == 1)
		NSLoutput(" ON");
	else
		NSLoutput(" OFF");

	return 1;
}
int nsl_base::nslStatus() const
{
	print_base_status();

 	return 1;
}

// print all

int nsl_base::print_base_all() const
{
	print_base();
	if (m_children_list != NULL)
	{
		//NSLoutput("\n# children: ");
		m_children_list->nslPrintAll();
	}
	return 1;
}
int nsl_base::nslPrintAll() const
{
	cmd_error("nsl_base: Nothing to print");
	return 1;
}
int nsl_base::print_base_all_status() const
{
	print_base_status();
	if (m_children_list != NULL)
	{
		//NSLoutput("\n# children: ");
		m_children_list->nslStatusAll();
	}
	return 1;
}
int nsl_base::nslStatusAll() const
{
	cmd_error("nsl_base: Nothing to print");
	return 1;
}

// std::ostream

int nsl_base::print_base(std::ostream& out) const
{
	out << "set " << get_abstract_type();
	out << " name " << get_name() << "\n";

 	return 1;
}
int nsl_base::print(std::ostream& out) const
{
	print_base(out);

 	return 1;
}

int nsl_base::print(std::fstream&) const
{
	return 1;
}

int nsl_base::print_base_status(std::ostream& out) const
{
 	out << "\n";
	out << "# name:\t\t" << get_name() << "\n";
	out << "# type:\t\t" << get_type() << "\n";
	out << "# base_type:\t\t" << get_base_type() << "\n";
	out << "# abstract_type:\t" << get_abstract_type() << "\n";
	out << "# index:\t\t" << get_index() << "\n";
	out << "# able_fg:\t\t";
	if (get_able_fg() == 1)
		out << "ON\n";
	else
		out << "OFF\n";
	out << "# file_able_fg:\t";
	if (get_file_able_fg() == 1)
		out << "ON\n";
	else
		out << "OFF\n";
	out.flush();

	return 1;
}
int nsl_base::print_status(std::ostream& out) const
{
	print_base_status(out);

 	return 1;
}

// print all

int nsl_base::print_base_all(std::ostream& out) const
{
	print_base(out);
	if (m_children_list != NULL)
	{
		cout << "// children: \n";
		m_children_list->print_all(out);
	}
	return 1;
}
int nsl_base::print_all(std::ostream&) const
{
	cmd_error("nsl_base: Nothing to print");
	return 1;
}
int nsl_base::print_base_all_status(std::ostream& out) const
{
	print_base_status(out);
	if (m_children_list != NULL)
	{
		cout << "// children: \n";
		m_children_list->print_all_status(out);
	}
	return 1;
}
int nsl_base::print_all_status(std::ostream&) const
{
	cmd_error("nsl_base: Nothing to print");
	return 1;
}

// reset

int nsl_base::reset_base(nsl_buffer*)
{
	return 1;
}
int nsl_base::reset(nsl_buffer* buf)
{
	reset_base(buf);
	return 1;
}

// read, write

int nsl_base::write_base(nsl_buffer&)
{
	return 1;
}
int nsl_base::write(nsl_buffer& buf)
{
	write_base(buf);
	return 1;
}
int nsl_base::read_base(nsl_buffer&)
{
	return 1;
}
int nsl_base::read(nsl_buffer& buf)
{
	read_base(buf);
	return 1;
}

// read, write

int nsl_base::write_base(nsl_char_buf&)
{
	return 1;
}
int nsl_base::write(nsl_char_buf& buf)
{
	write_base(buf);
	return 1;
}
int nsl_base::read_base(nsl_char_buf&)
{
	return 1;
}
int nsl_base::read(nsl_char_buf& buf)
{
	read_base(buf);
	return 1;
}

