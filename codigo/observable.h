#ifndef OBSERVABLE_H
	#define OBSERVABLE_H
	#include "observer.h"
    #include "common.h"


	typedef struct __observable
	{
		int type;
		void (*destroy)(struct __observable *);
		void * impl;

		Observer * observers[MAX_OBSERVERS];
		int (*registerObserver)(struct __observable*, Observer*);
		int (*unregisterObserver)(struct __observable *, Observer*);
		void (*notifyObservers)(struct __observable*);
        
	} Observable;

	
	Observable * observabletNew(void*, int);

#endif