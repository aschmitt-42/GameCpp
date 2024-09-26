#ifndef BALL_HPP
# define BALL_HPP

# include "iostream"
# include "raylib/src/raylib.h"


class Ball 
{
	private :
		int		X;
		int		Y;
		int		Radius;
		float	SpeedX;
		float	SpeedY;
	public :
		Ball(int x, int y, int radius, float speedX, float speedY);
		Ball& operator=(const Ball &tmp);
		~Ball();
		int GetX();
		int GetY();
		float GetSpeedy();
		float GetSpeedx();
		int GetRadius();
		void	SetX(int n);
		void	SetY(int n);

		void restart();
		void BounceX();
		void BounceY();
		void SpeedUp();

};

#endif