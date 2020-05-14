
//  ASL INPUT/OUTPUT LIBRARY 
//
//  ASL (Abstract Schema Language) Input/Output Library
//
//
//
//  FILE NAME   : aslio.c
//  MODULE TYPE : ASL Input/Output Library
//  STATUS      : Ready for use
//  PURPOSE     : Reliable Input/Output Library
//  
//
//  Instituto Tecnologico Autonomo de Mexico 
//  (c) Copyrigth 1995  
//
//
//
//  HISTORY : Version (Date-Name) Modification, description. 
//
//            1.0 (Agu 15, 1995 - Claudia Calderas & Salvador Marmol), 
//            Start of development for distributed execution.
//
//            1.2 (Jan 5, 1998 - Claudia Calderas & Salvador Marmol), 
//            Start of development for distributed execution.

 
#include "asl_all_rts_include.h"

AslReliableIO::AslReliableIO(void)  
{ 
	first = 1;
}

AslReliableIO::~AslReliableIO(void) 
{ 
}

void AslReliableIO::start(void) 
{ 
}

void AslReliableIO::stop(void)  
{ 
}


// AslErr Methods

void AslErr::printHeader(void)
{
}

AslErr& AslErr::operator << (const char *msg)   
{ 
	if (first && asl_debug)
	{
		printHeader();
		first = 0;
	}

	sprintf(buf,"%c",msg);
//	write(2, msg, strlen(msg));
	
	return *this; 
}

AslErr& AslErr::operator << (char *msg)   
{ 
	if (first && asl_debug)
	{
		printHeader();
		first = 0;
	}

	sprintf(buf,"%c",msg);
//	write(2, msg, strlen(msg));
	
	return *this; 
}

AslErr& AslErr::operator << (AslTerminator &dummy)   
{ 
	first = 1;

//	write(2, "\n", 1);
	
	return *this; 
}

AslErr& AslErr::operator << (char msg) 
{ 
	sprintf(buf,"%c",msg);
//	write(2, buf, strlen(buf)); 

	return *this; 
}

AslErr& AslErr::operator << (int  msg)  
{ 
	sprintf(buf,"%d",msg);
//	write(2, buf, strlen(buf));

	return *this; 
}

AslErr& AslErr::operator << (long int  msg)  
{ 
	sprintf(buf,"%ld",msg);
//	write(2, buf, strlen(buf)); 

	return *this; 
}

AslErr& AslErr::operator << (unsigned long int  msg)  
{ 
	sprintf(buf,"%ld",msg);
//	write(2, buf, strlen(buf)); 

	return *this; 
}

AslErr& AslErr::operator << (unsigned int  msg)  
{ 
	sprintf(buf,"%d",msg);
//	write(2, buf, strlen(buf)); 

	return *this; 
}

AslErr& AslErr::operator << (float msg)
{ 
	sprintf(buf,"%g",msg);
//	write(2, buf, strlen(buf)); 

	return *this; 
}

AslInOut& AslInOut::operator >> (char *msg)  
{ 
	gets(buf);
	strcpy(msg, buf); 

	return *this; 
}

AslInOut& AslInOut::operator >> (char &msg) 
{
	gets(buf);
	msg=buf[0];

	return *this; 
}

AslInOut& AslInOut::operator >> (int  &msg)  
{ 
	gets(buf); 
	msg=atoi(buf);    

	return *this; 
}

AslInOut& AslInOut::operator >> (unsigned int  &msg)  
{ 
	gets(buf); 
	msg=atoi(buf);    

	return *this; 
}

AslInOut& AslInOut::operator >> (long int  &msg)  
{ 
	gets(buf);
	msg=atol(buf); 

	return *this; 
}

AslInOut& AslInOut::operator >> (unsigned long int  &msg)   
{ 
	gets(buf);
	msg=atol(buf); 

	return *this; 
}

AslInOut& AslInOut::operator >> (float &msg) 
{ 
	gets(buf); 
	msg=atof(buf);    

	return *this; 
}

void AslInOut::printHeader(void)
{
//	threadID = AslThreadManager::AslGetThreadID();
//	printf("%s:%d:",hostName,threadID);
}

AslInOut& AslInOut::operator << (const char *msg)   
{ 
	if (first && asl_debug)
	{
		printHeader();
		first = 0;
	}
		
	printf("%s",msg); 

	return *this; 
}

AslInOut& AslInOut::operator << (char *msg)   
{ 
	if (first && asl_debug)
	{
		printHeader();
		first = 0;
	}
		
	printf("%s",msg); 

	return *this; 
}

AslInOut& AslInOut::operator << (AslTerminator &dummy)
{
	first = 1;

	printf("\n");

	fflush(stdout);

	return *this;
}

AslInOut& AslInOut::operator << (char msg)   
{ 
	printf("%c",msg); 

	return *this; 
}

AslInOut& AslInOut::operator << (int  msg)   
{ 
	printf("%d",msg); 

	return *this; 
}

AslInOut& AslInOut::operator << (unsigned int  msg)
{ 
	printf("%d",msg); 

	return *this; 
}

AslInOut& AslInOut::operator << (long int  msg)   
{ 
	printf("%ld",msg); 

	return *this; 
}

AslInOut& AslInOut::operator << (unsigned long int  msg)   
{ 
	printf("%ld",msg); 

	return *this; 
}

AslInOut& AslInOut::operator << (float msg)  
{ 
	printf("%g",msg); 

	return *this; 
}
