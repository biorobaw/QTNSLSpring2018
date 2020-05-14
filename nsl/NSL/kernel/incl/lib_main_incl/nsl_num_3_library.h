#include "nsl_num_3.h"
//class nsl_num_3;
typedef  float num_type;

void NSLmult_plus(nsl_num_3& out,const nsl_num_3& a,
	const num_type& b);


nsl_num_3 operator+(const nsl_num_3& a);
//template<class NslNumType, int NslTypeId>
nsl_num_3 operator+(const nsl_num_3& a,const nsl_num_3& b);
//template<class NslNumType, int NslTypeId>
nsl_num_3 operator+(const nsl_num_3& a,const num_type b);
//template<class NslNumType, int NslTypeId>
nsl_num_3 operator+(const num_type a, const nsl_num_3& b);
//template<class NslNumType, int NslTypeId>
nsl_num_3 operator+(const nsl_num_3& a,const nsl_num_0& b);
//template<class NslNumType, int NslTypeId>
nsl_num_3 operator+(const nsl_num_0& a, const nsl_num_3& b);
// num_3 addtraction
//template<class NslNumType, int NslTypeId>
nsl_num_3 NSLadd(const nsl_num_3& a);
//template<class NslNumType, int NslTypeId>
nsl_num_3 NSLadd(const nsl_num_3& a,const nsl_num_3& b);
//template<class NslNumType, int NslTypeId>
nsl_num_3 NSLadd(const nsl_num_3& a,const num_type b);
//template<class NslNumType, int NslTypeId>
nsl_num_3 NSLadd(const num_type a, const nsl_num_3& b);
//template<class NslNumType, int NslTypeId>
nsl_num_3 NSLadd(const nsl_num_3& a,const nsl_num_0& b);
//template<class NslNumType, int NslTypeId>
nsl_num_3 NSLadd(const nsl_num_0& a,const  nsl_num_3& b);


nsl_num_3 operator-(const nsl_num_3& a);
//template<class NslNumType, int NslTypeId>
nsl_num_3 operator-(const nsl_num_3& a,const nsl_num_3& b);
//template<class NslNumType, int NslTypeId>
nsl_num_3 operator-(const nsl_num_3& a,const num_type b);
//template<class NslNumType, int NslTypeId>
nsl_num_3 operator-(const num_type a, const nsl_num_3& b);
//template<class NslNumType, int NslTypeId>
nsl_num_3 operator-(const nsl_num_3& a,const nsl_num_0& b);
//template<class NslNumType, int NslTypeId>
nsl_num_3 operator-(const nsl_num_0& a, const nsl_num_3& b);

// num_3 subtraction
//template<class NslNumType, int NslTypeId>
nsl_num_3 NSLsub(const nsl_num_3& a);
//template<class NslNumType, int NslTypeId>
nsl_num_3 NSLsub(const nsl_num_3& a,const nsl_num_3& b);
//template<class NslNumType, int NslTypeId>
nsl_num_3 NSLsub(const nsl_num_3& a,const num_type b);
//template<class NslNumType, int NslTypeId>
nsl_num_3 NSLsub(const num_type a, const nsl_num_3& b);
//template<class NslNumType, int NslTypeId>
nsl_num_3 NSLsub(const nsl_num_3& a,const nsl_num_0& b);
//template<class NslNumType, int NslTypeId>
nsl_num_3 NSLsub(const nsl_num_0& a,const  nsl_num_3& b);

nsl_num_3 operator*(const nsl_num_3& a,const num_type b);
//template<class NslNumType, int NslTypeId>
nsl_num_3 operator*(const num_type a, const nsl_num_3& b);
