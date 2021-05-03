#include <SDL.h>
#include <stdio.h>
#include "Renderer.h"
#include "TetrisGame.h"

int main( int argc, char* args[] )
{
	TetrisGame tetris;
	tetris.start_tetris();
	return 0;
}