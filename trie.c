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
 * This file contains the implementation of operations an a trie data structure.
 *
 */


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
  TrieNode* temp, *temp2;
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
      // Add before
      
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
      
      if(*str && *node_str) {
	// Common prefix
	// Split the node

	temp = trie_make_node(node_str, node->data);
	temp->child = node->child;
	*node_str = '\0'; // TODO: Space could be saved by reallocating to smaller memory
	node->data = NULL;
	if(*str > *node_str) {
	  node->child = temp;
	  temp->next_alt = trie_make_node(str, data);
	} else {
	  temp2 = trie_make_node(str, data);
	  node->child = temp2;
	  temp2->next_alt = temp;
	}

	return;

      } else if (!*str && *node_str) {
	// Our string is a prefix of the node's string.
	// Split the node.
	
	temp = trie_make_node(node_str, node->data);
	*node_str = '\0'; // TODO: Space could be saved by reallocating to smaller memory
	node->data = data;
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


/**
 * @details Notice that this implementation is recursive. 
 *          Frees only memory allocated by trie_insert calls. The stored data will not be freed.
 */
void trie_free(TrieNode* root) {
  if (root == NULL)
    return;

  trie_free(root->next_alt);
  trie_free(root->child);
  free(root->str);
  free(root);
}
