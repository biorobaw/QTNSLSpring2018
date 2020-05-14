/************************************/
/*            nsl_site_layer.h      */
/************************************/

#ifndef _NSL_SITE_LAYER_H
#define _NSL_SITE_LAYER_H
#include "nsl_layer.h"
#include "nsl_base_list.h"

#ifndef _NSL_SET
//class nsl_base_list;
//typedef nsl_base_list nsl_list;
class nsl_link_layer;
#endif

class nsl_site_layer : public nsl_layer
{
protected:
//	func* f;	// input function
	nsl_base_list link_list;
	nsl_layer* site_layer; // temp site output
public:
	nsl_site_layer(const char*, const char*);
	~nsl_site_layer();

	nsl_layer* get_site_layer() { return site_layer; }
	void set_site_layer(nsl_layer* slayer) { site_layer = slayer; }

	void add_link(nsl_link_layer*);
//	nsl_link_layer* del_link();

	virtual int run() = 0;
};

#endif

