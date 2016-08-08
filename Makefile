CC=gcc
CFLAGS=-Wall -c
LDFLAGS=-Wall
SRCS=main.c sha1.c
OBJS=$(SRCS:.c=.o)
TARGET=sha1

all: $(TARGET)
.PHONY: all clean

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o $(TARGET)
