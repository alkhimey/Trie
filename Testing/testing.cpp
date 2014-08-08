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
 * This file contains unit tests of the Trie library. The unit tests are
 * implemented with the "catch" unit testing library.
 *
 */

#include "../trie.h"


#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

#include "../trie.h"


/////////////////////////////////////////////////
///                                           ///
/// Test cases start here                     ///
///                                           ///
/////////////////////////////////////////////////

const int t = 1;

TEST_CASE( "sanity" ) {
  
  TrieNode* root = NULL;
  
  trie_insert(&root, (char*)"mark", 	(void*)&t);
  trie_insert(&root, (char*)"mars", 	(void*)&t);
  trie_insert(&root, (char*)"mart", 	(void*)&t);
  trie_insert(&root, (char*)"start",    (void*)&t);
  trie_insert(&root, (char*)"starter",  (void*)&t);
  
  CHECK( trie_find(root, (char*)"mark") 	!= NULL);
  CHECK( trie_find(root, (char*)"mars") 	!= NULL);
  CHECK( trie_find(root, (char*)"mart") 	!= NULL);
  CHECK( trie_find(root, (char*)"start") 	!= NULL);
  CHECK( trie_find(root, (char*)"starter")	!= NULL);
  CHECK( trie_find(root, (char*)"mar") 		== NULL);
  CHECK( trie_find(root, (char*)"s") 		== NULL);
  CHECK( trie_find(root, (char*)"er") 		== NULL);
  CHECK( trie_find(root, (char*)"irrelevant") 	== NULL);

  trie_free(root);
}


TEST_CASE( "splitting node" ) {
  
  TrieNode* root = NULL;
  
  trie_insert(&root, (char*)"abcde", 	(void*)&t);
  trie_insert(&root, (char*)"abcdex", 	(void*)&t);
  trie_insert(&root, (char*)"abcdf", 	(void*)&t);
  trie_insert(&root, (char*)"ab", 	(void*)&t);

  CHECK( trie_find(root, (char*)"abcde") 	!= NULL);
  CHECK( trie_find(root, (char*)"abcdex") 	!= NULL);
  CHECK( trie_find(root, (char*)"abcdf") 	!= NULL);
  CHECK( trie_find(root, (char*)"ab")	 	!= NULL);
  CHECK( trie_find(root, (char*)"abcd") 	== NULL);

  trie_free(root);
}


TEST_CASE( "add before root" ) {
  
  TrieNode* root = NULL;
  
  trie_insert(&root, (char*)"great", 	(void*)&t);
  trie_insert(&root, (char*)"gr", 	(void*)&t);
  trie_insert(&root, (char*)"abc", 	(void*)&t);
  
  CHECK( trie_find(root, (char*)"great") 	!= NULL);
  CHECK( trie_find(root, (char*)"gr") 		!= NULL);
  CHECK( trie_find(root, (char*)"abc") 		!= NULL);
  
  trie_free(root);
}

TEST_CASE( "before first alternative" ) {
  
  TrieNode* root = NULL;
  
  trie_insert(&root, (char*)"a", 	(void*)&t);
  trie_insert(&root, (char*)"ag", 	(void*)&t);
  trie_insert(&root, (char*)"aa", 	(void*)&t);
  
  CHECK( trie_find(root, (char*)"a") 	!= NULL);
  CHECK( trie_find(root, (char*)"ag") 	!= NULL);
  CHECK( trie_find(root, (char*)"aa") 	!= NULL);

  trie_free(root);
}

TEST_CASE( "between alternatives" ) {
  
  TrieNode* root = NULL;
  
  trie_insert(&root, (char*)"ag", 	(void*)&t);
  trie_insert(&root, (char*)"aa", 	(void*)&t);
  trie_insert(&root, (char*)"ab", 	(void*)&t);
  
  CHECK( trie_find(root, (char*)"a") 	== NULL);
  CHECK( trie_find(root, (char*)"ab") 	!= NULL);

  trie_free(root);
}

TEST_CASE( "replace data" ) {
  
  TrieNode* root = NULL;
  
  trie_insert(&root, (char*)"abra", 	(void*)&t);
  CHECK( trie_find(root, (char*)"abra") != NULL);

  trie_insert(&root, (char*)"abra", 	(void*)0);
  CHECK( trie_find(root, (char*)"abra") == NULL);

  trie_insert(&root, (char*)"abra", 	(void*)&t);
  CHECK( trie_find(root, (char*)"abra") != NULL);

  trie_free(root);
}


TEST_CASE( "find in empty trie" ) {

  TrieNode* root = NULL;
  
  CHECK( trie_find(root, (char*)"abra") == NULL);

  trie_free(root);
}
