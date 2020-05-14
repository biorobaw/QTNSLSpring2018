/****************************************************************/
/*                                                           	*/
/*                  nsl_misc_library.h                          */
/*                                                            	*/
/****************************************************************/

// NSLmax
extern num_type NSLmax(const nsl_num_1&);
extern num_type NSLmax(const nsl_num_2&);
extern nsl_num_0 NSLmax(const nsl_num_0&,const nsl_num_0&);
extern nsl_num_0 NSLmax(const nsl_num_0&,const num_type);
extern nsl_num_1 NSLmax(const nsl_num_1&,const nsl_num_1&);
extern nsl_num_1 NSLmax(const nsl_num_1&,const nsl_num_0&);
extern nsl_num_1 NSLmax(const nsl_num_1&,const num_type);
extern nsl_num_2 NSLmax(const nsl_num_2&,const nsl_num_2&);
extern nsl_num_2 NSLmax(const nsl_num_2&,const nsl_num_0&);
extern nsl_num_2 NSLmax(const nsl_num_2&,const num_type);

// NSLmin
extern num_type NSLmin(const nsl_num_1&);
extern num_type NSLmin(const nsl_num_2&);
extern nsl_num_0 NSLmin(const nsl_num_0&,const nsl_num_0&);
extern nsl_num_0 NSLmin(const nsl_num_0&,const num_type);
extern nsl_num_1 NSLmin(const nsl_num_1&,const nsl_num_1&);
extern nsl_num_1 NSLmin(const nsl_num_1&,const nsl_num_0&);
extern nsl_num_1 NSLmin(const nsl_num_1&,const num_type);
extern nsl_num_2 NSLmin(const nsl_num_2&,const nsl_num_2&);
extern nsl_num_2 NSLmin(const nsl_num_2&,const nsl_num_0&);
extern nsl_num_2 NSLmin(const nsl_num_2&,const num_type);

// vector and matrix transformations
extern nsl_num_1 NSLmat_to_vec(const nsl_num_1&,const nsl_num_2&);
extern nsl_num_2 NSLvec_to_mat(const nsl_num_2&,const nsl_num_1&);

extern nsl_num_1 NSLmat_to_col_vec(const nsl_num_1&,const nsl_num_2&);
extern nsl_num_1 NSLmat_to_row_vec(const nsl_num_1&,const nsl_num_2&);
extern nsl_num_2 NSLcol_vec_to_mat(const nsl_num_2&,const nsl_num_1&);
extern nsl_num_2 NSLrow_vec_to_mat(const nsl_num_2&,const nsl_num_1&);

extern nsl_num_1 NSLmat_to_col_vec(const nsl_num_2&);
extern nsl_num_1 NSLmat_to_row_vec(const nsl_num_2&);
extern nsl_num_2 NSLcol_vec_to_mat(const nsl_num_1&,const int);
extern nsl_num_2 NSLrow_vec_to_mat(const nsl_num_1&,const int);

// product
extern nsl_num_0 NSLprod(const nsl_num_1&,const nsl_num_1&);
extern nsl_num_1 NSLprod(const nsl_num_1&,const nsl_num_2&);
extern nsl_num_1 NSLprod(const nsl_num_2&,const nsl_num_1&);
extern nsl_num_2 NSLprod(const nsl_num_2&,const nsl_num_2&);

// convolution
extern nsl_num_1 NSLconv_zero(const nsl_num_1&,const num_type);
extern nsl_num_1 NSLconv_zero(const num_type,const nsl_num_1&);
extern nsl_num_1 NSLconv_zero(const nsl_num_1&,const nsl_num_0&);
extern nsl_num_1 NSLconv_zero(const nsl_num_0&,const nsl_num_1&);
extern nsl_num_1 NSLconv_zero(const nsl_num_1&,const nsl_num_1&);
extern nsl_num_1 NSLconv_wrap(const nsl_num_1&,const nsl_num_1&);
extern nsl_num_1 NSLconv_copy(const nsl_num_1&,const nsl_num_1&);

extern nsl_num_2 NSLconv_zero(const nsl_num_2&,const num_type);
extern nsl_num_2 NSLconv_zero(const num_type,const nsl_num_2&);
extern nsl_num_2 NSLconv_zero(const nsl_num_2&,const nsl_num_0&);
extern nsl_num_2 NSLconv_zero(const nsl_num_0&,const nsl_num_2&);
extern nsl_num_2 NSLconv_zero(const nsl_num_2&,const nsl_num_1&);
extern nsl_num_2 NSLconv_zero(const nsl_num_1&,const nsl_num_2&);
extern nsl_num_2 NSLconv_zero(const nsl_num_2&,const nsl_num_2&);
extern nsl_num_2 NSLconv_wrap(const nsl_num_2&,const nsl_num_2&);
extern nsl_num_2 NSLconv_copy(const nsl_num_2&,const nsl_num_2&);

extern nsl_num_2 NSLexpdecay(const nsl_num_2&,const nsl_num_0&);
extern nsl_num_2 KERNEL(const int,const int,
	const nsl_num_0&,const nsl_num_0&,const nsl_num_0&);

