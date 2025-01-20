#include "buffer.h"
#include "lines.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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
    b->curr = b->head;
    while (b->curr != NULL) {
        Line_t* temp_next = b->curr->next;
        destroyLine(b->curr);
        b->curr = temp_next;
    }
    free(b);
    b = 0;
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

void bLog(Buffer_t b) {
    while(b.curr != NULL) {
        lineLog(*b.curr);
        b.curr = b.curr->next;
    }
}


/* Buffer Array */

// Empty Buffer List, capacity INIT_BUF_CAP
BufferList_t* newBufferList(){
    BufferList_t* bl = malloc(sizeof(BufferList_t));

    bl->buffers = malloc(sizeof(Buffer_t) * 2);
    memset(bl->buffers, 0, sizeof(Buffer_t) * 2);
    bl->size = 0;
    bl->capacity = INIT_BUF_CAP;
    return bl;
}

int blAppendBuffer(BufferList_t* bl, Buffer_t b) {
    if (bl->size == bl->capacity) {blGrow(bl); }
    bl->buffers[bl->size++] = b;
    return bl->size-1;
}


void blDestoryBufferAt(BufferList_t* bl, int index) {
    destroyBuffer(&bl->buffers[index]);
    for (int i = index; i < bl->size ; i++) {
        bl->buffers[i] = bl->buffers[i + 1];
    }
    bl->size--;
}

void blDestory(BufferList_t* bl) {
    for(int i = 0; i < bl->size; i++ ) {
        destroyBuffer(&bl->buffers[i]);
    }
    bl->buffers = 0;
    free(bl);
}

char blIsEmpty(BufferList_t* bl) {
    return bl->size == 0;
}

// TODO: overflow check
void blGrow(BufferList_t* bl) {
    int new_cap = bl->capacity * 2;
    bl->buffers = realloc(bl->buffers, new_cap);
    bl->capacity = new_cap;
}

void blLog(BufferList_t bl) {
    for (int i = 0 ; i < bl.size ; i++ ) {
        bLog(bl.buffers[i]);
    }
}

