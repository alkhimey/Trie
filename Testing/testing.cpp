/**
 * @author  Artium Nihamkin <artium@nihamkin.com>
 * @date May 2014 
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

TEST_CASE( "sanity test" ) {
  
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
  
  /*
  SECTION( "post" ) {
    CHECK_NOTHROW(x++);
    CHECK_THROWS(x++);
    CHECK( x == 100 );
  
    CHECK_NOTHROW(y--);
    CHECK_THROWS(y--);
    CHECK( y == 0 );
  }

  SECTION( "pre" ) {
    CHECK_NOTHROW(++x);
    CHECK_THROWS(++x);
    CHECK( x == 100 );
    
    CHECK_NOTHROW(--y);
    CHECK_THROWS(--y);
    CHECK( y == 0 );
    }*/
}
