#include "ui.h"
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>

termios_p old;
static termios_p initTermios(int fd);

void prepareUI() {
    old = initTermios(0);

    termios_p raw = initTermios(0);
    cfmakeraw(raw);
    tcsetattr(0, TCSANOW,  raw);  // Set raw
    free(raw);
    puts("\033[2J"); // Clear Screen

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
    }
}



void startUIElementHandler() {

}

void stopUIElementHandler() {

}
