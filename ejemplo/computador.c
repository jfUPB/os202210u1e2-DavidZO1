#include "computador.h"

static int _registerObserver(Computador *this, Observer *observer)
{
	return this->observ->registerObserver(this->observ, observer);
}

static int _unregisterObserver(Computador *this, Observer *observer)
{
	return this->observ->unregisterObserver(this->observ, observer);
}

static void _imprimir(Computador *this, Fax *fax)
{
	this->registerObserver(this, fax->observer);
	printf("Fax en %s\n", fax->name);
}

static void _destroy(Computador *this)
{
	this->observ->destroy(this->observ);

	if (NULL != this)
	{
		free(this);
		this = NULL;
	}
}

static CompEvent _getEvent(Computador *this)
{
	return this->event;
}

Computador *Comp_Creado(char *name)
{
	Computador *this = (Computador *)malloc(sizeof(*this));
	this->name = name;
	this->destroy = _destroy;
	this->getEvent = _getEvent;
	this->imprimir = _imprimir;

	this->observ = subjectNew(this, 1);
	this->registerObserver = _registerObserver;
	this->unregisterObserver = _unregisterObserver;

	return this;
}