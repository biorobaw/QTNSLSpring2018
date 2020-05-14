/* SCCS  %W%---%E%--%U% */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_macro.h                          */
/*                                                            */
/**************************************************************/

#ifndef _NSL_CMD_MACRO_H
#define _NSL_CMD_MACRO_H
#include <iostream>
#include "nsl_public.h"
class nsl_cmd_macro : public nsl_public
{
	int str_cnt;
public:
		nsl_cmd_macro(const char*,const int = 0);
		nsl_cmd_macro(const char*,const char*,const int = 0);
		nsl_cmd_macro();
		~nsl_cmd_macro();

	int	get_str_cnt() { return str_cnt; }
	void 	set_str_cnt(const int n) { str_cnt = n; }

		int exec(nsl_interpreter&);

	virtual int print_cmd_macro(std::ostream&) const;
	virtual int print(std::ostream&) const;
};


#endif
