#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include <stdbool.h>

// Constantes del juego
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define GROUND_HEIGHT 100
#define FPS 60
#define FRAME_TARGET_TIME (1000 / FPS)

// Variable global para el estado del juego
extern bool game_is_running; // Declaraci�n de la variable global

// Estructura para representar los atributos compartidos de los objetos del juego
typedef struct {
    float x, y;          // Posici�n del objeto
    float width, height; // Tama�o del objeto
} GameObject;

// Estructura del jugador
typedef struct {
    GameObject base;     // Hereda posici�n y tama�o de GameObject
    int vel_y;           // Velocidad vertical del jugador
    bool is_jumping;     // Estado de salto
} Player;

// Estructura del obst�culo
typedef struct {
    GameObject base;     // Hereda posici�n y tama�o de GameObject
    float vel_x;         // Velocidad horizontal del obst�culo
} Obstacle;

// Declaraci�n de funciones
int initialize_window(void);
void process_input(Player* player, bool* game_is_running);
void setup(Player* player, Obstacle* obstacle);
void update(Player* player, Obstacle* obstacle);
void render(Player* player, Obstacle* obstacle);
void destroy_window(void);

#endif
