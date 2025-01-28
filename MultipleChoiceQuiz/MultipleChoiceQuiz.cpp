#include <iostream>

#include "Game.h"

int main()
{
    std::cout.precision(3);

    Quiz::Game game;
    game.play();

    return 0;
}
