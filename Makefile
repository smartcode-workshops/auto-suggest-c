CC = gcc
CFLAGS = -Wall -Wextra -std=c99

SRCS = trie_node.c trie.c main.c
TEST_SRCS = test_trie.c
OBJS = $(SRCS:.c=.o)
TEST_OBJS = trie_node.o trie.o test_trie.o
TARGET = auto_suggest
TEST_TARGET = test_trie

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(TEST_TARGET): $(TEST_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET) $(TEST_OBJS) $(TEST_TARGET)

test: $(TEST_TARGET)
	./$(TEST_TARGET)

.PHONY: all clean test
