#include "Player.h"

void Player_init(Player* player, int x, int y) {
    player->rect.x = x;
    player->rect.y = y;
    player->rect.w = 50;
    player->rect.h = 50;
    player->velocityY = 0;
    player->isJumping = 0;
}

void Player_handleInput(Player* player, SDL_Event event) {
    if (event.type == SDL_KEYDOWN) {
        if (event.key.keysym.sym == SDLK_SPACE && !player->isJumping) {
            player->velocityY = -15;  // Velocidad del salto
            player->isJumping = 1;
        }
    }
}

void Player_update(Player* player) {
    player->velocityY += 1;  // Gravedad
    player->rect.y += player->velocityY;

    if (player->rect.y >= 500) {
        player->rect.y = 500;
        player->velocityY = 0;
        player->isJumping = 0;
    }
}

void Player_render(Player* player, SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &player->rect);
}

int Player_checkCollision(Player* player, SDL_Rect* obstacleRect) {
    return SDL_HasIntersection(&player->rect, obstacleRect);
}
