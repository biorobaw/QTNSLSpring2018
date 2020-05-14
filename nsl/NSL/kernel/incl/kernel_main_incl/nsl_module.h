/* SCCS  @(#)nsl_module.h	1.1---95/08/13--23:37:18 */
//
//	nsl_module.h
//
#ifndef _NSL_MODULE_H
#define _NSL_MODULE_H
#include "nsl_public.h"
class nsl_module : public nsl_public
{
protected:
	void (*mod_func)();
// new addittions
    void (*model_func)(nsl_model*);

public:
		nsl_module();
		//nsl_module(char *, nsl_module*);
		nsl_module(char*,void (*)(),int=0,int=0);

		virtual ~nsl_module();

	int init_module(char*,void (*)(),int,int=0);

        void model_func_init(nsl_model* m,void (*f)(nsl_model*))
        {
            m_parent = (nsl_base*) m;
            model_func = f;
        }
        void model_func_run()
        {
            model_func((nsl_model*) m_parent);
        }

	void	proc(const int);	// run function from simulation
	void	exec(); 		// exec function if specially called

	int	init_module();

	virtual int 	print(std::ostream&) const;
	int 	print_module(std::ostream&) const;
	virtual int 	print_status(std::ostream&) const;
	int 	print_module_status(std::ostream&) const;

	virtual int 	print_all(std::ostream&) const;
	int 	print_module_all(std::ostream&) const;
	virtual int 	print_all_status(std::ostream&) const;
	int 	print_module_all_status(std::ostream&) const;

	int 	write_module(nsl_buffer&);
	virtual int 	write(nsl_buffer&);
	int 	read_module(nsl_buffer&);
	virtual int 	read(nsl_buffer&);
};
#endif
