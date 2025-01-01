#include <stdio.h>
#include "buffer.h"
#include "keyhandler.h"
#include "ui.h"
#include "logger.h"


int main( int argc, char** argv) {
    if (argc > 1) {
        // Flags handling
        fputs(*argv, stdout);
        return 0;
    }

    if (0) {
    prepareUI();
    int run = 1;
    while (run) {
        char c = getchar();
        run = handleKey(c); 
        // TODO: Virtually apply the changes to a buffer
        // Then update the ui with the buffer changes
         
        /*char logMessage[13];*/
        /*sprintf(logMessage, "Key Press: %c", c);*/
        /*Log(logMessage);*/
    }

    revertToCanonical();
    }

    int success = LoggerOpen();
    if (success == -1) puts("Failed to open Logger");

    char* str1 = malloc(sizeof(str));

    BufferList bl = newBufferList();
    addBuffer(bl, newBuffer("ABC"));
    addBuffer(bl, newBuffer("AB"));
    addBuffer(bl, newBuffer("A"));
    logAllBuffers(bl);
    destoryAllBuffers(bl);
    Logf("%s\n", "Hello world");
    LoggerClose();
}

