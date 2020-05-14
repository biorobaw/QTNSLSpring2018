//  ASL RUN TIME SYSTEM LIBRARY
//
//  ASL (Abstract Schema Language) to C++ Compiler
//
//
//
//  FILE NAME   : asl_seq.h
//  MODULE TYPE : ASL Runtime System Library
//  STATUS      : In development
//  PURPOSE     : Export definition of the ASL runtime library
//  
//
//  Instituto Tecnologico Autonomo de Mexico 
//  (c) Copyright 1995  
//
//
//
//  HISTORY : Version (Date-Name) Modification, description. 
//
//            0.0 (Apr 20, 1992 - Longguang Wu),
//            Start of development.
//
//            0.5 (May 05, 1993 - Roger Zimmermann),
//            Version 0.5 Alpha.
//
//            0.7 (Oct 28, 1995 - Claudia Calderas & Salvador Marmol), 
//            Start of development for distributed execution.
//
//            1.0 (Aug 12, 1996 - Claudia Calderas & Salvador Marmol), 
//            Version 1.0 Beta.
//
//            1.0 (Oct 23, 1997 - Oscar Peguero), 
//            Version 1.0 Beta 2.
//
//            1.1 (Ene 29, 1998 - Oscar Peguero), 
//            Simple version for PC with double buffering (no threads).


//#pragma interface

#ifndef __ASL_SEQ_H
#define __ASL_SEQ_H
#include "nsl_layer.h"
#include "nsl_model.h"
#include "asllist.h"
#include "aslcom_seq.h"

struct AslState
{
	AslSchema *obj;
	int state;
	int steps;
	AslListSchema depList; // AslList<AslSchema>
};

struct aslArgument
{
	int argc;
	char **argv;
};

// Structure for connections y relabels

struct AslPortRelations
{
	int bid;	// now is a port ID
};

class AslSystem : public nsl_public
{
	AslList<AslSchema> schemaList;	// Container schema list
	AslList<AslState>  schemaExecList;
	
	int recvBid, sendBid;
	int AnsRecvBid, AnsSendBid;
	int cont;
	
	int breakfg; // -1 sim, -2 epoch
	
	aslArgument arg;
	
	char fileName[60];
public:
	AslSystem(int, char **);
	~AslSystem();
	
	void set_breakfg(int fg) { breakfg = fg; }
	int get_breakfg() { return breakfg; }
	
	void AslAddSchema(AslSchema*);
//	void AslRemoveSchema(char*);
//	void AslRemExecSchema(char *);
	
// new execution
	int AslDoListMakeConn(void);
	int AslDoListInitModule(void);
	int AslDoListEndModule(void);
	int AslDoListInitSys(void);
	int AslDoListEndSys(void);
	int AslDoListInitRun(void);
	int AslDoListSimRun(void);
	int AslDoListEndRun(void);
	int AslDoListInitTrain(void);
	int AslDoListSimTrain(void);
	int AslDoListEndTrain(void);

	int AslDoAllEndTrain(void);

	void AslExecMethod(AslState*);
	
	void AslParseArguments(int, char**);
	
	AslSchema& AslGetSchema(char*);
	
	void AslStop(void);
	void AslLoadFile(void);
	
	AslList<AslState>& getExecList(void) { return schemaExecList; };
};

// Class: AslSchemaInterface

class AslSchemaInterface : public nsl_model
{
protected:
	AslList<AslPort> *aslExternalInputPortList;      // External input port list
	AslList<AslPort> *aslExternalOutputPortList;     // External output port list
	AslList<AslFunction>   *aslExternalFuncList;     // External function list

	AslFunction* AslGetExternalFunc(char*);

public:
	AslSchemaInterface(char * = "" , nsl_model* = 0, int = 1);
	~AslSchemaInterface(void);

	AslPort* AslGetExternalInputPort(char*, int i);
	void AslAddExternalInputPort(AslPort*);

	AslPort* AslGetExternalOutputPort(char*, int i);
	void AslAddExternalOutputPort(AslPort*);

	void AslAddExternalFunc(AslFunction*);
//	asl_any_t AslExecuteRPC(char *, asl_any_t arg);
};

// Class: AslSchema

class AslSchema : public AslSchemaInterface
{
	int tid;

protected:
	AslList<AslPort>  *aslInternalInputPortList;   // Internal input port list
	AslList<AslPort> *aslInternalOutputPortList;   // Internal output port list
	char name[256];
	
	int steps;	// For maintaining schema run method steps

//	AslSystem *aslSystemPtr;

public:
	AslSchema(char * = "" , nsl_model* = 0, int = 1);	
	~AslSchema(void);

	AslPort* AslGetInternalInputPort(char*, int i);
	void AslAddInternalInputPort(AslPort*);

	AslPort* AslGetInternalOutputPort(char*, int i);
	void AslAddInternalOutputPort(AslPort*);

	int AslSearchInternalInputPortOcurrence(const char *);
	int AslSearchExternalInputPortOcurrence(const char *);	
	int AslSearchInternalOutputPortOcurrence(const char *);
	int AslSearchExternalOutputPortOcurrence(const char *);
	
	int nslBreakSim();
	int nslBreakEpoch();

	// added 10-98 by Alfredo
	void nslConnect(nsl_layer&, nsl_layer&);	
//	void connect(nsl_layer*, nsl_layer*);	
//	void connect(nsl_layer&, nsl_layer*);	
//	void connect(nsl_layer*, nsl_layer&);	
				
	void nslConnect(AslPort*, AslPort*);	// antes en AslOutputPort !!!!!	
	void nslDisconnect(AslPort*, AslPort*);	// 	"	"
	
	void nslRelabel(nsl_layer&, nsl_layer&);	
//	void relabel(nsl_layer*, nsl_layer*);	
	
	void nslRelabel(AslPort*, AslPort*);	// antes en AslOutputPort !!!!!	
	void nslDelabel(AslPort*, AslPort*);	// 	"	"
	
	void send();
	void receive();
	
//	void delegate(...);
	void delegate(AslSchema*);
	int display(void);
	
	void updateBuffers(void) { }	
	void memAlloc(void) { }	
/*
	virtual void makeConn(void) { }	
	virtual void initTrain(void) { }	
	virtual void simTrain(void) { }	
	virtual void endTrain(void) { }	
	virtual void initRun(void) { }	
	virtual void simRun(void) { }	
	virtual void endRun(void) { }	
	virtual void initSys(void) { }	
	virtual void endSys(void) { }	
	virtual void initModule(void) { }	
	virtual void endModule(void) { }	
*/
	int getSteps(void) { return steps; }
	void setSteps(int s) { steps = s; }
	char* getname(void){ return name; }
};

template<class T>
class AslSchemaModel : public nsl_model
{
public:
	AslSchemaModel(const char* str) : nsl_model(str,0,-1) {}
	
	~AslSchemaModel() {}
	
	nsl_model* makeInstance(){
		return new T;
	}
};

// Class AslFunction

class AslFunction
{
	char name[ASL_NAME_LEN];
	int argType;
	int answerType;

	AslSchema *schema;
	
//	asl_any_t answer;
public:
	AslFunction(AslSchema *, char*, int, int /*, asl_thread_func_t */);
	~AslFunction(void) {}

//	asl_thread_func_t funcPtr;
	
	char* AslGetName(void);
};

// Class AslPort 

class AslPort : public nsl_public
{
protected:

	AslList<AslPortRelations> connections;
	AslList<AslPortRelations> relabels;

	int commType;
	int numberOfMessages;
	
	int numberOfConnections;
	int numberOfRelabels;
	
	char  name[ASL_NAME_LEN];      // port name
	int   comType;                 // 1 - input, 2 - output	
	int   scope;                   // 1 - external, 2 - internal
	int   index;		       // Ocurrence of the same port name
	int   bid;		       // Port ID

	AslSchema     *schema;
	AslIPCManager *aslComm; 

public:

	AslPort(const char *, nsl_public *, int);	// constructor para diferentes implementaciones de puerto

	~AslPort(void);

	int   AslGetType(void); 
	int   AslGetIndex(void); 
	int   AslGetScope(void);
	int   AslGetBid(void);
	char* AslGetName(void);
	void  AslsetSchema(AslSchema *);	// schema reference setting

	int AslSearchPortOcurrence(const char*);
		
	int AslAddConnection(int bidc);
	int AslDeleteConnection(int bidc);

	int AslAddRelabel(int bidc);
	int AslDeleteRelabel(int bidc);
		
	virtual void send();
	virtual void receive();
	
	AslPortRelations* AslGetConnection(void);
	void AslPutConnectionListAtBegining(void);
	void AslGoToNextConnection(void);

	AslPortRelations* AslGetRelabel(void);
	void AslPutRelabelListAtBegining(void);
	void AslGoToNextRelabel(void);
	
	int AslGetNumberOfElements(void);
	int AslIsAnInputBuffer(void);
	int AslIsAnOutputBuffer(void);
	virtual void AslCopyData(AslPort*) {};
};

// AW99: took out Input and Output ports instead added InOut port
// Class: AslInputPort 
/*
template<class T>
class AslInputPort : public AslPort
{
public:
	T *var;
	int AslSearchPortOcurrence(const char *);
	
	AslInputPort(const char *str, nsl_public *s, T *var_asoc) : AslPort(str, s, ASL_DATA_INPUT)
	{
		var = var_asoc;

		index = AslSearchPortOcurrence(str);
		if (asl_debug)
			aslio << "ASL RTS: Creating Input Port "<<str<<"["<<index<<"]"<<aslend;
			
		AslCom->getPortList().insert(this);
		
		if (scope==INTERNAL) {
		    if (comType == ASL_DATA_INPUT) // 1	
			((AslSchema*) s)->AslAddInternalInputPort(this);
		    else
			((AslSchema*) s)->AslAddIInternalOutputPort(this);
		else
		    if (comType == ASL_DATA_INPUT) // 1	
			((AslSchema*) s)->AslAddExternalInputPort(this);
		    else
			((AslSchema*) s)->AslAddExternalOutputPort(this);
	}

	~AslInputPort(void) {}

	AslInputPort<T>& operator>>(T &msg);	// p ? x: input, now is p >> x
	AslInputPort<T>& operator<<(T &msg);	// used for relabeling	
	void AslCopyData(AslPort *);
	T* AslGetVar(void) { return var; }
};

// Class: AslOutputPort

template<class T>
class AslOutputPort : public AslPort
{
public:
	T *var;
	int AslSearchPortOcurrence(const char *);
	
	AslOutputPort(const char *str, nsl_public *s, T *var_asoc) : AslPort(str, s, ASL_DATA_OUTPUT) 
	{
		var = var_asoc;

		index = AslSearchPortOcurrence(str);
		if (asl_debug)
			aslio << "ASL RTS: Creating Output Port "<<str<<"["<<index<<"]"<<aslend;
		
		AslCom->getPortList().insert(this);

		if (scope==INTERNAL)	
			((AslSchema*) s)->AslAddInternalOutputPort(this);
		else
			((AslSchema*) s)->AslAddExternalOutputPort(this);
	}
	
	~AslOutputPort(void) {}
	
	AslOutputPort<T>& operator<<(T &msg);	// p ! x: output, now is p << x
	AslOutputPort<T>& operator>>(T &msg);	// used for relabeling
	T* AslGetVar(void) { return var; }	
};
*/
// Class: AslInOutPort 

template<class T>
class AslInOutPort : public AslPort
{
public:
//	T *var;
	nsl_layer *var;

//	AslInOutPort(const char *str, nsl_public *s, T *var_asoc, int com_type) : 
	AslInOutPort(const char *str, nsl_public *s, nsl_layer *var_asoc, int com_type) : 
		AslPort(str, s, com_type)
	{
		var = var_asoc;
	}

	~AslInOutPort(void) {}

//	AslInOutPort<T>& operator>>(T &msg);	// p ? x: input, now is p >> x
//	AslInOutPort<T>& operator<<(T &msg);	// P ! x: output, now is p << x	
	AslInOutPort<T>& operator>>(nsl_layer &msg);	// p ? x: input, now is p >> x
	AslInOutPort<T>& operator<<(nsl_layer &msg);	// P ! x: output, now is p << x	
	void AslCopyData(AslPort *);
//	T* AslGetVar(void) { return var; }
	nsl_layer* AslGetVar(void) { return var; }
	void send();
	void receive();
};

/*
// AslInputPort methods

template<class T> AslInputPort<T>& AslInputPort<T>::operator>>(T &msg)
{
//	int res;

//	res = aslComm->AslRecv(bid);

	msg = *var;	// recibo en var, Esto seria FilterBuf
	
	numberOfMessages--;
	
	return(*this);
}
template<class T> AslInputPort<T>& AslInputPort<T>::operator<<(T &msg)
{
	var = &msg;	// Esto seria en el FilterBuf
	
	numberOfMessages++;

	aslComm->AslSend(bid);
	
	numberOfMessages--;

	return(*this);	
}

template<class T> int AslInputPort<T>::AslSearchPortOcurrence(const char *n) 
{
	if (scope==INTERNAL)
		return schema->AslSearchInternalInputPortOcurrence(n);
	else
		return schema->AslSearchExternalInputPortOcurrence(n);
}

// AslOutputPort methods

template<class T> AslOutputPort<T>& AslOutputPort<T>::operator<<(T &msg)
{
	var = &msg;	// Esto seria en el FilterBuf
	
	numberOfMessages++;

	aslComm->AslSend(bid);
	
	numberOfMessages--;

	return(*this);	
}
template<class T> AslOutputPort<T>& AslOutputPort<T>::operator>>(T &msg)
{
//	int res;

//	res = aslComm->AslRecv(bid);

	msg = *var;	// recibo en var, Esto seria FilterBuf
	
	numberOfMessages--;
	
	return(*this);
}
template <class T> int AslOutputPort<T>::AslSearchPortOcurrence(const char *n) 
{
	if (scope==INTERNAL)
		return schema->AslSearchInternalOutputPortOcurrence(n);
	else
		return schema->AslSearchExternalOutputPortOcurrence(n);
		
}

template <class T> void AslInputPort<T>::AslCopyData(AslPort *port)
{
	var = ((AslOutputPort<T>*) port)->AslGetVar();
	numberOfMessages++;

}
*/

// AslInOutPort methods

template<class T> void AslInOutPort<T>::send()
{
	*this << *var;
}

template<class T> void AslInOutPort<T>::receive()
{
	*this >> *var;
}

template<class T> AslInOutPort<T>& AslInOutPort<T>::operator>>(nsl_layer&) // receive
{
//	int res;

//	res = aslComm->AslRecv(bid);

//Se esta copiando directo al puerto de nsl con el send mediante DataCopy
//AW99	msg = *var;	// recibo en var, Esto seria FilterBuf
	
	numberOfMessages--;
	
	send(); // in case they are being relabeled
	
	return(*this);
}
template<class T> AslInOutPort<T>& AslInOutPort<T>::operator<<(nsl_layer &msg) // send
{
	var = &msg;	// Esto seria en el FilterBuf
	
	numberOfMessages++;

	aslComm->AslSend(bid);
	
	numberOfMessages--;

	return(*this);	
}

template <class T> void AslInOutPort<T>::AslCopyData(AslPort *port)
{
	var->copy(((AslInOutPort<T>*) port)->AslGetVar());
//	*var = *((AslInOutPort<T>*) port)->AslGetVar(); // copy or ref
	numberOfMessages++;
//	aslComm->AslSend(bid); //send(); // AW99 added for relabeling purposes
}
				
#endif
