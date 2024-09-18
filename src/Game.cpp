#include "Game.hpp"

Game::Game(int width, int height)
{
    this->width = width;
    this->height = height;
    this->Player_1 = Player(10, 275, 0, "jean");
    this->Player_2 = Player(780, 275, 0, "anouk");
    this->Balle = Ball(400, 300, 20 , 2.0f, 2.0f);
}