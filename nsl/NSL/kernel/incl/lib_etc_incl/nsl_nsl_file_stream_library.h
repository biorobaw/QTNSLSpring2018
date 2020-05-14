/* SCCS  @(#)nsl_nsl_file_stream_library.h	1.1---95/08/13--23:38:36 */
//
// nsl_nsl_file_stream_library.h
//
#include <iostream>

class nsl_nsl_file;
class nsl_file;

extern nsl_nsl_file& operator<<(nsl_nsl_file&,char*);

/* SCCS  @(#)nsl_nsl_file_stream_library.h	1.1---95/08/13--23:38:36 */
//
// nsl_nsl_file_stream_library.h
//

extern nsl_file& operator>>(nsl_file&,unsigned char&);
extern nsl_file& operator<<(nsl_file&,unsigned char&);
extern nsl_file& operator>>(nsl_file&,char&);
extern nsl_file& operator<<(nsl_file&,char&);
extern nsl_file& operator>>(nsl_file&,char*);
extern nsl_file& operator<<(nsl_file&,char*);
extern nsl_file& operator>>(nsl_file&,int&);
extern nsl_file& operator<<(nsl_file&,int&);
extern nsl_file& operator>>(nsl_file&,float&);
extern nsl_file& operator<<(nsl_file&,float&);
extern nsl_file& operator>>(nsl_file&,double&);
extern nsl_file& operator<<(nsl_file&,double&);

extern nsl_nsl_file& operator<<(nsl_nsl_file&,char*);
/*
//template<class NslNumType, int NslTypeId>
extern std::istream& operator>>(std::istream&,nsl_num_0&);
//template<class NslNumType, int NslTypeId>
extern std::istream& operator>>(std::istream&,nsl_num_1&);
//template<class NslNumType, int NslTypeId>
extern std::istream& operator>>(std::istream&,nsl_num_2&);
//template<class NslNumType, int NslTypeId>
extern std::ostream& operator<<(std::ostream&,nsl_num_0&);
//template<class NslNumType, int NslTypeId>
extern std::ostream& operator<<(std::ostream&,nsl_num_1&);
//template<class NslNumType, int NslTypeId>
extern std::ostream& operator<<(std::ostream&,nsl_num_2&);
*/

