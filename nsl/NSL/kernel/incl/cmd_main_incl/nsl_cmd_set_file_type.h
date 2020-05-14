/* SCCS  %W%---%E%--%U% */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_set_file_type.h                  */
/*                                                            */
/**************************************************************/

#ifndef _NSL_CMD_SET_FILE_TYPE_H
#define _NSL_CMD_SET_FILE_TYPE_H
#include "nsl_cmd_set.h"
class nsl_cmd_set_file_type : public nsl_cmd_set
{
protected:
	in_out_enum file_type;
public:
		nsl_cmd_set_file_type(const char*,in_out_enum = NSL_OUTPUT);
		~nsl_cmd_set_file_type();

	virtual int init();
	virtual int set(nsl_interpreter&);
	virtual int get(nsl_buffer&);
 	virtual int update(nsl_cmd_type*);

	void	set_file_type(in_out_enum ft) {  file_type = ft; }
	in_out_enum get_file_type() { return file_type; }

	int print_cmd_set_file_type(std::ostream&) const;
	virtual int print(std::ostream&) const;
};
#endif

