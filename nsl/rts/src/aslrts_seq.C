#include "nsl_neuron.h"
#include "asl_all_rts_include.h"
#include "xnsl_system.h"

extern xnsl_system* XNSL_SYSTEM;
using namespace std;

// Methods of class: AslSystem
AslSystem::AslSystem(int argc, char **argv) : nsl_public("asl_system")
{
	strcpy(fileName,"");
	AslParseArguments(argc,argv);

	if (asl_debug)
		aslio<<"ASL SYSTEM: Kernel initialization"<< aslend;
	
	cont = 1;
	
	AslCom = new AslIPCManager();

// AW98	AslGraphInit(arg);
}

AslSystem::~AslSystem()
{
	delete AslCom;		
}

void AslSystem::AslAddSchema(AslSchema *s)
{	
	schemaList.insert(s);
}

/*void AslSystem::AslRemoveSchema(char *name)
{
	if (asl_debug)
		aslio<<"ASL SYSTEM: Deleting Schema "<<name<<" from List "<<aslend;
	
	AslSchema *temp;
	schemaList.startOnTop();
	while ((temp=schemaList.getActual())!=NULL && (strcmp(temp->getname(),name)!=0))
		schemaList.goNext();
			
	if (temp!=NULL)
	{
		temp=schemaList.removeThis();
		delete temp;
	}
	else
	{
		aslerr<<"ASL SYSTEM ERROR: Can't delete schema "<<name<<aslend;
	}	
}	*/

/* void AslSystem::AslChangeState(int STATE, int steps)
{	
	AslState *state = new AslState;
	
	state->obj = s;
	state->state = STATE;
	state->steps = steps;
	state->depList.insert(null);
	schemaExecList.insert(state);
}	*/

void AslSystem::AslLoadFile(void)
{	
	if (strcmp(fileName,""))
	{
		if (asl_debug)
			aslio << "ASL SYSTEM: Loading file " <<fileName<< aslend;
	
		NslLoad(fileName);

	}
}
// -------------------------------------------------------------------------

int AslSystem::AslDoListMakeConn(void)
{
	if (asl_debug)
		aslio << "ASL SYSTEM: Initiating" << aslend;
		
	AslState *execst;

	schemaExecList.startOnTop();
		
	while ((execst = schemaExecList.getActual()) != NULL)
	{
		execst->obj->makeConn();
		schemaExecList.goNext();
	}
	
	return 1;
}
int AslSystem::AslDoListInitModule(void) 
{
	return 1;
}
int AslSystem::AslDoListEndModule(void)
{
	return 1;
}
int AslSystem::AslDoListInitSys(void)
{
	if (asl_debug)
		aslio << "ASL SYSTEM: Initiating" << aslend;
		
	AslState *execst;

	schemaExecList.startOnTop();

	while ((execst = schemaExecList.getActual()) != NULL)
	{
		breakfg = 1;
		execst->obj->receive();
		execst->obj->initSys();  
		execst->obj->send();
		if (breakfg != 1)
			break;
		schemaExecList.goNext();
	}
	
	return breakfg;
}
int AslSystem::AslDoListEndSys(void)
{
	if (asl_debug)
		aslio << "ASL SYSTEM: Initiating" << aslend;
		
	AslState *execst;

	schemaExecList.startOnTop();
		
	while ((execst = schemaExecList.getActual()) != NULL)
	{
		breakfg = 1;
		execst->obj->receive();
		execst->obj->endSys();  
		execst->obj->send();
		if (breakfg != 1)
			break;
		schemaExecList.goNext();
	}
	
	return breakfg;
}
	
// run

int AslSystem::AslDoListInitRun(void)
{
	if (true)
	{
		aslio << "ASL SYSTEM: Initiating" << aslend;
	}
	AslState *execst;

	schemaExecList.startOnTop();
		
	while ((execst = schemaExecList.getActual()) != NULL)
	{
		breakfg = 1;
		execst->obj->receive();
		execst->obj->initRun(); 
		execst->obj->send();
		if (breakfg != 1)
			break;
		schemaExecList.goNext();
	}
	
	return breakfg;
}

int AslSystem::AslDoListSimRun(void)
{	
	if (true)
	{
		aslio << "ASL SYSTEM: Running" << aslend;
	}

	AslState *execst;

	schemaExecList.startOnTop();
		
	while ((execst = schemaExecList.getActual()) != NULL)
	{
		breakfg = 1;
		execst->obj->receive();
		execst->obj->simRun();  
		execst->obj->send();
		if (breakfg != 1)
			break;
		schemaExecList.goNext();
	}

	return breakfg;
}

int AslSystem::AslDoListEndRun(void)
{
	if (true)
		aslio << "ASL SYSTEM: Running" << aslend;
		
	AslState *execst;

	schemaExecList.startOnTop();
		
	while ((execst = schemaExecList.getActual()) != NULL)
	{
		breakfg = 1;
		execst->obj->receive();
		execst->obj->endRun(); 
		execst->obj->send();
		if (breakfg != 1)
			break;
		schemaExecList.goNext();
	}

	return breakfg;
}

// train

int AslSystem::AslDoListInitTrain(void)
{
	if (asl_debug)
		aslio << "ASL SYSTEM: Initiating" << aslend;
		
	AslState *execst;

	schemaExecList.startOnTop();
		
	while ((execst = schemaExecList.getActual()) != NULL)
	{
		breakfg = 1;
		execst->obj->receive();
		execst->obj->initTrain(); 
		execst->obj->send();
		if (breakfg != 1)
			break;
		schemaExecList.goNext();
	}

	return breakfg;
}

int AslSystem::AslDoListSimTrain(void)
{	
	if (asl_debug)
		aslio << "ASL SYSTEM: Running" << aslend;
		
	AslState *execst;

	schemaExecList.startOnTop();
		
	while ((execst = schemaExecList.getActual()) != NULL)
	{
		breakfg = 1;
		execst->obj->receive();
		execst->obj->simTrain();  
		execst->obj->send();
		if (breakfg != 1)
			break;
		schemaExecList.goNext();
	}

	return breakfg;
}

int AslSystem::AslDoListEndTrain(void)
{
	if (asl_debug)
		aslio << "ASL SYSTEM: Running" << aslend;
		
	AslState *execst;

	schemaExecList.startOnTop();
		
	while ((execst = schemaExecList.getActual()) != NULL)
	{
		breakfg = 1;
		execst->obj->receive();
		execst->obj->endTrain(); 
		execst->obj->send();
		if (breakfg != 1)
			break;
		schemaExecList.goNext();
	}

	return breakfg;
}

int AslSystem::AslDoAllEndTrain(void)
{
	if (asl_debug)
		aslio << "ASL SYSTEM: Running" << aslend;
		
	AslState *execst;

	schemaExecList.startOnTop();
		
	while ((execst = schemaExecList.getActual()) != NULL)
	{
		breakfg = 1;
		execst->obj->receive();
		execst->obj->endTrain(); 
		execst->obj->send();
//		if (breakfg != 1)
//			break;
		schemaExecList.goNext();
	}

	return breakfg;
}


void AslSystem::AslExecMethod(AslState *schema_st)
{	
	if (asl_debug)
		aslio << "ASL SYSTEM: Executing "<<schema_st->obj->getname()<<":"<<schema_st->state<< aslend;

	switch(schema_st->state)
	{
		case INITRUN	: schema_st->obj->initRun();
				  schema_st->state+=1;
				  break;
				  
		case SIMRUN	: int s;
				  if (s = schema_st->obj->getSteps()) {
					  schema_st->obj->simRun();
					  schema_st->obj->setSteps(s-1);
				  }
				  else schema_st->state+=1;
				  break;				  			
				   
		case END	:  aslio << "TERMINE ESTADOS" << aslend;
				// AslRemExecSchema(schema_st->obj->getname());
				   break;
	}
}

void AslSystem::AslParseArguments(int argc, char**argv)
{
	int i;

	arg.argc = argc;
	arg.argv = argv;
	
	asl_debug=0;
	
	for (i=1; i<argc; i++)
	{
		if (!strcmp(argv[i],"-debug"))
			asl_debug=1;
		else if (!strcmp(argv[i],"-graph"))
		{

			i++;
			strcpy(fileName,argv[i]);
		}
		
	}
}

void AslSystem::AslStop(void)
{
	cont = 0;
}

// Methods of class: AslSchemaInterface

AslSchemaInterface::AslSchemaInterface (char *str, nsl_model* parent, int fg) : 
	nsl_model(str,parent,fg)
{
	aslExternalOutputPortList = new AslList<AslPort>;
	aslExternalInputPortList  = new AslList<AslPort>;

	aslExternalFuncList = new AslList<AslFunction>;
}

AslSchemaInterface::~AslSchemaInterface (void)
{
	delete aslExternalOutputPortList;
	delete aslExternalInputPortList;
}

AslPort* AslSchemaInterface::AslGetExternalInputPort(char *n, int i)
{
	AslPort *temp;
	
	aslExternalInputPortList->startOnTop();
	
	while ((temp=aslExternalInputPortList->getActual())!=NULL && (strcmp(temp->AslGetName(), n) || temp->AslGetIndex()!=i))
		aslExternalInputPortList->goNext();

	return temp;
}

void AslSchemaInterface::AslAddExternalInputPort(AslPort* p)
{
	aslExternalInputPortList->insert(p);
}

AslPort* AslSchemaInterface::AslGetExternalOutputPort(char* n, int i)
{
	AslPort *temp;
	
	aslExternalOutputPortList->startOnTop();
	
	while ((temp=aslExternalOutputPortList->getActual())!=NULL && (strcmp(temp->AslGetName(), n) || temp->AslGetIndex()!=i))
		aslExternalOutputPortList->goNext();

	return temp;
}

void AslSchemaInterface::AslAddExternalFunc(AslFunction *p)
{ 
	aslExternalFuncList->insert(p);
}

AslFunction* AslSchemaInterface::AslGetExternalFunc(char* n)
{
	AslFunction *temp;
	
	aslExternalFuncList->startOnTop();
	
	while ((temp=aslExternalFuncList->getActual())!=NULL && strcmp(temp->AslGetName(), n))
		aslExternalFuncList->goNext();

	return temp;
}

void AslSchemaInterface::AslAddExternalOutputPort(AslPort*p)
{
	aslExternalOutputPortList->insert(p);
}

/* asl_any_t AslSchemaInterface::AslExecuteRPC(char *n, asl_any_t arg)
{
	AslFunction *temp;

	temp = AslGetExternalFunc(n);
	return temp->funcPtr(arg);
}	*/

// Methods of class: AslSchema

AslSchema::AslSchema(char *str, nsl_model* parent, int fg) : 
	AslSchemaInterface (str, parent, fg)
{
	strcpy(name, str);

	aslInternalOutputPortList = new AslList<AslPort>;
	aslInternalInputPortList  = new AslList<AslPort>;

	delegate(this);
	
	tid = -1;
	steps = 0;	// number of steps for simrun()

// original list
	asl->AslAddSchema(this);
	
	aslio<<"ASL RTS: Creating schema ["<<str<<"]"<<aslend;
}

AslSchema::~AslSchema()
{
	delete aslInternalOutputPortList;
	delete aslInternalInputPortList;

	// buscar en la lista de esquemas y borrarse de ahi !!!

/*	if (tid>0)
	{
		aslScheduler->AslGetThreadAnswer(tid, NULL);
		aslScheduler->AslDeleteThread(tid);
	}	*/
}
int AslSchema::nslBreakSim()
{
	if (asl != NULL)
		asl->set_breakfg(-1);
	else
		cmd_out("Null ASL system");

	return 1;
}
int AslSchema::nslBreakEpoch()
{
	if (asl != NULL)
		asl->set_breakfg(-2);
	else
		cmd_out("Null ASL system");

	return 1;
}
	
int AslSchema::display(void)
{		
	if (XNSL_SYSTEM != NULL)
	{	
		if (asl_debug)
			aslio<<"ASL SCHEMA: Displaying Graphics"<<aslend;
		XNSL_SYSTEM->display();
	}
	else
		aslerr << "NULL XNSL_SYSTEM" << aslend;
	return 1;
}
// -------------------------------------------------------------------------
void AslSchema::delegate(AslSchema* temp) // only one is enough
{                
        if (temp==NULL) return; 
                
        AslState *st = new AslState;
                
        st->obj = temp;
	st->state = MAKECONN;	// the first possible schema function
	st->steps = temp->steps;	// necesita de funcion ?????
//	st->depList.insert(null);	// !!!!!! depList !!!!!!!!!!
	AslList<AslState> *xclist = &(asl->getExecList());

	if (xclist == NULL)
	{
		cmd_error("WARNING: exec list NULL!");
	}

	xclist->insert(st);
}
/*
void AslSchema::delegate(...) // only one is enough
{
	int cont, i;
	va_list ap;
		
        va_start(ap,0);
	
        for(cont=0;;cont++) {
                AslSchema *temp = va_arg(ap, AslSchema*);
                
                if (temp==NULL) break; 
                
                AslState *st = new AslState;
                
                st->obj = temp;
		st->state = MAKECONN;	// the first possible schema function
		st->steps = temp->steps;	// necesita de funcion ?????
//		st->depList.insert(null);	// !!!!!! depList !!!!!!!!!!

		asl->getExecList().insert(st);
        }

        va_end(ap);
}
*/
AslPort *AslSchema::AslGetInternalInputPort(char* n, int i)
{
	AslPort *temp;
	
	aslInternalInputPortList->startOnTop();
	
	while ((temp=aslInternalInputPortList->getActual())!=NULL && (strcmp(temp->AslGetName(), n) || temp->AslGetIndex()!=i))
		aslInternalInputPortList->goNext();

	return temp;
}

void AslSchema::AslAddInternalInputPort(AslPort* p)
{
	aslInternalInputPortList->insert(p);
}

AslPort *AslSchema::AslGetInternalOutputPort(char* n, int i)
{
	AslPort *temp;
	
	aslInternalOutputPortList->startOnTop();
	
	while ((temp=aslInternalOutputPortList->getActual())!=NULL && (strcmp(temp->AslGetName(), n) || temp->AslGetIndex()!=i))
		aslInternalOutputPortList->goNext();

	return temp;
}

void AslSchema::AslAddInternalOutputPort(AslPort* p)
{
	aslInternalOutputPortList->insert(p);
}

int AslSchema::AslSearchInternalInputPortOcurrence(const char *n)
{
	AslPort *temp;
	int cont=0;
	
	aslInternalInputPortList->startOnTop();
	while ((temp=aslInternalInputPortList->getActual())!=NULL)
	{
		if (!strcmp(temp->AslGetName(), n))
			cont ++;
		aslInternalInputPortList->goNext();
	}
		
	return cont;
}

int AslSchema::AslSearchExternalInputPortOcurrence(const char *n)
{
	AslPort *temp;
	int cont=0;
	
	aslExternalInputPortList->startOnTop();
	while ((temp=aslExternalInputPortList->getActual())!=NULL)
	{
		if (!strcmp(temp->AslGetName(), n))
			cont ++;
		aslExternalInputPortList->goNext();
	}
		
	return cont;
}

int AslSchema::AslSearchInternalOutputPortOcurrence(const char *n)
{
	AslPort *temp;
	int cont=0;

	aslInternalOutputPortList->startOnTop();
	while ((temp=aslInternalOutputPortList->getActual())!=NULL)
	{
		if (!strcmp(temp->AslGetName(), n))
			cont ++;
		aslInternalOutputPortList->goNext();
	}

	return cont;
}

int AslSchema::AslSearchExternalOutputPortOcurrence(const char *n)
{
	AslPort *temp;
	int cont=0;
	
	aslExternalOutputPortList->startOnTop();
	while ((temp=aslExternalOutputPortList->getActual())!=NULL)
	{
		if (!strcmp(temp->AslGetName(), n))
			cont ++;
		aslExternalOutputPortList->goNext();
	}
		
	return cont;
}
void AslSchema::receive()
{
	AslPort *temp;
	AslList<AslPort>* list;
	
	list = aslExternalInputPortList;
	list->startOnTop();
	while ((temp=(AslPort*)list->getActual())!=NULL) {
		temp->receive();
		list->goNext();
	}
/*
	list = aslInternalInputPortList;
	list->startOnTop();
	while ((temp=(AslPort*)list->getActual())!=NULL){
		temp->receive();
		list->goNext();
	}
	
	list = aslExternalOutputPortList;
	list->startOnTop();
	while ((temp=(AslPort*)list->getActual())!=NULL) {
		temp->receive();
		list->goNext();
	}

	list = aslInternalOutputPortList;
	list->startOnTop();
	while ((temp=(AslPort*)list->getActual())!=NULL){
		temp->receive();
		list->goNext();
	}
*/
}
void AslSchema::send()
{
	AslPort *temp;
	AslList<AslPort>* list;
	
	list = aslExternalOutputPortList;
	list->startOnTop();
	while ((temp=(AslPort*)list->getActual())!=NULL) {
		temp->send();
		list->goNext();
	}

	list = aslInternalOutputPortList;
	list->startOnTop();
	while ((temp=(AslPort*)list->getActual())!=NULL){
		temp->send();
		list->goNext();
	}
	
	list = aslExternalInputPortList;
	list->startOnTop();
	while ((temp=(AslPort*)list->getActual())!=NULL) {
		temp->send();
		list->goNext();
	}

	list = aslInternalInputPortList;
	list->startOnTop();
	while ((temp=(AslPort*)list->getActual())!=NULL){
		temp->send();
		list->goNext();
	}

}

void AslSchema::nslConnect(nsl_layer& src, nsl_layer& dst)
{
	AslPort* psrc = (AslPort*) src.get_port();
	AslPort* pdst = (AslPort*) dst.get_port();
		
	AslCom->AslConnect(psrc, pdst);	// verificar para distribuido la variable comm
}
/*
void AslSchema::connect(nsl_layer *src, nsl_layer *dst)
{
	AslPort* psrc = (AslPort*) src->get_port();
	AslPort* pdst = (AslPort*) dst->get_port();
		
	AslCom->AslConnect(psrc, pdst);	// verificar para distribuido la variable comm
}

void AslSchema::connect(nsl_layer& src, nsl_layer *dst)
{
	AslPort* psrc = (AslPort*) src.get_port();
	AslPort* pdst = (AslPort*) dst->get_port();
		
	AslCom->AslConnect(psrc, pdst);	// verificar para distribuido la variable comm
}

void AslSchema::connect(nsl_layer *src, nsl_layer& dst)
{
	AslPort* psrc = (AslPort*) src->get_port();
	AslPort* pdst = (AslPort*) dst.get_port();
		
	AslCom->AslConnect(psrc, pdst);	// verificar para distribuido la variable comm
}
*/
void AslSchema::nslConnect(AslPort *src, AslPort *dst)
{
	AslCom->AslConnect(src, dst);	// verificar para distribuido la variable comm
}

void AslSchema::nslDisconnect(AslPort *src, AslPort *dst)
{
	AslCom->AslDisconnect(src, dst);
}

void AslSchema::nslRelabel(nsl_layer& src, nsl_layer& dst)
{
	AslPort* psrc = (AslPort*) src.get_port();
	AslPort* pdst = (AslPort*) dst.get_port();
		
	AslCom->AslRelabel(psrc, pdst);	// verificar para distribuido la variable comm
}
/*
void AslSchema::relabel(nsl_layer *src, nsl_layer *dst)
{
	AslPort* psrc = (AslPort*) src->get_port();
	AslPort* pdst = (AslPort*) dst->get_port();
		
	AslCom->AslRelabel(psrc, pdst);	// verificar para distribuido la variable comm
}
*/
void AslSchema::nslRelabel(AslPort *src, AslPort *dst)
{
	AslCom->AslRelabel(src, dst);	// verificar para distribuido la variable comm
}

void AslSchema::nslDelabel(AslPort *src, AslPort *dst)
{
	AslCom->AslDelabel(src, dst);
}

// Methods of class: AslFunction

AslFunction::AslFunction(AslSchema *s, char *n, int arg, int ans /*, asl_thread_func_t f */)
{
	schema = s;
	strcpy(name, n);
	argType = arg;
	answerType = ans;
//	funcPtr = f;
	
	aslio << "antes de agregarlo \n";
	schema->AslAddExternalFunc(this);
	aslio << "despues de agregarlo \n";

	if (asl_debug)
		aslio << "ASL RTS: Adding function "<<n<<aslend;
} 

char* AslFunction::AslGetName(void)
{
	return name;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
AslPort::AslPort(const char *str, nsl_public *s, int com)
{
	schema = (AslSchema*) s; // not needed ? 
	m_parent = s;

	strcpy(name, str);
	comType = com;	// ASL_DATA_OUTPUT/INPUT...
	
	scope = EXTERNAL;

	if (comType==ASL_DATA_INPUT)	
		((AslSchema*) s)->AslAddExternalInputPort(this);
	else if (comType==ASL_DATA_OUTPUT)
		((AslSchema*) s)->AslAddExternalOutputPort(this);
	else
		aslio << "ASL RTS: Not a valid port type: " << comType << aslend;
				
	aslComm = AslCom;		//antes c en lugar de comm

	index = AslSearchPortOcurrence(str);
	if (asl_debug)
		aslio << "ASL RTS: Creating Port "<<str<<"["<<index<<"]"<<aslend;
			
	AslCom->getPortList().insert(this);
		
	bid = aslComm->AslIncPortID();
	
	numberOfMessages = 0;
	numberOfConnections = 0;
	numberOfRelabels = 0;
} 

AslPort::~AslPort(void) 
{
/*	aslComm->AslDelBuf(bid);	*/
}

int AslPort::AslSearchPortOcurrence(const char *n) 
{
	if (scope==INTERNAL)
		return schema->AslSearchInternalInputPortOcurrence(n);
	else
		return schema->AslSearchExternalInputPortOcurrence(n);
}

int AslPort::AslGetIndex(void) 
{ 
	return index; 
}

int AslPort::AslGetType(void) 
{ 
	return comType; 
}

int AslPort::AslGetScope(void) 
{ 
	return scope; 
}

int AslPort::AslGetBid(void) 
{ 
	return bid; 
}

char* AslPort::AslGetName(void) 
{ 
	return name; 
}

void AslPort::AslsetSchema(AslSchema *s) 
{ 
	schema = s;
}
// -----------------
int AslPort::AslIsAnInputBuffer(void)
{
	return (comType==ASL_DATA_INPUT);
// 	|| (comType==ASL_CONTROL_INPUT);
//	return 1;
}

int AslPort::AslIsAnOutputBuffer(void)
{
	return (comType==ASL_DATA_OUTPUT);
//	 || (comType==ASL_CONTROL_OUTPUT) 
//	    || (commType==ASL_NEW_CONTAINER) || (commType==ASL_RELABEL_BUFFER) ; 
//	return 1;
}

int AslPort::AslGetNumberOfElements(void)
{
	int res;
	
	res = numberOfMessages;

	return res;
}

int AslPort::AslAddConnection(int bidc)
{
	AslPortRelations *temp, *node = new AslPortRelations;
	
	node->bid = bidc;
	
	connections.startOnTop();
	while ((temp=connections.getActual())!=NULL && temp->bid!=bidc)
		connections.goNext();
	
	if (temp==NULL)
	{
		numberOfConnections++;	
		connections.insert(node);
	}
	else
		if (asl_debug)
			aslio<<"ASL IPC MANAGER: Connection was already established"<<aslend;		    
	
	if (asl_debug)
		aslio<<"ASL IPC MANAGER: I have connected local buffer with bid ["<< bid 
		    <<"] with ["<< bidc << "] "<<aslend;
		    
	return 1;
}

int AslPort::AslDeleteConnection(int bidc)
{
	int res=1;
	
	AslPortRelations *temp;
	
	connections.startOnTop();
	while ((temp=connections.getActual())!=NULL && temp->bid!=bidc)
		connections.goNext();
	
	if (temp==NULL)
	{
		aslerr<<"ASL PORT ERROR: I can't disconnect buffer ["<<bid
		      <<"] of buffer ["<<bidc<<"] "<<aslend;
		res=0;
	}
	else
	{
		numberOfConnections--;
		temp = connections.removeThis();
		delete temp;
	}

	return res;	
}

AslPortRelations* AslPort::AslGetConnection(void)
{
	return connections.getActual();
}

void AslPort::AslPutConnectionListAtBegining(void)
{
	connections.startOnTop();
}

void AslPort::AslGoToNextConnection(void)
{
	connections.goNext();
}
int AslPort::AslAddRelabel(int bidc)
{
	AslPortRelations *temp, *node = new AslPortRelations;
	
	node->bid = bidc;
	
	relabels.startOnTop();
	while ((temp=relabels.getActual())!=NULL && temp->bid!=bidc)
		relabels.goNext();
	
	if (temp==NULL)
	{
		numberOfRelabels++;	
		relabels.insert(node);
	}
	else
		if (asl_debug)
			aslio<<"ASL IPC MANAGER: Relabel was already established"<<aslend;		    
	
	if (asl_debug)
		aslio<<"ASL IPC MANAGER: I have relabeled local buffer with bid ["<< bid 
		    <<"] with ["<< bidc << "] "<<aslend;
		    
	return 1;
}

int AslPort::AslDeleteRelabel(int bidc)
{
	int res=1;
	
	AslPortRelations *temp;
	
	relabels.startOnTop();
	while ((temp=relabels.getActual())!=NULL && temp->bid!=bidc)
		relabels.goNext();
	
	if (temp==NULL)
	{
		aslerr<<"ASL PORT ERROR: I can't delabel buffer ["<<bid
		      <<"] of buffer ["<<bidc<<"] "<<aslend;
		res=0;
	}
	else
	{
		numberOfRelabels--;
		temp = relabels.removeThis();
		delete temp;
	}

	return res;	
}

AslPortRelations* AslPort::AslGetRelabel(void)
{
	return relabels.getActual();
}

void AslPort::AslPutRelabelListAtBegining(void)
{
	relabels.startOnTop();
}

void AslPort::AslGoToNextRelabel(void)
{
	relabels.goNext();
}


void AslPort::send()
{
}

void AslPort::receive()
{
}
