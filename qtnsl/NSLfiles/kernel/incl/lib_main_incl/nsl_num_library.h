//
//	nsl_num_library.h
//

// mult_equal
#ifndef _NSL_NUM_LIBRARY_H
#define _NSL_NUM_LIBRARY_H
// data
class nsl_num_data;
class nsl_num_vector;
class nsl_num_matrix;
class nsl_num_0;
class nsl_num_1;
class nsl_num_2;
typedef float num_type;
//typedef nsl_num_2 nsl_num_2;
//typedef nsl_num_0 nsl_num_0;
//typedef nsl_num_1 nsl_num_1;


  extern void NSLmult_equal(nsl_num_data&,const nsl_num_data&,
		const num_type&) ;
  extern void NSLmult_equal(nsl_num_data&,const nsl_num_vector&,
		const nsl_num_data&) ;
  extern void NSLmult_equal(nsl_num_data&,const nsl_num_vector&,
		const nsl_num_vector&) ;
  extern void NSLmult_equal(nsl_num_data&,const nsl_num_matrix&,
		const nsl_num_data&) ;
  extern void NSLmult_equal(nsl_num_data&,const nsl_num_matrix&,
		const nsl_num_matrix&) ;
  extern void NSLmult_equal(nsl_num_data&,const nsl_num_data&,
		const nsl_num_data&) ;
  extern void NSLmult_equal(nsl_num_data&,const nsl_num_data&,
		const nsl_num_vector&) ;
  extern void NSLmult_equal(nsl_num_data&,const nsl_num_data&,
		const nsl_num_matrix&) ;

// vector

  extern void NSLmult_equal(nsl_num_vector&,const nsl_num_data&,
		const num_type&) ;
  extern void NSLmult_equal(nsl_num_vector&,const nsl_num_data&,
		const nsl_num_data&) ;
  extern void NSLmult_equal(nsl_num_vector&,const nsl_num_data&,
		const nsl_num_vector&) ;
  extern void NSLmult_equal(nsl_num_vector&,const nsl_num_vector&,
		const num_type&) ;
  extern void NSLmult_equal(nsl_num_vector&,const nsl_num_vector&,
		const nsl_num_data&) ;
  extern void NSLmult_equal(nsl_num_vector&,const nsl_num_vector&,
		const nsl_num_vector&) ;
  extern void NSLmult_equal(nsl_num_vector&,const nsl_num_matrix&,
		const nsl_num_data&) ;
  extern void NSLmult_equal(nsl_num_vector&,const nsl_num_matrix&,
		const nsl_num_vector&) ;

// matrix

  extern void NSLmult_equal(nsl_num_matrix&,const nsl_num_data&,
		const num_type&) ;
  extern void NSLmult_equal(nsl_num_matrix&,const nsl_num_data&,
		const nsl_num_data&) ;
  extern void NSLmult_equal(nsl_num_matrix&,const nsl_num_data&,
		const nsl_num_matrix&) ;
  extern void NSLmult_equal(nsl_num_matrix&,const nsl_num_vector&,
		const nsl_num_data&) ;
  extern void NSLmult_equal(nsl_num_matrix&,const nsl_num_matrix&,
		const num_type&) ;
  extern void NSLmult_equal(nsl_num_matrix&,const nsl_num_matrix&,
		const nsl_num_data&) ;
  extern void NSLmult_equal(nsl_num_matrix&,const nsl_num_matrix&,
		const nsl_num_vector&) ;
  extern void NSLmult_equal(nsl_num_matrix&,const nsl_num_matrix&,
		const nsl_num_matrix&) ;

// mult_plus

// data

  extern void NSLmult_plus(nsl_num_data&,const nsl_num_data&,const num_type&) ;
  extern void NSLmult_plus(nsl_num_data&,const nsl_num_vector&,
		const nsl_num_data&) ;
  extern void NSLmult_plus(nsl_num_data&,const nsl_num_vector&,
		const nsl_num_vector&) ;
  extern void NSLmult_plus(nsl_num_data&,const nsl_num_data&,const nsl_num_data&) ;
  extern void NSLmult_plus(nsl_num_data&,const nsl_num_data&,
		const nsl_num_vector&) ;

// vector

  extern void NSLmult_plus(nsl_num_vector&,const nsl_num_vector&,
		const num_type&) ;
  extern void NSLmult_plus(nsl_num_vector&,const nsl_num_vector&,
		const nsl_num_data&) ;
  extern void NSLmult_plus(nsl_num_vector&,const nsl_num_vector&,
		const nsl_num_vector&) ;
  extern void NSLmult_plus(nsl_num_vector&,const nsl_num_data&,
		const num_type&) ;
  extern void NSLmult_plus(nsl_num_vector&,const nsl_num_data&,
		const nsl_num_data&) ;
  extern void NSLmult_plus(nsl_num_vector&,const nsl_num_data&,
		const nsl_num_vector&) ;

// matrix

  extern void NSLmult_plus(nsl_num_matrix&,const nsl_num_matrix&,
		const num_type&) ;
  extern void NSLmult_plus(nsl_num_matrix&,const nsl_num_matrix&,
		const nsl_num_data&) ;
  extern void NSLmult_plus(nsl_num_matrix&,const nsl_num_matrix&,
		const nsl_num_matrix&) ;
  extern void NSLmult_plus(nsl_num_matrix&,const nsl_num_data&,
		const num_type&) ;
  extern void NSLmult_plus(nsl_num_matrix&,const nsl_num_data&,
		const nsl_num_data&) ;
  extern void NSLmult_plus(nsl_num_matrix&,const nsl_num_data&,
		const nsl_num_matrix&) ;

// mult_minus

// data

  extern void NSLmult_minus(nsl_num_data&,const nsl_num_data&,const num_type&) ;
  extern void NSLmult_minus(nsl_num_data&,const nsl_num_vector&,
		const nsl_num_data&) ;
  extern void NSLmult_minus(nsl_num_data&,const nsl_num_vector&,
		const nsl_num_vector&) ;
  extern void NSLmult_minus(nsl_num_data&,const nsl_num_data&,
		const nsl_num_data&) ;
  extern void NSLmult_minus(nsl_num_data&,const nsl_num_data&,
		const nsl_num_vector&) ;

// vector

  extern void NSLmult_minus(nsl_num_vector&,const nsl_num_vector&,
		const num_type&) ;
  extern void NSLmult_minus(nsl_num_vector&,const nsl_num_vector&,
		const nsl_num_data&) ;
  extern void NSLmult_minus(nsl_num_vector&,const nsl_num_vector&,
		const nsl_num_vector&) ;
  extern void NSLmult_minus(nsl_num_vector&,const nsl_num_data&,
		const num_type&) ;
  extern void NSLmult_minus(nsl_num_vector&,const nsl_num_data&,
		const nsl_num_data&) ;
  extern void NSLmult_minus(nsl_num_vector&,const nsl_num_data&,
		const nsl_num_vector&) ;

// matrix

  extern void NSLmult_minus(nsl_num_matrix&,const nsl_num_matrix&,
		const num_type&) ;
  extern void NSLmult_minus(nsl_num_matrix&,const nsl_num_matrix&,
		const nsl_num_data&) ;
  extern void NSLmult_minus(nsl_num_matrix&,const nsl_num_matrix&,
		const nsl_num_vector&) ;
  extern void NSLmult_minus(nsl_num_matrix&,const nsl_num_data&,
		const num_type&) ;
  extern void NSLmult_minus(nsl_num_matrix&,const nsl_num_data&,
		const nsl_num_data&) ;
  extern void NSLmult_minus(nsl_num_matrix&,const nsl_num_data&,
		const nsl_num_matrix&) ;

// add_equal

  extern void NSLadd_equal(nsl_num_data&,const nsl_num_matrix&) ;
  extern void NSLadd_equal(nsl_num_data&,const nsl_num_vector&) ;
  extern void NSLadd_equal(nsl_num_data&,const nsl_num_data&) ;

  extern void NSLadd_equal(nsl_num_vector&,const nsl_num_matrix&) ;
  extern void NSLadd_equal(nsl_num_vector&,const nsl_num_vector&) ;
  extern void NSLadd_equal(nsl_num_vector&,const nsl_num_data&) ;

  extern void NSLadd_equal(nsl_num_matrix&,const nsl_num_matrix&) ;
  extern void NSLadd_equal(nsl_num_matrix&,const nsl_num_vector&) ;
  extern void NSLadd_equal(nsl_num_matrix&,const nsl_num_0&) ;

  //fwd dec temp fix -bn7
  //extern void NSLadd_equal(nsl_num_2&,const nsl_num_0&);
// add_plus

  extern void NSLadd_plus(nsl_num_data&,const nsl_num_matrix&) ;
  extern void NSLadd_plus(nsl_num_data&,const nsl_num_vector&) ;
  extern void NSLadd_plus(nsl_num_data&,const nsl_num_data&) ;

  extern void NSLadd_plus(nsl_num_vector&,const nsl_num_vector&) ;
  extern void NSLadd_plus(nsl_num_vector&,const nsl_num_data&) ;

  extern void NSLadd_plus(nsl_num_matrix&,const nsl_num_matrix&) ;
  extern void NSLadd_plus(nsl_num_matrix&,const nsl_num_data&) ;

// add_minus

  extern void NSLadd_minus(nsl_num_data&,const nsl_num_matrix&) ;
  extern void NSLadd_minus(nsl_num_data&,const nsl_num_vector&) ;
  extern void NSLadd_minus(nsl_num_data&,const nsl_num_data&) ;

  extern void NSLadd_minus(nsl_num_vector&,const nsl_num_vector&) ;
  extern void NSLadd_minus(nsl_num_vector&,const nsl_num_data&) ;

  extern void NSLadd_minus(nsl_num_matrix&,const nsl_num_matrix&) ;
  extern void NSLadd_minus(nsl_num_matrix&,const nsl_num_data&) ;

//modified
  extern void NSLadd_equal(nsl_num_matrix& out,const nsl_num_data& a);
  extern void NSLadd_equal(nsl_num_data& out,const nsl_num_data& a);
  extern void NSLadd_equal(nsl_num_data& out,const nsl_num_vector& a);
  extern void NSLadd_equal(nsl_num_matrix& out,const nsl_num_matrix& a);

  //
  //	nsl_num_library.C
  //

  ///////////////////////////////////////////EXTENDED OVERLOADS/////////////////////////////////-bn7
  //qual

  // data
  //!!! changed any class from nsl_num_data,matrix,vector to typedef if they have [] operator CALLED
  extern void NSLmult_equal(nsl_num_data& out, nsl_num_data& a, num_type& b);

  extern void NSLmult_equal(nsl_num_data& out, nsl_num_vector& a,
  	 nsl_num_data& b);

  extern void NSLmult_equal(nsl_num_data& out, nsl_num_vector& a,
  	 nsl_num_vector& b);

  extern void NSLmult_equal(nsl_num_data& out, nsl_num_matrix& a,
  	 nsl_num_data& b);

  extern void NSLmult_equal(nsl_num_data& out, nsl_num_matrix& a,
  	 nsl_num_matrix& b);
  extern void NSLmult_equal(nsl_num_data& out, nsl_num_data& a,
  	 nsl_num_data& b);
  extern void NSLmult_equal(nsl_num_data& out, nsl_num_data& a,
  	 nsl_num_vector& b);

  extern void NSLmult_equal(nsl_num_data& out, nsl_num_data& a,
  	 nsl_num_matrix& b);

  // vector

  extern void NSLmult_equal(nsl_num_vector& out, nsl_num_vector& a,
  	 num_type& b);

  extern void NSLmult_equal(nsl_num_vector& out, const nsl_num_vector& a,
  	 const num_type& b);

  extern void NSLmult_equal(nsl_num_vector& out, nsl_num_vector& a,
  	 nsl_num_data& b);
  extern void NSLmult_equal(nsl_num_vector& out, nsl_num_vector& a,
  	 nsl_num_vector& b);
  // mat to vec

  extern void NSLmult_equal(nsl_num_vector& out, nsl_num_matrix& b,
  	 nsl_num_data& a);
  extern void NSLmult_equal(nsl_num_vector& out, nsl_num_matrix& a,
  	 nsl_num_vector& b);
  extern void NSLmult_equal(nsl_num_vector& out, nsl_num_data& a,
  	 nsl_num_data& b);

  extern void NSLmult_equal(nsl_num_vector& out, nsl_num_data& a,
  	 nsl_num_vector& b);
  // matrix

  extern void NSLmult_equal(nsl_num_matrix& out, nsl_num_matrix& a,
  	 num_type& b);
  extern void NSLmult_equal(nsl_num_matrix& out, nsl_num_matrix& a,
  	 nsl_num_data& b);

  extern void NSLmult_equal(nsl_num_matrix& out, nsl_num_matrix& a,
  	 nsl_num_matrix& b);
  // matrix conv
  // fix for no allocation/deallocation of d

  extern void NSLmult_equal(nsl_num_matrix& out, nsl_num_matrix& b,
  	 nsl_num_vector& a);
  // vec to mat

  extern void NSLmult_equal(nsl_num_matrix& out, nsl_num_vector& b,
  	 nsl_num_data& a);
  extern void NSLmult_equal(nsl_num_matrix& out, nsl_num_data& a,
  	 num_type& b);

  extern void NSLmult_equal(nsl_num_matrix& out, nsl_num_data& a,
  	 nsl_num_data& b);
  extern void NSLmult_equal(nsl_num_matrix& out, nsl_num_data& a,
  	 nsl_num_matrix& b);
  // mult_plus

  // data

  extern void NSLmult_plus(nsl_num_data& out, nsl_num_data& a, num_type& b);

  extern void NSLmult_plus(nsl_num_data& out, nsl_num_vector& a,
  	 nsl_num_data& b);

  extern void NSLmult_plus(nsl_num_data& out, nsl_num_vector& a,
  	 nsl_num_vector& b);
  extern void NSLmult_plus(nsl_num_data& out, nsl_num_data& a,
  	 nsl_num_data& b);

  extern void NSLmult_plus(nsl_num_data& out, nsl_num_data& a,
  	 nsl_num_vector& b);
  // vector

  extern void NSLmult_plus(nsl_num_vector& out, nsl_num_vector& a, num_type& b);
  extern void NSLmult_plus(nsl_num_vector& out, nsl_num_vector& a,
  	 nsl_num_data& b);
  extern void NSLmult_plus(nsl_num_vector& out, nsl_num_vector& a,
  	 nsl_num_vector& b);

  extern void NSLmult_plus(nsl_num_vector& out, nsl_num_data& a,
  	 num_type& b);

  extern void NSLmult_plus(nsl_num_vector& out, nsl_num_data& a,
  	 nsl_num_data& b);

  extern void NSLmult_plus(nsl_num_vector& out, nsl_num_data& a,
  	 nsl_num_vector& b);
  // matrix

  extern void NSLmult_plus(nsl_num_matrix& out, nsl_num_matrix& a,
  	 num_type& b);

  extern void NSLmult_plus(nsl_num_matrix& out, nsl_num_matrix& a,
  	 nsl_num_data& b);

  extern void NSLmult_plus(nsl_num_matrix& out, nsl_num_matrix& a,
  	 nsl_num_matrix& b);

  extern void NSLmult_plus(nsl_num_matrix& out, nsl_num_data& a,
  	 num_type& b);

  extern void NSLmult_plus(nsl_num_matrix& out, nsl_num_data& a,
  	 nsl_num_data& b);
  extern void NSLmult_plus(nsl_num_matrix& out, nsl_num_data& a,
  	 nsl_num_matrix& b);
  // mult_minus

  // data

  extern void NSLmult_minus(nsl_num_data& out, nsl_num_data& a, num_type& b);
  extern void NSLmult_minus(nsl_num_data& out, nsl_num_vector& a,
  	 nsl_num_data& b);
  extern void NSLmult_minus(nsl_num_data& out, nsl_num_vector& a,
  	 nsl_num_vector& b);
  extern void NSLmult_minus(nsl_num_data& out, nsl_num_data& a,
  	 nsl_num_data& b);
  extern void NSLmult_minus(nsl_num_data& out, nsl_num_data& a,
  	 nsl_num_vector& b);
  // vector

  extern void NSLmult_minus(nsl_num_vector& out, nsl_num_vector& a,
  	 num_type& b);

  extern void NSLmult_minus(nsl_num_vector& out, nsl_num_vector& a,
  	 nsl_num_data& b);

  extern void NSLmult_minus(nsl_num_vector& out, nsl_num_vector& a,
  	 nsl_num_vector& b);

  extern void NSLmult_minus(nsl_num_vector& out, nsl_num_data& a,
  	 num_type& b);
  extern void NSLmult_minus(nsl_num_vector& out, nsl_num_data& a,
  	 nsl_num_data& b);

  extern void NSLmult_minus(nsl_num_vector& out, nsl_num_data& a,
  	 nsl_num_vector& b);
  // matrix

  extern void NSLmult_minus(nsl_num_matrix& out, nsl_num_matrix& a,
  	 num_type& b);

  extern void NSLmult_minus(nsl_num_matrix& out, nsl_num_matrix& a,
  	 nsl_num_data& b);
  extern void NSLmult_minus(nsl_num_matrix& out, nsl_num_matrix& a,
  	 nsl_num_matrix& b);

  extern void NSLmult_minus(nsl_num_matrix& out, nsl_num_data& a,
  	 num_type& b);

  extern void NSLmult_minus(nsl_num_matrix& out, nsl_num_data& a,
  	 nsl_num_data& b);
  extern void NSLmult_minus(nsl_num_matrix& out, nsl_num_data& a,
  	 nsl_num_matrix& b);
  // add_equal

  // data

  extern void NSLadd_equal(nsl_num_data& out, nsl_num_matrix& a);
  extern void NSLadd_equal(nsl_num_data& out, nsl_num_vector& a);
  extern void NSLadd_equal(nsl_num_data& out, nsl_num_vector& a);

  extern void NSLadd_equal(nsl_num_data& out, nsl_num_data& a);
  extern void NSLadd_equal(nsl_num_data& out, nsl_num_0& a);// { };//TODO: revise -bn7

  extern void NSLadd_equal(nsl_num_data& out, nsl_num_data& a);

  // vector

  extern void NSLadd_equal(nsl_num_vector& out, nsl_num_vector& a);

  extern void NSLadd_equal(nsl_num_vector& out, nsl_num_vector& a);
  extern void NSLadd_equal(nsl_num_vector& out, nsl_num_data& a);

  extern void NSLadd_equal(nsl_num_vector& out, nsl_num_0& a);
  extern void NSLadd_equal(nsl_num_vector& out, nsl_num_matrix& a);
  // matrix

  extern void NSLadd_equal(nsl_num_matrix& out, nsl_num_matrix& a);
  extern void NSLadd_equal(nsl_num_matrix& out, nsl_num_matrix& a);

  extern void NSLadd_equal(nsl_num_matrix& out, nsl_num_0& a);


  extern void NSLadd_equal(nsl_num_matrix& out, nsl_num_data& a);// { };
  // vec_to_mat

  extern void NSLadd_equal(nsl_num_matrix& out, nsl_num_vector& a);
  // add_plus

  // data

  extern void NSLadd_plus(nsl_num_data& out, nsl_num_matrix& a);
  extern void NSLadd_plus(nsl_num_data& out, nsl_num_vector& a);
  extern void NSLadd_plus(nsl_num_data& out, nsl_num_data& a);
  extern void NSLadd_plus(nsl_num_vector& out, nsl_num_vector& a);
  extern void NSLadd_plus(nsl_num_vector& out, nsl_num_data& a);

  extern void NSLadd_plus(nsl_num_matrix& out, nsl_num_matrix& a);
  extern void NSLadd_plus(nsl_num_matrix& out, nsl_num_data& a);

  extern void NSLadd_minus(nsl_num_data& out, nsl_num_matrix& a);
  extern void NSLadd_minus(nsl_num_data& out, nsl_num_vector& a);
  extern void NSLadd_minus(nsl_num_data& out, nsl_num_data& a);
  extern void NSLadd_minus(nsl_num_data& out, nsl_num_0& a);

  extern void NSLadd_minus(nsl_num_vector& out, nsl_num_vector& a);
  extern void NSLadd_minus(nsl_num_vector& out, nsl_num_data& a);

  extern void NSLadd_minus(nsl_num_vector& out, nsl_num_0& a);// { };

  extern void NSLadd_minus(nsl_num_matrix& out, nsl_num_matrix& a);
  extern void NSLadd_minus(nsl_num_matrix& out, nsl_num_data& a);

  extern void NSLmult_equal(nsl_num_matrix& out, const nsl_num_matrix& a,
			 const num_type& b);
  extern void NSLmult_plus(nsl_num_matrix& out, const nsl_num_matrix& a,
			 const num_type& b);

  void NSLmult_equal(nsl_num_0 &, nsl_num_0 &, num_type&);
  void NSLmult_plus(nsl_num_0 &, nsl_num_0 &, num_type&);
  void NSLmult_equal(nsl_num_2& out,const nsl_num_2& a,
  	const num_type& b);
  void NSLmult_plus(nsl_num_2& out, nsl_num_2& a,num_type& b);
#endif
