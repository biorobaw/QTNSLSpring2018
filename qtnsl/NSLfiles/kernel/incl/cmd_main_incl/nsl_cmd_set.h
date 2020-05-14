/* SCCS  %W%---%E%--%U% */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_set.h                     	      */
/*                                                            */
/**************************************************************/

#ifndef _NSL_CMD_SET_H
#define _NSL_CMD_SET_H
#include "nsl_public.h"
class nsl_cmd_set : public nsl_public
{
protected:
	nsl_layer* LOBJ;
	on_off_enum UPDATE_FG; 	// ON - update set value to system obj
	on_off_enum INIT_FG; 	// 1 - update set value from system obj

		nsl_cmd_set(const char*) {};	//NEVER DEFINED -bn7
		nsl_cmd_set() {};
		~nsl_cmd_set() {};

public:
	nsl_layer*	get_lobj() { return LOBJ; }
	on_off_enum	get_update_fg() { return UPDATE_FG; }
	on_off_enum	get_init_fg() { return INIT_FG; }

	void 	set_lobj(nsl_layer* l) { LOBJ = l; }
	void	set_update_fg(on_off_enum i) { UPDATE_FG = i; }
	void	set_init_fg(on_off_enum i) { INIT_FG = i; }

	virtual int init(){return 0; };
	virtual int set(nsl_interpreter&){return 0; };
	virtual int get(nsl_buffer&){return 0; };
 	virtual int update(nsl_cmd_type*){return 0; };

	int print_cmd_set(std::ostream&) const{return 0; };
	virtual int print(std::ostream&) const{return 0; };
};
#endif
