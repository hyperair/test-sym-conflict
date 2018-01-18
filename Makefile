all: libfoo.so libbar.so libintermediaryfoo.so libintermediarybar.so main

libfoo.so: libfoo.c
	gcc -o $@ -shared -fPIC $<

libbar.so: libbar.c
	gcc -o $@ -shared -fPIC $<

libintermediaryfoo.so: intermediary.c libfoo.so
	gcc -o $@ -shared -fPIC $< -lfoo -L$(PWD)

libintermediarybar.so: intermediary.c libbar.so
	gcc -o $@ -shared -fPIC $< -lbar -L$(PWD)

main: main.c
	gcc -o $@ $< -ldl

clean:
	-rm main libintermediaryfoo.so libintermediarybar.so libbar.so libfoo.so
