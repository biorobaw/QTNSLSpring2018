/* SCCS  @(#)nsl_module.C	1.3---95/10/03--14:17:26 */
//
//	nsl_module.C
//

//# include "../../../../MAIN/src/sys_main_src/nsl_all_kernel_include.h"

#include "nsl_model.h"
#include "nsl_kernel.h"

extern void cmd_error(const char *);
extern void cmd_out(const char *);
extern void cmd_out(const char *, const char *);
//extern void cmd_out(const char *, int);

/* SCCS  @(#)nsl_module.C	1.3---95/10/03--14:17:26 */
//
//	nsl_module.C
//

//# include "../../../../MAIN/src/sys_main_src/nsl_all_kernel_include.h"

#include "nsl_model.h"
#include "nsl_kernel.h"

extern void cmd_error(const char *);
extern void cmd_out(const char *);
extern void cmd_out(const char *, const char *);
//extern void cmd_out(const char *, int);

nsl_module::nsl_module() : nsl_public("module")
{
}

nsl_module::nsl_module(char* str,void (*f)(),int tfg,int fg)
{
	init_module(str,f,tfg,fg);
}
nsl_module::~nsl_module()
{
}

int nsl_module::init_module(char* str,void (*f)(),int tfg,int fg)
{
	set_name(str);
	set_type("module");
	set_base_type("module");

	if (tfg == -1)
		disable();
	else
		enable();

	set_time_fg(tfg);

	if (SYSTEM == NULL)
	{
		SYSTEM = new nsl_system;
		cmd_out("nsl_module:Initializing SYSTEM...");
	}

	if (f != NULL)
	{
		mod_func = f;

		if (fg == 1)
		{
		    //if ((m_parent = SYSTEM->get_model()) != NULL) //add_module doesnt exist -bn7
			//((nsl_model*) m_parent)->add_module(this);
		    //else
			cmd_error("NSL MODULE: Null Manager Parent");
		}
	}
	else
		cmd_error("nsl_module: Unknown module function");

	return 1;
}
void nsl_module::exec()
{
	if (get_verbose_fg() == 1)
		cmd_out("// executing module: ",get_name());
	mod_func();
}
void nsl_module::proc(const int time)
{
	int tfg = get_time_fg();

	if (get_able_fg() == 1)
	{
	    switch (tfg)
	    {
	    case 0: // module
		if (time >= 0)
		{
		   if (get_verbose_fg() == 1)
		   	cmd_out("// processing module: ",get_name());
		   mod_func();
		}
		break;
	    case 1: // init_module
		if (time == 0)
		{
/*		   if (get_verbose_fg() == 1)
			cmd_out("// processing module: ",get_name());
*/		   mod_func();
		}
		break;
	    case 2: // run_module
		if (time > 0)
		{
/*		   if (get_verbose_fg() == 1)
			cmd_out("// processing module: ",get_name());
*/		   mod_func();
		}
		break;
	    case 3: // sys_module
		if (time < 0)
		{
		   if (get_verbose_fg() == 1)
			cmd_out("// processing module: ",get_name());
		   mod_func();
		}
		break;
	    default: // -1,-2
		break;
 	    }
	}
}

// print 

int nsl_module::print_module_status(std::ostream& out) const
{
	print_base(out);

	if (get_time_fg() == 2)
	   out << "// RUN_MODULE:\tprocessing for t > 0\n";
	else if (get_time_fg() == 1)
	   out << "// INIT_MODULE\tprocessing for t = 0\n";
	else if (get_time_fg() == 0)
	   out << "// MODULE\tprocessing for t >= 0\n";
	else // if (get_time_fg() == -1)
	   out << "// FUNC_MODULE\tprocessing by explicit *exec* command\n";

	out.flush();

	return 1;
}
int nsl_module::print_status(std::ostream& out)  const // virtual
{
	print_module_status(out);
	return 1;
}
int nsl_module::print_module(std::ostream& out) const
{
	print_base(out);
	return 1;
}
int nsl_module::print(std::ostream& out) const // virtual
{
	print_module(out);
	return 1;
}

// print all

int nsl_module::print_module_all_status(std::ostream& out) const
{
	print_module_status(out);
	print_base_all_status(out);
	return 1;
}
int nsl_module::print_all_status(std::ostream& out)  const // virtual
{
	print_module_all_status(out);
	return 1;
}
int nsl_module::print_module_all(std::ostream& out) const
{
	print_module(out);
	print_base_all(out);
	return 1;
}
int nsl_module::print_all(std::ostream& out) const // virtual
{
	print_module_all(out);
	return 1;
}

// read, write

int nsl_module::write_module(nsl_buffer&)
{
	return 1;
}
int nsl_module::write(nsl_buffer& buf)
{
	write_module(buf);
	return 1;
}
int nsl_module::read_module(nsl_buffer&)
{
	return 1;
}
int nsl_module::read(nsl_buffer& buf)
{
	read_module(buf);
	return 1;
}

