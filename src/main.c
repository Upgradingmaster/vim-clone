#include <stdio.h>
#include "model/buffer.h"
#include "keyhandler.h"
#include "ui.h"
#include "logger.h"


int main( int argc, char** argv) {
    if (argc > 1) {
        // Flags handling
        fputs(*argv, stdout);
        return 0;
    }
    prepareUI();

    int success = LoggerOpen();
    if (success == -1) puts("Failed to open Logger");

    int run = 1;
    if (0){
    while (run) {
        // Main Loop
        // read input
            // Map to trie
            // if not accept {continue;}
            // else motion = trie.val
        // react to motion in backend
        // Render
        char c = getchar();
        run = handleKey(c); 
        
         
        /*char logMessage[13];*/
        /*sprintf(logMessage, "Key Press: %c", c);*/
        /*Log(logMessage);*/
    }
    revertToCanonical();
}



    BufferList bl = newBufferLis    t();
    addBuffer(bl, newBuffer("ABC"));
    addBuffer(bl, newBuffer("AB"));
    addBuffer(bl, newBuffer("A"));
    logAllBuffers(bl);
    destoryAllBuffers(bl);
    Logf("%s\n", "Hello world");
    LoggerClose();
}

