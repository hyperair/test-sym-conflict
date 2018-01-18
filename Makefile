CC ?= gcc
CFLAGS ?= -g -O0

ALL = libfoo.so libbar.so libintermediaryfoo.so libintermediarybar.so main

all: $(ALL)

libfoo.so: libfoo.c
	$(CC) $(CFLAGS) -o $@ -shared -fPIC $<

libbar.so: libbar.c
	$(CC) $(CFLAGS) -o $@ -shared -fPIC $<

libintermediaryfoo.so: intermediary.c libfoo.so
	$(CC) $(CFLAGS) -o $@ -shared -fPIC $< -lfoo -L$(PWD)

libintermediarybar.so: intermediary.c libbar.so
	$(CC) $(CFLAGS) -o $@ -shared -fPIC $< -lbar -L$(PWD)

main: main.c
	$(CC) $(CFLAGS) -o $@ $< -ldl

clean:
	-rm $(ALL)

run: $(ALL)
	LD_LIBRARY_PATH=$(PWD) ./main
