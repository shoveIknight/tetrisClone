#include "Renderer.h"

Renderer::Renderer()
{
	gameWindow = NULL;
	gameSurface = NULL;
	gameRenderer = NULL;
	gameTexture = NULL;
}
Renderer::~Renderer()
{
	//delete gameWindow;
	//delete gameSurface;
}
bool Renderer::Init()
{
	bool succsess = true;

	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		std::cout << "error" << SDL_GetError() << std::endl;
		succsess = false;
	}

	else
	{
		gameWindow = SDL_CreateWindow("Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGTH, SDL_WINDOW_SHOWN);

	}

	if (gameWindow == NULL)
	{
		std::cout << "error" << SDL_GetError() << std::endl;
		succsess = false;
	}
	else
	{
		gameRenderer = SDL_CreateRenderer(gameWindow, -1, SDL_RENDERER_SOFTWARE);
		gameSurface = SDL_GetWindowSurface(gameWindow);


		SDL_FillRect(gameSurface, NULL, SDL_MapRGB(gameSurface->format, 0, 0, 0));
	}
	if (gameRenderer == NULL)
	{
		std::cout << "error" << SDL_GetError() << std::endl;
		succsess = false;
	}
	else
	{
		SDL_SetRenderDrawColor(gameRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
	}
	return succsess;
}
SDL_Window* Renderer::getWindow()
{
	return gameWindow;
}
void Renderer::drawRect(SDL_Rect* rect) {
	SDL_FillRect(gameSurface, rect, SDL_MapRGB(gameSurface->format, 0, 0, 255));
}
void Renderer::clear()
{

	//SDL_RenderCopy(gameRenderer, gameTexture, NULL, NULL);
	SDL_SetRenderDrawColor(gameRenderer, 0, 0, 0, 0xFF);
	SDL_RenderClear(gameRenderer);
}
void Renderer::gameUpdate() {
	SDL_UpdateWindowSurface(gameWindow);
}

int Renderer::getScreenHeight() {
	return SCREEN_HEIGTH;
}

int Renderer::getScreenWidth() {
	return SCREEN_WIDTH;
}

void Renderer::quit()
{
	SDL_DestroyTexture(gameTexture);
	gameTexture = NULL;
	SDL_FreeSurface(gameSurface);
	SDL_DestroyWindow(gameWindow);
	gameWindow = NULL;
	gameSurface = NULL;
	SDL_Quit();
	SDL_DestroyRenderer(gameRenderer);
	gameRenderer = NULL;

}



void Renderer::updateRender()
{
	SDL_RenderPresent(gameRenderer);
}

SDL_Renderer* Renderer::getRenderer()
{
	return gameRenderer;
}

void Renderer::setTarget()
{
	SDL_SetRenderTarget(gameRenderer, gameTexture);
}

void Renderer::delay(int n)
{
	SDL_Delay(n);
}