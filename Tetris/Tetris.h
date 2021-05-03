#pragma once
#include <SDL.h>
#include <iostream>
#include "Pieces.h"
#include "Renderer.h"
#include <SDL.h>
#include "Color.h"
class Tetris
{
public:

	void Init();
	void clear();
	void draw(Pieces piece, Pieces next_piece);
	void update(Pieces piece);
	bool check_collision(int m, int n, Pieces piece);
	void delay(int n);
	void quit();
	void checkTetris();

private:
	Color board[32][18];
	Renderer newGame;
};

