#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node_t {
   
  struct node_t* next_alt; // Next alternative
  struct node_t* child;    // Next letters
  char* str;

  void* data;
} TrieNode;


void trie_insert(TrieNode **proot, char* str, void* data);

void* trie_find(TrieNode* root, char* str);

void trie_free(TrieNode* root);


