# ifndef BUFFER 
# define BUFFER
#include "lines.h"

// Linked list of lines
typedef struct {
    Line headLine;
    Line tailLine;
    int curr_row;
    int curr_col;
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
