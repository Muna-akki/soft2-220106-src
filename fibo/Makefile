CC = gcc

BINDIR = bin
INCLUDE = include
LIBDIR = lib
SRCDIR = src

CFLAGS = -Wall -I$(INCLUDE) 


SRC = $(SRCDIR)/fibo.c
OBJ = $(SRCDIR)/func.o

TARGET = $(BINDIR)/fibo

$(TARGET): $(SRC) $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^


.PHONY: tmpclean clean

tmpclean:
	rm -f $(SRCDIR)/*~
clean: tmpclean
	rm -f $(TARGET) $(OBJ)