#pragma once
#include <SDL2/SDL.h>
#include <iostream>
#include <vector>
class Pieces
{
public:

	int getX();
	void setType(int x, int y = 0);
	int getY();
	void incY();
	void incX();
	void decX();
	void rotateRight();
	bool getRealShape(int x, int y);
	void setColor(int, int, int);
	int getR();
	int getG();
	int getB();
private:

	bool real_shape[4][4];
	int x=7, y=1,rotate = 0, type;
	int shape[4][7][4] = 
	{ 
	  { {1, 5, 9, 13}, {1, 5, 9, 6}, {1, 5, 6, 10} , {1, 5, 9, 8}, {0, 4, 8, 9}, {1, 4, 5, 8}, {0, 1, 4, 5} },
	  { {4, 5, 6, 7},  {4, 5, 6, 9}, {2, 3, 5, 6} ,  {0, 4, 5, 6}, {4, 5, 6, 8}, {0, 1, 5, 6}, {0, 1, 4, 5} },
	  { {1, 5, 9, 13}, {1, 4, 5, 9}, {2, 6, 7, 11} , {0, 1, 4, 8}, {0, 1, 5, 9}, {1, 4, 5, 8}, {0, 1, 4, 5} },
	  { {4, 5, 6, 7},  {1, 4, 5, 6}, {2, 3, 5, 6} ,  {0, 1, 2, 6}, {2, 4, 5, 6}, {0, 1, 5, 6}, {0, 1, 4, 5} },
	};
	int color_r, color_g, color_b;

};

