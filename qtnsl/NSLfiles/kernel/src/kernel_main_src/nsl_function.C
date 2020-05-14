#include "nsl_function.h"

extern void cmd_out(const char *, const char *);

nsl_function::nsl_function() : nsl_public("function")
{
}
nsl_function::nsl_function(char* str,void (*f)(),int tfg,int fg)
{
	init_function(str,f,tfg,fg);
}
nsl_function::~nsl_function()
{
}

int nsl_function::init_function(char* str,void (*f)(),int tfg,int fg)
{
	set_name(str);
	set_type("function");
	set_base_type("function");

	if (tfg == -1)
		disable();
	else
		enable();

	set_time_fg(tfg);

/*	if (SYSTEM == NULL)
	{
		SYSTEM = new nsl_system;
		cmd_out("nsl_function:Initializing SYSTEM...");
	}
*/
	if (f != NULL)
	{
		mod_func = f;

		if (fg == 1)
		{
/*AW99		    if ((m_parent = SYSTEM->get_model()) != NULL)
			((nsl_model*) m_parent)->add_function(this);
		    else
*/			cmd_error("nsl_function: Null Manager Parent");
		}
	}
	else
		cmd_error("nsl_function: Unknown function function");

	return 1;
}
void nsl_function::exec()
{
	if (get_verbose_fg() == 1)
		cmd_out("// executing function: ",get_name());
	mod_func();
}
void nsl_function::proc(const int time)
{
	int tfg = get_time_fg();

	if (get_able_fg() == 1)
	{
	    switch (tfg)
	    {
	    case 0: // function
		if (time >= 0)
		{
		   if (get_verbose_fg() == 1)
		   	cmd_out("// processing function: ",get_name());
		   mod_func();
		}
		break;
	    case 1: // init_function
		if (time == 0)
		{
/*		   if (get_verbose_fg() == 1)
			cmd_out("// processing function: ",get_name());
*/		   mod_func();
		}
		break;
	    case 2: // run_function
		if (time > 0)
		{
/*		   if (get_verbose_fg() == 1)
			cmd_out("// processing function: ",get_name());
*/		   mod_func();
		}
		break;
	    case 3: // sys_function
		if (time < 0)
		{
		   if (get_verbose_fg() == 1)
			cmd_out("// processing function: ",get_name());
		   mod_func();
		}
		break;
	    default: // -1,-2
		break;
 	    }
	}
}

// print

int nsl_function::print_function_status(ostream& out) const
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
int nsl_function::print_status(ostream& out)  const // virtual
{
	print_function_status(out);
	return 1;
}
int nsl_function::print_function(ostream& out) const
{
	print_base(out);
	return 1;
}
int nsl_function::print(ostream& out) const // virtual
{
	print_function(out);
	return 1;
}

// print all

int nsl_function::print_function_all_status(ostream& out) const
{
	print_function_status(out);
	print_base_all_status(out);
	return 1;
}
int nsl_function::print_all_status(ostream& out)  const // virtual
{
	print_function_all_status(out);
	return 1;
}
int nsl_function::print_function_all(ostream& out) const
{
	print_function(out);
	print_base_all(out);
	return 1;
}
int nsl_function::print_all(ostream& out) const // virtual
{
	print_function_all(out);
	return 1;
}

// read, write

int nsl_function::write_function(nsl_buffer&)
{
	return 1;
}
int nsl_function::write(nsl_buffer& buf)
{
	write_function(buf);
	return 1;
}
int nsl_function::read_function(nsl_buffer&)
{
	return 1;
}
int nsl_function::read(nsl_buffer& buf)
{
	read_function(buf);
	return 1;
}
