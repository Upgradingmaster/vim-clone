#include <stdlib.h>
#include <string.h>
#include "bufferlist.h"
#include "buffer.h"


/* Buffer List */

// Empty Buffer List, capacity INIT_BUF_CAP
BufferList_t* newBufferList(){
    BufferList_t* bl = malloc(sizeof(BufferList_t));

    bl->buffers = malloc(sizeof(Buffer_t) * 2);
    memset(bl->buffers, 0, sizeof(Buffer_t) * 2);
    bl->size = 0;
    bl->capacity = INIT_BL_CAP;
    return bl;
}

void destroyBufferList(BufferList_t* bl) {
    for(int i = 0; i < bl->size; i++ ) {
        destroyBuffer(bl->buffers + (sizeof(Buffer_t) * i ));
    }
    free(bl);
}

int blAppendBuffer(BufferList_t* bl, Buffer_t b) {
    if (bl->size == bl->capacity) {blGrow(bl); }
    bl->buffers[bl->size++] = b;
    return bl->size-1;
}


void blDestoryBufferAt(BufferList_t* bl, int index) {
    destroyBuffer(bl->buffers + (sizeof(Buffer_t) * index));
    for (int i = index; i < bl->size ; i++) {
        bl->buffers[i] = bl->buffers[i + 1];
    }
    bl->size--;
}


bool blIsEmpty(BufferList_t* bl) {
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

