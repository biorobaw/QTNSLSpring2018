/**************************************************************/
/*                                                            */
/*                   nsl_cmd_spec_type.h                      */
/*                                                            */
/**************************************************************/

#ifndef _NSL_CMD_SPEC_TYPE_H
#define _NSL_CMD_SPEC_TYPE_H
#include "nsl_cmd_type.h"

#ifndef _NSL_SET
class nsl_buffer;
class nsl_interpreter;
#endif

class nsl_cmd_spec_type : public nsl_cmd_type
{
protected:
	spec_type_enum spec_type;
public:
		nsl_cmd_spec_type(const char*,spec_type_enum = NSL_CORNER);
		~nsl_cmd_spec_type();

	virtual int init();
	virtual int set(nsl_interpreter&);
	virtual int get(nsl_buffer&);
 	virtual int update(nsl_cmd_type*);

	void	set_spec_type(spec_type_enum ft) {  spec_type = ft; }
	spec_type_enum get_spec_type() { return spec_type; }

	int print_cmd_spec_type(std::ostream&) const;
	virtual int print(std::ostream&) const;
};




#endif
