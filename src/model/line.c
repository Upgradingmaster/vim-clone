#include "line.h"
#include "logger.h"
#include <string.h>
#include <stdlib.h>
#include <string.h>

/* ---Line LL Element--- */

//                 gs-ge
// [ c_0, c_1, c_2]
Line_t* newLineString(char initStr[]) {
    Line_t* line_p = malloc(sizeof(Line_t));

    int len_c = strlen(initStr);
    char* content = strdup(initStr);

    /* Gap Buffer */
    line_p->content = content; 
    line_p->gapStart = len_c;
    line_p->gapEnd = len_c;
    line_p->size = len_c;
    line_p->capacity = len_c;

    /* LL Element*/
    line_p->next = 0;
    line_p->prev = 0;

    return line_p;
}

//                  gs       ge
// [ c_0, c_1, c_2, _, _, _]

Line_t* newLineN(size_t capacity) {
    Line_t* line_p = malloc(sizeof(Line_t));

    char* content = calloc(capacity, sizeof(char));

    /* Gap Buffer */
    line_p->content = content; 
    line_p->gapStart = 0;
    line_p->gapEnd = capacity;
    line_p->size = 0;
    line_p->capacity = capacity;

    /* LL Element*/
    line_p->next = 0;
    line_p->prev = 0;

    return line_p;
}


void destroyLine(Line_t* l) {
    free(l->content);
    free(l);
}; 

void lineLog(const Line_t l) {
    char* content = l.content;
    size_t cap = l.capacity;
    char str[cap + 3];
    str[0] =  '[';
    str[cap+3-2] =  ']';
    str[cap+3-1] =  '\0';
    for(size_t i = 0; i < cap; i++) {
        char c = content[i];
        
        if (l.gapStart <= i && i < l.gapEnd) {
            str[i + 1] = '_';
        } else {
            str[i + 1] = c;
        }
    }
    Logf(">> LINE: %s | Capacity: %d | Size: %d | GS: %d | GE: %d", str, cap, l.size, l.gapStart, l.gapEnd);
}

// Insert
bool lineInsertChar(Line_t* l, char c) {
    if (lineNeedResize(l)){
        if (!lineGrow(l, CAPPED_DOUBLE_SIZE(l->capacity))) {
            return false;
        }
    }
    l->content[l->gapStart++] = c;
    l->size++;
    return true;
}

bool lineInsertString(Line_t* l, char c[]) {
    for (size_t i = 0 ; i < strlen(c); i++) {
        if (!lineInsertChar(l, c[i])) return false;
    }
    return true;
}
bool lineDeleteChar(Line_t* l) {
    if (l->gapStart == 0) return false;
    l->gapStart--;
    l->size--;
    return true;
}

// Update allocated memory for the line to cap_1. as long as it is greater 
// Then extend the gap_end to take the new space, moving the data forward
// Thus the gapStart, maintains position. The gapEnd moves forward
// Edge case: 
// `gs == ge == i` i.e. empty gap,   
//      the new gap starts at the index `i` maintaining gapStart,
//      pushing the gapEnd, and data at indices i, i+1, i+2 etc. ahead
//  `ge_0 == cap_0` dont move anything, just realloc and update pointers
//
// WARN:
//  - Does not check for exceeding the MAX_BUF_SIZE
// TODO: Test switching to malloc instead of realloc for more "control"
bool lineGrow(Line_t* l, size_t cap_1) {
    if (cap_1 <= l->capacity) return false;
    int cap_0 = l->capacity;
    int ge_0 = l->gapEnd;
    int num_bytes_right = cap_0 - ge_0;
    int ge_1 = cap_1 - num_bytes_right;

    // [a, b, c, _, _, d, e, f]                            
    
    // Extend space
    char* new_content = realloc(l->content, cap_1);
    // [a, b, c, _, _, d, e, f, _, _, _, _, _, _, _, _]
    
    // Shift gap-right to the end of the new space
        // Copy gap-right [ge_0:cap_0)
        // to [ge_1:cap_1)
    memmove(new_content + ge_1, new_content + ge_0, num_bytes_right);
    // [a, b, c, _, _, _, _, _, _, _, _, _, _, d, e, f]

    l->gapEnd = ge_1;
    l->content = new_content;
    l->capacity = cap_1;
    return true;
}

bool lineMoveGap(Line_t* l, size_t gs_1) {
    size_t gs_0 = l->gapStart;
    size_t ge_0 = l->gapEnd;

    // size_t gs_1 = new_gs;
    size_t ge_1 = gs_1 + ge_0 - gs_0;


    if ( ge_1 > l->capacity || 
         gs_0 == gs_1
    ) return false;

    if (gs_0 < gs_1) { // Move Right
        memmove(&l->content[gs_0], &l->content[ge_0], ge_1 - ge_0);
    }
    else if (gs_1 < gs_0) { // Move Left
        memmove(&l->content[ge_1], &l->content[gs_1], gs_0 - gs_1);
    }

    l->gapStart = gs_1;
    l->gapEnd = ge_1;
    return true;
}

bool lineLeft(Line_t* l) {
    if (l->gapStart == 0) {
        return false;
    }
    l->content[--l->gapEnd] = l->content[--l->gapStart];
    return true;
}

bool lineRight(Line_t* l) {
    if (l->gapEnd == l->capacity) {
        return false;
    }
    l->content[l->gapStart++] = l->content[l->gapEnd++];
    return true;
}
