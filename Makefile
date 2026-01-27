CC = gcc
CFLAGS = -Wall
TARGET = noter.elf
OBJS = main.o logic.o

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

main.o: main.c logic.h
	$(CC) $(CFLAGS) -c main.c

logic.o: logic.c logic.h
	$(CC) $(CFLAGS) -c logic.c

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: clean
