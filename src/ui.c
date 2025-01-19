#include "ui.h"
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>

termios_p old;
static termios_p initTermios(int fd);

void prepareUI() {
    old = initTermios(0);

    // Set raw
    termios_p raw = initTermios(0);
    cfmakeraw(raw);
    tcsetattr(0, TCSANOW,  raw);  
    free(raw);

    // Enable alternate screen
    puts("\x1b[?1049h"); 

    /*pthread_t keyListenerThread;*/
    /*pthread_create(&keyListenerThread, NULL, startKeyListener, NULL);*/
}

// Return the `state` of `fd` wrapped in  a `termios` struct
static termios_p initTermios(int fd) {
    termios_p termios_p = malloc(sizeof(struct termios));
    tcgetattr(fd, termios_p);
    return termios_p;
}


void revertToCanonical() {
    if (old) {
        tcsetattr(0, TCSANOW,  old); 
        free(old);
        puts("\x1b[?1049l"); // Disable alternate screen
    }
}



