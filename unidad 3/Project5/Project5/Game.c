#include "Game.h"
#include <stdio.h>

// Definición de la variable global para el estado del juego
bool game_is_running = true;

// Variables globales para la ventana y el renderizador
SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;

int last_frame_time = 0; // Para controlar el tiempo entre frames
int gravity = 300;       // Gravedad que afecta al jugador
int jump_force = 400;    // Fuerza de salto del jugador

// Inicializa la ventana y el renderizador
int initialize_window(void) {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("Error inicializando SDL: %s\n", SDL_GetError());
        return 0;
    }

    // Crear la ventana del juego
    window = SDL_CreateWindow(
        "Geometry Dash",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WINDOW_WIDTH,
        WINDOW_HEIGHT,
        SDL_WINDOW_SHOWN
    );

    if (!window) {
        printf("Error creando la ventana: %s\n", SDL_GetError());
        return 0;
    }

    // Crear el renderizador
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        printf("Error creando el renderizador: %s\n", SDL_GetError());
        return 0;
    }

    return 1; // Éxito
}

// Procesa la entrada del usuario
void process_input(Player* player, bool* game_is_running) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_QUIT:
            *game_is_running = false;
            break;
        case SDL_KEYDOWN:
            if (event.key.keysym.sym == SDLK_ESCAPE) {
                *game_is_running = false;
            }
            if (event.key.keysym.sym == SDLK_SPACE && !player->is_jumping) {
                player->vel_y = -jump_force;
                player->is_jumping = true;
            }
            break;
        }
    }
}

// Configura el jugador y el obstáculo al iniciar el juego
void setup(Player* player, Obstacle* obstacle) {
    // Configurar el jugador
    player->base.x = 50;
    player->base.y = WINDOW_HEIGHT - GROUND_HEIGHT - 50;
    player->base.width = 50;
    player->base.height = 50;
    player->vel_y = 0;
    player->is_jumping = false;

    // Configurar el obstáculo
    obstacle->base.x = WINDOW_WIDTH;
    obstacle->base.y = WINDOW_HEIGHT - GROUND_HEIGHT - 50;
    obstacle->base.width = 50;
    obstacle->base.height = 50;
    obstacle->vel_x = -200;
}

// Actualiza la lógica del juego
void update(Player* player, Obstacle* obstacle) {
    int time_to_wait = FRAME_TARGET_TIME - (SDL_GetTicks() - last_frame_time);
    if (time_to_wait > 0 && time_to_wait <= FRAME_TARGET_TIME) {
        SDL_Delay(time_to_wait);
    }

    float delta_time = (SDL_GetTicks() - last_frame_time) / 1000.0f;
    last_frame_time = SDL_GetTicks();

    // Aplicar gravedad al jugador
    player->vel_y += gravity * delta_time;
    player->base.y += player->vel_y * delta_time;

    // Si el jugador toca el suelo, deja de caer
    if (player->base.y >= WINDOW_HEIGHT - GROUND_HEIGHT - player->base.height) {
        player->base.y = WINDOW_HEIGHT - GROUND_HEIGHT - player->base.height;
        player->vel_y = 0;
        player->is_jumping = false;
    }

    // Mover el obstáculo hacia la izquierda
    obstacle->base.x += obstacle->vel_x * delta_time;

    // Si el obstáculo sale de la pantalla, reaparece a la derecha
    if (obstacle->base.x + obstacle->base.width < 0) {
        obstacle->base.x = WINDOW_WIDTH;
    }

    // Detectar colisión entre el jugador y el obstáculo
    if (player->base.x < obstacle->base.x + obstacle->base.width &&
        player->base.x + player->base.width > obstacle->base.x &&
        player->base.y < obstacle->base.y + obstacle->base.height &&
        player->base.y + player->base.height > obstacle->base.y) {
        // Si hay colisión, termina el juego
        game_is_running = false;
        printf("Perdiste.\n");
    }
}

// Renderiza los objetos en la pantalla
void render(Player* player, Obstacle* obstacle) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Fondo negro
    SDL_RenderClear(renderer);

    // Dibujar el jugador
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_Rect player_rect = { (int)player->base.x, (int)player->base.y, (int)player->base.width, (int)player->base.height };
    SDL_RenderFillRect(renderer, &player_rect);

    // Dibujar el obstáculo
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_Rect obstacle_rect = { (int)obstacle->base.x, (int)obstacle->base.y, (int)obstacle->base.width, (int)obstacle->base.height };
    SDL_RenderFillRect(renderer, &obstacle_rect);

    SDL_RenderPresent(renderer); // Mostrar en pantalla
}

// Destruye la ventana y limpia la memoria
void destroy_window(void) {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
