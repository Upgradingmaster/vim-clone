#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "model/buffer.h"
#include "model/lines.h"
#include "keyhandler.h"
#include "ui.h"
#include "logger.h"


int main( int argc, char** argv) {
    int success = LoggerOpen(1);
    if (success == -1) puts("Failed to open Logger");

    if (argc > 1) {
        // Flags handling
        puts(*argv);

        BufferList_t* bl = newBufferList();
        Line_t* line = newLine("abc");
        Line_t* line1 = newLine("deff");
        Line_t* line2 = newLine("hellooooo");
        int i_buf = newBuffer(bl);
        bAddLine(&bl->buffers[i_buf], line);
        bAddLine(&bl->buffers[i_buf], line1);
        bAddLine(&bl->buffers[i_buf], line2);



        blDestory(bl);
        LoggerClose();

        return 0;
    }

    prepareUI();

    int run = 1;
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

