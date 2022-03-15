#include <stdio.h>
#include "../ejemplo/computador.h"
#include "../ejemplo/fax.h"
#include "../codigo/observable.h"
#include "../codigo/observer.h"

int main(int argc, char **argv)
{

    Fax *Fax = Fax_create("Fax");
    Computador *Comput = Com_create("Com");

    Comput->imprimir(Comput, Fax);
   
    Fax->destroy(Fax);
    Comput->destroy(Comput);
}