/* SCCS  @(#)nsl_layer.C	1.1---95/10/13--16:37:10 */
//
//	nsl_layer.C
//

#include "nsl_layer.h"
#include "nsl_base.h"
#include "nsl_buffer.h"
#include "nsl_kernel.h"
#include <stddef.h>

extern void cmd_out(const char *);
extern int NSLoutput(const char *, const char *);
extern int NSLoutput(const char *, int);
extern int NSLoutput(const int str1,std::ostream& out);
//extern void cmd_error(const char *);

// nsl_public(rfg = 1) - avoid recursion on nsl_base::init_base

nsl_layer::nsl_layer(int sfg,int fg,int rfg) : nsl_public(rfg) 
{
	init_layer("layer","",sfg);
}
nsl_layer::nsl_layer(const char* ltype,const char* lname,nsl_public* m,
	int sfg,int fg,int rfg) : nsl_public(ltype,rfg)
{
	init_layer(ltype,lname,sfg);

	if (fg == 1) // add to model/layer
	{
		if (rfg == 0) { // m_children_list would get instantiated in nsl_base.C
			data_list = new nsl_list("layer");
			m_children_list->append(data_list); // added 9/98 for children
		}

		m_parent = m;
		if (m != NULL)
			m->add_data(this); // add_layer
	   	else
	   		SYSTEM->add_data(this); // add layer to SYSTEM top level
	}
}
nsl_layer::~nsl_layer()
{
}

// initialize

void nsl_layer::initialize(const char* ltype,const char* lname,nsl_public* m,
	int sfg,int fg,int rfg)
{
	init_layer(ltype,lname,sfg);

	if (fg == 1) // add to model/layer
	{
		if (rfg == 0) { // m_children_list would get instantiated in nsl_base.C
			data_list = new nsl_list("layer");
			m_children_list->append(data_list); // added 9/98 for children
		}

		m_parent = m;
		if (m != NULL)
			m->add_data(this); // add_layer
	   	else
	   		SYSTEM->add_data(this); // add layer to SYSTEM top level
	}
}

// init

int nsl_layer::init_layer(const char* ltype,const char* lname,int sfg)
{
	// need a flag to avoid nsl_system::nsl_num_0 recursion
	if (sfg == 0 && SYSTEM == NULL)
	{
		SYSTEM = new nsl_system;
		cmd_out("nsl_layer:Initializing SYSTEM...");
	}

	layer_type = 0; // basic layer
	set_type(ltype);
	set_name(lname);
	set_base_type("layer");

	value_fg = 0;
	region_fg = 0;

	sub_layer_fg = sfg; // sub layer flag

//	data_list = new nsl_list("layer");
//	m_children_list->append(data_list); // added 9/98 for children

	return 1;
}

int nsl_layer::get_size(int i)
{
	if ((i >= 0) && (i < size_fg))
		return size[i];
	else
	{
		cmd_error("nsl_layer::get_size: BAD size: ",i);
		return 0;
	}
}

// run

int nsl_layer::run()
{
	return 1;
}
// print

int nsl_layer::print_layer_status() const
{
	print_base();
	NSLoutput("\n# layer_type:\t\t",layer_type);

	return 1;
}
int nsl_layer::nslStatus()  const // virtual
{
	print_layer_status();
	return 1;
}
int nsl_layer::print_layer() const
{
	if (sub_layer_fg == 0) {
		NSLoutput("\nnsl set ",get_name());
	}

	return 1;
}
int nsl_layer::nslPrint() const // virtual
{
	print_layer();
	return 1;
}

// ostream

int nsl_layer::print_layer_status(ostream& out) const
{
	print_base(out);
	out <<  "# layer_type:\t\t" << layer_type << "\n";
	out.flush();

	return 1;
}
int nsl_layer::print_status(ostream& out)  const // virtual
{
	print_layer_status(out);
	return 1;
}
int nsl_layer::print_layer(ostream& out) const
{
	nsl_string str;
	nsl_string str2;
	const char* tmp;
	nsl_base* parent;

	if (sub_layer_fg == 0) 
	{
		parent = m_parent;
		strcpy(str,get_name());
		while (parent != NULL) {
			tmp = parent->get_name();
			if (strcmp(tmp,"system") != 0) {
				strcpy(str2,str);
				sprintf(str,"%s.%s",tmp,str2);
			}
			else
				break;
			parent = parent->get_m_parent();
		}

		out <<  "\nnsl set " << str << "\n";
		out.flush();
	}

	return 1;
}
//inicio cambios EGR
int nsl_layer::show_variables(nsl_layer *layer) const
{	nsl_string str;
	nsl_string str0;
	nsl_string str2;
	const char* tmp;
	nsl_string nombre;
	nsl_string tipo;
	nsl_string algo;
	nsl_base* parent;
	if (sub_layer_fg == 0)
	{	parent = m_parent;
		strcpy(str,get_name());
		strcpy(nombre,str);
		strcpy(tipo,get_abstract_type());
		while (parent != NULL)
		{	tmp = parent->get_name();
			if (strcmp(tmp,"system") != 0)
			{	strcpy(str2,str);
				sprintf(str,"%s/%s",tmp,str2);
			}
			else
				break;
			parent = parent->get_m_parent();
		}
		for(int i=0;i<strlen(str);i++)
			if(str[i]=='/')
			{	str0[i]='\n';
				sprintf(str2,".sp.fr1.h insert end %s",str0);
				//Tcl_Eval(NSL_TCL_INTERP,str2); //tcl functions commented out -bn7
				str0[i]=str[i];
			}
			else
				str0[i]=str[i];
		sprintf(str2,".sp.fr1.h insert end %s",str);
		//Tcl_Eval(NSL_TCL_INTERP,str2);
	}
	return 1;
}
//fin cambios EGR
int nsl_layer::print(ostream& out) const // virtual
{
	print_layer(out);
	return 1;
}

int nsl_layer::reset_layer(nsl_buffer*)
{
	return 1;
}
int nsl_layer::reset(nsl_buffer* buf)
{
	reset_layer(buf);
	return 1;
}

int nsl_layer::write_layer(nsl_buffer&)
{
	return 1;
}
int nsl_layer::write(nsl_buffer& buf)
{
	write_layer(buf);
	return 1;
}
int nsl_layer::read_layer(nsl_buffer&)
{
	return 1;
}
int nsl_layer::read(nsl_buffer& buf)
{
	read_layer(buf);
	return 1;
}

int nsl_layer::write_layer(nsl_char_buf&)
{
	return 1;
}
int nsl_layer::write(nsl_char_buf& buf)
{
	write_layer(buf);
	return 1;
}
int nsl_layer::read_layer(nsl_char_buf&)
{
	return 1;
}
int nsl_layer::read(nsl_char_buf& buf)
{
	read_layer(buf);
	return 1;
}


void nsl_layer::send() {}
void nsl_layer::receive() {}
void nsl_layer::copy(nsl_layer*) {}
