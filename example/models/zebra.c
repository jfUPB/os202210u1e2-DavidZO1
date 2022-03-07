/**
 * cuando un leon ruge la zebra lo escucha
 */

#include "zebra.h"

static void _destroy(Zebra* this)
{
	this->observer->destroy(this->observer);

	if (this != NULL){
		free(this);
		this = NULL;
	}
}

static void _smell(Zebra * this, Leon* leon)
{
	leon->registerObserver(leon, this->observer);
	printf("%s Acabo de oler a %s\n", this->name, leon->name);
}

static void _handleCatEvent(Zebra* this, Leon* leon)
{
	printf("%s\n Escuche a %s", this->name, leon->name);
}


/**
 * Observer Method called upon the receiption of an incoming event.
 * @param type
 * @param subject
 */
static void _notify(Zebra* this, int numero, void* subject) {
	_handleCatEvent(this, (Leon*) subject);
}

Zebra* ZEBRA_create(char* zebrasName)
{
	Zebra* this = (Zebra*) malloc(sizeof(*this));

	this->name = zebrasName;
	this->smell = _smell;
	this->destroy = _destroy;
	this->observer = observerNew(this, (void (*)(void*, int, void*))_notify);

	return this;
}

