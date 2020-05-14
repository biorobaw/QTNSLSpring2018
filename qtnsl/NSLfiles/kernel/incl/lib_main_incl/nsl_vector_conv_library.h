/* SCCS  @(#)nsl_vector_conv_library.h	1.1---95/08/13--23:38:58 */
//
// nsl_vector_conv_library.h
//
class nsl_num_vector;
class nsl_num_data;

//typedef nsl_num_vector nsl_num_1;
////typedef nsl_num_data nsl_num_0;

extern 	nsl_num_1 	operator*(const nsl_num_1&,const nsl_num_1&);
extern	nsl_num_1 	operator*(const nsl_num_0&,const nsl_num_1&);
extern	nsl_num_1 	operator*(const nsl_num_1&,const nsl_num_0&);
extern	nsl_num_1 	operator*(const nsl_num_1&,const num_type);
extern	nsl_num_1 	operator*(const num_type,const nsl_num_1&);

extern nsl_num_1 NSLconv_zero(const nsl_num_1&,const num_type);
extern nsl_num_1 NSLconv_zero(const num_type,const nsl_num_1&);
extern nsl_num_1 NSLconv_zero(const nsl_num_1&,const nsl_num_0&);
extern nsl_num_1 NSLconv_zero(const nsl_num_0&,const nsl_num_1&);
extern nsl_num_1 NSLconv_zero(const nsl_num_1&,const nsl_num_1&);
extern nsl_num_1 NSLconv_wrap(const nsl_num_1&,const nsl_num_1&);
extern nsl_num_1 NSLconv_copy(const nsl_num_1&,const nsl_num_1&);

