#include <stdio.h>
#include <SDL.h>
#include <SDL_ttf.h>
#include <string>
#include <sstream>
#include "Score.h"
#include "mySnake.h"
#undef main

using namespace std;

int x= 75;
int y= 100;
int sizeOfText=50;

int loadScore()
{
    string Text="YOUR SCORE:";
    stringstream ss;
    ss<<getScore();
    string s;
    ss>>s;
    Text+=s;
	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;
	bool isRunning = true;
	SDL_Event mainEvent;
	TTF_Font* font = NULL;
	SDL_Surface* surface = NULL;
	SDL_Texture* texture = NULL;
	if (SDL_Init(SDL_INIT_EVERYTHING)<0)
	{
		printf("Unable to initialize SDL %s\n", SDL_GetError());
	}

	if (TTF_Init() < 0)
	{
		SDL_Log("%s", TTF_GetError());
	}


	window = SDL_CreateWindow("SCORE", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 700 , 300, SDL_WINDOW_SHOWN);
	if (window == NULL)
	{
		printf("Could not create window %s", SDL_GetError());
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == NULL)
	{
		printf("Could not create render %s", SDL_GetError());
	}
	Painter painter(window, renderer);
    painter.clearWithBgColor(AntiqueWhite_COLOR);
	font = TTF_OpenFont("scoreFont.ttf", sizeOfText);

	SDL_Color fg =INDIANRED1_COLOR;

	string text = Text;
	surface = TTF_RenderText_Solid(font, text.c_str(), fg);
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);

	SDL_Rect srcRest;
	SDL_Rect desRect;
	TTF_SizeText(font, text.c_str(), &srcRest.w, &srcRest.h);

	srcRest.x = 0;
	srcRest.y =  0;

	desRect.x = x;
	desRect.y = y;

	desRect.w = srcRest.w;
	desRect.h = srcRest.h;


	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	while (isRunning)
	{
		while (SDL_PollEvent(&mainEvent))
		{
			switch (mainEvent.type)
			{

				case SDL_QUIT:
				{
					isRunning = false;
					break;
				}
				default:
				{
					break;
				}
			}
		}
		SDL_RenderCopy(renderer, texture, &srcRest, &desRect);
		SDL_RenderPresent(renderer);
		SDL_Delay(2000);
		isRunning = false;
	}
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	TTF_Quit();
	//SDL_Quit(); //quit ở đây là renderGameover k chạy luôn

}
