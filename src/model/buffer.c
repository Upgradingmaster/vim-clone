#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bufferlist.h"
#include "buffer.h"
#include "line.h"

/* Buffer: Linked list of lines */
// Create a new Empty Buffer and attach it to the buffer list 
// Returns a the index in the list
int newBuffer(BufferList_t* bl) {
    Buffer_t b = {};
    int idx = blAppendBuffer(bl, b);
    return idx;
}

void destroyBuffer(Buffer_t* b) {
    // Traverse linked list destroying lines
    Line_t* curr = b->head;
    while (curr != NULL) {
        Line_t* temp_next = curr->next;
        destroyLine(b->curr);
        curr = temp_next;
    }
    free(b);
}

void bLog(Buffer_t b) {
    while(b.curr != NULL) {
        lineLog(*b.curr);
        b.curr = b.curr->next;
    }
    b.curr = b.head;
}

void bAddLine(Buffer_t* b, Line_t* l) {
    if (b->head == NULL || b->tail == NULL || b->curr == NULL) { // Empty
        b->curr = l;
        b->head = l;
        b->tail = l;
    } else {
        b->tail->next = l;
        b->tail = l;
    }

}


