/* SCCS  @(#)nsl_buffer_stream_library.h	1.1---95/08/13--23:38:36 */

//
// nsl_buffer_stream_library.h
//
#ifndef _NSL_BUFFER_STREAM_LIBRARY_H
#define _NSL_BUFFER_STREAM_LIBRARY_H
#include <fstream>
#include <iostream>
#include <iosfwd>

#ifndef _NSL_SET
class nsl_int_data;
class nsl_num_data;
class nsl_num_vector;
class nsl_num_matrix;
class nsl_buffer;
class nsl_int_matrix;
class nsl_matrix_layer;
class nsl_int_vector;
class nsl_matrix_layer;
class nsl_int_matrix;

class nsl_interpreter;
class nsl_layer;
class nsl_data_layer;
class nsl_str_data;
class nsl_ptr_data;
class nsl_vector_layer;
class nsl_int_vector;
class nsl_str_vector;
class nsl_ptr_vector;
class nsl_num_matrix;
class nsl_str_matrix;
class nsl_ptr_matrix;
class nsl_str_data;
class nsl_ptr_data;
class nsl_vector_layer;
class nsl_num_vector;
class nsl_str_vector;
class nsl_ptr_vector;
#endif

extern 	nsl_buffer& operator>>(nsl_buffer&,char&);
extern 	nsl_buffer& operator<<(nsl_buffer&,char);

extern 	nsl_buffer& operator>>(nsl_buffer&,char*); // str
extern 	nsl_buffer& operator<<(nsl_buffer&,const char*); // str

extern 	nsl_buffer& operator>>(nsl_buffer&,int&);
extern 	nsl_buffer& operator<<(nsl_buffer&,int);

extern 	nsl_buffer& operator>>(nsl_buffer&,float&);
extern 	nsl_buffer& operator<<(nsl_buffer&,float);

extern nsl_buffer& operator>>(nsl_buffer&,nsl_layer&);
extern nsl_buffer& operator>>(nsl_buffer&,nsl_data_layer&);
extern nsl_buffer& operator>>(nsl_buffer&,nsl_int_data&);
extern nsl_buffer& operator>>(nsl_buffer&,nsl_num_data&);
extern nsl_buffer& operator>>(nsl_buffer&,nsl_str_data&);
extern nsl_buffer& operator>>(nsl_buffer&,nsl_ptr_data&);
extern nsl_buffer& operator>>(nsl_buffer&,nsl_vector_layer&);
extern nsl_buffer& operator>>(nsl_buffer&,nsl_int_vector&);
extern nsl_buffer& operator>>(nsl_buffer&,nsl_num_vector&);
extern nsl_buffer& operator>>(nsl_buffer&,nsl_str_vector&);
extern nsl_buffer& operator>>(nsl_buffer&,nsl_ptr_vector&);
extern nsl_buffer& operator>>(nsl_buffer&,nsl_matrix_layer&);
extern nsl_buffer& operator>>(nsl_buffer&,nsl_int_matrix&);
extern nsl_buffer& operator>>(nsl_buffer&,nsl_num_matrix&);
extern nsl_buffer& operator>>(nsl_buffer&,nsl_str_matrix&);
extern nsl_buffer& operator>>(nsl_buffer&,nsl_ptr_matrix&);

extern nsl_buffer& operator<<(nsl_buffer&,nsl_layer&);
extern nsl_buffer& operator<<(nsl_buffer&,nsl_data_layer&);
extern nsl_buffer& operator<<(nsl_buffer&,nsl_int_data&);
extern nsl_buffer& operator<<(nsl_buffer&,nsl_num_data&);
extern nsl_buffer& operator<<(nsl_buffer&,nsl_str_data&);
extern nsl_buffer& operator<<(nsl_buffer&,nsl_ptr_data&);
extern nsl_buffer& operator<<(nsl_buffer&,nsl_vector_layer&);
extern nsl_buffer& operator<<(nsl_buffer&,nsl_int_vector&);
extern nsl_buffer& operator<<(nsl_buffer&,nsl_num_vector&);
extern nsl_buffer& operator<<(nsl_buffer&,nsl_str_vector&);
extern nsl_buffer& operator<<(nsl_buffer&,nsl_ptr_vector&);
extern nsl_buffer& operator<<(nsl_buffer&,nsl_matrix_layer&);
extern nsl_buffer& operator<<(nsl_buffer&,nsl_int_matrix&);
extern nsl_buffer& operator<<(nsl_buffer&,nsl_num_matrix&);
extern nsl_buffer& operator<<(nsl_buffer&,nsl_str_matrix&);
extern nsl_buffer& operator<<(nsl_buffer&,nsl_ptr_matrix&);

// istd::ostream

extern 	nsl_buffer& operator<<(nsl_buffer&,std::istream&);
extern 	nsl_buffer& operator>>(nsl_buffer&,std::ostream&);
extern 	nsl_buffer& operator<<(nsl_buffer&,std::fstream&);
extern 	nsl_buffer& operator>>(nsl_buffer&,std::fstream&);

extern std::istream& operator>>(std::istream&,nsl_buffer&);
extern std::ostream& operator<<(std::ostream&,nsl_buffer&);
extern std::fstream& operator>>(std::fstream&,nsl_buffer&);
extern std::fstream& operator<<(std::fstream&,nsl_buffer&);



// iostream

extern 	nsl_buffer& operator<<(nsl_buffer&,std::istream&);
extern 	nsl_buffer& operator>>(nsl_buffer&,std::ostream&);
extern 	nsl_buffer& operator<<(nsl_buffer&,std::fstream&);
extern 	nsl_buffer& operator>>(nsl_buffer&,std::fstream&);

extern std::istream& operator>>(std::istream&,nsl_buffer&);
extern std::ostream& operator<<(std::ostream&,nsl_buffer&);
extern std::fstream& operator>>(std::fstream&,nsl_buffer&);
extern std::fstream& operator<<(std::fstream&,nsl_buffer&);

#endif
