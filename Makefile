CC ?= cc

INC = -Iinc -Iansilib/inc
LIB =

CFLAGS = $(INC) -Wall -Wextra -pedantic -g -std=c99
CPPFLAGS =
LDFLAGS =

SRCS = src/io.c \
       src/main.c \
       ansilib/src/ansi/cursor.c \
       ansilib/src/ansi/screen.c \
       ansilib/src/graphics/common.c \
       ansilib/src/graphics/box.c \
       ansilib/src/graphics/shapes.c


OBJS = obj/io.o \
       obj/main.o \
       obj/ansi/cursor.o \
       obj/ansi/screen.o \
       obj/graphics/common.o \
       obj/graphics/box.o \
       obj/graphics/shapes.o

.PHONY: all clean

all: bin/anim

bin/anim: $(OBJS)
	@mkdir -p bin
	$(CC) $(LDFLAGS) -o $@ $^

obj/graphics/%.o: ansilib/src/graphics/%.c
	@mkdir -p obj/graphics
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

obj/ansi/%.o: ansilib/src/ansi/%.c
	@mkdir -p obj/ansi
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

obj/%.o: src/%.c
	@mkdir -p obj
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

clean:
	rm -rf obj bin
