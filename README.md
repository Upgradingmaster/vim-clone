
# Tasks
- Core Models:
    1. BL   - Dynamic List ? Vim itself uses doubly linked list
    2. BUF  - Linked List ? Vim uses something more complex
    3. Line - Gap Buffer : **Done**
- Key Press -> Trie
- Update Model based on the trie acceptance (Track "dirty" sections)
- Rendering "dirty"
- General Error Handling:
    1. Allocator failures

Factors:
1. Logging 
2. Dynamicity
3. Cleanup/Destructor
4. Constructor
