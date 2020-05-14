/* SCCS  @(#)nsl_diff.C	1.1---95/08/13--19:20:46 */
//
//	nsl_diff.C
//
#include "nsl.h"

#include "nsl_diff.h"
#include "nsl_diff_manager.h"
#include "nsl_num_data.h"
#include "nsl_num_vector.h"
#include "nsl_num_matrix.h"
#include "nsl_num.h"
#include "nsl_system.h"
#include "nsl_layer.h"
#include "nsl_diff_method.h"
#include "nsl_base_list.h"

#include <stddef.h>
//#define _NSL_PROMPTS

//extern void cmd_out(const char *, int);
extern void cmd_out(const char *);
extern void cmd_out(const char *, const char *);
extern void cmd_error(const char *);
//extern void cmd_error(const char *, int);

nsl_diff::nsl_diff(const char* dname,nsl_diff_manager* parent,int fg) :
	nsl_public("diff",fg),
	delta("delta",this,1), end_time("end_time",this,1),
	tm("tm",this,1), h("h",this,1)
{
	set_name(dname); // should come from argument

	init_diff(parent,fg);
}
nsl_diff::~nsl_diff()
{
}

int nsl_diff::init_diff(nsl_diff_manager* parent,int fg)
{
	set_base_type("diff");
	set_update_fg(NSL_ON);

	//hardcoded testing with prompts -bn7
#ifndef _NSL_PROMPTS
	cout << "nsl_diff: parent = " << parent << " int fg = " << fg << endl;
	set_delta(0.01f);
#endif

	m_children_list->append(data_list);

	if (fg == 2) // add to system library
	{
		if (SYSTEM == NULL)
		{
			SYSTEM = new nsl_system;
			cmd_out("nsl_diff:Initializing SYSTEM...");
		}

		SYSTEM->add_diff_model(this);

		return 1;
	}

	nsl_diff_manager* mg;

	if (parent != NULL) {
		m_parent = parent;
 		parent->add_diff(this);
 	}
 	else {
 		cmd_error("nsl_diff: Null manager");
		return 1;
	}

 	dobj = 0;

	// initialize to default diff method
//AW98	set_diff_obj(); // added instead in nsl_diff_method

	return 1;
}

// print 

int nsl_diff::print_diff_status(ostream& out) const
{
	nsl_layer* layer;

	print_base(out);

	if (dobj != NULL)
	{
		out << "set time_constant " << dobj->get_tm() << "\n";
		if ((layer = dobj->get_layer()) != NULL)
			layer->print_status(out);
	}

	out.flush();

	return 1;
}
int nsl_diff::print_status(ostream& out)  const // virtual
{
	print_diff_status(out);
	return 1;
}
int nsl_diff::print_diff(ostream& out) const
{
	print_base(out);
	return 1;
}
int nsl_diff::print(ostream& out) const // virtual
{
	print_diff(out);
	return 1;
}

// print all

int nsl_diff::print_diff_all_status(ostream& out) const
{
	print_diff_status(out);
	print_base_all_status(out);
	return 1;
}
int nsl_diff::print_all_status(ostream& out)  const // virtual
{
	print_diff_all_status(out);
	return 1;
}
int nsl_diff::print_diff_all(ostream& out) const
{
	print_diff(out);
	print_base_all(out);
	return 1;
}
int nsl_diff::print_all(ostream& out) const // virtual
{
	print_diff_all(out);
	return 1;
}

// read, write

int nsl_diff::write_diff(nsl_buffer&)
{
	return 1;
}
int nsl_diff::write(nsl_buffer& buf)
{
	write_diff(buf);
	return 1;
}
int nsl_diff::read_diff(nsl_buffer&)
{
	return 1;
}
int nsl_diff::read(nsl_buffer& buf)
{
	read_diff(buf);
	return 1;
}

// differential equation set

int nsl_diff::set_diff_obj(nsl_layer* layer)
{
 	// update only if new method
	if (m_parent == 0)
	{
		cmd_error("nsl_diff: Null parent");
		return 1;
	}

 	if (get_update_fg() == 0)
		return 1;

	set_update_fg(NSL_OFF);

	nsl_list* dlist;
	nsl_string dtype;
	const char* t;
	const char* m;
	
	m = ((nsl_diff_manager*) m_parent)->get_method();

	if ((dlist = (nsl_list*) SYSTEM->get_m_children_list()->
		get_by_name("diff_method")) == NULL)
	{
	     cmd_error("nsl_diff: NULL system diff list");
	     return 1;
	}

	if (layer != NULL) {
		t = layer->get_abstract_type();
		sprintf(dtype,"%s_%s",m,t);
	}
	else
		sprintf(dtype,"%s",m);

	cmd_out("// Default diff method: ",dtype);

	dobj = (nsl_diff_method*) dlist->get_by_type(dtype);

	if (dobj == NULL)
	{
		disable();
		cmd_error("nsl_diff: Bad Method Obj");
		if (t != NULL)
			cmd_error("nsl_diff: Layer Type: ",t);
		cmd_error("nsl_diff: Method Type: ",m);
	}

	return 1;
}
int nsl_diff::update_diff_obj(nsl_layer* m,num_type k)
{
	if (dobj != NULL)
	{
		enable();
		dobj->set_tm(k);
		dobj->set_layer(m);
		dobj->set_dt(((nsl_diff_manager*) m_parent)->get_dt());
		dobj->init();
 	}

	return 1;
}

// copy diff values locally

nsl_diff& nsl_diff::eq(nsl_layer& m,num_type k)
{
 	set_diff_obj(&m);
	update_diff_obj(&m,k);

	return *this;
}
nsl_diff& nsl_diff::eq(nsl_layer& m,nsl_num_0& k)
{
 	set_diff_obj(&m);
	update_diff_obj(&m,k.elem());

	return *this;
}

nsl_diff& nsl_diff::eq(nsl_layer* m,num_type k)
{
 	set_diff_obj(m);
	update_diff_obj(m,k);

	return *this;
}
nsl_diff& nsl_diff::eq(nsl_layer* m,nsl_num_0& k)
{
 	set_diff_obj(m);
	update_diff_obj(m,k.elem());

	return *this;
}

// call diff object according to specified method

int nsl_diff::operator=(const num_type a)
{
	if (dobj == NULL)
	{
		cmd_error("nsl_diff: Bad Method");
		return 1;
	}
	if (get_able_fg() == 1)
		dobj->exec(a);

	return 1;
}

/*
nsl_num_vector& nslDiff(nsl_num_vector& m,nsl_num_data& k,
	const nsl_num_vector& a)
{
	nsl_diff_method* dobj;
	num_type dt = 0.0;

	if (NSL_DIFF != NULL) {
		dobj = NSL_DIFF->get_diff_method();
//		dt = ((nsl_diff_manager*) m_parent)->get_dt();
		dt = NSL_DIFF->get_delta();
	}
	else {
		cmd_error("nslDiff: NULL NSL_DIFF");
		return m;
	}



	if (dobj != NULL)
		dobj->execute(mx,kx,dtx,ax);
	else
		cmd_error("nslDiff: NULL method");

	return m;
}*/


/*
nsl_num_1& nslDiff(nsl_num_1& m,nsl_num_0& k,
	const nsl_num_1& a)
{
	nsl_diff_method* dobj;
	num_type dt = 0.0;

	if (NSL_DIFF != NULL) {
		dobj = NSL_DIFF->get_diff_method();
//		dt = ((nsl_diff_manager*) m_parent)->get_dt();
		dt = NSL_DIFF->get_delta();
	}
	else {
		cmd_error("nslDiff: NULL NSL_DIFF");
		return m;
	}

	if (dobj != NULL)
		dobj->execute(m,k,dt,a);
	else
		cmd_error("nslDiff: NULL method");

	return m;
}*/
/*
int nsl_diff::operator=(const nsl_num_data& a) //commented out for now -bn7
{
	if (dobj == NULL)
	{
		cmd_error("nsl_diff: Bad Method");
		return 1;
	}
	if (get_able_fg() == 1)
		dobj->exec(a);

	return 1;
}
int nsl_diff::operator=(const nsl_num_vector& a)
{
	if (dobj == NULL)
	{
		cmd_error("nsl_diff: Bad Method");
		return 1;
	}
	if (get_able_fg() == 1)
  		dobj->exec(a);
 
	return 1;
}
int nsl_diff::operator=(const nsl_num_matrix& a)
{
	if (dobj == NULL)
	{
		cmd_error("nsl_diff: Bad Method");
		return 1;
	}
	if (get_able_fg() == 1)
		dobj->exec(a);

	return 1;
}*/

// added 12/95 by AW

int nsl_diff::run(nsl_layer* out,nsl_layer* in)
{
	if (dobj != NULL)
	{
		dobj->set_tm(tm.elem());
		dobj->set_dt(delta.elem());
		dobj->run(out,in);
	}
	else
		cmd_error("nsl_diff::run: Bad Method");

	return 1;
}

nsl_diff* nsl_diff::make_copy()
{
	return new nsl_diff("copy");
}

//added 4/2017 bn7


// added 5/98 by AW

num_type& nslDiff(num_type& m,num_type k,const num_type& a)
{
	nsl_diff_method* dobj;
	num_type dt = 0.0;

	if (NSL_DIFF != NULL) {
		dobj = NSL_DIFF->get_diff_method();
//		dt = ((nsl_diff_manager*) m_parent)->get_dt();
		dt = NSL_DIFF->get_delta();
	}
	else {
		cmd_error("nslDiff: NULL NSL_DIFF");
		return m;
	}

	if (dobj != NULL)
		dobj->execute(m,k,dt,a);
	else
		cmd_error("nslDiff: NULL method");

	return m;
}


nsl_num_0& nslDiff(nsl_num_0& m,double k,const nsl_num_0& a)
{
	nsl_diff_method* dobj;
	num_type dt = 0.0;

	if (NSL_DIFF != NULL) {
		dobj = NSL_DIFF->get_diff_method();
//		dt = ((nsl_diff_manager*) m_parent)->get_dt();
		dt = NSL_DIFF->get_delta();
	}
	else {
		cmd_error("nslDiff: NULL NSL_DIFF");
		return m;
	}

	if (dobj != NULL)
		dobj->execute(m,k,dt,a);
	else
		cmd_error("nslDiff: NULL method");

	return m;
}
//template<class NslNumType, int NslTypeId>
nsl_num_0& nslDiff(nsl_num_0& m,int k,const nsl_num_0& a)
{
	nsl_diff_method* dobj;
	num_type dt = 0.0;

	if (NSL_DIFF != NULL) {
		dobj = NSL_DIFF->get_diff_method();
//		dt = ((nsl_diff_manager*) m_parent)->get_dt();
		dt = NSL_DIFF->get_delta();
	}
	else {
		cmd_error("nslDiff: NULL NSL_DIFF");
		return m;
	}

	if (dobj != NULL)
		dobj->execute(m,k,dt,a);
	else
		cmd_error("nslDiff: NULL method");

	return m;
}
//template<class NslNumType, int NslTypeId>
nsl_num_0& nslDiff(nsl_num_0& m,nsl_num_0& k,const nsl_num_0& a)
{
	nsl_diff_method* dobj;
	num_type dt = 0.0;

	if (NSL_DIFF != NULL) {
		dobj = NSL_DIFF->get_diff_method();
//		dt = ((nsl_diff_manager*) m_parent)->get_dt();
		dt = NSL_DIFF->get_delta();
	}
	else {
		cmd_error("nslDiff: NULL NSL_DIFF");
		return m;
	}

	if (dobj != NULL)
		dobj->execute(m,k,dt,a);
	else
		cmd_error("nslDiff: NULL method");

	return m;
}

//template<class NslNumType, int NslTypeId>
nsl_num_1& nslDiff(nsl_num_1& m,double k,
	const nsl_num_1& a)
{
	nsl_diff_method* dobj;
	num_type dt = 0.0;

	if (NSL_DIFF != NULL) {
		dobj = NSL_DIFF->get_diff_method();
//		dt = ((nsl_diff_manager*) m_parent)->get_dt();
		dt = NSL_DIFF->get_delta();
	}
	else {
		cmd_error("nslDiff: NULL NSL_DIFF");
		return m;
	}

	if (dobj != NULL)
		dobj->execute(m,k,dt,a);
	else
		cmd_error("nslDiff: NULL method");

	return m;
}
//template<class NslNumType, int NslTypeId>
nsl_num_1& nslDiff(nsl_num_1& m,int k,
	const nsl_num_1& a)
{
	nsl_diff_method* dobj;
	num_type dt = 0.0;

	if (NSL_DIFF != NULL) {
		dobj = NSL_DIFF->get_diff_method();
//		dt = ((nsl_diff_manager*) m_parent)->get_dt();
		dt = NSL_DIFF->get_delta();
	}
	else {
		cmd_error("nslDiff: NULL NSL_DIFF");
		return m;
	}

	if (dobj != NULL)
		dobj->execute(m,k,dt,a);
	else
		cmd_error("nslDiff: NULL method");

	return m;
}
/*
//template<class NslNumType, int NslTypeId>
nsl_num_1& nslDiff(nsl_num_1& m,nsl_num_0& k,
	const nsl_num_1& a)
{
	nsl_diff_method* dobj;
	num_type dt = 0.0;

	if (NSL_DIFF != NULL) {
		dobj = NSL_DIFF->get_diff_method();
//		dt = ((nsl_diff_manager*) m_parent)->get_dt();
		dt = NSL_DIFF->get_delta();
	}
	else {
		cmd_error("nslDiff: NULL NSL_DIFF");
		return m;
	}

	if (dobj != NULL)
		dobj->execute(m,k,dt,a);
	else
		cmd_error("nslDiff: NULL method");

	return m;
}
*/
//template<class NslNumType, int NslTypeId>
nsl_num_2& nslDiff(nsl_num_2& m,double k,
	const nsl_num_2& a)
{
	nsl_diff_method* dobj;
	num_type dt = 0.0;

	if (NSL_DIFF != NULL) {
		dobj = NSL_DIFF->get_diff_method();
//		dt = ((nsl_diff_manager*) m_parent)->get_dt();
		dt = NSL_DIFF->get_delta();
	}
	else {
		cmd_error("nslDiff: NULL NSL_DIFF");
		return m;
	}

	if (dobj != NULL)
		dobj->execute(m,k,dt,a);
	else
		cmd_error("nslDiff: NULL method");

	return m;
}
//template<class NslNumType, int NslTypeId>
nsl_num_2& nslDiff(nsl_num_2& m,int k,
	const nsl_num_2& a)
{
	nsl_diff_method* dobj;
	num_type dt = 0.0;

	if (NSL_DIFF != NULL) {
		dobj = NSL_DIFF->get_diff_method();
//		dt = ((nsl_diff_manager*) m_parent)->get_dt();
		dt = NSL_DIFF->get_delta();
	}
	else {
		cmd_error("nslDiff: NULL NSL_DIFF");
		return m;
	}

	if (dobj != NULL)
		dobj->execute(m,k,dt,a);
	else
		cmd_error("nslDiff: NULL method");

	return m;
}
//template<class NslNumType, int NslTypeId>
nsl_num_2& nslDiff(nsl_num_2& m,nsl_num_0& k,
	const nsl_num_2& a)
{
	nsl_diff_method* dobj;
	num_type dt = 0.0;

	if (NSL_DIFF != NULL) {
		dobj = NSL_DIFF->get_diff_method();
//		dt = ((nsl_diff_manager*) m_parent)->get_dt();
		dt = NSL_DIFF->get_delta();
	}
	else {
		cmd_error("nslDiff: NULL NSL_DIFF");
		return m;
	}

	if (dobj != NULL)
		dobj->execute(m,k,dt,a);
	else
		cmd_error("nslDiff: NULL method");

	return m;
}

//template<class NslNumType, int NslTypeId>
nsl_num_3& nslDiff(nsl_num_3& m,double k,
	const nsl_num_3& a)
{
	nsl_diff_method* dobj;
	num_type dt = 0.0;

	if (NSL_DIFF != NULL) {
		dobj = NSL_DIFF->get_diff_method();
//		dt = ((nsl_diff_manager*) m_parent)->get_dt();
		dt = NSL_DIFF->get_delta();
	}
	else {
		cmd_error("nslDiff: NULL NSL_DIFF");
		return m;
	}

	if (dobj != NULL)
		dobj->execute(m,k,dt,a);
	else
		cmd_error("nslDiff: NULL method");

	return m;
}
//template<class NslNumType, int NslTypeId>
nsl_num_3& nslDiff(nsl_num_3& m,int k,
	const nsl_num_3& a)
{
	nsl_diff_method* dobj;
	num_type dt = 0.0;

	if (NSL_DIFF != NULL) {
		dobj = NSL_DIFF->get_diff_method();
//		dt = ((nsl_diff_manager*) m_parent)->get_dt();
		dt = NSL_DIFF->get_delta();
	}
	else {
		cmd_error("nslDiff: NULL NSL_DIFF");
		return m;
	}

	if (dobj != NULL)
		dobj->execute(m,k,dt,a);
	else
		cmd_error("nslDiff: NULL method");

	return m;
}
//template<class NslNumType, int NslTypeId>
nsl_num_3& nslDiff(nsl_num_3& m,nsl_num_0& k,
	const nsl_num_3& a)
{
	nsl_diff_method* dobj;
	num_type dt = 0.0;

	if (NSL_DIFF != NULL) {
		dobj = NSL_DIFF->get_diff_method();
//		dt = ((nsl_diff_manager*) m_parent)->get_dt();
		dt = NSL_DIFF->get_delta();
	}
	else {
		cmd_error("nslDiff: NULL NSL_DIFF");
		return m;
	}

	if (dobj != NULL)
		dobj->execute(m,k,dt,a);
	else
		cmd_error("nslDiff: NULL method");

	return m;
}

//template<class NslNumType, int NslTypeId>
nsl_num_4& nslDiff(nsl_num_4& m,double k,
	const nsl_num_4& a)
{
	nsl_diff_method* dobj;
	num_type dt = 0.0;

	if (NSL_DIFF != NULL) {
		dobj = NSL_DIFF->get_diff_method();
//		dt = ((nsl_diff_manager*) m_parent)->get_dt();
		dt = NSL_DIFF->get_delta();
	}
	else {
		cmd_error("nslDiff: NULL NSL_DIFF");
		return m;
	}

	if (dobj != NULL)
		dobj->execute(m,k,dt,a);
	else
		cmd_error("nslDiff: NULL method");

	return m;
}
//template<class NslNumType, int NslTypeId>
nsl_num_4& nslDiff(nsl_num_4& m,int k,
	const nsl_num_4& a)
{
	nsl_diff_method* dobj;
	num_type dt = 0.0;

	if (NSL_DIFF != NULL) {
		dobj = NSL_DIFF->get_diff_method();
//		dt = ((nsl_diff_manager*) m_parent)->get_dt();
		dt = NSL_DIFF->get_delta();
	}
	else {
		cmd_error("nslDiff: NULL NSL_DIFF");
		return m;
	}

	if (dobj != NULL)
		dobj->execute(m,k,dt,a);
	else
		cmd_error("nslDiff: NULL method");

	return m;
}
//template<class NslNumType, int NslTypeId>
nsl_num_4& nslDiff(nsl_num_4& m,nsl_num_0& k,
	const nsl_num_4& a)
{
	nsl_diff_method* dobj;
	num_type dt = 0.0;

	if (NSL_DIFF != NULL) {
		dobj = NSL_DIFF->get_diff_method();
//		dt = ((nsl_diff_manager*) m_parent)->get_dt();
		dt = NSL_DIFF->get_delta();
	}
	else {
		cmd_error("nslDiff: NULL NSL_DIFF");
		return m;
	}

	if (dobj != NULL)
		dobj->execute(m,k,dt,a);
	else
		cmd_error("nslDiff: NULL method");

	return m;
}

nsl_num_0& nslDiff(nsl_num_0& m,NslNumType k,const nsl_num_0& a)
{
	nsl_diff_method* dobj;
	num_type dt = 0.0;

	if (NSL_DIFF != NULL) {
		dobj = NSL_DIFF->get_diff_method();
//		dt = ((nsl_diff_manager*) m_parent)->get_dt();
		dt = NSL_DIFF->get_delta();
	}
	else {
		cmd_error("nslDiff: NULL NSL_DIFF");
		return m;
	}

	if (dobj != NULL)
		dobj->execute(m,k,dt,a);
	else
		cmd_error("nslDiff: NULL method");

	return m;
}

nsl_num_1& nslDiff(nsl_num_1& m,nsl_num_0& k,
	const nsl_num_1& a)
{
	nsl_diff_method* dobj;
	num_type dt = 0.0;

	if (NSL_DIFF != NULL) {
		dobj = NSL_DIFF->get_diff_method();
//		dt = ((nsl_diff_manager*) m_parent)->get_dt();
		dt = NSL_DIFF->get_delta();
	}
	else {
		cmd_error("nslDiff: NULL NSL_DIFF");
		return m;
	}

	if (dobj != NULL)
		dobj->execute(m,k,dt,a);
	else
		cmd_error("nslDiff: NULL method");

	return m;
}
// added 5/98 by AW
/*


nsl_num_0<NslNumType>& nslDiff(nsl_num_0<NslNumType>& m,nsl_num_0<NslNumType>& k,const nsl_num_0<NslNumType>& a)
{
	nsl_diff_method* dobj;
	num_type dt = 0.0;

	if (NSL_DIFF != NULL) {
		dobj = NSL_DIFF->get_diff_method();
//		dt = ((nsl_diff_manager*) m_parent)->get_dt();
		dt = NSL_DIFF->get_delta();
	}
	else {
		cmd_error("nslDiff: NULL NSL_DIFF");
		return m;
	}

	if (dobj != NULL)
		dobj->execute(m,k,dt,a);
	else
		cmd_error("nslDiff: NULL method");

	return m;
}

nsl_num_1<NslNumType>& nslDiff(nsl_num_1<NslNumType>& m,NslNumType k,
	const nsl_num_1<NslNumType>& a)
{
	nsl_diff_method* dobj;
	num_type dt = 0.0;

	if (NSL_DIFF != NULL) {
		dobj = NSL_DIFF->get_diff_method();
//		dt = ((nsl_diff_manager*) m_parent)->get_dt();
		dt = NSL_DIFF->get_delta();
	}
	else {
		cmd_error("nslDiff: NULL NSL_DIFF");
		return m;
	}

	if (dobj != NULL)
		dobj->execute(m,k,dt,a);
	else
		cmd_error("nslDiff: NULL method");

	return m;
}



nsl_num_2<NslNumType>& nslDiff(nsl_num_2<NslNumType>& m,NslNumType k,
	const nsl_num_2<NslNumType>& a)
{
	nsl_diff_method* dobj;
	num_type dt = 0.0;

	if (NSL_DIFF != NULL) {
		dobj = NSL_DIFF->get_diff_method();
//		dt = ((nsl_diff_manager*) m_parent)->get_dt();
		dt = NSL_DIFF->get_delta();
	}
	else {
		cmd_error("nslDiff: NULL NSL_DIFF");
		return m;
	}

	if (dobj != NULL)
		dobj->execute(m,k,dt,a);
	else
		cmd_error("nslDiff: NULL method");

	return m;
}

nsl_num_2<NslNumType>& nslDiff(nsl_num_2<NslNumType>& m,nsl_num_0<NslNumType>& k,
	const nsl_num_2<NslNumType>& a)
{
	nsl_diff_method* dobj;
	num_type dt = 0.0;

	if (NSL_DIFF != NULL) {
		dobj = NSL_DIFF->get_diff_method();
//		dt = ((nsl_diff_manager*) m_parent)->get_dt();
		dt = NSL_DIFF->get_delta();
	}
	else {
		cmd_error("nslDiff: NULL NSL_DIFF");
		return m;
	}

	if (dobj != NULL)
		dobj->execute(m,k,dt,a);
	else
		cmd_error("nslDiff: NULL method");

	return m;
}

nsl_num_3<NslNumType>& nslDiff(nsl_num_3<NslNumType>& m,NslNumType k,
	const nsl_num_3<NslNumType>& a)
{
	nsl_diff_method* dobj;
	num_type dt = 0.0;

	if (NSL_DIFF != NULL) {
		dobj = NSL_DIFF->get_diff_method();
//		dt = ((nsl_diff_manager*) m_parent)->get_dt();
		dt = NSL_DIFF->get_delta();
	}
	else {
		cmd_error("nslDiff: NULL NSL_DIFF");
		return m;
	}

	if (dobj != NULL)
		dobj->execute(m,k,dt,a);
	else
		cmd_error("nslDiff: NULL method");

	return m;
}

nsl_num_3<NslNumType>& nslDiff(nsl_num_3<NslNumType>& m,nsl_num_0<NslNumType>& k,
	const nsl_num_3<NslNumType>& a)
{
	nsl_diff_method* dobj;
	num_type dt = 0.0;

	if (NSL_DIFF != NULL) {
		dobj = NSL_DIFF->get_diff_method();
//		dt = ((nsl_diff_manager*) m_parent)->get_dt();
		dt = NSL_DIFF->get_delta();
	}
	else {
		cmd_error("nslDiff: NULL NSL_DIFF");
		return m;
	}

	if (dobj != NULL)
		dobj->execute(m,k,dt,a);
	else
		cmd_error("nslDiff: NULL method");

	return m;
}

nsl_num_4<NslNumType>& nslDiff(nsl_num_4<NslNumType>& m,NslNumType k,
	const nsl_num_4<NslNumType>& a)
{
	nsl_diff_method* dobj;
	num_type dt = 0.0;

	if (NSL_DIFF != NULL) {
		dobj = NSL_DIFF->get_diff_method();
//		dt = ((nsl_diff_manager*) m_parent)->get_dt();
		dt = NSL_DIFF->get_delta();
	}
	else {
		cmd_error("nslDiff: NULL NSL_DIFF");
		return m;
	}

	if (dobj != NULL)
		dobj->execute(m,k,dt,a);
	else
		cmd_error("nslDiff: NULL method");

	return m;
}

nsl_num_4<NslNumType>& nslDiff(nsl_num_4<NslNumType>& m,nsl_num_0<NslNumType>& k,
	const nsl_num_4<NslNumType>& a)
{
	nsl_diff_method* dobj;
	num_type dt = 0.0;

	if (NSL_DIFF != NULL) {
		dobj = NSL_DIFF->get_diff_method();
//		dt = ((nsl_diff_manager*) m_parent)->get_dt();
		dt = NSL_DIFF->get_delta();
	}
	else {
		cmd_error("nslDiff: NULL NSL_DIFF");
		return m;
	}

	if (dobj != NULL)
		dobj->execute(m,k,dt,a);
	else
		cmd_error("nslDiff: NULL method");

	return m;
}
*/
