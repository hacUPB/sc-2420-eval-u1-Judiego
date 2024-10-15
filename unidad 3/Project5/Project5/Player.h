#ifndef PLAYER_H
#define PLAYER_H

#include <SDL.h>

typedef struct {
    SDL_Rect rect;
    int velocityY;
    int isJumping;
} Player;

void Player_init(Player* player, int x, int y);
void Player_handleInput(Player* player, SDL_Event event);
void Player_update(Player* player);
void Player_render(Player* player, SDL_Renderer* renderer);
int Player_checkCollision(Player* player, SDL_Rect* obstacleRect);

#endif
