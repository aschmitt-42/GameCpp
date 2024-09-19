#include "Ball.hpp"

Ball::Ball(int x, int y, int radius, float speedX, float speedY) 
    : X(x), Y(y), Radius(radius), SpeedX(speedX), SpeedY(speedY) { }

Ball& Ball::operator=(const Ball &tmp)
{
    this->X = tmp.X;
    this->Y = tmp.Y;
    this->Radius = tmp.Radius;
    this->SpeedX = tmp.SpeedX;
    this->SpeedY = tmp.SpeedY;
    return *this;
}

Ball::~Ball()
{
    std::cout << "Destructor Ball called" << std::endl; 
}

int Ball::GetX() { return ( X );}
int Ball::GetY() { return ( Y );}
float Ball::GetSpeedy() { return ( SpeedY );}
float Ball::GetSpeedx() { return ( SpeedX );}
int Ball::GetRadius() { return ( Radius );}

void Ball::SetX(int n) { X = n;}
void Ball::SetY(int n) { Y = n;}

void Ball::restart()
{
    X = 400;
    Y = 300;
    SpeedX = 2.0f;
    SpeedY = 2.0f;
}

void Ball::BounceX()
{
    SpeedX *= -1;
}

void Ball::BounceY()
{
    SpeedY *= -1;
}

void Ball::SpeedUp()
{
    if (SpeedX < 0) 
        SpeedX -= 0.5f;
    else 
        SpeedX += 0.5f;
}
