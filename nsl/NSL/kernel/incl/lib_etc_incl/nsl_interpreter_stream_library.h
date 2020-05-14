/* SCCS  @(#)nsl_interpreter_stream_library.h	1.1---95/08/13--23:38:36 */

//
// nsl_interpreter_stream_library.h
//
#ifndef _NSL_INTERPRETER_STREAM_LIBRARY_H
#define _NSL_INTERPRETER_STREAM_LIBRARY_H
#include "nsl.h"
#ifndef _NSL_SET
class nsl_interpreter;
class nsl_layer;
class nsl_data_layer;
class nsl_int_data;
class nsl_str_data;
class nsl_ptr_data;
class nsl_vector_layer;
class nsl_int_vector;
class nsl_num_vector;
class nsl_str_vector;
class nsl_ptr_vector;
class nsl_matrix_layer;
class nsl_int_matrix;
class nsl_num_matrix;
class nsl_str_matrix;
class nsl_ptr_matrix;
class nsl_num_data;
class nsl_str_data;
class nsl_ptr_data;
class nsl_vector_layer;
class nsl_int_vector;
class nsl_num_vector;
class nsl_str_vector;
class nsl_ptr_vector;
class nsl_matrix_layer;
class nsl_buffer;
#endif

extern	nsl_interpreter& operator>>(nsl_interpreter&,char*);
extern	nsl_interpreter& operator>>(nsl_interpreter&,float&);
extern	nsl_interpreter& operator>>(nsl_interpreter&,int&);
extern	nsl_interpreter& operator>>(nsl_interpreter&,char&);

extern nsl_interpreter& operator<<(nsl_interpreter&,const char*);
extern nsl_interpreter& operator<<(nsl_interpreter&,float);
extern nsl_interpreter& operator<<(nsl_interpreter&,int);
extern nsl_interpreter& operator<<(nsl_interpreter&,char);

extern nsl_interpreter& operator>>(nsl_interpreter&,nsl_layer&);
extern nsl_interpreter& operator>>(nsl_interpreter&,nsl_data_layer&);
extern nsl_interpreter& operator>>(nsl_interpreter&,nsl_int_data&);
extern nsl_interpreter& operator>>(nsl_interpreter&,nsl_num_data&);
extern nsl_interpreter& operator>>(nsl_interpreter&,nsl_str_data&);
extern nsl_interpreter& operator>>(nsl_interpreter&,nsl_ptr_data&);
extern nsl_interpreter& operator>>(nsl_interpreter&,nsl_vector_layer&);
extern nsl_interpreter& operator>>(nsl_interpreter&,nsl_int_vector&);
extern nsl_interpreter& operator>>(nsl_interpreter&,nsl_num_vector&);
extern nsl_interpreter& operator>>(nsl_interpreter&,nsl_str_vector&);
extern nsl_interpreter& operator>>(nsl_interpreter&,nsl_ptr_vector&);
extern nsl_interpreter& operator>>(nsl_interpreter&,nsl_matrix_layer&);
extern nsl_interpreter& operator>>(nsl_interpreter&,nsl_int_matrix&);
extern nsl_interpreter& operator>>(nsl_interpreter&,nsl_num_matrix&);
extern nsl_interpreter& operator>>(nsl_interpreter&,nsl_str_matrix&);
extern nsl_interpreter& operator>>(nsl_interpreter&,nsl_ptr_matrix&);

extern nsl_interpreter& operator<<(nsl_interpreter&,nsl_layer&);
extern nsl_interpreter& operator<<(nsl_interpreter&,nsl_data_layer&);
extern nsl_interpreter& operator<<(nsl_interpreter&,nsl_int_data&);
extern nsl_interpreter& operator<<(nsl_interpreter&,nsl_num_data&);
extern nsl_interpreter& operator<<(nsl_interpreter&,nsl_str_data&);
extern nsl_interpreter& operator<<(nsl_interpreter&,nsl_ptr_data&);
extern nsl_interpreter& operator<<(nsl_interpreter&,nsl_vector_layer&);
extern nsl_interpreter& operator<<(nsl_interpreter&,nsl_int_vector&);
extern nsl_interpreter& operator<<(nsl_interpreter&,nsl_num_vector&);
extern nsl_interpreter& operator<<(nsl_interpreter&,nsl_str_vector&);
extern nsl_interpreter& operator<<(nsl_interpreter&,nsl_ptr_vector&);
extern nsl_interpreter& operator<<(nsl_interpreter&,nsl_matrix_layer&);
extern nsl_interpreter& operator<<(nsl_interpreter&,nsl_int_matrix&);
extern nsl_interpreter& operator<<(nsl_interpreter&,nsl_num_matrix&);
extern nsl_interpreter& operator<<(nsl_interpreter&,nsl_str_matrix&);
extern nsl_interpreter& operator<<(nsl_interpreter&,nsl_ptr_matrix&);

extern	nsl_interpreter& operator<<(nsl_interpreter&,std::istream&);
extern	nsl_interpreter& operator>>(nsl_interpreter&,std::ostream&);
extern	nsl_interpreter& operator<<(nsl_interpreter&,std::fstream&);
extern	nsl_interpreter& operator>>(nsl_interpreter&,std::fstream&);

extern std::fstream& operator>>(std::fstream&,nsl_buffer&);
extern std::istream& operator>>(std::istream&,nsl_buffer&);
extern std::ostream& operator<<(std::ostream&,nsl_buffer&);
extern std::ostream& operator>>(std::ostream&,nsl_buffer&);




#endif
