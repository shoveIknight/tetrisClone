#include "TetrisGame.h"

void TetrisGame::start_tetris()
{
	Tetris newTetris;
	bool gameLoop = false;
	Pieces newPiece, nextPiece;
	SDL_Event e;
	newTetris.Init();
	nextPiece.setType(rand() % 7, rand() % 4);
	nextPiece.setColor(rand() % 200 + 50, rand() % 200 + 50, rand() % 200 + 50);
	bool new_piece = false;
	while (!gameLoop) {
		if (new_piece == false) {
			newPiece = nextPiece;
			Pieces tmpPiece;
			nextPiece = tmpPiece;
			nextPiece.setType(rand() % 7, rand() % 4);
			nextPiece.setColor(rand() % 200 + 50, rand() % 200 + 50, rand() % 200 + 50);
			new_piece = true;
		}
		while (SDL_PollEvent(&e) != 0)
		{
			newTetris.draw(newPiece, nextPiece);
			if (e.type == SDL_QUIT)
			{
				gameLoop = true;
			}
			else if (e.type == SDL_KEYDOWN) {
				if (e.key.keysym.sym == SDLK_DOWN) {
					if (!newTetris.check_collision(newPiece.getX(), newPiece.getY() + 1, newPiece)) {
						newPiece.incY();
					}
					newTetris.clear();
					newTetris.draw(newPiece, nextPiece);
					newTetris.delay(50);
				}
				else if (e.key.keysym.sym == SDLK_RIGHT) {
					if (!newTetris.check_collision(newPiece.getX() + 1, newPiece.getY(), newPiece)) {
						newPiece.incX();
					}
					newTetris.clear();
					newTetris.draw(newPiece, nextPiece);
					newTetris.delay(50);
				}
				else if (e.key.keysym.sym == SDLK_LEFT) {
					if (!newTetris.check_collision(newPiece.getX() - 1, newPiece.getY(), newPiece)) {
						newPiece.decX();
					}
					newTetris.clear();
					newTetris.draw(newPiece, nextPiece);
					newTetris.delay(50);
				}
				else if (e.key.keysym.sym == SDLK_UP) {
					Pieces tmpPiece = newPiece;
					tmpPiece.rotateRight();
					if (!newTetris.check_collision(tmpPiece.getX(), tmpPiece.getY(), tmpPiece)) {
						newPiece.rotateRight();
					}
					newTetris.clear();
					newTetris.draw(newPiece, nextPiece);
					newTetris.delay(50);
				}
				else
				{
					if (!newTetris.check_collision(newPiece.getX(), newPiece.getY() + 1, newPiece)) {
						newPiece.incY();
						newTetris.delay(150);
						newTetris.clear();
						newTetris.draw(newPiece, nextPiece);
					}
					else
					{
						newTetris.update(newPiece);
						new_piece = false;
						newTetris.checkTetris();
						newTetris.clear();
						newTetris.draw(newPiece, nextPiece);
					}
				}
			}

		}
		if (!newTetris.check_collision(newPiece.getX(), newPiece.getY() + 1, newPiece)) {
			newPiece.incY();
			newTetris.delay(150);
			newTetris.clear();
			newTetris.draw(newPiece, nextPiece);
		}
		else
		{
			newTetris.update(newPiece);
			new_piece = false;
			newTetris.checkTetris();
			newTetris.clear();
			newTetris.draw(newPiece, nextPiece);
		}

		if (1) //newTetris.checkGameOver() )
		{
			//newTetris.draw()
		}

	}
	newTetris.quit();
}