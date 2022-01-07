CC = gcc

BINDIR = bin
INCLUDE = include
LIBDIR = lib
SRCDIR = src

CFLAGS = -Wall 

SRC = $(SRCDIR)/helloworld1.c
OBJ = $(SRCDIR)/calc_magicnumber.o

TARGET = $(BINDIR)/helloworld1

$(TARGET): $(SRC) $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^


.PHONY: tmpclean clean

tmpclean:
	rm -f $(SRCDIR)/*~
clean: tmpclean
	rm -f $(TARGET) $(OBJ) $(SRCDIR)/helloworld1.o