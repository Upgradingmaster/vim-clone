# ifndef VIM_CLONE_BUFFER_LIST
# define VIM_CLONE_BUFFER_LIST
#define INIT_BL_CAP 2
#include <stdbool.h>

typedef struct Buffer Buffer_t;
typedef struct BufferList BufferList_t;

struct BufferList{
    Buffer_t* buffers;
    int size;
    int capacity;
};

BufferList_t* newBufferList();
void destroyBufferList(BufferList_t*);

int blAppendBuffer(BufferList_t*, Buffer_t);

void blDestoryBufferAt(BufferList_t*, int);
bool blIsEmpty(BufferList_t*);

void blGrow(BufferList_t*);


void blLog(BufferList_t);

# endif
