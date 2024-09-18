#include "Ball.hpp"

Ball::Ball(int x, int y, int radius, int speedX, int speedY) 
    : ballPosX(x), ballPosY(y), ballRadius(radius), ballSpeedX(speedX), ballSpeedY(speedY) { }

Ball& Ball::operator=(const Ball &tmp)
{
    this->ballPosX = tmp.ballPosX;
    this->ballPosY = tmp.ballPosY;
    this->ballRadius = tmp.ballRadius;
    this->ballSpeedX = tmp.ballSpeedX;
    this->ballSpeedY = tmp.ballSpeedY;
    return *this;
}