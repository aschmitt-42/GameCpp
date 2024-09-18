#include "Game.hpp"
# include "raylib.h"


#include "raylib.h"

int main() {
    InitWindow(800, 600, "Balle rebondissante");

    // Position et vitesse initiales de la balle
    int ballPosX = 400;
    int ballPosY = 300;
    int ballRadius = 20;

    float ballSpeedX = 2.0f;
    float ballSpeedY = 2.0f;

    // initialisation pour les joueurs 
    int posX = 10;
    int posY = 275;
    int posx = 780;
    int posy = 275;
    int speed = 5;  // Vitesse de déplacement
    int paddleWidth = 100;   // Largeur des raquettes (hauteur du rectangle)
    int paddleHeight = 10;   // Hauteur des raquettes (largeur du rectangle)
    int a = 1;
    // float speedIncrement = 0.5f;  // Incrément de la vitesse après chaque collision

    int n = 0;
    SetTargetFPS(144);  // Limite à 144 FPS

    // Couleur initiale du fond (beige/jaune clair)
    int redColorValue = 255;   // La composante rouge reste à 255
    int greenColorValue = 255; // La composante verte commence à 255 (beige/jaune clair)
    int blueColorValue = 200;  // La composante bleue reste fixe à 200 pour garder un ton chaud
    int decrementValue = 50; 

    while (!WindowShouldClose()) {
        // Déplacer la balle

        if (ballPosX < 0 || ballPosX > 800)
        {
            BeginDrawing();
            ClearBackground(GREEN);
            DrawCircle(ballPosX, ballPosY, ballRadius, RED);
            DrawRectangle(posX, posY, paddleHeight, paddleWidth, YELLOW);  // Joueur 1
            DrawRectangle(posx, posy, paddleHeight, paddleWidth, YELLOW);  // Joueur 2
            DrawText(TextFormat("BANDE DE NULL"), 200, 275, 50, BLACK);
            EndDrawing();
            std::this_thread::sleep_for(std::chrono::seconds(3));
            ballPosX = 400;
            ballPosY = 300;
            ballSpeedX = 2.0f;
            ballSpeedY = 2.0f;
            n = 0;
        }
        ballPosX += ballSpeedX;
        ballPosY += ballSpeedY;

        // Rebondir sur les bords supérieur et inférieur
        if (ballPosY >= 600 - ballRadius || ballPosY <= ballRadius) ballSpeedY *= -1;

        // Détection des touches pour les deux joueurs
        if (IsKeyDown(KEY_UP)) {
            posY -= speed;
            if (posY < 0) posY = 0;
        }
        if (IsKeyDown(KEY_DOWN)) {
            posY += speed;
            if (posY + paddleWidth > GetScreenHeight()) posY = GetScreenHeight() - paddleWidth;
        }
        if (IsKeyDown(KEY_W)) {
            posy -= speed;
            if (posy < 0) posy = 0;
        }
        if (IsKeyDown(KEY_S)) {
            posy += speed;
            if (posy + paddleWidth > GetScreenHeight()) posy = GetScreenHeight() - paddleWidth;
        }

        // Collision avec la raquette gauche (joueur 1)
        if (ballPosX - ballRadius <= posX + paddleHeight &&   // Si la balle touche le bord droit de la raquette
            ballPosY >= posY && ballPosY <= posY + paddleWidth) {  // Si la balle est à la bonne hauteur
            ballSpeedX *= -1;  // Inverser la direction horizontale
            if (ballPosY >= posY + (paddleWidth / 2) )
                ballSpeedY *= -1;
            n++;
            a = 1;
        }
        
        // Collision avec la raquette droite (joueur 2)
        if (ballPosX + ballRadius >= posx &&   // Si la balle touche le bord gauche de la raquette
            ballPosY >= posy && ballPosY <= posy + paddleWidth) {  // Si la balle est à la bonne hauteur
            ballSpeedX *= -1;  // Inverser la direction horizontale
            if (ballPosY >= posy + (paddleWidth / 2) )
                ballSpeedY *= -1;
            n++;
            a = 1;
        }

        if (n && n%5 == 0 && a)
        {
            if (ballSpeedX < 0) ballSpeedX -= 0.5f;  // Si la balle va vers la gauche
            else ballSpeedX += 0.5f;
            a = 0;
            if (greenColorValue > 0) greenColorValue -= decrementValue;
        }
        
        
        BeginDrawing();
        // ClearBackground(GREEN);
        ClearBackground((Color){ (unsigned char)redColorValue, (unsigned char)greenColorValue, (unsigned char)blueColorValue, 255 });

        // Dessiner la balle
        DrawCircle(ballPosX, ballPosY, ballRadius, RED);

        // Dessiner les raquettes
        DrawRectangle(posX, posY, paddleHeight, paddleWidth, YELLOW);  // Joueur 1
        DrawRectangle(posx, posy, paddleHeight, paddleWidth, YELLOW);  // Joueur 2
        DrawText(TextFormat("%d", n), 400, 275, 50, WHITE);
        EndDrawing();

    }

    CloseWindow();
    return 0;
}


/*
int main() {
    InitWindow(800, 600, "Balle rebondissante");

    // Position et vitesse initiales de la balle
    int ballPosX = 400;
    int ballPosY = 300;
    int ballRadius = 20;

    int ballSpeedX = 1;
    int ballSpeedY = 1;

    // initialisation pour les joueurs 
    int posX = 10;
    int posY = 275;
    int posx = 780;
    int posy = 275;
    int speed = 5;  // Vitesse de déplacement
    int paddleWidth = 50;
    int paddleHeight = 10;

    SetTargetFPS(144);  // Limite à 60 FPS

    while (!WindowShouldClose()) {
        // Déplacer la balle
        ballPosX += ballSpeedX;
        ballPosY += ballSpeedY;

        // Rebondir sur les bords
        // if (ballPosX >= 800 - ballRadius || ballPosX <= ballRadius) ballSpeedX *= -1;  // Bords gauche et droit
        if (ballPosY >= 600 - ballRadius || ballPosY <= ballRadius) ballSpeedY *= -1;  // Bords haut et bas
        
        // detection des touches
        if (IsKeyDown(KEY_UP)){
            posY -= speed;
            if (posY < 0) posY = 0;}

        if (IsKeyDown(KEY_DOWN)){
            posY += speed;
            if (posY + paddleWidth > GetScreenHeight()) posY = GetScreenHeight() - paddleWidth;} 

        if (IsKeyDown(KEY_W)){
            posy -= speed;
            if (posy < 0) posy = 0;}

        if (IsKeyDown(KEY_S)){
            posy += speed;
            if (posy + paddleWidth > GetScreenHeight()) posy = GetScreenHeight() - paddleWidth;} 


        BeginDrawing();
        ClearBackground(GREEN);
        
        // Dessiner la balle
        DrawCircle(ballPosX, ballPosY, ballRadius, RED);

        // dessiner les raquettes
        DrawRectangle(posX, posY, paddleHeight, paddleWidth, YELLOW);
        DrawRectangle(posx, posy, paddleHeight, paddleWidth, YELLOW);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}*/