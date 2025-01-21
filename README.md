- Handle allocator failures

Models:
1. BL   - Dynamic List 
2. BUF  - Linked List
3. Line - Gap Buffer
    - Todo: 
        - shrink if necessary , check on-delete?
        ```c
        if (size <  cap / 4) {
            shrink_buffer (buf, buf->size / 2);
        }
        ```


    Factors:
    1. Logging - Done
    2. Dynamicity - Done
    3. Cleanup/Destructor - Done
    4. Constructor
