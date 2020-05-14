
//  ASL LIST LIBRARY 
//
//  ASL (Abstract Schema Language) List Library
//
//
//
//  FILE NAME   : asllist.h
//  MODULE TYPE : ASL List Library
//  STATUS      : Ready for use 
//  PURPOSE     : General List Library
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

//#pragma interface

#ifndef __ASL_LIST
#define __ASL_LIST 1

#include <stdio.h>

template <class T>
class AslNode
{
public:
	T       *ptrObject;
	AslNode *ptrNext;
	int      delList;
public:
	AslNode(void);
	~AslNode(void);
};

template <class T>
class AslList
{
	AslNode<T>  *ptrRoot;
	AslNode<T>  *ptrBottom;
	AslNode<T>  *ptrThis;
	
	int   count;
public:
	void  insert(T *);
	T*    removeThis(void);

	void  goNext(void);
	void  startOnTop(void);
	void  startOnBottom(void);
	T*    replaceActual(T*);
	T*    getActual(void);

	int   numberOfElements(void);
	int   isEmpty(void);

	AslList(void);
	~AslList(void);
};

template <class T> AslNode<T>::AslNode(void)
{
	ptrObject=NULL;
	ptrNext=NULL;

	delList=0;
}

template <class T> AslNode<T>::~AslNode(void)
{
	if (delList!=0)
	{
		if (ptrNext!=NULL)
		{
			ptrNext->delList = 1;
			delete ptrNext;
		}	
	}
}

template <class T> AslList<T>::AslList(void)
{
	ptrRoot=NULL;
	ptrBottom=NULL;
	ptrThis=NULL;

	count=0;
}

template <class T> AslList<T>::~AslList(void)
{
	if (ptrRoot!=NULL)
	{
		ptrRoot->delList = 1;
		delete ptrRoot;
	}
}

template <class T> int AslList<T>::numberOfElements(void)
{
	return count;
}

template <class T> void AslList<T>::goNext(void)
{
	if (ptrThis!=NULL) 
		ptrThis=ptrThis->ptrNext;
}

template <class T> int AslList<T>::isEmpty(void)
{
	if (count==0)
		return 1;
	else
		return 0;
}

template <class T> void AslList<T>::startOnTop(void)
{
	ptrThis=ptrRoot;
}

template <class T> void AslList<T>::startOnBottom(void)
{
	ptrThis=ptrBottom;
}

template <class T> T* AslList<T>::replaceActual(T *p)
{
	if (ptrThis==NULL)
		return NULL;
		
	T *temp = ptrThis->ptrObject;
	ptrThis->ptrObject = p;
	return temp;
}

template <class T> T* AslList<T>::getActual(void)
{
	if (ptrThis==NULL)
		return NULL;
	else
//		aslio<<"-----EN LA FUNCION GETACTUAL--- \n";
		return ptrThis->ptrObject;
}

template <class T> void AslList<T>::insert(T *data)
{
	AslNode<T> *aux;

	aux = new AslNode<T>;

	if (aux == NULL)
		return;

	if (ptrBottom==NULL)
		ptrRoot = aux;
	else
		ptrBottom->ptrNext=aux;
 
	ptrBottom = aux;
	aux->ptrNext=NULL;
	aux->ptrObject=data;
	ptrThis=aux;

	count++;
}

template <class T> T* AslList<T>::removeThis(void)
{
	T *data;
	AslNode<T> *aux;

	if (ptrThis!=NULL)
	{
		data = getActual();

		if (ptrRoot==ptrBottom)
		{
			ptrRoot=NULL;
			ptrBottom=NULL;
		}
		else
		{
			if (ptrBottom==ptrThis)
			{
				aux=ptrRoot;
				while (aux->ptrNext!=ptrBottom) aux=aux->ptrNext;
				ptrBottom=aux;
				ptrBottom->ptrNext=NULL;
			}
			else 
				if (ptrRoot==ptrThis)
					ptrRoot=ptrThis->ptrNext;
				else
				{
					aux=ptrRoot;
					while (aux->ptrNext!=ptrThis) aux=aux->ptrNext;			
					aux->ptrNext=ptrThis->ptrNext;
				}
		}

		delete ptrThis;

		count--;

		return data;
	}
	else
		return NULL;
}

#endif
