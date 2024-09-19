#include "Player.hpp"

Player::Player(int x, int y, int num, std::string name)
{
    this->posX = x;
    this->posY = y;
    this->num = num;
    this->name = name;
    this->score = 0;
}

Player::~Player(void)
{
    std::cout << "Destructor Player " << this->name << " called" << std::endl;
}

Player& Player::operator=(const Player &tmp)
{
    this->posX = tmp.posX;
    this->posY = tmp.posY;
    this->num = tmp.num;
    this->name = tmp.name;
    this->score = tmp.score;
    return *this;
}

int Player::GetX() { return ( posX );};
int Player::GetY() { return ( posY );};
int Player::GetScore() { return ( score );};
std::string Player::GetName() { return ( name );};
int Player::GetHeight() { return ( Height );};
int Player::GetWidth() { return ( Width );};
int Player::GetSpeed() { return ( speed );};
void Player::Up() {
    posY -= speed;
    if (posY < 0) posY = 0;
};
void Player::Down() {
    posY += speed;
    if (posY + Width > GetScreenHeight()) posY = GetScreenHeight() - Width;
};
