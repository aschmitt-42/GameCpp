#ifndef PLAYER_HPP
# define PLAYER_HPP

# include "iostream"
# include "raylib.h"

class Player 
{
    private :
        int posX;
        int posY;
        int speed = 5;
        int Width = 100;
        int Height = 10;
        int score = 0;
        int a = 1;
        int num;
        std::string name;
        
    public :
        Player(int x, int y, int num, int name);

};

#endif