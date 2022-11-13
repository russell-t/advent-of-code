CC=gcc
CFLAGS= -Wall -g
TARGET = run

$(TARGET): src.o intcode.o
	$(CC) $(CFLAGS) -o $(TARGET) src.o intcode.o

src.o: src.c
	$(CC) $(CLFAGS) -c src.c

intcode.o: intcode.c
	$(CC) $(CFLAGS) -c intcode.c

clean:
	$(RM) *.o $(TARGET) *~
