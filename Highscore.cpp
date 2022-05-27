#include <stdio.h>
#include <SDL.h>
#include <SDL_ttf.h>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include "Painter.h"
#include "mySnake.h"
#include "iostream"

using namespace std;

const int HIGHSCORE_WIDTH = 600 ;
const int HIGHSCORE_HEIGHT= 400 ;
const int posX = 280;
const int posY = 40;

#undef main
bool comp(const int a, const int b){
   return a > b;
}
void loadHighScore()
{
    vector<int> ArrScore=getArrScore();
    /*ifstream file;
    file.open("HighScore.txt");
    int x;
    while(file>>x){
        Arr_Score.push_back(x);
    }*/

    sort(ArrScore.begin(),ArrScore.end(),comp);
	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;
	bool isRunning = true;
	SDL_Event mainEvent;
	TTF_Font* font = NULL;
	SDL_Surface* surface = NULL;
	SDL_Texture* texture = NULL;

	//initializes  the subsystems
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		printf("Unable to initialize SDL %s\n", SDL_GetError());
	}

	//Initialize the truetype font API.
	if (TTF_Init() < 0)
	{
		SDL_Log("%s", TTF_GetError());
	}

	//Create window
	window = SDL_CreateWindow("HighScore", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, HIGHSCORE_WIDTH, HIGHSCORE_HEIGHT, SDL_WINDOW_SHOWN);
	if (window == NULL)
	{
		printf("Could not create window %s", SDL_GetError());
	}

	//create a renderer
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == NULL)
	{
		printf("Could not create render %s", SDL_GetError());
	}
	Painter painter(window, renderer);
    painter.clearWithBgColor(CYAN_COLOR );

    for(int i=0;i<=ArrScore.size();i++){
        font = TTF_OpenFont("mono0755.ttf", 20);
        SDL_Color fg = MEDIUMPURPLE3_COLOR;
        bool isRunning = true;
        stringstream ss;
        string text;
        if(i==0){
            ss<<"HIGHSCORE";
            getline(ss,text);
        }
        if(i>=1){
            ss<<i<<":"<<ArrScore[i-1];
            getline(ss,text);
        }
        if(i==0){
            fg = {0, 0, 0};
            font = TTF_OpenFont("mono0755.ttf",30);
        }
        if(i==1 || i==2 || i==3) fg={255,215,0};
        surface = TTF_RenderText_Solid(font, text.c_str(), fg);
        texture = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_FreeSurface(surface);

        SDL_Rect srcRest;
        SDL_Rect desRect;
        TTF_SizeText(font, text.c_str(), &srcRest.w, &srcRest.h);

        srcRest.x = 0;
        srcRest.y = 0;

        desRect.x = posX;
        desRect.y = i*posY;
        if(i==0) desRect.x=210;
        desRect.w = srcRest.w;
        desRect.h = srcRest.h;

        //set background color
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        //main loop
        SDL_RenderCopy(renderer, texture, &srcRest, &desRect);
            //draw to screen
        SDL_RenderPresent(renderer);
        //int i=
        while (isRunning)
        {
            if(i!=ArrScore.size()) isRunning=false;
            //if(i==0) isRunning=false;
            if(i==0 && ArrScore.size()==0) isRunning=true;
            //main event
            while (SDL_PollEvent(&mainEvent))
            {
                switch (mainEvent.type)
                {
                    //User - requested quit
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
            //SDL_RenderClear(renderer);
            //Copy a portion of the texture to the current rendering target.
            SDL_RenderCopy(renderer, texture, &srcRest, &desRect);
            //draw to screen
            SDL_RenderPresent(renderer);
            SDL_Delay(500);
            isRunning = false;


        }

    }
    SDL_Delay(2500);

	//Destroy a window.
	SDL_DestroyWindow(window);
	//Destroy a renderer
	SDL_DestroyRenderer(renderer);
	//Shutdown and cleanup the truetype font API.
	TTF_Quit();
	//cleans up all initialized subsystems
	SDL_Quit();
	//return 0;
}
