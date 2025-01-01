# ifndef BUFFER 
# define BUFFER
#include "lines.h"

typedef struct {
    Line headLine;
    Line tailLine;
    int c_row;
    int c_col;
    int v_top;
    int v_bottom;
} Buffer;

typedef struct {
    Buffer* buffers;
    int size;
} BufferList;

BufferList newBufferList();
Buffer newBuffer(char* contents);

void addBuffer(BufferList, Buffer);
void destoryBuffer(BufferList, int i);
void destoryAllBuffers(BufferList bl);

void logAllBuffers(BufferList bl);
# endif
