all: jupiter

jupiter: main.c
	gcc -g -O0 -o $@ main.c

clean:
	-rm jupiter

check: all
	./jupiter | grep "Hello from .*jupiter!"
	@echo "*** ALL TESTS PASSED ***"

install:
	install -d $(prefix)/bin
	install -m 0750 jupiter $(prefix)/bin

uninstall:
	-rm $(prefix)/bin/jupiter

.PHONY: all clean check install uninstall
