#include "game/Game.h"

int main() {
    Game game;
    while (game.isRunning()) {
        game.update();
        game.draw();
    }
    return 0;
}
