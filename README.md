# Trie #

This is an imlementation of the [Trie](http://en.wikipedia.org/wiki/Trie) data structure. It allows fast storage and retrieval of data keyed by ASCII strings. 


## Specific Implementation Details ##

This implementation was written for educational porpuses. An effort was made to make it efficient in runtime and storage

Some important thing one should know about it:

* Storing the characters in the nodes and not in the edges produces much simpler code.

*  Similar to [radix trie](http://en.wikipedia.org/wiki/Radix_tree), nodes who are single childs are merged with their parents (unless the parents are terminal nodes).

* But, unlike radix trie, my implementation uses a linked list to store alternatives of child nodes. For example if we have added these two strings `ape, apple` into a trie, then the root node will contain `ap` and it will have a child `e` who's next alternative is `lpe`. This allows stroing any ascii string while keeping the implementation simple and readable. The downside is that now operations on the trie would take O(c**2) where c is the size of the alphabet.

* This is a recursion/stacck implementation, except the memeory freeing operation.

* Currently, deletion is not implemented. You are wellcomed to fork the code and try to implement it yourself.


## Makefile Targets ##

**tests** - Builds only the tests. Will produce `run_tests.out` executable in the main directory. For the unit tests, I used the [Catch](https://github.com/philsquared/Catch) framework.

**all** - Will compile the tests and `program.out` demo program

