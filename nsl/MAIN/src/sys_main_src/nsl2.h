//
//	nsl.h
//
/*
#include <cstdlib>
using namespace std;


//# include <strings> // include nesting w/ <string.h>
# ifndef __GNUCC__
	# include <string> // include nesting w/ <string.h>
# endif

# undef NSL_NAME_SIZE
# define NSL_NAME_SIZE 80
typedef char nsl_string[NSL_NAME_SIZE];

# undef NSL_STREAMBUF_SIZE
# define NSL_STREAMBUF_SIZE 1024

// AW98 get rid of this line if using templates !
typedef float NslNumType;

typedef float num_type;
typedef void  nsl_void;

typedef float NslFloat;
typedef double NslDouble;
typedef int NslInt;
typedef nsl_string NSlString;

  class nsl_layer;
  class nsl_data_layer;
/*  template<class NslNumType> */ class nsl_num_0;
  class nsl_vector_layer;
/*  template<class NslNumType> */ class nsl_num_1;
  class nsl_matrix_layer;
/*  template<class NslNumType> */ class nsl_num_2;
  class nsl_3_layer;
/*  template<class NslNumType> */ class nsl_num_3;
  class nsl_4_layer;
/*  template<class NslNumType> */ class nsl_num_4;
/*
  class nsl_str_data;
  class nsl_str_vector;
  class nsl_str_matrix;

  class nsl_ptr_data;
  class nsl_ptr_vector;
  class nsl_ptr_matrix;

  class nsl_model;
  class nsl_module;
  class nsl_sys_module;
  class nsl_system;

  class nsl_in_out_data;
  class nsl_on_off_data;
  class nsl_file_data;
  class nsl_dump_data;
  class nsl_row_col_data;
*/

/*
typedef nsl_str_data NslStr0;
typedef nsl_str_vector NslStr1;
typedef nsl_str_matrix NslStr2;
// typedef nsl_str_3d NslStr3;

typedef nsl_ptr_data NslRef0;
typedef nsl_ptr_vector NslRef1;
typedef nsl_ptr_matrix NslRef2;
// typedef nsl_ptr_3d NslRef3;

  class nsl_base_node;
  class nsl_base;
  class nsl_public;
  class nsl_base_list;
  class nsl_base_stack;
  class nsl_interpreter;
  class nsl_shell;
  class nsl_buffer;
  class nsl_streambuf;

typedef nsl_base_list nsl_list;
typedef nsl_base_stack nsl_stack;
typedef nsl_model nsl_network;

  class nsl_file;
  class nsl_nsl_file;
  class nsl_file_manager;

  class nsl_diff_manager;
  class nsl_diff;
  class nsl_diff_method;

  class nsl_diff_euler;
  class nsl_diff_interpolation;

  class nsl_library;
  class nsl_thresh_library;

  class nsl_cmd_buf;
  class nsl_cmd_macro;
  class nsl_cmd_exec;
  class nsl_cmd_exec_assign;
  class nsl_cmd_exec_cd;
  class nsl_cmd_exec_close;
  class nsl_cmd_exec_cont;
  class nsl_cmd_exec_create;
  class nsl_cmd_exec_csh;
  class nsl_cmd_exec_disable;
  class nsl_cmd_exec_elem;
  class nsl_cmd_exec_enable;
  class nsl_cmd_exec_exec;
  class nsl_cmd_exec_file_disable;
  class nsl_cmd_exec_file_enable;
  class nsl_cmd_exec_help;
  class nsl_cmd_exec_init;
  class nsl_cmd_exec_load;
  class nsl_cmd_exec_open;
  class nsl_cmd_exec_quit;
  class nsl_cmd_exec_reset;
  class nsl_cmd_exec_run;
  class nsl_cmd_exec_set;
  class nsl_cmd_exec_sh;
  class nsl_cmd_exec_status;
  class nsl_cmd_exec_step;
  class nsl_cmd_exec_update;
  class nsl_cmd_exec_write;

  class nsl_cmd_type;
  class nsl_cmd_layer;
  class nsl_cmd_data_layer;
  class nsl_cmd_int_data;
  class nsl_cmd_num_data;
  class nsl_cmd_str_data;
  class nsl_cmd_ptr_data;
  class nsl_cmd_vector_layer;
  class nsl_cmd_int_vector;
  class nsl_cmd_num_vector;
  class nsl_cmd_str_vector;
  class nsl_cmd_ptr_vector;
  class nsl_cmd_matrix_layer;
  class nsl_cmd_int_matrix;
  class nsl_cmd_num_matrix;
  class nsl_cmd_str_matrix;
  class nsl_cmd_ptr_matrix;
  class nsl_cmd_model;
  class nsl_cmd_module;
  class nsl_cmd_system;
  class nsl_cmd_file;
  class nsl_cmd_diff;
  class nsl_cmd_file_manager;
  class nsl_cmd_diff_manager;

#undef NSL_ENDL
#define NSL_ENDL "\n"

  //already defined in nsl.h -bn7

enum row_col_enum { NSL_ROW=0, NSL_COL=1 };
enum on_off_enum { NSL_OFF=0, NSL_ON=1 };
enum in_out_enum { NSL_OUTPUT=0, NSL_INPUT=1, NSL_INOUT=2 };
enum dump_enum { NSL_LP=0, NSL_COUT=1, NSL_FOUT=2 };
enum file_enum { NSL_CIN=0, NSL_FIN=1 };


enum spec_type_enum { NSL_CORNER=0, NSL_CENTER=1 };
enum stim_type_enum { NSL_BLOCK=0, NSL_ICON=1 };

#ifdef __GNUCC__
	nsl_diff* NSL_DIFF;
  	nsl_system* NSL_SYSTEM;
	nsl_interpreter* NSL_INTERPRETER;
#else
	extern nsl_diff* NSL_DIFF;
	extern nsl_system* NSL_SYSTEM;
	extern  nsl_interpreter* NSL_INTERPRETER;
#endif

#undef NSL
#define NSL (*NSL_INTERPRETER)

extern  int BREAKFG;
extern  int INTERRUPTFG;

*/
