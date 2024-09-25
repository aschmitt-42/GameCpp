#include "Game.hpp"


Game::Game(int width, int height)
{
    this->width = width;
    this->height = height;
    this->BackColor = (Color){ (unsigned char)255, (unsigned char)100, (unsigned char)200, 255 };
    InitWindow(this->width, this->height, "Balle rebondissante");
    SetTargetFPS(144);

    this->end = 0;
    this->StartPlayer();
    this->Balle = new Ball(400, 300, 15 , 2.0f, 2.0f);
    this->score = 0;
    this->a = 1;
    
    
    
}

void Game::StartPlayer()
{
    this->Texture2 = LoadTexture("assets/image2.png");
    this->Texture1 = LoadTexture("assets/image1.png");

    std::string nomJoueur1, nomJoueur2;
    this->SaisieNoms(nomJoueur1, nomJoueur2);

    this->Player_1 = new Player(10, this->height / 2, this->Texture1.height, this->Texture1.width, 1, nomJoueur1);
    this->Player_2 = new Player(width - 10 - this->Texture2.width, this->height / 2, this->Texture2.height, this->Texture2.width, 2, nomJoueur2);
}

void Game::SaisieNoms(std::string &nomJoueur1, std::string &nomJoueur2) 
{
    char joueur1[100] = "\0";  // Pour stocker le nom du joueur 1
    char joueur2[100] = "\0";  // Pour stocker le nom du joueur 2
    int letterCount1 = 0;
    int letterCount2 = 0;

    bool joueur1Saisi = false;
    bool joueur2Saisi = false;
    Color TextColor = (Color){ 50, 50, 50, 255 };        // Couleur du texte
    Color InputTextColor = (Color){ 0, 0, 0, 255 };      // Texte entré par l'utilisateur
    Color BorderColor = (Color){ 200, 200, 200, 255 };   // Bordures des champs

    while ((!joueur1Saisi || !joueur2Saisi) && !WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BackColor);

        // Texte pour le joueur 1
        DrawText("Entrez le nom du joueur 1:", 100, 100, 20, TextColor);
        DrawRectangleLines(95, 145, 300, 40, BorderColor); // Bordure du champ de texte
        DrawText(joueur1, 100, 150, 30, InputTextColor);   // Affiche le nom saisi
        if (joueur1Saisi) {
            DrawText("Nom du joueur 1 saisi!", 100, 200, 20, GREEN);
        }

        // Texte pour le joueur 2
        DrawText("Entrez le nom du joueur 2:", 100, 300, 20, TextColor);
        DrawRectangleLines(95, 345, 300, 40, BorderColor); // Bordure du champ de texte
        DrawText(joueur2, 100, 350, 30, InputTextColor);   // Affiche le nom saisi
        if (joueur2Saisi) {
            DrawText("Nom du joueur 2 saisi!", 100, 400, 20, GREEN);
        }

        // Saisie du nom du joueur 1
        if (!joueur1Saisi) {
            int key = GetCharPressed();
            while (key > 0) {
                if ((key >= 32) && (key <= 125) && (MeasureText(joueur1, 30) < 280)) {
                    joueur1[letterCount1] = (char)key;
                    joueur1[letterCount1 + 1] = '\0';
                    letterCount1++;
                }
                key = GetCharPressed();
            }

            if (IsKeyPressed(KEY_BACKSPACE)) {
                letterCount1--;
                if (letterCount1 < 0) letterCount1 = 0;
                joueur1[letterCount1] = '\0';
            }

            if (IsKeyPressed(KEY_ENTER) && letterCount1 > 0) {
                joueur1Saisi = true;
                nomJoueur1 = joueur1;  // Sauvegarder le nom
            }
        }

        // Saisie du nom du joueur 2
        if (joueur1Saisi && !joueur2Saisi) {
            int key = GetCharPressed();
            while (key > 0) {
                if ((key >= 32) && (key <= 125) && (MeasureText(joueur2, 30) < 280)) {
                    joueur2[letterCount2] = (char)key;
                    joueur2[letterCount2 + 1] = '\0';
                    letterCount2++;
                }
                key = GetCharPressed();
            }

            if (IsKeyPressed(KEY_BACKSPACE)) {
                letterCount2--;
                if (letterCount2 < 0) letterCount2 = 0;
                joueur2[letterCount2] = '\0';
            }

            if (IsKeyPressed(KEY_ENTER) && letterCount2 > 0) {
                joueur2Saisi = true;
                nomJoueur2 = joueur2;  // Sauvegarder le nom
            }
        }

        EndDrawing();
    }
    if (!joueur1Saisi || !joueur2Saisi) {
        this->end = 1;
        nomJoueur1 = "j";
        nomJoueur2 = "j";
    }
}

Game::~Game()
{
    if (Player_1)
        delete Player_1;
    if (Player_2)
        delete Player_2;
    if (Balle)
        delete Balle;
    // UnloadTexture(this->Texture1);
    // UnloadTexture(this->Texture2);
}


void Game::restart()
{
    const char* text = "LOSER";
    int textHeight = 50;
    int textWidth = MeasureText(text, textHeight);

    Color buttonColor = LIGHTGRAY;
    Color textColor = BLACK;

    Rectangle button = { 350, 300, 100, 50 }; // x, y, width, height
    const char* buttonText = "REPLAY";
    int te = MeasureText(buttonText, 20);
    bool isHover = CheckCollisionPointRec(GetMousePosition(), button);

    while (!WindowShouldClose() && this->end)
    {
        
        isHover = CheckCollisionPointRec(GetMousePosition(), button); // Vérifier si la souris est sur le bouton

        if (isHover) 
        {
            buttonColor = GRAY;
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                this->end = 0;
        } 
        else
            buttonColor = LIGHTGRAY;

        BeginDrawing();
        ClearBackground(RED);

        DrawTexture(Texture1, Player_1->GetX(), Player_1->GetY(), RED);
        DrawTexture(Texture2, Player_2->GetX(), Player_2->GetY(), RED);
        DrawCircle(Balle->GetX(), Balle->GetY(), Balle->GetRadius(), BLACK);

        DrawRectangleRec(button, buttonColor);
        DrawText(buttonText, button.x + (button.width - te) / 2, button.y + 15, 20, textColor);

        DrawText(text, (width - textWidth) / 2, (height - textHeight) / 2 - 50, textHeight, BLACK);

        EndDrawing();
    }

    if (this->end == 0) {
        Balle->restart();
        score = 0;
    }
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

    BeginDrawing();
    
    ClearBackground(this->BackColor);

    DrawTexture(Texture1, Player_1->GetX(), Player_1->GetY(), this->BackColor);
    DrawTexture(Texture2, Player_2->GetX(), Player_2->GetY(), this->BackColor);

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
    while (!WindowShouldClose() && this->end == 0) {

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