
#ifndef _NSL_FUNCTION_H
#define _NSL_FUNCTION_H
#include "nsl_public.h"
class nsl_function : public nsl_public
{
protected:
	void (*mod_func)();
// new addittions
        void (*model_func)(nsl_model*);

public:
		nsl_function();
		nsl_function(char*,void (*)(),int=0,int=0);

		virtual ~nsl_function();

	int init_function(char*,void (*)(),int,int=0);

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

	int	init_function();

	virtual int 	print(std::ostream&) const;
	int 	print_function(std::ostream&) const;
	virtual int 	print_status(std::ostream&) const;
	int 	print_function_status(std::ostream&) const;

	virtual int 	print_all(std::ostream&) const;
	int 	print_function_all(std::ostream&) const;
	virtual int 	print_all_status(std::ostream&) const;
	int 	print_function_all_status(std::ostream&) const;

	int 	write_function(nsl_buffer&);
	virtual int 	write(nsl_buffer&);
	int 	read_function(nsl_buffer&);
	virtual int 	read(nsl_buffer&);
};
#endif
