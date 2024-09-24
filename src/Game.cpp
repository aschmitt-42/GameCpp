#include "Game.hpp"

Game::Game(int width, int height)
{
    this->Player_1 = new Player(10, height / 2, 1, "jean");
    this->Player_2 = new Player(width - 10 - 41, height / 2 , 2, "anouk");
    this->Balle = new Ball(400, 300, 15 , 2.0f, 2.0f);
    this->width = width;
    this->height = height;
    this->score = 0;
    this->a = 1;
    this->end = 0;
    InitWindow(this->width, this->height, "Balle rebondissante");
    SetTargetFPS(144);
    this->Texture2 = LoadTexture("assets/image2.png");
    this->Texture1 = LoadTexture("assets/image1.png");
}

Game::~Game()
{
    delete Player_1;
    delete Player_2;
    delete Balle;
    // UnloadTexture(this->paddleTexture);
}

// void Game::restart()
// {
//     const char* text = "LOOSER";
//     int textHeight = 50;
//     int textWidth = MeasureText(text, textHeight);

//     Color buttonColor = LIGHTGRAY;
//     Color textColor = BLACK;
    

//     // Définir la position et la taille du bouton
//     Rectangle button = { 350, 250, 100, 50 }; // x, y, width, height
//     const char* buttonText = "Cliquez-moi";
//     int te = MeasureText(buttonText, 20);
//     bool isHover = CheckCollisionPointRec(GetMousePosition(), button);

//     BeginDrawing();
//     ClearBackground(RED);
    
//     DrawTexture(Texture1, Player_1->GetX(), Player_1->GetY(), RED);
//     DrawTexture(Texture2, Player_2->GetX(), Player_2->GetY(), RED);

//     DrawCircle(Balle->GetX(), Balle->GetY(), Balle->GetRadius(), BLACK);
    
//     DrawRectangleRec(button, buttonColor);
    
//     DrawText(buttonText, button.x + (button.width - te) / 2, button.y + 15, 15, textColor);

//     DrawText(TextFormat("LOOSER"), (width - textWidth) / 2, (height - textHeight) / 2, textHeight, BLACK); // 200 275
//     EndDrawing();
    
//     while (!WindowShouldClose())
//     {
//         isHover = CheckCollisionPointRec(GetMousePosition(), button);
//         if (isHover) 
//         {
            
//             buttonColor = GRAY; // Couleur du bouton au survol
//             if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
//                 std::cout << "bouton cliqué" << std::endl;
//                 break;
//             }
//         }
//         else {
//             buttonColor = LIGHTGRAY; // Couleur par défaut
//         }
//     }
//     Balle->restart();
//     score = 0;
// }

void Game::restart()
{
    const char* text = "LOSER";
    int textHeight = 50;
    int textWidth = MeasureText(text, textHeight);

    Color buttonColor = LIGHTGRAY;
    Color textColor = BLACK;

    // Définir la position et la taille du bouton
    Rectangle button = { 350, 300, 100, 50 }; // x, y, width, height
    const char* buttonText = "REPLAY";
    int te = MeasureText(buttonText, 15);

    // Boucle de rendu et détection du clic sur le bouton
    while (!WindowShouldClose())
    {
        // Vérifier si la souris est sur le bouton
        bool isHover = CheckCollisionPointRec(GetMousePosition(), button);

        // Changer la couleur du bouton si la souris est dessus
        if (isHover) 
        {
            buttonColor = GRAY; // Couleur du bouton au survol

            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) 
            {
                std::cout << "Bouton cliqué ! Réinitialisation du jeu." << std::endl;
                break; // Quitter la boucle et relancer le jeu
            }
        } 
        else
            buttonColor = LIGHTGRAY;


        // Démarrer le dessin
        BeginDrawing();
        ClearBackground(RED);

        // Dessiner les textures des joueurs et la balle
        DrawTexture(Texture1, Player_1->GetX(), Player_1->GetY(), RED);
        DrawTexture(Texture2, Player_2->GetX(), Player_2->GetY(), RED);
        DrawCircle(Balle->GetX(), Balle->GetY(), Balle->GetRadius(), BLACK);

        // Dessiner le bouton
        DrawRectangleRec(button, buttonColor);
        DrawText(buttonText, button.x + (button.width - te) / 2, button.y + 15, 15, textColor);

        // Dessiner le texte "LOOSER"
        DrawText(text, (width - textWidth) / 2, (height - textHeight) / 2 - 50, textHeight, BLACK);

        EndDrawing();
    }

    // Réinitialiser la balle et le score
    Balle->restart();
    score = 0;
}


void Game::CollisionGauche()
{
    float prevBallPosX = Balle->GetX() - Balle->GetSpeedx();
    
    if (Balle->GetX() - Balle->GetRadius() <= Player_1->GetX() + Player_1->GetHeight() && 
        prevBallPosX - Balle->GetRadius() > Player_1->GetX() + Player_1->GetHeight())
    {
        // Vérification si la balle est dans la zone verticale de la raquette
        if (Balle->GetY() >= Player_1->GetY() - 15 && Balle->GetY() <= Player_1->GetY() + Player_1->GetWidth() + 15)
        {
            Balle->BounceX();
            Balle->SetX(Player_1->GetX() + Player_1->GetHeight() + Balle->GetRadius()); // Ajuster la position de la balle pour éviter qu'elle traverse la raquette

            if (Balle->GetY() >= Player_1->GetY() + (Player_1->GetWidth() / 2))
                Balle->BounceY();

            score++;
            a = 1;
        }
    }
}


void Game::CollisionDroite()
{
    float prevBallPosX = Balle->GetX() - Balle->GetSpeedx();

    if (Balle->GetX() + Balle->GetRadius() >= Player_2->GetX() && prevBallPosX + Balle->GetRadius() < Player_2->GetX())
    {
        // Vérification si la balle est dans la zone verticale de la raquette
        if (Balle->GetY() >= Player_2->GetY() - 15  && Balle->GetY() <= Player_2->GetY() + Player_2->GetWidth() + 15)
        {
            Balle->BounceX();
            Balle->SetX(Player_2->GetX() - Balle->GetRadius()); // Ajuster la balle pour éviter qu'elle traverse la raquette

            if (Balle->GetY() >= Player_2->GetY() + (Player_2->GetWidth() / 2))
                Balle->BounceY();

            score++;
            a = 1;
        }
    }
}

void Game::CollisionHautBas()
{
    if (Balle->GetY() >= height - Balle->GetRadius() || Balle->GetY() <= Balle->GetRadius())
        Balle->BounceY();
        
}

void Game::Draw()
{
    Color fond = (Color){ (unsigned char)255, (unsigned char)100, (unsigned char)200, 255 };

    BeginDrawing();
    
    ClearBackground(fond);

    DrawTexture(Texture1, Player_1->GetX(), Player_1->GetY(), fond);
    DrawTexture(Texture2, Player_2->GetX(), Player_2->GetY(), fond);

    DrawCircle(Balle->GetX(), Balle->GetY(), Balle->GetRadius(), BLACK);

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

        if (Balle->GetX() < 0 || Balle->GetX() > width) {
            this->end = 1;
            this->restart();
        }

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