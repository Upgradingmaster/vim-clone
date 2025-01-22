#ifndef VIM_CLONE_LINES
#define VIM_CLONE_LINES
#include <stddef.h>
#include <stdbool.h>

#define LINE_NEED_RESIZE(l) l->gapStart >= l->gapEnd
#define MAX_LINE_BUF_SIZE 32
#define CAPPED_DOUBLE_SIZE(size) (size < (MAX_LINE_BUF_SIZE - 1)/2) ? (size * 2) + 1 : MAX_LINE_BUF_SIZE
#define LINE_RHS_LENGTH(l)  l->capacity - l->gapEnd

/* ---BufferList/Buffer/Line (LL Element)--- */
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
bool lineShrink(Line_t* l, size_t cap_1);
bool lineMoveGap(Line_t*, size_t);
bool lineLeft(Line_t*);
bool lineRight(Line_t*);

#endif
