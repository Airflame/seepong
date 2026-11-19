#include "seepong.h"

RECT getRect(PLAYER player)
{
    RECT rect = {
        .left   = player.x,
        .top    = player.y,
        .right  = player.x + player.width,
        .bottom = player.y + player.height
    };
    return rect;
}