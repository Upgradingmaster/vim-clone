#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "model/buffer.h"
#include "model/bufferlist.h"
#include "model/line.h"
#include "keyhandler.h"
#include "ui.h"
#include "logger.h"


int main( int argc, char** argv) {
    if (argc > 1) {
        // Flags handling
        if (strcmp(argv[1], "--debug") == 0) {
            if (LoggerOpen(1) == -1) puts("Failed to open Logger");
            Line_t* line = newLineN(5);
            lineLog(*line);

            while(1) {
                char a = getchar();
                switch (a) {
                    case '\n': continue;
                    case 'd': lineDeleteChar(line); break;
                    case 'l': lineLeft(line); break;
                    case 'r': lineRight(line); break;
                    case 'g': lineGrow(line, CAPPED_DOUBLE_SIZE(line->capacity)); break;
                    case 's': 
                              int f;
                              scanf("%d", &f);
                              lineShrink(line, f);
                              break;
                    case 'm': 
                              int e;
                              scanf("%d", &e);
                              lineMoveGap(line, e);
                              break;
                            
                    default: lineInsertChar(line, a);
                }
                lineLog(*line);
            }
            destroyLine(line);
            LoggerClose();
        }
        return 0;
    }
    int success = LoggerOpen(1);
    if (success == -1) puts("Failed to open Logger");

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

