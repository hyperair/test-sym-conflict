#include "lib.h"
#include <stdio.h>

__attribute__((constructor))
void library_loaded ()
{
    printf ("libfoo loaded\n");
}

__attribute__((destructor))
void library_unloaded ()
{
    printf ("libfoo unloaded\n");
}

void do_lib_helloworld ()
{
    printf ("hello from libfoo\n");
}
