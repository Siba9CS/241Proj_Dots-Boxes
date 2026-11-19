CC = gcc
CFLAGS = -Wall -Wextra -g

TARGET = dotsandboxes
OBJS = main.o board.o game.o

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c board.h game.h
	$(CC) $(CFLAGS) -c $<

valgrind: $(TARGET)
	valgrind --leak-check=full ./$(TARGET)

clean:
	rm -f *.o $(TARGET)

.PHONY: clean valgrind
