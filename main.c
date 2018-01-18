#define _GNU_SOURCE
#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>

static void callhello (const char *filename)
{
    void *handle = dlopen (filename, RTLD_NOW | RTLD_LOCAL);

    if (!handle) {
        fprintf (stderr, "%s\n", dlerror ());
        exit (EXIT_FAILURE);
    }

    typedef void (*helloworld_func) ();
    helloworld_func hi = dlsym (handle, "helloworld");

    if (!hi) {
        fprintf (stderr, "%s\n", dlerror ());
        exit (EXIT_FAILURE);
    }

    hi ();

    /* dlclose (handle); */
}

int main ()
{
    callhello ("libintermediaryfoo.so");
    callhello ("libintermediarybar.so");

    return 0;
}
