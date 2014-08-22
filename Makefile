CC=gcc
CPP=g++
CFLAGS=-Wall -g
TESTS_DIR=Testing

all:	demo tests

demo:	trie.o main.c
	$(CC) trie.o main.c -o demo.out $(CFLAGS)	

tests: $(TESTS_DIR)/testing.cpp trie.o 
	$(CPP) trie.o $(TESTS_DIR)/testing.cpp -o run_test.out $(CFLAGS)

trie.o:	trie.c trie.h
	$(CC) -c trie.c -o trie.o $(CFLAGS)

clean:
	rm -f trie.o run_test.out demo.out
