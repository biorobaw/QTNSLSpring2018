#ifndef _NSL_CHAR_BUF_STREAM_LIBRARY_H
#define _NSL_CHAR_BUF_STREAM_LIBRARY_H
#include <iostream>
class nsl_char_buf;
class nsl_data_layer;
class nsl_str_data;
class nsl_ptr_data;
class nsl_vector_layer;
class nsl_ptr_vector;
class nsl_str_vector;
class nsl_layer;
class nsl_num_0;
class nsl_num_1;
class nsl_num_2;
class nsl_ptr_matrix;
class nsl_str_matrix;
class nsl_matrix_layer;
extern 	nsl_char_buf& operator>>(nsl_char_buf&,char&);
extern 	nsl_char_buf& operator<<(nsl_char_buf&,char);

extern 	nsl_char_buf& operator>>(nsl_char_buf&,char*); // str
extern 	nsl_char_buf& operator<<(nsl_char_buf&,const char*); // str

extern 	nsl_char_buf& operator>>(nsl_char_buf&,int&);
extern 	nsl_char_buf& operator<<(nsl_char_buf&,int);

extern 	nsl_char_buf& operator>>(nsl_char_buf&,float&);
extern 	nsl_char_buf& operator<<(nsl_char_buf&,float);

extern 	nsl_char_buf& operator>>(nsl_char_buf&,double&);
extern 	nsl_char_buf& operator<<(nsl_char_buf&,double);

extern nsl_char_buf& operator>>(nsl_char_buf&,nsl_layer&);
extern nsl_char_buf& operator>>(nsl_char_buf&,nsl_data_layer&);
//extern nsl_char_buf& operator>>(nsl_char_buf&,nsl_int_data&);
//extern nsl_char_buf& operator>>(nsl_char_buf&,nsl_num_data&);
extern nsl_char_buf& operator>>(nsl_char_buf&,nsl_str_data&);
extern nsl_char_buf& operator>>(nsl_char_buf&,nsl_ptr_data&);
extern nsl_char_buf& operator>>(nsl_char_buf&,nsl_vector_layer&);
//extern nsl_char_buf& operator>>(nsl_char_buf&,nsl_int_vector&);
//extern nsl_char_buf& operator>>(nsl_char_buf&,nsl_num_vector&);
extern nsl_char_buf& operator>>(nsl_char_buf&,nsl_str_vector&);
extern nsl_char_buf& operator>>(nsl_char_buf&,nsl_ptr_vector&);
extern nsl_char_buf& operator>>(nsl_char_buf&,nsl_matrix_layer&);
//extern nsl_char_buf& operator>>(nsl_char_buf&,nsl_int_matrix&);
//extern nsl_char_buf& operator>>(nsl_char_buf&,nsl_num_matrix&);
extern nsl_char_buf& operator>>(nsl_char_buf&,nsl_str_matrix&);
extern nsl_char_buf& operator>>(nsl_char_buf&,nsl_ptr_matrix&);

extern nsl_char_buf& operator<<(nsl_char_buf&,nsl_layer&);
extern nsl_char_buf& operator<<(nsl_char_buf&,nsl_data_layer&);
//extern nsl_char_buf& operator<<(nsl_char_buf&,nsl_int_data&);
//extern nsl_char_buf& operator<<(nsl_char_buf&,nsl_num_data&);
extern nsl_char_buf& operator<<(nsl_char_buf&,nsl_str_data&);
extern nsl_char_buf& operator<<(nsl_char_buf&,nsl_ptr_data&);
extern nsl_char_buf& operator<<(nsl_char_buf&,nsl_vector_layer&);
//extern nsl_char_buf& operator<<(nsl_char_buf&,nsl_int_vector&);
//extern nsl_char_buf& operator<<(nsl_char_buf&,nsl_num_vector&);
extern nsl_char_buf& operator<<(nsl_char_buf&,nsl_str_vector&);
extern nsl_char_buf& operator<<(nsl_char_buf&,nsl_ptr_vector&);
extern nsl_char_buf& operator<<(nsl_char_buf&,nsl_matrix_layer&);
//extern nsl_char_buf& operator<<(nsl_char_buf&,nsl_int_matrix&);
//extern nsl_char_buf& operator<<(nsl_char_buf&,nsl_num_matrix&);
extern nsl_char_buf& operator<<(nsl_char_buf&,nsl_str_matrix&);
extern nsl_char_buf& operator<<(nsl_char_buf&,nsl_ptr_matrix&);

//template<class NslNumType, int NslTypeId>
extern nsl_char_buf& operator>>(nsl_char_buf& buf,nsl_num_0& layer);
//template<class NslNumType, int NslTypeId>
extern nsl_char_buf& operator<<(nsl_char_buf& buf,nsl_num_0& layer);
//template<class NslNumType, int NslTypeId>
extern nsl_char_buf& operator>>(nsl_char_buf& buf,nsl_num_1& layer);
//template<class NslNumType, int NslTypeId>
extern nsl_char_buf& operator<<(nsl_char_buf& buf,nsl_num_1& layer);
//template<class NslNumType, int NslTypeId>
extern nsl_char_buf& operator>>(nsl_char_buf& buf,nsl_num_2& layer);
//template<class NslNumType, int NslTypeId>
extern nsl_char_buf& operator<<(nsl_char_buf& buf,nsl_num_2& layer);

// iostream

extern 	nsl_char_buf& operator<<(nsl_char_buf&,std::istream&);
extern 	nsl_char_buf& operator>>(nsl_char_buf&,std::ostream&);
extern 	nsl_char_buf& operator<<(nsl_char_buf&,std::fstream&);
extern 	nsl_char_buf& operator>>(nsl_char_buf&,std::fstream&);

extern std::istream& operator>>(std::istream&,nsl_char_buf&);
extern std::ostream& operator<<(std::ostream&,nsl_char_buf&);
extern std::fstream& operator>>(std::fstream&,nsl_char_buf&);
extern std::fstream& operator<<(std::fstream&,nsl_char_buf&);
#endif
