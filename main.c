/**
 * @author  Artium Nihamkin <artium@nihamkin.com>
 * @date August 2014 
 *
 * @section LICENSE
 *
 * The MIT License (MIT)
 * Copyright © 2014 Artium Nihamkin, http://nihamkin.com
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the “Software”), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 * @section DESCRIPTION
 * 
 * This file contains a simple program that demonstrates the usage of the trie library.
 *
 */


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
