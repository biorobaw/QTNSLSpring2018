/* SCCS  @(#)nsl_matrix_add_library.h	1.1---95/08/13--23:38:58 */
//
// nsl_matrix_add_library.h
//
class nsl_num_2;
class nsl_num_0;

extern	nsl_num_2 	operator+(const nsl_num_2&);
extern	nsl_num_2 	operator+(const nsl_num_2&,const nsl_num_2&);
extern	nsl_num_2 	operator+(const nsl_num_0&,const nsl_num_2&);
extern	nsl_num_2 	operator+(const nsl_num_2&,const nsl_num_0&);
extern	nsl_num_2 	operator+(const nsl_num_2&,const NslNumType);
extern	nsl_num_2 	operator+(const NslNumType,const nsl_num_2&);

extern void NSLadd_equal(nsl_num_2&,const nsl_num_2&);
extern void NSLadd_equal(nsl_num_2&,const nsl_num_1&);
extern void NSLadd_col_equal(nsl_num_2&,const nsl_num_1&);
extern void NSLadd_row_equal(nsl_num_2&,const nsl_num_1&);
extern void NSLadd_equal(nsl_num_2&,const nsl_num_0&);

extern void NSLadd_plus(nsl_num_2&,const nsl_num_2&);
extern void NSLadd_plus(nsl_num_2&,const nsl_num_0&);

extern void NSLadd_minus(nsl_num_2&,const nsl_num_2&);
extern void NSLadd_minus(nsl_num_2&,const nsl_num_0&);
