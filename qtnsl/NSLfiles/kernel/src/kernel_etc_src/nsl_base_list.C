/* SCCS  @(#)nsl_base_list.C	1.1---95/08/13--19:20:41 */
/**************************************************************/
/*                                                            */
/*                   nsl_base_list.C                          */
/*                                                            */
/**************************************************************/

#include <stddef.h>
#include "nsl_kernel.h"
#include "nsl_base_list.h"
#include "nsl_base.h"

nsl_base_list::nsl_base_list(const int level) : nsl_public(level)
{
	init_base_list("list");
}
nsl_base_list::nsl_base_list(const char* bname,int level) : nsl_public(bname,level)
{
	init_base_list(bname);
}
nsl_base_list::~nsl_base_list()
{
	clear();
}

int nsl_base_list::init_base_list(const char* bname)
{
	set_type("list");
	set_name(bname);
	top = NULL; cur = NULL; bot = NULL; total = 0;

	return 1;
}

int nsl_base_list::insert(nsl_base *pb)
{
	nsl_base_node* p;

	if (pb == NULL)
		return 0;

	p = new nsl_base_node(pb);

 	if(top == NULL || bot == NULL){
 		cur = top = bot = p;
	}
 	else if(cur == top){
 		cur->prev = p;
		p->next = cur;
 		cur = top = p;
	}
	else if(cur == bot){
		bot->next = p;
		p->prev = bot;
		bot = p;
 	}
	else{
		if (cur->next != NULL)
 			cur->next->prev = p;
		p->next = cur->next;
		cur->next = p;
		p->prev = cur;
	}

	return ++total;
}

// append: put at end of list

int nsl_base_list::append(nsl_base *pb)
{
	nsl_base_node* p;

	if (pb == NULL)
		return 0;

	p = new nsl_base_node(pb);

 	if(top == NULL || bot == NULL){
		cur = top = bot = p;
	}
	else{
 		bot->next = p;
		p->prev = bot;
		bot = p;
	}

	return ++total;
}

int nsl_base_list::clear()
{
	cur = top;
	if(cur == 0){
//		cout << "Nothing in the list.\n" << flush;
		return 0;
	}

	do{
		nsl_base_node* tmp = cur;
		cur = cur->next;
		if (tmp->ptr != NULL)
			delete tmp->ptr;
		delete tmp;
		total--;
	}while (cur != 0);

	top = 0;
	bot = 0;

	return total;
}

int nsl_base_list::clear(const int i0,const int i1) // check this
{
	int i = i1;

	wind(i0); // get to starting position for clearing

	if(cur == NULL || bot == NULL){
//		cout << "Nothing in the list.\n" << flush;
		return 0;
	}

	do {
		nsl_base_node* tmp = cur;
		cur = cur->next;
		delete tmp;
		total--;
	} while (cur != 0 && i-- > 0);

	if (cur == 0)
	{
		top = 0;
		bot = 0;
	}

	return total;
}

int nsl_base_list::clear_cur()
{
	nsl_base_node *tmp;

	if(top == NULL || bot == NULL) {
//		cout<<"No data in the list\n"<<flush;
		return 0;
	}
	else if(cur == top){
		tmp = cur;
		top = cur->next;
		if (top != NULL)
			top->prev = NULL;
		delete tmp;
		total--;
	}
	else if(cur == bot){
		tmp = cur;
		bot = cur->prev;
		if (bot != NULL)
			bot->next = NULL;
		delete tmp;
		total--;
	}
	else{
		tmp = cur;
		if (cur->prev != NULL)
			cur->prev->next = cur->next;
		if (cur->next != NULL)
			cur->next->prev = cur->prev;
		delete tmp;
		total--;
	}

	return 1;
}

nsl_base* nsl_base_list::return_cur()
{
	nsl_base_node *tmp;

	if(top == NULL || bot == NULL) {
//		cout<<"No data in the list\n"<<flush;
		return 0;
	}
	else if(cur == top){
		tmp = cur;
		top = cur->next;
		if (top != NULL)
			top->prev = NULL;
		total--;
		return tmp->ptr;
 	}
	else if(cur == bot){
		tmp = cur;
		bot = cur->prev;
		if (bot != NULL)
			bot->next = NULL;
		total--;
		return tmp->ptr;
 	}
	else{
		tmp = cur;
		if (cur->prev != NULL)
			cur->prev->next = cur->next;
		if (cur->next != NULL)
			cur->next->prev = cur->prev;
		total--;
		return tmp->ptr;
 	}
}

nsl_base* nsl_base_list::delete_by_index(const int bindex)
{
    	nsl_base* base = 0;
	nsl_base_node* node = 0;
         
        for (node = top; node != NULL; node = node->next)
            if (node->ptr != NULL && bindex == node->ptr->get_index())
	    {
		cur = node;
		return return_cur();
 	    }	

        return 0;
}
nsl_base* nsl_base_list::delete_by_name(const char* bname)
{
    	nsl_base* base = 0;
	nsl_base_node* node = 0;
         
        for (node = top; node != NULL; node = node->next)
            if (node->ptr != NULL && strcmp(node->ptr->get_name(),bname) == 0)
	    {
		cur = node;
		return return_cur();
	    }		

        return 0;
}

void nsl_base_list::wind(const int step)
{
	cur = top;
	for(int i = 0; i < step; i++)
		cur = cur->next;
}

// nsl_list::wind_up() { cur = top; } should be called before this function
// returns current and then goes to next

nsl_base* nsl_base_list::next()
{
	nsl_base_node *tmp;
	if(cur != 0){	
		tmp = cur;
		cur = cur->next;
		return tmp->ptr; // cur;
	}
	return 0;
}
nsl_base* nsl_base_list::prev()
{
	nsl_base_node *tmp;
	if(cur != 0){	
		tmp = cur;
		cur = cur->prev;
		return tmp->ptr; // cur;
	}
	return 0;
}
nsl_base* nsl_base_list::get_next()
{
	if (cur != NULL && cur->next != NULL)
		return cur->next->ptr;
	else
		return 0;
}
nsl_base* nsl_base_list::get_prev()
{
	if (cur != NULL && cur->prev != NULL)
		return cur->prev->ptr;
	else
		return 0;
}

nsl_base* nsl_base_list::get()
{
	if (cur != NULL)
		return cur->ptr;
	else
		return 0;
}
nsl_base* nsl_base_list::get_curr() 
{
	if (cur != NULL)
		return cur->ptr;
	else
		return 0;
}
nsl_base* nsl_base_list::get_by_index(const int bindex)
{
        nsl_base* base = 0;

        wind_up();

        while ((base = (nsl_base*) next()) != NULL)
            if (bindex == base->get_index())
                 return base;

        return base;
}
nsl_base* nsl_base_list::get_by_name(const char* bname)
{
	nsl_base* base = 0;

        wind_up();
            
        while ((base = (nsl_base*) next()) != NULL)
            if (strcmp(bname,base->get_name()) == 0)
                return base;		

        return base;
}
nsl_base* nsl_base_list::get_by_type(const char* bname)
{
	nsl_base* base = 0;

        wind_up();
            
        while ((base = (nsl_base*) next()) != NULL)
            if (strcmp(bname,base->get_type()) == 0)
                 return base;

        return base;
}
nsl_base* nsl_base_list::get_by_type_and_name(const char* btype,
	const char* bname)
{
	nsl_base* base = 0;

        wind_up();
            
        while ((base = (nsl_base*) next()) != NULL)
            if (strcmp(btype,base->get_type()) == 0 && 
		strcmp(bname,base->get_name()) == 0)
                 	return base;

        return base;
}
nsl_base* nsl_base_list::get_by_type_and_index(const char* btype,
	const int i)
{
	nsl_base* base = 0;

        wind_up();
            
        while ((base = (nsl_base*) next()) != NULL)
            if (strcmp(btype,base->get_type()) == 0 && base->get_index() == i)
                 return base;

        return base;
}

// get inheritance children 

nsl_base* nsl_base_list::get_i_by_index(const int bindex)
{
        nsl_base* base = 0;
        nsl_base *base0 = 0;

        wind_up();

        while ((base = (nsl_base*) next()) != NULL)
            if (bindex == base->get_index())
                return base;
	    else
	    {
		if (strcmp(base->get_type(),"list") == 0)
			base0 = base;
		else
			base0 = (nsl_base_list*) base->get_i_children_list();

		if (base0 == NULL)
			return 0;

		base = ((nsl_base_list*) base0)->get_i_by_index(bindex);
		if (base != NULL)
			return base;
	    }

	return 0;
}
nsl_base* nsl_base_list::get_i_by_name(const char* bname)
{
	nsl_base* base = 0;
        nsl_base *base0 = 0;
     
        wind_up();
            
        while ((base = (nsl_base*) next()) != NULL)
            if (strcmp(bname,base->get_name()) == 0)
                return base;
	    else
	    {
		if (strcmp(base->get_type(),"list") == 0)
			base0 = base;
		else
			base0 = (nsl_base_list*) base->get_i_children_list();

		if (base0 == NULL)
			return 0;

		base = ((nsl_base_list*) base0)->get_i_by_name(bname);
		if (base != NULL)
			return base;
	    }
		
        return 0;
}
nsl_base* nsl_base_list::get_i_by_type(const char* bname)
{
	nsl_base* base = 0;
        nsl_base *base0 = 0;

        wind_up();
            
        while ((base = (nsl_base*) next()) != NULL)
            if (strcmp(bname,base->get_type()) == 0)
                 return base;
	    else
	    {
		if (strcmp(base->get_type(),"list") == 0)
			base0 = base;
		else
			base0 = (nsl_base_list*) base->get_i_children_list();

		if (base0 == NULL)
			return 0;

		base = ((nsl_base_list*) base0)->get_i_by_type(bname);
		if (base != NULL)
			return base;
	    }
		
        return 0;
}

nsl_base* nsl_base_list::get_i_by_type_and_name(const char* btype, 
	const char* bname)
{
	nsl_base* base = 0;
        nsl_base *base0 = 0;

        wind_up();
            
        while ((base = (nsl_base*) next()) != NULL)
	{
            if ((strcmp(btype,get_name()) == 0 || 
		strcmp(btype,base->get_type()) == 0) && 
		    strcmp(bname,base->get_name()) == 0)
	    {
                return base;
	    }
	    else if (strcmp(base->get_type(),"list") == 0)
	    {
		return ((nsl_base_list*) base)->
			get_i_by_type_and_name(btype,bname);
	    }
	    else
	    {
		base0 = (nsl_base_list*) base->get_i_children_list();

		if (base0 == NULL)
			return 0;

		base = ((nsl_base_list*) 
			base0)->get_i_by_type_and_name(btype,bname);
		if (base != NULL)
		    return base;
	    }
	}

	return 0;
}
nsl_base* nsl_base_list::get_i_by_type_and_index(const char* btype, 
	const int bindex)
{
	nsl_base* base = 0;
        nsl_base *base0 = 0;

        wind_up();
            
        while ((base = (nsl_base*) next()) != NULL)
	{
            if ((strcmp(btype,get_name()) == 0 ||
		strcmp(btype,base->get_type()) == 0) && 
		    base->get_index() == bindex)
	    {
                return base;
	    }
	    else if (strcmp(base->get_type(),"list") == 0)
	    {
		return ((nsl_base_list*) base)->
			get_i_by_type_and_index(btype,bindex);
	    }
	    else
	    {
		base0 = (nsl_base_list*) base->get_i_children_list();

		if (base0 == NULL)
			return 0;

		base = ((nsl_base_list*) 
			base0)->get_i_by_type_and_index(btype,bindex);
		if (base != NULL)
		    return base;
	    }
	}

	return 0;
}

// get management children 

nsl_base* nsl_base_list::get_m_by_index(const int bindex)
{
        nsl_base* base = 0;
        nsl_base *base0 = 0;

        wind_up();

        while ((base = (nsl_base*) next()) != NULL)
            if (bindex == base->get_index())
                return base;
	    else
	    {
		if (strcmp(base->get_type(),"list") == 0)
			base0 = base;
		else
			base0 = (nsl_base_list*) base->get_m_children_list();

		if (base0 == NULL)
			return 0;

		base = ((nsl_base_list*) base0)->get_m_by_index(bindex);
		if (base != NULL)
			return base;
	    }

	return 0;
}
nsl_base* nsl_base_list::get_m_by_name(const char* bname)
{
	nsl_base* base = 0;
        nsl_base *base0 = 0;

        wind_up();
            
        while ((base = (nsl_base*) next()) != NULL)
            if (strcmp(bname,base->get_name()) == 0)
                return base;
	    else
	    {
		if (strcmp(base->get_type(),"list") == 0)
			base0 = base;
		else
			base0 = (nsl_base_list*) base->get_m_children_list();

		if (base0 == NULL)
			return 0;

		base = ((nsl_base_list*) base0)->get_m_by_name(bname);
		if (base != NULL)
			return base;
	    }

	return 0;
}
nsl_base* nsl_base_list::get_m_by_type(const char* bname)
{
	nsl_base* base = 0;
        nsl_base *base0 = 0;
 
        wind_up();
            
        while ((base = (nsl_base*) next()) != NULL)
            if (strcmp(bname,base->get_type()) == 0)
                 return base;
	    else
	    {
		if (strcmp(base->get_type(),"list") == 0)
			base0 = base;
		else
			base0 = (nsl_base_list*) base->get_m_children_list();

		if (base0 == NULL)
			return 0;

		base = ((nsl_base_list*) base0)->get_m_by_type(bname);
		if (base != NULL)
			return base;
	    }

	return 0;
}

nsl_base* nsl_base_list::get_m_by_type_and_name(const char* btype, 
	const char* bname)
{
	nsl_base* base = 0;
        nsl_base *base0 = 0;

        wind_up();
            
        while ((base = (nsl_base*) next()) != NULL)
	{
            if ((strcmp(btype,get_name()) == 0 || 
		strcmp(btype,base->get_type()) == 0) && 
		    strcmp(bname,base->get_name()) == 0)
	    {
                return base;
	    }
	    else if (strcmp(base->get_type(),"list") == 0)
	    {
		return ((nsl_base_list*) base)->
			get_m_by_type_and_name(btype,bname);
	    }
	    else
	    {
		base0 = (nsl_base_list*) base->get_m_children_list();

		if (base0 == NULL)
			return 0;

		base = ((nsl_base_list*) 
			base0)->get_m_by_type_and_name(btype,bname);
		if (base != NULL)
		    return base;
	    }
	}

	return 0;
}
nsl_base* nsl_base_list::get_m_by_type_and_index(const char* btype, 
	const int bindex)
{
	nsl_base* base = 0;
        nsl_base *base0 = 0;

        wind_up();
            
        while ((base = (nsl_base*) next()) != NULL)
	{
            if ((strcmp(btype,get_name()) == 0 ||
		strcmp(btype,base->get_type()) == 0) && 
		    base->get_index() == bindex)
	    {
                return base;
	    }
	    else if (strcmp(base->get_type(),"list") == 0)
	    {
		return ((nsl_base_list*) base)->
			get_m_by_type_and_index(btype,bindex);
	    }
	    else
	    {
		base0 = (nsl_base_list*) base->get_m_children_list();

		if (base0 == NULL)
			return 0;

		base = ((nsl_base_list*) 
			base0)->get_m_by_type_and_index(btype,bindex);
		if (base != NULL)
		    return base;
	    }
	}

	return 0;
}

// get management or inheritance children 

nsl_base* nsl_base_list::get_mi_by_index(const int bindex)
{
        nsl_base *base = 0;
        nsl_base *base1 = 0;
        nsl_base *base2 = 0;

        wind_up();

        while ((base = (nsl_base*) next()) != NULL)
            if (bindex == base->get_index())
                return base;
	    else
	    {
		if (strcmp(base->get_type(),"list") == 0)
			base2 = base;
		else
			base2 = base->get_m_children_list();
	
		if (base2 == NULL)
			return 0;

		base1 = ((nsl_base_list*) base2)->get_mi_by_index(bindex);
		if (base1 != NULL)
			return base1;

		if (strcmp(base->get_type(),"list") == 0)
			base2 = base;
		else
			base2 = base->get_i_children_list();

		if (base2 == NULL)
			return 0;

		base1 = ((nsl_base_list*) base2)->get_mi_by_index(bindex);
		if (base1 != NULL)
			return base1;
	    }

	return 0;
}
nsl_base* nsl_base_list::get_mi_by_name(const char* bname)
{
	nsl_base* base = 0;
        nsl_base *base1 = 0;
        nsl_base *base2 = 0;

        wind_up();
            
        while ((base = (nsl_base*) next()) != NULL)
            if (strcmp(bname,base->get_name()) == 0)
                return base;
	    else
	    {
		if (strcmp(base->get_type(),"list") == 0)
			base2 = base;
		else
			base2 = base->get_m_children_list();
			
		if (base2 == NULL)
			return 0;

		base1 = ((nsl_base_list*) base2)->get_mi_by_name(bname);
		if (base1 != NULL)
			return base1;

		if (strcmp(base->get_type(),"list") == 0)
			base2 = base;
		else
			base2 = base->get_i_children_list();

		if (base2 == NULL)
			return 0;

		base1 = ((nsl_base_list*) base2)->get_mi_by_name(bname);
		if (base1 != NULL)
			return base1;
	    }

	return 0;
}
nsl_base* nsl_base_list::get_mi_by_type(const char* bname)
{
	nsl_base* base = 0;
        nsl_base *base1 = 0;
        nsl_base *base2 = 0;

        wind_up();
            
        while ((base = (nsl_base*) next()) != NULL)
            if (strcmp(bname,base->get_type()) == 0)
                 return base;
	    else
	    {
		if (strcmp(base->get_type(),"list") == 0)
			base2 = base;
		else
			base2 = base->get_m_children_list();
			
		if (base2 == NULL)
			return 0;

		base1 = ((nsl_base_list*) base2)->get_mi_by_type(bname);
		if (base1 != NULL)
			return base1;

		if (strcmp(base->get_type(),"list") == 0)
			base2 = base;
		else
			base2 = base->get_i_children_list();

		if (base2 == NULL)
			return 0;

		base1 = ((nsl_base_list*) base2)->get_mi_by_type(bname);
		if (base1 != NULL)
			return base1;
	    }

	return 0;
}

nsl_base* nsl_base_list::get_mi_by_type_and_name(const char* btype, 
	const char* bname)
{
	nsl_base* base = 0;
        nsl_base *base1 = 0;
        nsl_base *base2 = 0;

        wind_up();
            
        while ((base = (nsl_base*) next()) != NULL)
            if (strcmp(bname,base->get_name()) == 0 &&
		strcmp(btype,base->get_type()) == 0)
                 return base;
	    else
	    {
		if (strcmp(base->get_type(),"list") == 0)
			base2 = base;
		else
			base2 = base->get_m_children_list();
			
		if (base2 == NULL)
			return 0;

		base1 = ((nsl_base_list*) base2)->
			get_mi_by_type_and_name(btype,bname);
		if (base1 != NULL)
			return base1;

		if (strcmp(base->get_type(),"list") == 0)
			base2 = base;
		else
			base2 = base->get_i_children_list();

		if (base2 == NULL)
			return 0;

		base1 = ((nsl_base_list*) base2)->
			get_mi_by_type_and_name(btype,bname);
		if (base1 != NULL)
			return base1;
	    }

	return 0;
}

nsl_base* nsl_base_list::get_mi_by_type_and_index(const char* btype, 
	const int bindex)
{
	nsl_base* base = 0;
        nsl_base *base1 = 0;
        nsl_base *base2 = 0;

        wind_up();
            
        while ((base = (nsl_base*) next()) != NULL)
            if (bindex == base->get_index() &&
		strcmp(btype,base->get_type()) == 0)
                 return base;
	    else
	    {
		if (strcmp(base->get_type(),"list") == 0)
			base2 = base;
		else
			base2 = base->get_m_children_list();
			
		if (base2 == NULL)
			return 0;

		base1 = ((nsl_base_list*) base2)->
			get_mi_by_type_and_index(btype,bindex);
		if (base1 != NULL)
			return base1;

		if (strcmp(base->get_type(),"list") == 0)
			base2 = base;
		else
			base2 = base->get_i_children_list();

		if (base2 == NULL)
			return 0;

		base1 = ((nsl_base_list*) base2)->
			get_mi_by_type_and_index(btype,bindex);
		if (base1 != NULL)
			return base1;
	    }

	return 0;
}

// enable, disable

int nsl_base_list::enable_all()
{
	nsl_base* base = 0;

	enable();

        wind_up();
            
        while ((base = (nsl_base*) next()) != NULL)
 		base->enable_all();

	return 1;
}
int nsl_base_list::disable_all()
{
	nsl_base* base = 0;

	disable();

        wind_up();
            
        while ((base = (nsl_base*) next()) != NULL)
		base->disable_all();

	return 1;
}

// print

// * use of wind_up or next requires method not to be a const *

int nsl_base_list::print_base_list(ostream& out) const
{
	print_base(out);

	return 1;
}
int nsl_base_list::print(ostream& out) const
{
	print_base_list(out);

	return 1;
}
int nsl_base_list::print_base_list_all(ostream& out) const
{
   	nsl_base* base = 0;
	nsl_base_node* node = 0;
         
        for (node = top; node != NULL; node = node->next)
	{
	    if ((base = node->ptr) == NULL)
		continue;
	    if (strcmp(base->get_type(),"list") == 0)
		base->print_all(out);
	    else
		base->print(out);
	}

	out.flush();

	return 1;
}
int nsl_base_list::print_all(ostream& out) const
{
	print_base_list_all(out);

	return 1;
}
int nsl_base_list::print_by_name(ostream& out,char* bname) 
{
	wind_up();
	nsl_base* base = 0;

	if ((base = (nsl_base*)get_by_name(bname)) != NULL)
		base->print(out);

	out.flush();

	if (base == NULL)
		return 0;

	return 1;
}
int nsl_base_list::print_by_index(ostream& out,int bindex) 
{
	wind_up();
	nsl_base* base = 0;

	if ((base = (nsl_base*)get_by_index(bindex)) != NULL)
		base->print(out);

	out.flush();

	if (base == NULL)
		return 0;

	return 1;
}

// print status

int nsl_base_list::print_base_list_status(ostream& out) const
{
	print_base_status(out);

	return 1;
}
int nsl_base_list::print_status(ostream& out) const
{
	print_base_list_status(out);

	return 1;
}
int nsl_base_list::print_base_list_all_status(ostream& out) const
{
 	nsl_base* base = 0;
	nsl_base_node* node = 0;
         
        for (node = top; node != NULL; node = node->next)
	{
	    if ((base = node->ptr) == NULL)
		continue;
	    if (strcmp(base->get_type(),"list") == 0)
		base->print_all_status(out);
	    else
		base->print_status(out);
	}

	out.flush();

	return 1;
}
int nsl_base_list::print_all_status(ostream& out) const
{
	print_base_list_all_status(out);

	return 1;
}
int nsl_base_list::print_status_by_name(ostream& out,char* bname)
{
	wind_up();
	nsl_base* base = 0;

	if ((base = (nsl_base*)get_by_name(bname)) != NULL)
		base->print_status(out);

	out.flush();

	if (base == NULL)
		return 0;

	return 1;
}
int nsl_base_list::print_status_by_index(ostream& out,int bindex)
{
	wind_up();
	nsl_base* base = 0;

	if ((base = (nsl_base*)get_by_index(bindex)) != NULL)
		base->print_status(out);

	out.flush();

	if (base == NULL)
		return 0;

	return 1;
}

// read, write

int nsl_base_list::write_base_list(nsl_buffer&)
{
	return 1;
}
int nsl_base_list::write(nsl_buffer& buf)
{
	write_base_list(buf);
	return 1;
}
int nsl_base_list::read_base_list(nsl_buffer&)
{
	return 1;
}
int nsl_base_list::read(nsl_buffer& buf)
{
	read_base_list(buf);
	return 1;
}

