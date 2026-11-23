#include "seepong.h"

RECT getRect(const PLAYER *player)
{
    RECT rect = {
        .left   = player->x - player->width / 2,
        .top    = player->y - player->height / 2,
        .right  = player->x + player->width / 2,
        .bottom = player->y + player->height / 2
    };
    return rect;
}