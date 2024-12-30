#ifndef KEY_HANDLER
#define KEY_HANDLER

enum Mode {
    Normal,
    Insert,
    Visual
};

int handleKey(char c);
#endif
