#include "Tetris.h"
void Tetris::Init()
{
	newGame.Init();
}

void Tetris::clear()
{
	newGame.clear();
}

void Tetris::draw(Pieces piece, Pieces next_piece)
{
	SDL_Rect tmp_rect = { 0, 3, 20 * 18 + 3, 20 * 32 + 3 };  //main outline rectangle
	SDL_SetRenderDrawColor(newGame.getRenderer(), 0xFF, 0, 0x00, 0xFF); //changing color to red
	int m = piece.getX();
	int n = piece.getY();
	SDL_RenderDrawRect(newGame.getRenderer(), &tmp_rect); //drawing outline rectangle
	tmp_rect = { 17 * (20) + 3 * (20 + 1), 17 * (7) + (7) * 3, 17 * 10, 17 * 15 }; //next piece's outline rectangle
	SDL_RenderDrawRect(newGame.getRenderer(), &tmp_rect); //drawing next piece's outline rectangle

	//drawing the board
	for (int i = 0; i < 32; i++)
	{
		for (int j = 0; j < 18; j++)
		{
			if (board[i][j].check()) {
				SDL_Rect tmp_rect = { 17 * j + 3 * (j + 1), 17 * i + (i + 1) * 3, 17, 17 };
				SDL_SetRenderDrawColor(newGame.getRenderer(), board[i][j].getR(), board[i][j].getG(), board[i][j].getB(), 0xFF); //changing color to green
				SDL_RenderFillRect(newGame.getRenderer(), &tmp_rect);
			}
		}
	}
	//drawing the board

	//drawing current dropping piece
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (piece.getRealShape(i,j) == 1)
			{
				SDL_Rect tmp_rect = { 17 * (j + m) + 3 * (j + m + 1), 17 * (i + n) + (i + n + 1) * 3, 17, 17 };
				SDL_SetRenderDrawColor(newGame.getRenderer(), piece.getR(), piece.getG(), piece.getB(), 0xFF);
				SDL_RenderFillRect(newGame.getRenderer(), &tmp_rect);
			}
		}
	}
	//drawing current dropping piece

	//drawing next piece that will drop
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (next_piece.getRealShape(i, j) == 1)
			{
				SDL_Rect tmp_rect = { 17 * (j + 23) + 3 * (j + 23 + 1), 17 * (i + 10) + (i + 10 + 1) * 3, 17, 17 };
				//SDL_Rect tmp_rect = { 20 * (m+j), 20 * (n+i), 17, 17 };
				SDL_SetRenderDrawColor(newGame.getRenderer(), next_piece.getR(), next_piece.getG(), next_piece.getB(), 0xFF);
				SDL_RenderFillRect(newGame.getRenderer(), &tmp_rect);
			}
		}
	}
	//drawing next piece that will drop

	newGame.updateRender(); //updating the renderer


}

void Tetris::update(Pieces piece) //when the current dropping object stops we add it to the board matrix
{
	int m = piece.getX();
	int n = piece.getY();
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (piece.getRealShape(i, j) == 1)
			{
				board[n + i][m + j].setCheck();
				board[n + i][m + j].setR(piece.getR());
				board[n + i][m + j].setG(piece.getG());
				board[n + i][m + j].setB(piece.getB());
			}
		}
	}
}


bool Tetris::check_collision(int m, int n, Pieces piece) //checks whether current dropping piece collides with the board if it does returns true else returns false
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (piece.getRealShape(i, j) == 1)
			{
				if (n + i >= 32 || m + j >= 18 || m + j < 0)
					return true;
				else if (board[n + i][m + j].check() == 1)
					return true;
			}
		}
	}
	return false;
}

void Tetris::delay(int n) //delay
{
	SDL_Delay(n);
}

void Tetris::quit() //quit
{
	newGame.quit();
}

void Tetris::checkTetris() //checks wheter there is a full line or not if there is cleans the line
{
	int j;
	bool check = false;
	for (int i = 0; i < 32; i++)
	{
		for (j = 0; j < 18; j++)
		{
			if (board[i][j].check() == 0) {
				break;
			}
		}
		if (j == 18 && board[i][j - 1].check() == 1) {
			check = true;
			for (j = 0; j < 18; j++)
			{
				board[i][j].setUncheck();
			}
		}
		if (check) {
			delay(200);
			for (int k = (i - 1); k >= 0; k--)
			{
				for (j = 0; j < 18; j++)
				{
					if (board[k][j].check() == 1 && board[k + 1][j].check() != 1)
					{
						board[k + 1][j] = board[k][j];
						board[k][j].setUncheck() ;
					}
				}

			}
		}
	}
}