# ifndef VIM_CLONE_BUFFER 
# define VIM_CLONE_BUFFER
#include "line.h"

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

# endif
