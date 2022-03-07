#ifndef LEON_H
  #define LEON_H
  #include <stdio.h>
  #include <stdlib.h>
  #include "../../observer/observer.h"
  #include "../../observer/subject.h"

  typedef enum __leon_event
  {
    SPEAK
  } LeonEvent;

  typedef struct __leon
  {
    char* name;
    void (*destroy)(struct __leon*);

    LeonEvent event;
    LeonEvent (*getEvent)(struct __leon*);

    void (*speak)(struct __leon*);

    Subject * subject;
    int (*registerObserver)(struct __leon*, Observer*);
    int (*unregisterObserver)(struct __leon *, Observer*);
  } Leon;

 
  Leon* LEON_create(char *);

#endif
