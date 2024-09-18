#ifndef BALL_HPP
# define BALL_HPP

# include "iostream"
# include "raylib.h"


class Ball 
{
	private :
		int		ballPosX;
		int		ballPosY;
		int		ballRadius;
		float	ballSpeedX;
		float	ballSpeedY;
	public :
		Ball(int x, int y, int radius, int speedX, int speedY);

};

#endif