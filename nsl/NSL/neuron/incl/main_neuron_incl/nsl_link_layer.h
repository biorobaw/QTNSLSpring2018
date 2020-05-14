/************************************/
/*           nsl_link_layer.h       */
/************************************/

#ifndef _NSL_LINK_LAYER_H
#define _NSL_LINK_LAYER_H
#include "nsl_layer.h"
class nsl_link_layer : public nsl_layer
{
protected:
	nsl_layer* from; 
	nsl_layer* to;
	nsl_layer* weight;
	int weight_fg;
	int sign;
	nsl_layer* link_layer; // temp link output
public:
	// add constructor for num_type weights
	nsl_link_layer(nsl_layer&,nsl_layer&,nsl_layer&,int = 1);
	nsl_link_layer(nsl_layer&,nsl_layer&,int = 1);
	~nsl_link_layer();

	nsl_layer* get_from() { return from; }
	nsl_layer* get_to() { return to; }
	nsl_layer* get_weight() { return weight; }
	int get_sign() { return sign; }

	nsl_layer* get_link_layer() { return link_layer; }

	virtual int run() = 0;
};

#endif
