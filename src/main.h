# ifndef MAIN 
# define MAIN

#include "buffer.h"
#include "trie.h"

struct State {
    Buffer curr;
    BufferList buffers;
    Trie trie;
};

# endif
