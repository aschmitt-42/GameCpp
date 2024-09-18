#ifndef GAME_HPP
# define GAME_HPP

# include "iostream"
# include "raylib.h"
# include <chrono>
# include <thread>
# include "Ball.hpp"
# include "Player.hpp"

class Game 
{
    private :
        Player  &Player_1;
        Player  &Player_2;
        Ball    Balle;
        int     width;
        int     height;
        int     score;
        int     a;
    public :
        Game(int width, int height);

};

#endif