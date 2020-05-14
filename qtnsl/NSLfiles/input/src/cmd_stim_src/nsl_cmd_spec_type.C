/**************************************************************/
/*                                                            */
/*                nsl_cmd_spec_type.C                         */
/*                                                            */
/**************************************************************/
#include "nsl_cmd_spec_type.h"
#include "nsl_stream.h"
#include "nsl_input.h"

nsl_cmd_spec_type::nsl_cmd_spec_type(const char* sname,spec_type_enum tn)
	: nsl_cmd_type("stim_type")
{
	set_spec_type(tn);
	set_name(sname);
}
nsl_cmd_spec_type::~nsl_cmd_spec_type()
{
}
int nsl_cmd_spec_type::init()
{
	return 2;
}
int nsl_cmd_spec_type::get(nsl_buffer& buf)
{
 	if (spec_type == NSL_CORNER)
		buf << "CORNER";
 	else
		buf << "CENTER";

	return 1;
}
int nsl_cmd_spec_type::update(nsl_cmd_type*)
{
	return 2;
}
int nsl_cmd_spec_type::set(nsl_interpreter& nsl)
{
	int fg=2;
	nsl_string str;

 	if (nsl.get_str_cnt() != 0)
	{
	    nsl >> str;

 	    if (strcmp(str,"CORNER") == 0 || strcmp(str,"corner") == 0)
	    {
		set_spec_type(NSL_CORNER);
 	    }
 	    else if (strcmp(str,"CENTER") == 0 || strcmp(str,"center") == 0)
	    {
		set_spec_type(NSL_CENTER);
 	    }
	}

	return fg;
}
int nsl_cmd_spec_type::print_cmd_spec_type(std::ostream& out) const
{
	print_base(out);

	if (spec_type == NSL_CORNER)
	{
		out << "// value:\t\tCORNER\n";
 	}
 	else if (spec_type == NSL_CENTER)
	{
		out << "// value:\t\tCENTER\n";
 	}
	out.flush();

	return 1;
}
int nsl_cmd_spec_type::print(std::ostream& out) const // virtual
{
	print_cmd_spec_type(out);
	return 1;
}
