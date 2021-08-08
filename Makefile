DEPS=get_next_line.h
CC=gcc
CFLAGS=-Wall -Werror -Wextra -D BUFFER_SIZE=5
OBJS=get_next_line.o get_next_line_utils.o main.o
PROGS=main

%.o: %.c $(DEPS) 
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJS) $(DEPS)
	$(CC) -o main $(OBJS) $(CFLAGS)

clean:
	rm $(OBJS)

fclean:
	rm $(OBJS) $(PROGS)

all: $(PROGS)

re: fclean all

.PHONY: clean

