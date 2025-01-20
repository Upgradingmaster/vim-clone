# ifndef BUFFER 
# define BUFFER
#include "lines.h"


#define INIT_BUF_CAP 2

typedef struct Buffer Buffer_t;
typedef struct BufferList BufferList_t;

/* Buffer: Linked list of lines */
struct Buffer {
    Line_t* head;
    Line_t* tail;
    Line_t* curr;
    int curr_row;
    int curr_col;
};
int newBuffer(BufferList_t*);
void destroyBuffer(Buffer_t*);
void bAddLine(Buffer_t*, Line_t*);

void bLog(Buffer_t);

struct BufferList{
    Buffer_t* buffers;
    int size;
    int capacity;
};

BufferList_t* newBufferList();

int blAppendBuffer(BufferList_t*, Buffer_t);

void blDestoryBufferAt(BufferList_t*, int);
void blDestory(BufferList_t*);
char blIsEmpty(BufferList_t*);

void blGrow(BufferList_t*);


void blLog(BufferList_t);

# endif
