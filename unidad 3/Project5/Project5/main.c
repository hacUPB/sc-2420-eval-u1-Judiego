#include "Game.h"

int main(int argc, char* argv[]) {
    if (!initialize_window()) {
        return 1;
    }

    Player player;
    Obstacle obstacle;

    setup(&player, &obstacle);

    while (game_is_running) {
        process_input(&player, &game_is_running);
        update(&player, &obstacle);
        render(&player, &obstacle);
    }

    destroy_window();
    return 0;
}
