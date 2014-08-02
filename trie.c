#include "trie.h"
#include <string.h>

TrieNode* trie_make_node(char* str, void* data) {
  TrieNode* node = (TrieNode *)malloc(sizeof(TrieNode));

  node->data = data;
  node->next_alt = NULL;
  node->child = NULL;

  node->str = (char *)malloc(sizeof(char) * (strlen(str) + 1));
  strcpy(node->str, str);

  return node;
}

void trie_insert(TrieNode **proot, char* str, void* data) {
  char* node_str;
  TrieNode* temp;
  TrieNode* node = *proot;
  TrieNode* prev = NULL;
  TrieNode* parent = NULL;
  
  if (*proot == NULL) {
    // Create the root

    *proot = trie_make_node(str, data);
    return;
  } else if (*str < *((*proot)->str)) {
    // Add before root

    temp = trie_make_node(str, data);
    temp->next_alt = *proot;
    *proot = temp;
    return;

  }

  while(node != NULL) {
    node_str = node->str;

    if(*str > *node_str) {
      
      prev = node;
      node = node->next_alt;

    } else if(*str < *node_str) {
      // Add before.
      
      temp = trie_make_node(str, data);
     
      if (prev == NULL) {	
	temp->next_alt = node;
	parent->child = temp;
      } else {
	
	temp->next_alt = node;
	prev->next_alt = temp;
      }

      return;

    } else {
      
      
      for(; *str && *node_str; str++, node_str++) {
	if (*str != *node_str)
	  break;
      }
      
      if (!*str && *node_str) {
	// Our string is a prefix of the node's string.
	// Split the node.
	
	temp = trie_make_node(node_str, node->data);
	*node_str = '\0'; // TODO: Do we need to reallocate?
	temp->child = node->child;
	node->child = temp;
	return;
      
      } else if (*str && !*node_str) {
	// Node's string is a prefix of our string.
	// Continue to it's child
	
	if (node->child == NULL) {

	  node->child = trie_make_node(str, data);
	  return;

	} else {

	  parent = node;
	  node = node->child;
	  prev = NULL;

	}

      } else if (!(*str || *node_str)) {
	// Strings match (the key already exists)
	// Replace the data.

	node->data = data;
	return;
      }
    }
  }

  // Add as last alternative
  prev->next_alt = trie_make_node(str, data);
  
  
}

void* trie_find(TrieNode* root, char* str) {
  TrieNode* node = root;
  char* node_str;
  
  while(node != NULL) {
    node_str = node->str;
    if(*str != *node_str) {
      
      node = node->next_alt;
      
    } else {
      
      for(; *str && *node_str; str++, node_str++) {
	if (*str != *node_str)
	  break;
      }
      
      if (!(*str || *node_str))	return node->data;
      if (!*str) 		return NULL; // node_str is substring of str
      
      node = node->child;
    }
  }
  
  return NULL;
}


void trie_free(TrieNode* root) {
  
}
