#ifndef VIM_CLONE_LINES
#define VIM_CLONE_LINES
#include <stddef.h>
#include <stdbool.h>

#define lineNeedResize(l) l->gapStart >= l->gapEnd
#define MAX_LINE_BUF_SIZE 16
#define CAPPED_DOUBLE_SIZE(size) (size < MAX_LINE_BUF_SIZE/2) ? size * 2 : MAX_LINE_BUF_SIZE

/* ---Line LL Element--- */
typedef struct Line {

    /* Gap Buffer */
    char* content; 
    size_t gapStart;
    size_t gapEnd;
    size_t size;
    size_t capacity;

    struct Line* next;
    struct Line* prev;
} Line_t;
Line_t* newLineString(char initStr[]);
Line_t* newLineN(size_t capacity);
void destroyLine(Line_t*);
void lineLog(const Line_t);

// Insert
bool lineInsertChar(Line_t*, char);
bool lineInsertString(Line_t*, char[]);
bool lineDeleteChar(Line_t*);
 
// Gap
bool lineGrow(Line_t*, size_t);
bool lineMoveGap(Line_t*, size_t);
bool lineLeft(Line_t*);
bool lineRight(Line_t*);

#endif
