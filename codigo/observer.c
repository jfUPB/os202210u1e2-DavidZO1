#include "common.h"
#include "observer.h"

/**
 * Destructor para el observer.
 * Limpiar memoria
 * @param this
 */
static void _destroy(Observer* this) {
	if (NULL != this) {
		free(this);
		this = NULL;
	}
}

/**
 * Notifica el observador
 * @param this
 * @return OK or KO
 */
static void _notify(Observer* this, int type, void * observable) {
	this->notifyImpl(this->impl, type, observable);
}

/**
 * Constructor
 * @return Instancia del observer
 */
Observer * observer_new(void* impl, void (*notifyImpl)(void*, int, void*)) {
	Observer * this;
	this = (Observer *) calloc(1, sizeof(*this));
	this->destroy = _destroy;
	this->notify = _notify;
	this->impl = impl;
	this->notifyImpl = (void (*)(void*, int, void*)) notifyImpl;
	return this;
}