#ifndef UI
#define UI
#include <termios.h>

typedef struct termios* termios_p;
void prepareUI();
void revertToCanonical();
void startUIElementHandler();
void stopUIElementHandler();
#endif

