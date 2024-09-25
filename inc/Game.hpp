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
        Player  *Player_1;
        Player  *Player_2;
        Ball    *Balle;
        int     width;
        int     height;
        int     score;
        int     a;
        int     end;
        Texture2D Texture1;
        Texture2D Texture2;
        Color BackColor;
        
    public :
        Game(int width, int height);
        ~Game();
        void run();
        void restart();
        void CollisionGauche();
        void CollisionDroite();
        void CollisionHautBas();
        void Draw();
        void Incrementation();
        void StartPlayer();
        void SaisieNoms(std::string &nomJoueur1, std::string &nomJoueur2);
};

#endif