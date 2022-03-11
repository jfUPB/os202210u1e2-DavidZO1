#ifndef ZEBRA_H
	#define ZEBRA_H
 	#include <stdio.h>
	#include <stdlib.h>
	#include "../../observer/observer.h"
	#include "leon.h"

	typedef struct __zebra
	{
		char* name;
		void (*speak)(struct __zebra*);
		void (*destroy)(struct __zebra*);
		void (*smell)(struct __zebra*, Leon*);

		Observer* observer;
	} Zebra;

	Zebra* Zebra_create(char *);

#endif
