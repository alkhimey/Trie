# Trie #

This is an implementation of the [Trie](http://en.wikipedia.org/wiki/Trie) data structure. It allows fast storage and retrieval of data keyed by ASCII strings. 


## Specific Implementation Details ##

This implementation was written for educational purposes, therfore readability and simplicity were chosen as the main guidelines. A secondary effort was made to make it efficient in run-time and storage

Some important thing one should know about it:

* Characters are stored in the nodes and not in the edges. Many textbooxs show diagrams where the characters are drawn on the edges. Storing the charactes on the nodes produces much simpler and readable code. 

*  Similar to [radix trie](http://en.wikipedia.org/wiki/Radix_tree), nodes who are single childs are merged with their parents (unless the parents are terminal nodes).

* But, unlike radix trie, this implementation uses a linked list to store alternatives of child nodes. For example if we have added these two strings `ape, apple` into a trie, then the root node will contain `ap` and it will have a child `e` who's next alternative is `ple`. This allows storing strings with full range of ASCII characters, while keeping the implementation simple and readable. The downside is that with this implementation operations on the trie would take O(c**2) where c is the size of the alphabet.

* This is a recursion/stack free implementation, except the memory release operation.

* Currently, deletion is not implemented. Cloning the code and trying to implement this operation is encouraged.


## Makefile Targets ##

**demo** - Will compile the `demo.out` demo program

**tests** - Builds only the tests. Will produce `run_tests.out` executable in the main directory. For the unit tests, the [Catch](https://github.com/philsquared/Catch) framework is used.


