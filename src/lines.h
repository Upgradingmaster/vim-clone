#ifndef LINES
#define LINES

typedef struct Content{
    char* content;
    int gapStart;
    int gapEnd;
    int size;
} Content;

typedef struct Line{
    Content content;
    struct Line* next;
    struct Line* prev;
} Line;



#endif
