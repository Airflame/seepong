#ifndef SEEPONG_SEEPONG_H
#define SEEPONG_SEEPONG_H

#include <windows.h>

typedef struct PLAYER {
    int x;
    int y;
    int width;
    int height;
} PLAYER;

RECT getRect(PLAYER player);

#endif //SEEPONG_SEEPONG_H
