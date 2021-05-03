#include "pieces.h"

int Pieces::getX()
{
	return x;
}


void Pieces::setType(int x, int y ) // x is the pieces type I L etc. and y is the rotation of the piece
{
	type = x;
	for (int i = 0; i < 4; i++)
	{
		int m = shape[y][x][i] / 4;
		int n = shape[y][x][i] % 4;
		real_shape[m][n] = 1;
	}
	rotate = y;
}

int Pieces::getY()
{
	return y;
}

void Pieces::incY() //moves piece to down
{
	y += 1;
}

void Pieces::incX() //moves piece to right
{
	x += 1;
}

void Pieces::decX() //moves piece to left
{
	x -= 1;
}

void Pieces::rotateRight() //rotates piece in clockwise by 90 degrees
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			real_shape[i][j] = 0;
		}
	}

	for (int i = 0; i < 4; i++)
	{
		int m = shape[(rotate + 1) % 4][type][i] / 4;
		int n = shape[(rotate + 1) % 4][type][i] % 4;
		real_shape[m][n] = 1;
	}
	rotate = (rotate + 1) % 4;
}

bool Pieces::getRealShape(int x, int y)
{
	return real_shape[x][y];
}

void Pieces::setColor(int r, int g, int b)
{
	color_r = r;
	color_g = g;
	color_b = b;
}

int Pieces::getR()
{
	return color_r;
}

int Pieces::getG()
{
	return color_g;
}

int Pieces::getB()
{
	return color_b;
}