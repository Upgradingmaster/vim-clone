#ifndef LINES
#define LINES
#include <stddef.h>

struct Line;
struct LineContent;

/* ---Line LL Element--- */
typedef struct Line {
    struct LineContent* content;
    struct Line* next;
    struct Line* prev;
} Line_t;
Line_t* newLine();
void destroyLine(Line_t*);

/* ---Line Content - Gap Buffer--- */
typedef struct LineContent {
    char* content; 
    int gapStart;
    int gapEnd;
    int size;
    int capacity;
} LineContent_t;

LineContent_t* newLC();
void destroyLC(LineContent_t*);

// Insert
void lcInsertChar(LineContent_t*, char);
void lcInsertString(LineContent_t*, char*, size_t);
void lcDeleteChar(LineContent_t*);
 
// Resize
char lcNeedResize(LineContent_t*);
void lcResize(LineContent_t*);

// Gap



#endif
