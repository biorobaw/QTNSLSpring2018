//  MAXSELECTOR MODEL
//
//

#ifndef __ASLDIDDAY_H
#define __ASLDIDDAY_H
#include "asl.h"
#include "asl_seq.h"
#include "nsl.h"
#include "nsl_dout_num_1.h"
#include "nsl_din_num_1.h"
class MaxSelector : public NslModule
{	
public:
	NslDinFloat1 in; // network input
	
private:
	NslFloat1 up; 	// membrane potential
	NslFloat1 uf; 	// firing rate
	
	NslFloat0 vp; 	// membrane potential
	NslFloat0 vf; 	// firing rate

	NslFloat0 k;
	NslFloat0 tu;
	NslFloat0 tv;
	NslFloat0 hu;
	NslFloat0 hv;
	NslFloat0 wuu;
	NslFloat0 wuv;
	NslFloat0 wvu;

public:	
	MaxSelector(char*, NslModule*,int);
	~MaxSelector() {}
	
	void initRun();
	void simRun();
};

class MaxSelectorStimulus : public NslModule
{	
public:
	NslDoutFloat1 out;
	
	MaxSelectorStimulus(char*, NslModule*,int);
	~MaxSelectorStimulus() {}
};

class MaxSelectorModel : public NslModel
{	
public:
	MaxSelector maxSelector;
	MaxSelectorStimulus stimulus;
	
	MaxSelectorModel();
	~MaxSelectorModel() {}
	
	void makeConn();
};

#endif
