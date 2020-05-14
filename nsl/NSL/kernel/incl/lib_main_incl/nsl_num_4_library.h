void NSLmult_equal(nsl_num_4& out,const nsl_num_4& a,
	const num_type& b);
//template<class NslNumType, int NslTypeId>
void NSLmult_equal(nsl_num_4& out,const num_type& b,
	const nsl_num_4& a);
//template<class NslNumType, int NslTypeId>
void NSLmult_plus(nsl_num_4& out,const nsl_num_4& a,
	const num_type& b);
//template<class NslNumType, int NslTypeId>
void NSLmult_plus(nsl_num_4& out,const num_type& b,
	const nsl_num_4& a);


nsl_num_4 operator*(const nsl_num_4& a,const num_type b);
//template<class NslNumType, int NslTypeId>
nsl_num_4 operator*(const num_type a, const nsl_num_4& b);


nsl_num_4 operator+(const nsl_num_4& a);
//template<class NslNumType, int NslTypeId>
nsl_num_4 operator+(const nsl_num_4& a,const nsl_num_4& b);
//template<class NslNumType, int NslTypeId>
nsl_num_4 operator+(const nsl_num_4& a,const num_type b);
//template<class NslNumType, int NslTypeId>
nsl_num_4 operator+(const num_type a, const nsl_num_4& b);
//template<class NslNumType, int NslTypeId>
nsl_num_4 operator+(const nsl_num_4& a,const nsl_num_0& b);
//template<class NslNumType, int NslTypeId>
nsl_num_4 operator+(const nsl_num_0& a, const nsl_num_4& b);
// num_4 addtraction
//template<class NslNumType, int NslTypeId>
nsl_num_4 NSLadd(const nsl_num_4& a);
//template<class NslNumType, int NslTypeId>
nsl_num_4 NSLadd(const nsl_num_4& a,const nsl_num_4& b);
//template<class NslNumType, int NslTypeId>
nsl_num_4 NSLadd(const nsl_num_4& a,const num_type b);
//template<class NslNumType, int NslTypeId>
nsl_num_4 NSLadd(const num_type a, const nsl_num_4& b);
//template<class NslNumType, int NslTypeId>
nsl_num_4 NSLadd(const nsl_num_4& a,const nsl_num_0& b);
//template<class NslNumType, int NslTypeId>
nsl_num_4 NSLadd(const nsl_num_0& a,const  nsl_num_4& b);

//template<class NslNumType, int NslTypeId>
void NSLadd_plus(const nsl_num_4& a,const nsl_num_4& b);
