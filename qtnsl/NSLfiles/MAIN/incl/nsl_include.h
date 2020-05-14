/* SCCS  @(#)nsl_include.h	1.1---95/08/13--23:46:24 */
/****************************************************************/
/*                                                           	*/
/*                       nsl_include.h                          */
/*                                                            	*/
/****************************************************************/

# ifndef NSL_INCLUDE_H
# define NSL_INCLUDE_H
# include "../../../MAIN/src/sys_main_src/nsl_all_kernel_include.h"
# ifdef NSL_NEURON
	# include "../../incl/nsl_all_neuron_include.h"
# endif
# ifdef NSL_WIN
	# include "xkernel.h"
# endif

//extern void NSLinit(int,char**);
//extern void NSLmain(int,char**);
/*
#ifdef NSL_INPUT_FG
	# include "../../incl/nsl_all_input_include.h"
#endif

#define INPUT_MAT(a,x,y)                \
static nsl_input_matrix a##(#a,x,y,2)     \

#define INPUT_VEC(a,x)          	\
static nsl_input_vector a##(#a,x,2)       \

#define INPUT_DAT(a)                    \
static nsl_input_data a##(#a,2)           \

#define MATRIX(a,x,y)                   \
static nsl_num_2 a##(#a,x,y,2)           \

#define VECTOR(a,x)                     \
static nsl_num_1 a##(#a,x,NSL_ROW,2)     \

#define ROW_VEC(a,x)                      \
static nsl_num_1 a##(#a,x,NSL_ROW,2)   \

#define COL_VEC(a,x)                      \
static nsl_num_1 a##(#a,x,NSL_COL,2)   \

#define DATA(a)                         \
static nsl_num_0 a##(#a,0,2)               \

# ifdef NSL_NEURON
	define NETWORK(a)                \
	nsl_neural_network a##(#a,2);
# else
	#define NETWORK(a)               \
	nsl_model a##(#a,2);
# endif

#define MODEL(a)                      \
nsl_model a##(#a,2);             \

# undef DIFF
# define DIFF(a,b)			\
static nsl_diff a##_diff(1);		\
a##_diff.eq(a,b)			\
*/
/*
# undef DIFF
# define DIFF(a,b,c)			\
static nsl_diff a##_diff(c);		\
a##_diff.eq(a,b)			\
*/

# define MODULE(a)                      \
void a##_func();                             \
nsl_module a##(#a,a##_func,1);             \
void a##_func()                              \

# define INIT_MODULE(a)                 \
void a##_func();                             \
nsl_module a##(#a,a##_func,1,1);           \
void a##_func()                              \

# define RUN_MODULE(a)                  \
void a##_func();                             \
nsl_module a##(#a,a##_func,2,1);           \
void a##_func()                              \

# define FUNC_MODULE(a)                 \
void a##_func();                             \
nsl_module a##(#a,a##_func,-1,1);          \
void a##_func()                              \

# define SYS_MODULE(a)                  \
void a##_func();                             \
nsl_module a##(#a,a##_func,3,1);           \
void a##_func()                              \

#endif
