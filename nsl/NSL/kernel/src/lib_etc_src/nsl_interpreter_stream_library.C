/* SCCS  @(#)nsl_interpreter_stream_library.C	1.1---95/08/13--20:46:10 */
//
// nsl_interpreter_stream_library.C
//

#include <stdio.h>
#include "nsl_kernel.h"
#include "nsl_stream.h"

// char

nsl_interpreter& operator>>(nsl_interpreter& nsl,char& val)
{
	nsl.init_input();

	nsl.get_buffer() >> val;

	nsl.end_input();

	return nsl;
}
nsl_interpreter& operator<<(nsl_interpreter& nsl,char val)
{
	nsl.get_buffer() << val;

	return nsl;
}

// str

nsl_interpreter& operator>>(nsl_interpreter& nsl,char* str)
{
	nsl.init_input();

	nsl.get_buffer() >> str;

	nsl.end_input();

	return nsl;
}
nsl_interpreter& operator<<(nsl_interpreter& nsl,const char* str0)
{
	int len,j = 0;
	nsl_string str,tmp;
	char c = 0;

	nsl_buffer& buf = nsl.get_buffer();

	strcpy(tmp,""); 
	strcpy(str,"");

	if ((len = strlen(str0)) > 0)
	{
// '\n' has to be read from keyboard independently
// general: get read of initial "space" char
		while (j <= len && (c = str0[j]) != EOF && 
		    (c == ' ' || c == '\t' || c == '\n'))
			j++;

// read actual strings until endl
		while (j <= len && (c = str0[j]) != EOF && c != '\n')
		{
// get rid of in between spaces
		// get rid of any extra spaces
			while (j <= len && (c = str0[j]) != EOF && 
			    (c == ' ' || c == '\t'))
				j++;

		// read string into tmp buffer, w/o extra spaces and endlines
			int i = 0;
			while (j <= len && (c = str0[j]) != EOF
			    && c != '\n' && c != ' ' && c != '\t')
			{
		   	    	tmp[i] = c;
				tmp[i+1] = '\0';
				i++;
				j++;
			}

			int ilen = i;

		// read str from tmp w/o any comments
			str[0] = '\0';	// reset str
			if (ilen > 0) // string
			{
		    		str[0] = tmp[0];
		   		i = 1;
		    		while (i < ilen)
		    		{
			// get rid of comments
				    if (tmp[i-1] == '/' && tmp[i] == '/')
				    {
			    		ilen = i-1;
	   	 	    		str[ilen] = '\0';
			   		while (j <= len && (c = str0[j]) != EOF
					    && c != '\n')
						j++;
				    }
				    else
			    		str[i] = tmp[i];
				    i++;
		    		}
		    		if (ilen > 0)
		    		{
		        	    str[ilen] = '\0';
				    buf << str; // copy str into buffer
		    		}
			}

			if (c != '\n') // read endl separately w/o skipping
				j++;
		}

		if (c == '\n')
			buf.set_line_fg(1);

		if (c == EOF)
			buf.set_eof_fg(-1);
	}

	return nsl;
}

// int

nsl_interpreter& operator>>(nsl_interpreter& nsl,int& val)
{
	nsl.init_input();

	nsl.get_buffer() >> val;

	nsl.end_input();

	return nsl;
}
nsl_interpreter& operator<<(nsl_interpreter& nsl,int val)
{
	nsl.get_buffer() << val;

	return nsl;
}

// float

nsl_interpreter& operator>>(nsl_interpreter& nsl,float& val)
{
	nsl.init_input();

	nsl.get_buffer() >> val;

	nsl.end_input();

	return nsl;
}
nsl_interpreter& operator<<(nsl_interpreter& nsl,float val)
{
	nsl.get_buffer() << val;

	return nsl;
}

// layer

nsl_interpreter& operator>>(nsl_interpreter& nsl,nsl_layer& layer)
{
	nsl.init_input();

	nsl.get_buffer() >> layer;

	nsl.end_input();

	return nsl;
}

nsl_interpreter& operator<<(nsl_interpreter& nsl,nsl_layer& layer)
{
	nsl.init_input();

	nsl.get_buffer() << layer;

	nsl.end_input();

	return nsl;
}

// data layer

nsl_interpreter& operator>>(nsl_interpreter& nsl,nsl_data_layer& layer)
{
	nsl.init_input();

	nsl.get_buffer() >> layer;

	nsl.end_input();

	return nsl;
}

nsl_interpreter& operator<<(nsl_interpreter& nsl,nsl_data_layer& layer)
{
	nsl.init_input();

	nsl.get_buffer() << layer;

	nsl.end_input();

	return nsl;
}

// int data
/*
nsl_interpreter& operator>>(nsl_interpreter& nsl,nsl_int_data& layer)
{
	nsl.init_input();

	nsl.get_buffer() >> layer;

	nsl.end_input();

	return nsl;
}

nsl_interpreter& operator<<(nsl_interpreter& nsl,nsl_int_data& layer)
{
	nsl.init_input();

	nsl.get_buffer() << layer;

	nsl.end_input();

	return nsl;
}
*/
// num data
/*
nsl_interpreter& operator>>(nsl_interpreter& nsl,nsl_num_0& layer)
{
	nsl.init_input();

	nsl.get_buffer() >> layer;

	nsl.end_input();

	return nsl;
}

nsl_interpreter& operator<<(nsl_interpreter& nsl,nsl_num_0& layer)
{
	nsl.init_input();

	nsl.get_buffer() << layer;

	nsl.end_input();

	return nsl;
} */

// str data

nsl_interpreter& operator>>(nsl_interpreter& nsl,nsl_str_data& layer)
{
	nsl.init_input();

	nsl.get_buffer() >> layer;

	nsl.end_input();

	return nsl;
}

nsl_interpreter& operator<<(nsl_interpreter& nsl,nsl_str_data& layer)
{
	nsl.init_input();

	nsl.get_buffer() << layer;

	nsl.end_input();

	return nsl;
}

// ptr data

nsl_interpreter& operator>>(nsl_interpreter& nsl,nsl_ptr_data& layer)
{
	nsl.init_input();

	nsl.get_buffer() >> layer;

	nsl.end_input();

	return nsl;
}

nsl_interpreter& operator<<(nsl_interpreter& nsl,nsl_ptr_data& layer)
{
	nsl.init_input();

	nsl.get_buffer() << layer;

	nsl.end_input();

	return nsl;
}


// vector layer

nsl_interpreter& operator>>(nsl_interpreter& nsl,nsl_vector_layer& layer)
{
	nsl.init_input();

	nsl.get_buffer() >> layer;

	nsl.end_input();

	return nsl;
}

nsl_interpreter& operator<<(nsl_interpreter& nsl,nsl_vector_layer& layer)
{
	nsl.init_input();

	nsl.get_buffer() << layer;

	nsl.end_input();

	return nsl;
}

// int vector
/*
nsl_interpreter& operator>>(nsl_interpreter& nsl,nsl_int_vector& layer)
{
	nsl.init_input();

	nsl.get_buffer() >> layer;

	nsl.end_input();

	return nsl;
}

nsl_interpreter& operator<<(nsl_interpreter& nsl,nsl_int_vector& layer)
{
	nsl.init_input();

	nsl.get_buffer() << layer;

	nsl.end_input();

	return nsl;
}
*/
// num vector
/*
nsl_interpreter& operator>>(nsl_interpreter& nsl,nsl_num_1& layer)
{
	nsl.init_input();

	nsl.get_buffer() >> layer;

	nsl.end_input();

	return nsl;
}
*/
nsl_interpreter& operator<<(nsl_interpreter& nsl,nsl_num_1& layer)
{
	nsl.init_input();

	nsl.get_buffer() << layer;

	nsl.end_input();

	return nsl;
}

// str vector

nsl_interpreter& operator>>(nsl_interpreter& nsl,nsl_str_vector& layer)
{
	nsl.init_input();

	nsl.get_buffer() >> layer;

	nsl.end_input();

	return nsl;
}

nsl_interpreter& operator<<(nsl_interpreter& nsl,nsl_str_vector& layer)
{
	nsl.init_input();

	nsl.get_buffer() << layer;

	nsl.end_input();

	return nsl;
}

// ptr vector

nsl_interpreter& operator>>(nsl_interpreter& nsl,nsl_ptr_vector& layer)
{
	nsl.init_input();

	nsl.get_buffer() >> layer;

	nsl.end_input();

	return nsl;
}

nsl_interpreter& operator<<(nsl_interpreter& nsl,nsl_ptr_vector& layer)
{
	nsl.init_input();

	nsl.get_buffer() << layer;

	nsl.end_input();

	return nsl;
}


// matrix layer

nsl_interpreter& operator>>(nsl_interpreter& nsl,nsl_matrix_layer& layer)
{
	nsl.init_input();

	nsl.get_buffer() >> layer;

	nsl.end_input();

	return nsl;
}

nsl_interpreter& operator<<(nsl_interpreter& nsl,nsl_matrix_layer& layer)
{
	nsl.init_input();

	nsl.get_buffer() << layer;

	nsl.end_input();

	return nsl;
}

// int matrix
/*
nsl_interpreter& operator>>(nsl_interpreter& nsl,nsl_int_matrix& layer)
{
	nsl.init_input();

	nsl.get_buffer() >> layer;

	nsl.end_input();

	return nsl;
}

nsl_interpreter& operator<<(nsl_interpreter& nsl,nsl_int_matrix& layer)
{
	nsl.init_input();

	nsl.get_buffer() << layer;

	nsl.end_input();

	return nsl;
}
*/
// num matrix
/*
nsl_interpreter& operator>>(nsl_interpreter& nsl,nsl_num_2& layer)
{
	nsl.init_input();

	nsl.get_buffer() >> layer;

	nsl.end_input();

	return nsl;
}

nsl_interpreter& operator<<(nsl_interpreter& nsl,nsl_num_2& layer)
{
	nsl.init_input();

	nsl.get_buffer() << layer;

	nsl.end_input();

	return nsl;
}
*/
// str matrix

nsl_interpreter& operator>>(nsl_interpreter& nsl,nsl_str_matrix& layer)
{
	nsl.init_input();

	nsl.get_buffer() >> layer;

	nsl.end_input();

	return nsl;
}

nsl_interpreter& operator<<(nsl_interpreter& nsl,nsl_str_matrix& layer)
{
	nsl.init_input();

	nsl.get_buffer() << layer;

	nsl.end_input();

	return nsl;
}

// ptr matrix

nsl_interpreter& operator>>(nsl_interpreter& nsl,nsl_ptr_matrix& layer)
{
	nsl.init_input();

	nsl.get_buffer() >> layer;

	nsl.end_input();

	return nsl;
}

nsl_interpreter& operator<<(nsl_interpreter& nsl,nsl_ptr_matrix& layer)
{
	nsl.init_input();

	nsl.get_buffer() << layer;

	nsl.end_input();

	return nsl;
}

// istd::ostream

nsl_interpreter& operator<<(nsl_interpreter& nsl,std::istream& in)
{
	nsl.get_buffer() << in;

	return nsl;
}
nsl_interpreter& operator>>(nsl_interpreter& nsl,std::ostream& out)
{
	nsl.get_buffer() >> out;

	return nsl;
}

nsl_interpreter& operator<<(nsl_interpreter& nsl,std::fstream& in)
{
	nsl << (std::istream&) in;

	return nsl;
}

nsl_interpreter& operator>>(nsl_interpreter& nsl,std::fstream& out)
{
	nsl.get_buffer() >> out;

	return nsl;
}

std::istream& operator>>(std::istream& in,nsl_interpreter& nsl) // in >> nsl
{
	nsl << in;

	return in;
}

std::ostream& operator<<(std::ostream& out,nsl_interpreter& nsl) // out << nsl
{
	nsl >> out;

	return out;
}

std::fstream& operator>>(std::fstream& in,nsl_interpreter& nsl) // in >> buf
{
	nsl << in;

	return in;
}

std::fstream& operator<<(std::fstream& out,nsl_interpreter& nsl) // out << buf
{
	out << nsl;

	return out;
}

