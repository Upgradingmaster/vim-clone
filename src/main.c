#include <stdio.h>
#include "cli.h"


int main( int argc, char** argv) {
    if (argc == 1) {
        return startVimDefault();
    } else {
        // Flags handling
        return 0;
    }

}
