#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <SDL.h>

typedef struct {
    SDL_Rect rect;
    int speed;
} Obstacle;

void Obstacle_init(Obstacle* obstacle, int x, int y);
void Obstacle_update(Obstacle* obstacle);
void Obstacle_render(Obstacle* obstacle, SDL_Renderer* renderer);

#endif
