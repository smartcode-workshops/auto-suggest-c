CC = gcc
CFLAGS = -Wall -Wextra -std=c99

SRCS = trie_node.c trie.c main.c
OBJS = $(SRCS:.c=.o)
TARGET = auto_suggest

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

test: $(TARGET)
	./$(TARGET)

.PHONY: all clean test
