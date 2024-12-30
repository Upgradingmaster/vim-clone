#include <stdio.h>
#include "keyhandler.h"
#include "ui.h"


int main( int argc, char** argv) {
    if (argc > 1) {
        // Flags handling
        fputs(*argv, stdout);
        return 0;
    }

    prepareUI();

    int run = 1;
    while (run) {
        char c = getchar();
        run = handleKey(c); // TODO: Virtually apply the changes to a buffer
                            // Then update the ui with the buffer changes
    }

    revertToCanonical();

}
