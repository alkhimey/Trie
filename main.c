#include <stdio.h>
#include "trie.h"

#define MAX_LEN 200

/*void print(TrieNode* root, int lvl) {
  printf("Level: %d Node is terminal: %d\n", lvl, root->isTerminal); 
  int i;
  for(i = 0; i < ALPHABET_SIZE; i++)
    if (root->next[i] != NULL) {
      print(root->next[i], lvl+1);	
    }
    }*/


int main(void) {
  char str[MAX_LEN];
  
  TrieNode* root = NULL;

  char *pos;


  do {
    fgets(str, MAX_LEN, stdin);

    if ((pos=strchr(str, '\n')) != NULL)
      *pos = '\0';

    trie_insert(&root, str, (void*)1);
  } while (strcmp(str, "last") != 0);

  //  printf("Printing root...\n");
  //print(root, 0);
  
  printf("Enter string to search: ");
  do {
    scanf("%s", str);
    if (trie_find(root, str))
      printf("Found\n");
    else
      printf("Not found\n");
  } while (strcmp(str, "last") != 0);

}
