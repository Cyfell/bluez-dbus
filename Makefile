CC=gcc
CFLAGS=-W -Wall -ansi -pedantic -I/usr/include/glib-2.0/ -I/usr/lib64/glib-2.0/include/ -std=c11 -rdynamic
LDFLAGS= -lglib-2.0 -lgio-2.0
EXEC=bluez-dbus
SRC= $(wildcard *.c)
OBJ= $(SRC:.c=.o)

all: $(EXEC)

bluez-dbus: $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

bluez-dbus.o:

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)
