#include "buffer.h"
#include "logger.h"
#include <stdio.h>
#include <stdlib.h>

// Returns an array of buffers in the heap
// Malloc failure might cause buffers.buffers to be NULL
BufferList newBufferList(){
    BufferList buffersList = {malloc(sizeof(Buffer)), 1}; 
    return buffersList;
}

Buffer newBuffer(char* contents) {
    Buffer b = { 
        .contents = contents,
        .c_row = 0,
        .c_col = 0,
        .v_top = 0,
        .v_bottom = 0
    };
    return b;
}

void addBuffer(BufferList bl, Buffer buffer) {
    bl.buffers = realloc( bl.buffers, sizeof(Buffer) * ++bl.size );
    bl.buffers[bl.size-1] = buffer;
}

void destoryBuffer(BufferList bl, int index) {
    for (int i = index; i < bl.size ; i++) {
        bl.buffers[i]  = bl.buffers[i + 1];
    }
    bl.size--;
    bl.buffers = realloc(bl.buffers, sizeof(Buffer) * bl.size );
}

void destoryAllBuffers(BufferList bl) {
    for(int i = 0; i < bl.size; i++ ) {
        free(bl.buffers[i].contents);
    }
    free(bl.buffers);
    bl.buffers = NULL;
}

void logAllBuffers(BufferList bl) {
    for (int i = 0 ; i < bl.size ; i++ ) {
        Buffer b = bl.buffers[i];
        Logf("\n Buffer: %id\n\tContents: [%s]\n\tCRow: %d\n\tCColumn: %d\n\tVTop: %d\n\tVBottom: %d\n", i+1, b.contents, b.c_row, b.c_col, b.v_top, b.v_bottom );
    }
}

