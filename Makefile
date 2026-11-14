CC = gcc
CFLAGS = -Wall -Wextra -g
OBJS = main.o board.o game.o

dotsandboxes: $(OBJS)
	$(CC) $(CFLAGS) -o dotsandboxes $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o dotsandboxes
