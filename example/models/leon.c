#include "leon.h"

/**
 * Cuando el leon ruge, la zebra lo escucha.
 */

static void _speak(Leon* this)
{
  printf("%s\n", "Mi nombre es");
  printf("%s\n", this->name);
  printf("%s\n", "Roaaaar");

	this->event = SPEAK;
	this->subject->notifyObservers(this->subject);
}

static void _destroy(Leon* this)
{
	this->subject->destroy(this->subject);

  if (NULL != this) {
    free(this);
    this = NULL;
  }
}

static LeonEvent _getEvent(Leon* this)
{
	return this->event;
}

/**
 * Proxy method for Register an observer for the Leon object.
 * @param this
 * @param observer
 * @return
 */
static int _registerObserver(Leon* this, Observer* observer) {
  return this->subject->registerObserver(this->subject, observer);
}

/**
 * Proxy method for Unregister observer for the Leon object.
 * @param this
 * @param observer
 * @return
 */
static int _unregisterObserver(Leon* this, Observer* observer) {
  return this->subject->unregisterObserver(this->subject, observer);
}
Leon* LEON_create(char * name)
{
	Leon* this = (Leon *) malloc(sizeof(*this));
	this->name = name;
	this->destroy = _destroy;
	this->getEvent = _getEvent;
	this->speak = _speak;

	this->subject = subjectNew(this, 1);
	this->registerObserver = _registerObserver;
	this->unregisterObserver = _unregisterObserver;

	return this;
}
