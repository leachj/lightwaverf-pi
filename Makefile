CFLAGS := -fPIC -O3 -g -Wall -Werror
CC := gcc
MAJOR := 0
MINOR := 1
NAME := lightwaverf
VERSION := $(MAJOR).$(MINOR)
PREFIX := /usr/local

all: lib samples

lib: lib$(NAME).so.$(VERSION)
 
samples: send receive
 
send: lib$(NAME).so
	$(CC) send.c -o $@ -L. -l$(NAME) -lwiringPi
 
receive: lib$(NAME).so
	$(CC) receive.c -o $@ -L. -l$(NAME) -lwiringPi

lib$(NAME).so: lib$(NAME).so.$(VERSION)
	ldconfig -v -n .
 
lib$(NAME).so.$(VERSION): $(NAME).o
	$(CC) -shared -Wl,-soname,lib$(NAME).so.$(MAJOR) $^ -o $@
 
clean:
	$(RM) send receive *.o *.so*

install: lib$(NAME).so
	install -m 0644 lib$(NAME).so.$(VERSION) $(PREFIX)/lib
	ldconfig -n $(PREFIX)/lib
	ln -f -s $(PREFIX)/lib/lib$(NAME).so.$(MAJOR) $(PREFIX)/lib/lib$(NAME).so
	install -m 0644 *.h $(PREFIX)/include
    
.PHONY: install
