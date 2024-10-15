#include "Obstacle.h"

void Obstacle_init(Obstacle* obstacle, int x, int y) {
    obstacle->rect.x = x;
    obstacle->rect.y = y;
    obstacle->rect.w = 50;
    obstacle->rect.h = 50;
    obstacle->speed = 5;
}

void Obstacle_update(Obstacle* obstacle) {
    obstacle->rect.x -= obstacle->speed;

    if (obstacle->rect.x + obstacle->rect.w < 0) {
        obstacle->rect.x = 800;  // Reiniciar la posición cuando sale de la pantalla
    }
}

void Obstacle_render(Obstacle* obstacle, SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(renderer, &obstacle->rect);
}
