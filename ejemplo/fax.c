#include "fax.h"
#include "computador.h"

static void _destroy(Fax* this)
{
	this->observer->destroy(this->observer);

	if (this != NULL){
		free(this);
		this = NULL;
	}
}
static void _notify(Fax*this, int numero, void* subject) {
	_handleEvent(this, (Computador*) subject);
}

Fax* Impr_create(char* name)
{
	Fax*this = (Fax*) malloc(sizeof(*this));

	this->name = name;
	this->destroy = _destroy;
	this->observer = observerNew(this, (void (*)(void*, int, void*))_notify);

	return this;
}