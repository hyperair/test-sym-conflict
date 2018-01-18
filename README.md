# Library Symbol Collision Experiment

This is a short experiment to test whether overlapping symbols in transitive
dependencies of loaded libraries conflict.


## Usage

To run this test, simply run the following command

    $ make -j4 run

## Conclusion

The output of the command above is as follows:

    LD_LIBRARY_PATH=/home/hyperair/src/test-sym-conflict ./main
    libfoo loaded
    hello from libfoo
    libbar loaded
    hello from libbar
    libfoo unloaded
    libbar unloaded

As can be seen, the `do_lib_helloworld` methods from both `libfoo` and `libbar`
were called individually and did not override each other. I think this means
that individual plugin libraries linking against different webkit versions ought
to work without issue.
