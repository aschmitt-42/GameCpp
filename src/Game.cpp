#include "Game.hpp"

Game::Game(int width, int height)
{
    this->Player_1 = new Player(10, height / 2, 1, "jean");
    this->Player_2 = new Player(width - 20, height / 2 , 2, "anouk");
    this->Balle = new Ball(400, 300, 20 , 2.0f, 2.0f);
    this->width = width;
    this->height = height;
    this->score = 0;
    this->a = 1;
    InitWindow(this->width, this->height, "Balle rebondissante");
    SetTargetFPS(144);
}

Game::~Game()
{
    delete Player_1;
    delete Player_2;
    delete Balle;
}

void Game::restart()
{
    BeginDrawing();
    ClearBackground(GREEN);
    DrawCircle(Balle->GetX(), Balle->GetY(), Balle->GetRadius(), RED);
    DrawRectangle(Player_1->GetX(), Player_1->GetY(), Player_1->GetHeight(), Player_1->GetWidth(), YELLOW);  // Joueur 1
    DrawRectangle(Player_2->GetX(), Player_2->GetY(), Player_2->GetHeight(), Player_2->GetWidth(), YELLOW);  // Joueur 2
    DrawText(TextFormat("BANDE DE NULL"), 200, 275, 50, BLACK);
    EndDrawing();
    std::this_thread::sleep_for(std::chrono::seconds(3));
    Balle->restart();
    score = 0;
}

void Game::CollisionGauche()
{
    if (Balle->GetX() - Balle->GetRadius() <= Player_1->GetX() + Player_1->GetHeight() &&   // Si la balle touche le bord droit de la raquette
        Balle->GetY() >= Player_1->GetY() && Balle->GetY() <= Player_1->GetY() + Player_1->GetWidth()) {  // Si la balle est à la bonne hauteur
        Balle->BounceX(); // Inverser la direction horizontale
        if (Balle->GetY() >= Player_1->GetY() + (Player_1->GetWidth() / 2) )
            Balle->BounceY();
        score++;
        a = 1;
    }
}

void Game::CollisionDroite()
{
    if (Balle->GetX() + Balle->GetRadius() >= Player_2->GetX() &&   // Si la balle touche le bord droit de la raquette
        Balle->GetY() >= Player_2->GetY() && Balle->GetY() <= Player_2->GetY() + Player_2->GetWidth()) {  // Si la balle est à la bonne hauteur
        Balle->BounceX(); // Inverser la direction horizontale
        if (Balle->GetY() >= Player_2->GetY() + (Player_2->GetWidth() / 2) )
            Balle->BounceY();
        score++;
        a = 1;
    }
}

void Game::CollisionHautBas()
{
    if (Balle->GetY() >= height - Balle->GetRadius() || Balle->GetY() <= Balle->GetRadius())
        Balle->BounceY();
        
}

void Game::Draw()
{
    int redColorValue = 255;   // La composante rouge reste à 255
    int greenColorValue = 155; // La composante verte commence à 255 (beige/jaune clair)
    int blueColorValue = 200; 
    // int decrementValue = 50;

    BeginDrawing();
        
    ClearBackground((Color){ (unsigned char)redColorValue, (unsigned char)greenColorValue, (unsigned char)blueColorValue, 255 });

    DrawCircle(Balle->GetX(), Balle->GetY(), Balle->GetRadius(), RED);

    DrawRectangle(Player_1->GetX(), Player_1->GetY(), Player_1->GetHeight(), Player_1->GetWidth(), YELLOW);  // Joueur 1
    DrawRectangle(Player_2->GetX(), Player_2->GetY(), Player_2->GetHeight(), Player_2->GetWidth(), YELLOW);  // Joueur 2
        
    DrawText(TextFormat("%d", score), 400, 275, 50, WHITE);

    EndDrawing();
}

void Game::Incrementation()
{
    if (score && score%5 == 0 && a){
        Balle->SpeedUp();
        a = 0;
    }
}

void Game::run()
{
    while (!WindowShouldClose()) {

        if (Balle->GetX() < 0 || Balle->GetX() > width)
            this->restart();

        Balle->SetX( Balle->GetX() + Balle->GetSpeedx() ); // faire avancer la balle
        Balle->SetY( Balle->GetY() + Balle->GetSpeedy() ); // faire avancer la balle
        
        if (IsKeyDown(KEY_W))
            Player_1->Up();
        
        if (IsKeyDown(KEY_S))
            Player_1->Down();

        if (IsKeyDown(KEY_UP))
            Player_2->Up();

        if (IsKeyDown(KEY_DOWN)) 
            Player_2->Down();

        this->CollisionGauche();
        this->CollisionDroite();
        this->CollisionHautBas();

        this->Incrementation();

        this->Draw();
        
    }
    CloseWindow();
}