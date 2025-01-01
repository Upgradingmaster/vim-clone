#include "lines.h"
#include <stdlib.h>
#include <stdlib.h>

static int isGap(Line l, int i);


void setChar(Line l, int i, char c) {
    Content cont = l.content;
    if (cont.content != 0 && i < cont.size ) {
        cont.content[i] = c;
    }
}

Line* newLine() {
    Content c = malloc(sizeof(string));

    return
}


void setString(Line l, char* string) {
    Content cont = l.content;
    cont.content = realloc(cont.content, sizeof(string));
}


static int isGap(Line l, int i) {
    return (i <= l.content.gapEnd && i >= l.content.gapStart) ? 1:0;
}


