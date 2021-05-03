#pragma once
#include <SDL.h>
#include <iostream>
#include <SDL_image.h>
#include <string>

#define SCREEN_WIDTH 1920
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
	void loadSurface(std::string path);
	void loadTexture(std::string path);
	void updateRender();
	SDL_Renderer* getRenderer();
	void setTexture(); 
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

