all:	trie.o main.c
	gcc trie.o main.c -o program.out -g


trie.o:	trie.c trie.h
	gcc -c trie.c -o trie.o -g
