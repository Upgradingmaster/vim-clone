#include "keyhandler.h"
#include <stdio.h>
#include <pthread.h>

static void setMode(enum Mode mode);

enum Mode mode = Normal;
// Handle the character, returns 0 to quit, else returns 1
int handleKey(char c) {
    switch (c) {
        case 'q' : return 0;
        case 'v' : setMode(Visual); break;
        case 'i' : setMode(Insert); break;
        case 'h' : if (mode == Normal) {fputs("\x1b[1D", stdout);}; break;
        case 'j' : if (mode == Normal) {fputs("\x1b[1B", stdout);}; break;
        case 'k' : if (mode == Normal) {fputs("\x1b[1A", stdout);}; break;
        case 'l' : if (mode == Normal) {fputs("\x1b[1C", stdout);}; break;

        // ESC / <C-c>
        case 27  : 
        case 3   : setMode(Normal); break;

        default: if (mode == Insert) putchar(c); 
    }
    return 1;
}

static void setMode(enum Mode set_mode) {
    mode = set_mode;
    fputs("\x1b[s", stdout);
    fputs("\x1b[1;1H", stdout);
    switch (mode) {
        case 0: fputs("Normal", stdout); break;
        case 1: fputs("Insert", stdout); break;
        case 2: fputs("Visual", stdout); break;
    }
    fputs("\x1b[u", stdout);
}

