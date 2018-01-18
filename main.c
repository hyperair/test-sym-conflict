#define _GNU_SOURCE
#include <dlfcn.h>

static void callhello (const char *filename)
{
    void *handle = dlopen (filename, RTLD_LOCAL);

    typedef void (*helloworld_func) ();
    helloworld_func hi = dlsym (handle, "helloworld");
    hi ();

    dlclose (handle);
}

int main ()
{
    callhello ("libintermediaryfoo.so");
    callhello ("libintermediarybar.so");

    return 0;
}
