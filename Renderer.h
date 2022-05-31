#pragma once
#include <SDL2/SDL.h>
#include <iostream>
#include <string>

#define SCREEN_WIDTH 720
#define SCREEN_HEIGTH 1080
class Renderer
{
public:

	Renderer();
	~Renderer();
	bool Init();
	SDL_Window* getWindow();
	void drawRect(SDL_Rect* rect);
	void clear();
	void gameUpdate();
	int getScreenHeight();
	int getScreenWidth();
	void quit();
	void updateRender();
	SDL_Renderer* getRenderer();
	void setTarget();
	void delay(int );

private:
	//const int screen_width = 1280;
	//const int SCREEN_HEIGTH = 960;
	SDL_Window* gameWindow;
	SDL_Surface* gameSurface;
	SDL_Renderer* gameRenderer;
	SDL_Texture* gameTexture;
};

