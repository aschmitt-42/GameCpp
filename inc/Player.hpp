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
        int Width;
        int Height;
        int score = 0;
        int num;
        std::string name;
        
    public :
        Player(int x, int y, int w, int h, int num, std::string name);
        ~Player();
        Player& operator=(const Player &tmp);
        int GetX();
        int GetY();
        int GetScore();
        int GetSpeed();
        std::string GetName();
        int GetHeight();
        int GetWidth();
        
        void    Up();
        void    Down();
};

#endif