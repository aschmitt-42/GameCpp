#include "Game.hpp"
# include "raylib.h"



int main() {
    InitWindow(800, 600, "Balle rebondissante");

    // Position et vitesse initiales de la balle
    int ballPosX = 400;
    int ballPosY = 300;
    int ballRadius = 20;

    int ballSpeedX = 4;
    int ballSpeedY = 4;

    SetTargetFPS(60);  // Limite à 60 FPS

    while (!WindowShouldClose()) {
        // Déplacer la balle
        ballPosX += ballSpeedX;
        ballPosY += ballSpeedY;

        // Rebondir sur les bords
        if (ballPosX >= 800 - ballRadius || ballPosX <= ballRadius) ballSpeedX *= -1;  // Bords gauche et droit
        if (ballPosY >= 600 - ballRadius || ballPosY <= ballRadius) ballSpeedY *= -1;  // Bords haut et bas

        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Dessiner la balle
        DrawCircle(ballPosX, ballPosY, ballRadius, RED);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}



// int main()
// {
    
//     InitWindow(800, 600, "Déplacer un carré");

//     // Position initiale du carré
//     int posX = 10;
//     int posY = 275;
//     int posx = 780;
//     int posy = 275;
//     int speed = 10;  // Vitesse de déplacement
//     int squareSize = 50;

//     SetTargetFPS(60);  // Limite à 60 FPS

//     while (!WindowShouldClose()) {
//         // Déplacement du carré avec les touches fléchées
//         if (IsKeyDown(KEY_UP)){
//             posY -= speed;
//             if (posY < 0) posY = 0;}

//         if (IsKeyDown(KEY_DOWN)){
//             posY += speed;
//             if (posY + squareSize > GetScreenHeight()) posY = GetScreenHeight() - squareSize;} 

//         if (IsKeyDown(KEY_W)){
//             posy -= speed;
//             if (posy < 0) posy = 0;}

//         if (IsKeyDown(KEY_S)){
//             posy += speed;
//             if (posy + squareSize > GetScreenHeight()) posy = GetScreenHeight() - squareSize;} 

//         BeginDrawing();
//         ClearBackground(GREEN);

//         // Dessiner le carré à la nouvelle position
//         DrawRectangle(posX, posY, 10, squareSize, YELLOW);
//         DrawRectangle(posx, posy, 10, squareSize, YELLOW);

//         EndDrawing();
//     }

//     CloseWindow();
//     return 0;
// }