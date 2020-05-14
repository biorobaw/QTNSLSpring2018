/* SCCS  %W%---%E%--%U% */
//
// nsl_nsl_file_stream_library.C
//
#include <fstream>
#include "nsl_nsl_file_stream_library.h"
#include "nsl_nsl_file.h"
#include "nsl_stream.h"
#include "nsl_num.h"

using namespace std;
extern nsl_nsl_file& operator<<(nsl_nsl_file&,char*);


extern void cmd_error(const char *);

nsl_nsl_file& operator<<(nsl_nsl_file& f,char* str)
{
	fstream* fs;

	if ((fs = f.get_file_stream()) != NULL)
		(*fs) << str;
	else
		cmd_error("NULL fstream in nsl_nsl_file");

	return f;
}



//template<class NslNumType, int NslTypeId>
std::istream& operator>>(std::istream& in,nsl_num_0& layer)
{
	in >> layer.elem();

	return in;
}
//template<class NslNumType, int NslTypeId>
std::istream& operator>>(std::istream& in,nsl_num_1& layer)
{
	int i0 = layer.get_i0();
	int i1 = layer.get_i1();

	for (int i = i0; i <= i1; i++)
		in >> layer[i];

	return in;
}
////template<class NslNumType, int NslTypeId>
std::istream& operator>>(std::istream& in,nsl_num_2& layer)
{
	int i0 = layer.get_i0();
	int i1 = layer.get_i1();
	int j0 = layer.get_j0();
	int j1 = layer.get_j1();

	for (int i = i0; i <= i1; i++)
	    for (int j = j0; j <= j1; j++)
		in >> layer[i][j];

	return in;
}
//template<class NslNumType, int NslTypeId>
std::ostream& operator<<(std::ostream& out,nsl_num_0& layer)
{
	out << layer.elem();

	return out;
}
//template<class NslNumType, int NslTypeId>
std::ostream& operator<<(std::ostream& out,nsl_num_1& layer)
{
	int i0 = layer.get_i0();
	int i1 = layer.get_i1();

	for (int i = i0; i <= i1; i++)
		out << layer[i];

	return out;
}
//template<class NslNumType, int NslTypeId>
std::ostream& operator<<(std::ostream& out,nsl_num_2& layer)
{
	int i0 = layer.get_i0();
	int i1 = layer.get_i1();
	int j0 = layer.get_j0();
	int j1 = layer.get_j1();

	for (int i = i0; i <= i1; i++)
	    for (int j = j0; j <= j1; j++)
		out << layer[i][j];

	return out;
}


/* SCCS  %W%---%E%--%U% */
//
// nsl_nsl_file_stream_library.C
//

# include "nsl_all_kernel_include.h"

nsl_file& operator>>(nsl_file& f,unsigned char& data)
{
	fstream* fs;

	if ((fs = f.get_file_stream()) != NULL)
		fs->get(); // (*fs) >> data;
	else
		cmd_error("NULL fstream in nsl_file");

	return f;
}

nsl_file& operator<<(nsl_file& f,unsigned char& data)
{
	fstream* fs;

	if ((fs = f.get_file_stream()) != NULL)
		fs->put(data); // (*fs) << data;
	else
		cmd_error("NULL fstream in nsl_file");

	return f;
}

nsl_file& operator>>(nsl_file& f,char& data)
{
	fstream* fs;

	if ((fs = f.get_file_stream()) != NULL)
		(*fs) >> data;
	else
		cmd_error("NULL fstream in nsl_file");

	return f;
}

nsl_file& operator<<(nsl_file& f,char& data)
{
	fstream* fs;

	if ((fs = f.get_file_stream()) != NULL)
		(*fs) << data;
	else
		cmd_error("NULL fstream in nsl_file");

	return f;
}

nsl_file& operator>>(nsl_file& f,char* data)
{
	fstream* fs;

	if ((fs = f.get_file_stream()) != NULL)
		(*fs) >> data;
	else
		cmd_error("NULL fstream in nsl_file");

	return f;
}
nsl_file& operator<<(nsl_file& f,char* data)
{
	fstream* fs;

	if ((fs = f.get_file_stream()) != NULL)
		(*fs) << data;
	else
		cmd_error("NULL fstream in nsl_file");

	return f;
}

nsl_file& operator>>(nsl_file& f,int& data)
{
	fstream* fs;

	if ((fs = f.get_file_stream()) != NULL)
		(*fs) >> data;
	else
		cmd_error("NULL fstream in nsl_file");

	return f;
}

nsl_file& operator<<(nsl_file& f,int& data)
{
	fstream* fs;

	if ((fs = f.get_file_stream()) != NULL)
		(*fs) << data;
	else
		cmd_error("NULL fstream in nsl_file");

	return f;
}
nsl_file& operator>>(nsl_file& f,float& data)
{
	fstream* fs;

	if ((fs = f.get_file_stream()) != NULL)
		(*fs) >> data;
	else
		cmd_error("NULL fstream in nsl_file");

	return f;
}
nsl_file& operator<<(nsl_file& f,float& data)
{
	fstream* fs;

	if ((fs = f.get_file_stream()) != NULL)
		(*fs) << data;
	else
		cmd_error("NULL fstream in nsl_file");

	return f;
}
nsl_file& operator>>(nsl_file& f,double& data)
{
	fstream* fs;

	if ((fs = f.get_file_stream()) != NULL)
		(*fs) >> data;
	else
		cmd_error("NULL fstream in nsl_file");

	return f;
}
nsl_file& operator<<(nsl_file& f,double& data)
{
	fstream* fs;

	if ((fs = f.get_file_stream()) != NULL)
		(*fs) << data;
	else
		cmd_error("NULL fstream in nsl_file");

	return f;
}

/*
template<class NslNumType>
istream& operator>>(istream& in,nsl_num_0<NslNumType>& layer)
{
	in >> layer.elem();

	return in;
}
template<class NslNumType>
istream& operator>>(istream& in,nsl_num_1<NslNumType>& layer)
{
	int i0 = layer.get_i0();
	int i1 = layer.get_i1();

	for (int i = i0; i <= i1; i++)
		in >> layer[i];

	return in;
}
template<class NslNumType>
istream& operator>>(istream& in,nsl_num_2<NslNumType>& layer)
{
	int i0 = layer.get_i0();
	int i1 = layer.get_i1();
	int j0 = layer.get_j0();
	int j1 = layer.get_j1();

	for (int i = i0; i <= i1; i++)
	    for (int j = j0; j <= j1; j++)
		in >> layer[i][j];

	return in;
}
template<class NslNumType>
ostream& operator<<(ostream& out,nsl_num_0<NslNumType>& layer)
{
	out << layer.elem();

	return out;
}
template<class NslNumType>
ostream& operator<<(ostream& out,nsl_num_1<NslNumType>& layer)
{
	int i0 = layer.get_i0();
	int i1 = layer.get_i1();

	for (int i = i0; i <= i1; i++)
		out << layer[i];

	return out;
}
template<class NslNumType>
ostream& operator<<(ostream& out,nsl_num_2<NslNumType>& layer)
{
	int i0 = layer.get_i0();
	int i1 = layer.get_i1();
	int j0 = layer.get_j0();
	int j1 = layer.get_j1();

	for (int i = i0; i <= i1; i++)
	    for (int j = j0; j <= j1; j++)
		out << layer[i][j];

	return out;
}
*/
