#ifndef COMPUTADOR_H
#define COMPUTADOR_H
#include <stdio.h>
#include <stdlib.h>
#include "../codigo/observable.h"
#include "fax.h"

typedef enum __computador_event
{
    IMPRESION
} CompEvent;

typedef struct __computador
{
    char *name;
    void (*destroy)(struct __computador *);
    CompEvent event;
    CompEvent (*getEvent)(struct __computador *);
    void (*imprimir)(struct __computador *, Fax*);
    Observable *observ;
    int (*registerObserver)(struct __computador *, Observer *);
    int (*unregisterObserver)(struct __computador *, Observer *);
} Computador;

Computador *Com_create(char *);

#endif
