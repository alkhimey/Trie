#include <stdio.h>
#include "trie.h"

#define MAX_LEN 200

void print(TrieNode* root, int lvl) {
  int i;
  
  if(root == NULL)
    return;

  for(i = 0; i < lvl; i++)
    printf("\t");
  if(root->data != NULL) {
    printf("%s*\n", root->str);
  } else {
    printf("%s\n", root->str);
  }
  
  print(root->child, lvl+1);
  print(root->next_alt, lvl);
}


int main(void) {
  char str[MAX_LEN];
  
  TrieNode* root = NULL;

  char *pos;


  while(1) {
    printf("Enter string to store: ");
    
    fgets(str, MAX_LEN, stdin);
    
    if ((pos=strchr(str, '\n')) != NULL)
      *pos = '\0';

    if(pos == str)
      break;
    
    trie_insert(&root, str, (void*)1);
  }
  
  printf("Printing the trie...\n");
  print(root, 0);
  
  while(1) {
    printf("Enter string to search: ");
   
    fgets(str, MAX_LEN, stdin);
    
    if ((pos=strchr(str, '\n')) != NULL)
      *pos = '\0';
    
    if(pos == str)
      break;
    
    if (trie_find(root, str))
      printf("Found\n");
    else
      printf("Not found\n");
  } 
      
}
