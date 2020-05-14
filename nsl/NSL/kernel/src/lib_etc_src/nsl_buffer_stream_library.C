/* SCCS  @(#)nsl_buffer_stream_library.C	1.1---95/08/13--20:46:09 */
//
// nsl_buffer_stream_library.C
//

#include "nsl_buffer.h"
#include "nsl_kernel.h"
#include "nsl_cmd_macro.h"
#include "nsl_file.h"
#include "nsl_ptr_data.h"
#include "nsl_str_vector.h"
#include "nsl_str_matrix.h"
#include "nsl_ptr_matrix.h"
#include "nsl_ptr_vector.h"

typedef nsl_base_list nsl_list;
// char

extern void cmd_error(const char *, const char *);
extern void cmd_error(const char *, int);
extern int NSLoutput(const char* str);
extern int NSLoutput(const char* str, const char *);

nsl_buffer& operator>>(nsl_buffer& buf,char& c)
{
	buf.get_stream() >> c;

	return buf;
}
nsl_buffer& operator<<(nsl_buffer& buf,char c)
{
	buf.get_stream() << c; 

	return buf;
}

// string

// all strings (including int,float, layers, etc.)
// get read from buf using this routine
// macros are printed out but not logged
nsl_buffer& operator>>(nsl_buffer& buf, char* str)
{
	nsl_interpreter* nsl;
	nsl_file* f;
	int cnt,tp;
	nsl_list* list;
	const char* mstr;
 	nsl_cmd_macro* macro;
	nsl_cmd_buf* shell;
	
	if (buf.get_str_cnt() > 0)
	{
	    if (buf.get_line_fg() == 1)
	    {
		buf.set_line_fg(0);
		NSLoutput("\n");	// endl
	    }
	    buf.get_stream() >> str;
	    if ((nsl = (nsl_interpreter*) buf.get_m_parent()) != NULL)
	    {
		if ((shell = (nsl_cmd_buf*) nsl->get_shell_list()->
			get_top()) != NULL &&
			(list = shell->get_macro_list()) != NULL)
		{
		  while ((macro = (nsl_cmd_macro*) list->get_by_type(str)) != 0)
		  {
			mstr = macro->get_name();
			cnt = macro->get_str_cnt();
			nsl->get_buffer().reset_rewind_marker();
			nsl->putback(mstr,cnt);
			buf.get_stream() >> str;
 		  }
		}

		cnt = buf.get_macro_str_cnt();

		if ((tp = nsl->get_input_type()) != 0)
			NSLoutput(str," ");
	    	else if (nsl->get_log_able_fg() == NSL_ON
		    && (f = nsl->get_log_file()) != NULL)
		{
		    if (cnt == 0)
		    {
			// str file write 
		    	((std::ostream&) *(f->get_file_stream())) << str << " ";
		    	if (nsl->get_str_cnt() == 0)
				((std::ostream&) *(f->get_file_stream())) << endl;
		    }
		    NSLoutput(str," "); // one of these outside is enough !
		}

		if (cnt > 0)
			buf.set_macro_str_cnt(cnt-1);
	    }
	}
	else
		str[0] = '\0';

	return buf;
}

nsl_buffer& operator<<(nsl_buffer& buf, const char* str)
{
	if (strlen(str) > 0)
  		buf.get_stream() << str;
 
	return buf;
}

// int

nsl_buffer& operator>>(nsl_buffer& buf,int& val)
{
	nsl_string str;

	if (buf.get_str_cnt() > 0)
	{
		buf >> str;
		int error_fg = (int) sscanf(str,"%d",&val);
 		if (error_fg == 0)
		{
			error_fg = 1;
			cmd_error("Bad Input: ",str);
		}
		else
			error_fg = 0;
		buf.set_error_fg(error_fg);
	}

	return buf;
}
nsl_buffer& operator<<(nsl_buffer& buf,int val)
{
	nsl_string str;

	if (strlen(str) > 0)
	{
		int error_fg = (int) sprintf(str,"%d",val);
  		if (error_fg == 0)
		{
			error_fg = 1;
			cmd_error("Bad Output: ",val);
		}
 		else
		{
			error_fg = 0;
			buf << str;
		}
		buf.set_error_fg(error_fg);
 	}

	return buf;
}

// float

nsl_buffer& operator>>(nsl_buffer& buf,float& val)
{
	nsl_string str;

	if (buf.get_str_cnt() > 0)
	{
		buf >> str;
		int error_fg = (int) sscanf(str,"%f",&val);
		if (error_fg == 0)
		{
			error_fg = 1;
			cmd_error("Bad Input: ",str);
		}
		else
			error_fg = 0;
		buf.set_error_fg(error_fg);
	}

	return buf;
}
nsl_buffer& operator<<(nsl_buffer& buf,float val)
{
	nsl_string str;

	if (strlen(str) > 0)
	{
		int error_fg = (int) sprintf(str,"%f",val);
  		if (error_fg == 0)
		{
			error_fg = 1;
			cmd_error("Bad Output: ",val);
		}
		else
		{
			error_fg = 0;
			buf << str;
		}
		buf.set_error_fg(error_fg);
 	}

	return buf;
}

// layer

nsl_buffer& operator>>(nsl_buffer& buf,nsl_layer& layer)
{
	layer.read(buf);

	return buf;
}
nsl_buffer& operator<<(nsl_buffer& buf,nsl_layer& layer)
{
	layer.write(buf);

	return buf;
}

// data layer

nsl_buffer& operator>>(nsl_buffer& buf,nsl_data_layer& layer)
{
	layer.read(buf);

	return buf;
}
nsl_buffer& operator<<(nsl_buffer& buf,nsl_data_layer& layer)
{
	layer.write(buf);

	return buf;
}

// int data
/*
nsl_buffer& operator>>(nsl_buffer& buf,nsl_int_data& layer)
{
	layer.read_num_data(buf); // int

	return buf;
}
nsl_buffer& operator<<(nsl_buffer& buf,nsl_int_data& layer)
{
	layer.write_num_data(buf); // int

	return buf;
}
*/
// num data

nsl_buffer& operator>>(nsl_buffer& buf,nsl_num_0& layer)
{
	layer.read_num_data(buf);

	return buf;
}
nsl_buffer& operator<<(nsl_buffer& buf,nsl_num_0& layer)
{
	layer.write_num_data(buf);

	return buf;
}

// str data

nsl_buffer& operator>>(nsl_buffer& buf,nsl_str_data& layer)
{
	layer.read_str_data(buf);

	return buf;
}
nsl_buffer& operator<<(nsl_buffer& buf,nsl_str_data& layer)
{
	layer.write_str_data(buf);

	return buf;
}

// ptr data

nsl_buffer& operator>>(nsl_buffer& buf,nsl_ptr_data& layer)
{
	layer.read_ptr_data(buf);

	return buf;
}
nsl_buffer& operator<<(nsl_buffer& buf,nsl_ptr_data& layer)
{
	layer.write_ptr_data(buf);

	return buf;
}


// vector layer

nsl_buffer& operator>>(nsl_buffer& buf,nsl_vector_layer& layer)
{
	layer.read(buf);

	return buf;
}
nsl_buffer& operator<<(nsl_buffer& buf,nsl_vector_layer& layer)
{
	layer.write(buf);

	return buf;
}

// int vector
/*
nsl_buffer& operator>>(nsl_buffer& buf,nsl_int_vector& layer)
{
	layer.read_num_vector(buf); // int

	return buf;
}
nsl_buffer& operator<<(nsl_buffer& buf,nsl_int_vector& layer)
{
	layer.write_num_vector(buf); // int

	return buf;
}
*/
// num vector

nsl_buffer& operator>>(nsl_buffer& buf,nsl_num_1& layer)
{
	layer.read_num_vector(buf);

	return buf;
}
nsl_buffer& operator<<(nsl_buffer& buf,nsl_num_1& layer)
{
	layer.write_num_vector(buf);

	return buf;
}

// str vector

nsl_buffer& operator>>(nsl_buffer& buf,nsl_str_vector& layer)
{
	layer.read_str_vector(buf);

	return buf;
}
nsl_buffer& operator<<(nsl_buffer& buf,nsl_str_vector& layer)
{
	layer.write_str_vector(buf);

	return buf;
}

// ptr vector

nsl_buffer& operator>>(nsl_buffer& buf,nsl_ptr_vector& layer)
{
	layer.read_ptr_vector(buf);

	return buf;
}
nsl_buffer& operator<<(nsl_buffer& buf,nsl_ptr_vector& layer)
{
	layer.write_ptr_vector(buf);

	return buf;
}


// matrix layer

nsl_buffer& operator>>(nsl_buffer& buf,nsl_matrix_layer& layer)
{
	layer.read(buf);

	return buf;
}
nsl_buffer& operator<<(nsl_buffer& buf,nsl_matrix_layer& layer)
{
	layer.write(buf);

	return buf;
}

// int matrix
/*
nsl_buffer& operator>>(nsl_buffer& buf,nsl_int_matrix& layer)
{
	layer.read_num_matrix(buf); // int

	return buf;
}
nsl_buffer& operator<<(nsl_buffer& buf,nsl_int_matrix& layer)
{
	layer.write_num_matrix(buf); // int

	return buf;
}
*/
// num matrix

nsl_buffer& operator>>(nsl_buffer& buf,nsl_num_2& layer)
{
	layer.read_num_matrix(buf);

	return buf;
}
nsl_buffer& operator<<(nsl_buffer& buf,nsl_num_2& layer)
{
	layer.write_num_matrix(buf);

	return buf;
}

// str matrix

nsl_buffer& operator>>(nsl_buffer& buf,nsl_str_matrix& layer)
{
	layer.read_str_matrix(buf);

	return buf;
}
nsl_buffer& operator<<(nsl_buffer& buf,nsl_str_matrix& layer)
{
	layer.write_str_matrix(buf);

	return buf;
}

// ptr matrix

nsl_buffer& operator>>(nsl_buffer& buf,nsl_ptr_matrix& layer)
{
	layer.read_ptr_matrix(buf);

	return buf;
}
nsl_buffer& operator<<(nsl_buffer& buf,nsl_ptr_matrix& layer)
{
	layer.write_ptr_matrix(buf);

	return buf;
}

// istd::ostream (future: special buffer)

// buf << in called from nsl << in to get chars into buffer.
// extra spaces, tabs and comments are deleted
// formatted input is put into the buffer.

nsl_buffer& operator<<(nsl_buffer& buf,istream& in)
{
	nsl_string str,tmp;
	char c = 0;

	strcpy(tmp,""); 
	strcpy(str,"");

// '\n' has to be read from keyboard independently
// general: get read of initial "space" char
	while (in && (c = in.peek()) != EOF && in.get(c) && 
		(c == ' ' || c == '\t' || c == '\n'));

// putback "good" char
	in.putback(c);

// read actual strings until endl
	while (in && (c = in.peek()) != EOF && in.get(c) && c != '\n')
	{
// get rid of in between spaces
		// get rid of any extra spaces
		while ((c == ' ' || c == '\t') && in && in.get(c));
		in.putback(c);

		// read string into tmp buffer, w/o extra spaces and endlines
		int i = 0;
		while (in && (c = in.peek()) != EOF
			&& c != '\n' && c != ' ' && c != '\t' && in.get(c))
		    tmp[i++] = c;
		int len = i;

		// read str from tmp w/o any comments
		str[0] = '\0';	// reset str
		if (len > 0) // string
		{
		    str[0] = tmp[0];
		    i = 1;
		    while (i < len)
		    {
			// get rid of comments
			if (tmp[i-1] == '/' && tmp[i] == '/')
			{
			    len = i-1;
	   	 	    str[len] = '\0';
			    while (in && (c = in.peek()) != EOF && c != '\n')
				in.get(c);
			}
			else
			    str[i] = tmp[i];
			i++;
		    }
		    if (len > 0)
		    {
		        str[len] = '\0';
			buf << str; // copy str into buffer
		    }
		}

		if (c == '\n') // read endl separately w/o skipping it
			in.putback(c);
	}

	if (c == '\n')
		buf.set_line_fg(1);

	if (c == EOF)
		buf.set_eof_fg(-1);

	return buf;
}
nsl_buffer& operator>>(nsl_buffer& buf,std::ostream& out) // buf >> out
{
	char c = 0;

	while (buf.get_char_cnt() > 0)
	{
		buf >> c;
		out << c;
	}

	return buf;
}

nsl_buffer& operator<<(nsl_buffer& buf,fstream& in) // buf << in
{
	buf << (istream&) in;

	return buf;
}
nsl_buffer& operator>>(nsl_buffer& buf,fstream& out) // buf >> out
{
	buf >> (std::ostream&) out;

	return buf;
}

// istd::ostream

istream& operator>>(istream& in,nsl_buffer& buf) // in >> buf
{
	buf << in;

	return in;
}

std::ostream& operator<<(std::ostream& out,nsl_buffer& buf) // out << buf
{
	buf >> out;

	return out;
}

fstream& operator>>(fstream& in,nsl_buffer& buf) // in >> buf
{
	buf << (istream&) in;

	return in;
}

fstream& operator<<(fstream& out,nsl_buffer& buf) // out << buf
{
	(std::ostream&) out << buf;

	return out;
}


