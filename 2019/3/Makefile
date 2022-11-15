CC=gcc
CFLAGS= -Wall -g
TARGET = calculate

$(TARGET): *.o
	$(CC) $(CFLAGS) -o $(TARGET) *.o

*.o: *.c
	$(CC) $(CFLAGS) -c *.c

clean:
	$(RM) *.o $(TARGET) *~
