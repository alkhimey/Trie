CC=gcc
CPP=g++
CFLAGS=-Wall
TESTS_DIR=Testing

all:	trie.o main.c tests
	$(CC) trie.o main.c -o program.out

tests: $(TESTS_DIR)/testing.cpp trie.o 
	$(CPP) trie.o $(TESTS_DIR)/testing.cpp -o run_test.out

trie.o:	trie.c trie.h
	$(CC) -c trie.c -o trie.o -g


clean:
	rm -f *.out *.o $(TESTS_DIR)/*.out $(TESTS_DIR)/*.o
