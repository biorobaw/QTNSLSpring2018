/**************************************************************/
/*                                                            */
/*                nsl_cmd_stim_type.C                         */
/*                                                            */
/**************************************************************/
#include "nsl_input.h"
#include "nsl_cmd_stim_type.h"
#include "nsl_interpreter.h"


nsl_cmd_stim_type::nsl_cmd_stim_type(const char* sname,stim_type_enum tn)
	: nsl_cmd_type("stim_type")
{
	set_stim_type(tn);
	set_name(sname);
}
nsl_cmd_stim_type::~nsl_cmd_stim_type()
{
}
int nsl_cmd_stim_type::init()
{
	return 2;
}
int nsl_cmd_stim_type::get(nsl_buffer& buf)
{
 	if (stim_type == NSL_BLOCK)
		buf << "BLOCK";
 	else
		buf << "ICON";

	return 1;
}
int nsl_cmd_stim_type::update(nsl_cmd_type*)
{
	return 2;
}
int nsl_cmd_stim_type::set(nsl_interpreter& nsl)
{
	int fg=2;
	nsl_string str;

 	if (nsl.get_str_cnt() != 0)
	{
	    nsl >> str;

 	    if (strcmp(str,"BLOCK") == 0 || strcmp(str,"block") == 0)
	    {
		set_stim_type(NSL_BLOCK);
 	    }
 	    else if (strcmp(str,"ICON") == 0 || strcmp(str,"icon") == 0)
	    {
		set_stim_type(NSL_ICON);
 	    }
	}

	return fg;
}
int nsl_cmd_stim_type::print_cmd_stim_type(std::ostream& out) const
{
	print_base(out);

	if (stim_type == NSL_BLOCK)
	{
		out << "// value:\t\tBLOCK\n";
 	}
 	else if (stim_type == NSL_ICON)
	{
		out << "// value:\t\tICON\n";
 	}
	out.flush();

	return 1;
}
int nsl_cmd_stim_type::print(std::ostream& out) const // virtual
{
	print_cmd_stim_type(out);
	return 1;
}
