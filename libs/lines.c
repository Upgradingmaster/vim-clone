#include "lines.h"
#include "logger.h"
#include <string.h>
#include <stdlib.h>
#include <string.h>

#define INIT_LINE_CAPACITY 50

/* ---Line LL Element--- */
Line_t* newLine(char c[]) {
    Line_t* line_p = malloc(sizeof(Line_t));
    line_p->content = newLineContent(c);
    line_p->next = 0;
    line_p->prev = 0;
    return line_p;
}
void destroyLine(Line_t* l) {
    destroyLineContent(l->content);
    free(l);
}; 
void lineLog(Line_t l) {
    char* content = l.content->content;
    char str[100];
    int count = 0;
    for(int i = 0; i < l.content->capacity; i++) {
        if (content[i] != '0') {
            str[count] = content[i];
            count++;
        }
    }
    str[count] = '\0';
    Logf(">> LINE: %s", str);
}


/* ---Line Content - Gap Buffer--- */
LineContent_t* newLineContent(char c[]) {
    LineContent_t* line_content_p = malloc(sizeof(LineContent_t));
    size_t size = strlen(c);
    char* str = strdup(c);

    line_content_p->content = str;
    line_content_p->gapStart = 0;
    line_content_p->gapEnd = size-1;
    line_content_p->size = size;
    line_content_p->capacity = size;
    return line_content_p;
};
void destroyLineContent(LineContent_t* l) {
    free(l->content);
    free(l);
}

// Insert
void lcInsertChar(LineContent_t* l, char c) {
    if (lcNeedResize(l)){
        lcResize(l);
    }
    l->content[l->gapStart++] = c;
    l->size++;
}

void lcInsertString(LineContent_t* l, char* c, size_t length) {
    for (size_t i = 0 ; i < length; i++) {
        lcInsertChar(l, c[0]);
    }
}
void lcDeleteChar(LineContent_t* l) {
    l->content[l->gapStart--] = 0;
}

// Resize
char lcNeedResize(LineContent_t* l) {
    return l->gapStart >= l->gapEnd;
}

void lcResize(LineContent_t* l) {
    int old_cap = l->capacity;
    int new_cap = l->capacity * 2;

    int old_end = l->gapEnd;
    int new_end = old_cap + old_end;

    int right_bytes_num =  old_cap - old_end;


    char* new_char_p = realloc(l->content, new_cap);
    if (new_char_p == 0) {
        return;
    }

    if (old_end == old_cap - 1) {
        l->gapEnd = new_cap;
    } else {
        // move from [end:old_cap-1] to [oldcap+end:new_cap-1]
        // [a, b, c, _, d, e, f, _,  _,  _,  _,  _,  _] 
        // [a, b, c, _, _, _, _, _,  _,  _,  d,  e,  f]
        memmove(&new_char_p[new_end], &new_char_p[old_end], right_bytes_num);
        memset(&new_char_p[old_end], 0, right_bytes_num);
        l->gapEnd = new_end;
    }

    l->content = new_char_p;
    l->capacity = new_cap;
}

    /*int diff = i - l->gapStart;*/
    /*l->gapStart += diff;*/
    /*l->gapEnd += diff;*/

