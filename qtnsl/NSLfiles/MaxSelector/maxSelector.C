/****************************************************************/
/*                                                           	*/
/*                       maxSelector.C                         	*/
/*                                                            	*/
/****************************************************************/

# include "nsl_include.h"
#include "nsl_kernel.h"
#include "nsl_num.h"
#include "nsl_data_math.h"
#include "nsl_vector_math.h"
#include "nsl_num_vector.h"
#include "nsl_other_include.h"
#include "asl_all_rts_include.h"
#include "maxSelector.h"

#define _NSL_PROMPTS //remove hardcoded testing -bn7

extern nsl_num_0 NSLramp(const nsl_num_0& a);
extern nsl_num_1 NSLstep(const nsl_num_1& a,const nsl_num_0& b);
extern nsl_num_0& nslDiff(nsl_num_0& m,nsl_num_0& k,const nsl_num_0& a);
extern nsl_num_1& nslDiff(nsl_num_1& m,nsl_num_0& k,const nsl_num_1& a);


MaxSelector::MaxSelector(char* str, NslModule* parent,int size) :
	NslModule(str, parent),
	in("in",this,size), up("up",this,size), uf("uf",this,size),
	vp("vp",this), vf("vf",this),k("k",this), tu("tu",this), tv("tv",this),
	hu("hu",this), hv("hv",this),
	wuu("wuu",this), wuv("wuv",this), wvu("wvu",this)
{
	tu.set_value( 1.0 );
	tv.set_value( 1.0 );
	k.set_value( 0.1 );
	wuu.set_value( 1.0 );
	wuv.set_value( 1.0 );
	wvu.set_value( 1.0 );
	hu.set_value( 0.1 );
	hv.set_value( 0.5 );
}

void MaxSelector::initRun()
{
	up = 0;
	vp = 0;
	uf = 0;
	vf = 0;

	for (int i = 0; i < in.get_imax(); i++)
		in[i] = 0;

	in[4] = 1.0;
	in[6] = 0.5;
}

void MaxSelector::simRun()
{	
	//nsldiff call to

	NslNumType *vv = up.get_v();
	NslNumType *vx = uf.get_v();
	NslNumType *vz = in.get_v();

	nslDiff(up,tu, - up + wuu*uf - wvu*vf - hu + in);
	uf = NSLstep(up,k);

	nslDiff(vp,tv, - vp + (wuv*uf).sum() - hv); // (wuv*uf).sum() // nslSum(wuv*uf)
	vf = NSLramp(vp);
}

MaxSelectorStimulus::MaxSelectorStimulus(char* str, NslModule* parent,int size) :
	NslModule(str, parent),
	out("out",this,size)
{
}

MaxSelectorModel::MaxSelectorModel() : NslModel("MaxSelectorModel"),
	maxSelector("maxSelector",this,10), stimulus("stimulus",this,10)
{
	makeConn();
}

void MaxSelectorModel::makeConn()
{
	nslConnect(stimulus.out,maxSelector.in);
}

AslSchemaModel<MaxSelectorModel> _MaxSelectorModel("MaxSelectorModel");


