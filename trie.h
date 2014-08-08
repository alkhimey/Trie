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
 * This file contains the trie data structure and definitions of operations that
 * can be performed with it.
 *
 */

#ifndef __TRIE_H__
#define __TRIE_H__


#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node_t {
   
  struct node_t* next_alt; /// Next alternative
  struct node_t* child;    /// Next letters
  char* str;

  void* data;		   /// The data stored at this node. NULL means this node is not terminal.
} TrieNode;


#ifdef __cplusplus
extern "C"{
#endif 


/**
 * @brief Inserts data into the trie.
 *
 * @param proot Pointer to pointer of the root node. If proot points to NULL, 
 *              this function will allocate it. A common mistake is not to set
 *              set the pointer to the root to NULL before calling this function
 *              the first time.
 * @param str	The key to which the data should be inserted.
 * @param data  Pointer to the data. Only the pointer is stored, data is not copied.	
 */
void trie_insert(TrieNode **proot, char* str, void* data);

/**
 * @brief Retrieves data associated with a key.
 *
 * @param root The root of the trie.
 * @param str  The key.
 * @return Pointer to the stored data. NULL if the key is not in the trie.
 */
void* trie_find(TrieNode* root, char* str);

/**
 * @brief Frees all allocated memory. 
 */
void trie_free(TrieNode* root);

#ifdef __cplusplus
}
#endif

#endif
