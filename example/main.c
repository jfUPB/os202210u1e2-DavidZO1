/**
 * Main program that uses the Observer implementation.
 */

#include <stdio.h>
#include "models/leon.h"
#include "models/zebra.h"

/**
 * Defining the basic DOG class/interface-a-like
 */

int main(int argc, char const *argv[])
{

	Leon* hopkins = LEON_create("Hopkins");
	Zebra* alfred = ZEBRA_create("Alfred");

	alfred->smell(alfred, hopkins);
	hopkins->speak(hopkins);

	hopkins->destroy(hopkins);
	alfred->destroy(alfred);

	return 0;
}
