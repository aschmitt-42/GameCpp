#include "Player.hpp"

Player::Player(int x, int y, int num, int name)
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