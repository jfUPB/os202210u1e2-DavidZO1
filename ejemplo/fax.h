
#ifndef IMPRESORA_H
#define IMPRESORA_H
#include <stdio.h>
#include <stdlib.h>
#include "../codigo/observer.h"
#include "computador.h"

typedef struct __fax
{
    char *name;
    void (*destroy)(struct __fax *);
    Observer *observer;
} Fax;

Fax *Fax_create(char *);
#endif