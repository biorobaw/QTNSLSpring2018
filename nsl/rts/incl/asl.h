// asl.h

//#pragma interface

#ifndef __ASL_H
#define __ASL_H

// Constants

const int ASL_NAME_LEN = 80;

const int EXTERNAL = 1;
const int INTERNAL = 2;

const int NORMAL  = 1;
const int POINTER = 2;
const int VECTOR  = 3;
const int MATRIX  = 4;

const int MAKECONN    = 0;
const int INITRUN     = 1;
const int SIMRUN      = 2;
const int MAKEDISCONN = 3;
const int END         = 4;

const int ASL_SIGNAL = 0;
const int ASL_THREAD = 1;

const int ASL_MAXENV = 256;

const int ASL_DATA_INPUT     = 1;	//antes tenia un 0
const int ASL_DATA_OUTPUT    = 2;	//antes un 1
const int ASL_CONTROL_INPUT  = 3;
const int ASL_CONTROL_OUTPUT = 4;
const int ASL_NEW_CONTAINER  = 5;
const int ASL_RELABEL_BUFFER = 6;

extern int asl_debug;

class AslSystem;

class AslSchema;
class AslSchemaInterface;
template<class T>  class AslSchemaModel;
//typedef AslSchemaModel<nsl_model> NslApplicationModel;

class AslFunction;
class AslPort;

template<class T> class AslList;
typedef AslList<AslSchema> AslListSchema;

typedef AslSchema NslModule;
typedef AslSchema NslModel;

class AslErr;
class AslInOut;
class AslTerminator;
class AslIPCManager;

extern AslErr        aslerr;
extern AslInOut      aslio;
extern AslTerminator aslend;
extern AslIPCManager *AslCom;
extern AslSystem *asl;

//extern struct aslArgument;

extern int NslLoad(char*);

#endif
