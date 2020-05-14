#include "nsl_char_buf_stream_library.h"
#include "nsl_num.h"
//template<class NslNumType, int NslTypeId>
nsl_char_buf& operator>>(nsl_char_buf& buf,nsl_num_0& layer)
{
	layer.read_num_data(buf);

	return buf;
}
//template<class NslNumType, int NslTypeId>
nsl_char_buf& operator<<(nsl_char_buf& buf,nsl_num_0& layer)
{
	layer.write_num_data(buf);

	return buf;
}
//template<class NslNumType, int NslTypeId>
nsl_char_buf& operator>>(nsl_char_buf& buf,nsl_num_1& layer)
{
	layer.read_num_vector(buf);

	return buf;
}
//template<class NslNumType, int NslTypeId>
nsl_char_buf& operator<<(nsl_char_buf& buf,nsl_num_1& layer)
{
	layer.write_num_vector(buf);

	return buf;
}
//template<class NslNumType, int NslTypeId>
nsl_char_buf& operator>>(nsl_char_buf& buf,nsl_num_2& layer)
{
	layer.read_num_matrix(buf);

	return buf;
}
//template<class NslNumType, int NslTypeId>
nsl_char_buf& operator<<(nsl_char_buf& buf,nsl_num_2& layer)
{
	layer.write_num_matrix(buf);

	return buf;
}
