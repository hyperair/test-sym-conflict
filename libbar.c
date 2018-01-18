#include "lib.h"
#include <stdio.h>

__attribute__((constructor))
void library_loaded ()
{
    printf ("libbar loaded\n");
}

__attribute__((destructor))
void library_unloaded ()
{
    printf ("libbar unloaded\n");
}

void do_lib_helloworld ()
{
    printf ("hello from libbar\n");
}
