#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <chrono>
#include <SDL.h>
#include <SDL_image.h>


#include "painter.h"
#include "PlayGround.h"
#include "Collection.h"
#include "Score.h"
#include "HighScore.h"
#include "Audio.h"
#include "mySnake.h"


using namespace std;


const int SCREEN_WIDTH = 900;
const int SCREEN_HEIGHT = 600;
const string WINDOW_TITLE = "Hung's Snake";


const int GROUND_WIDTH = 30;
const int GROUND_HEIGHT = 20;
const int CELL_SIZE = 30;


#define CLOCK_NOW chrono::system_clock::now
typedef chrono::duration<double> ElapsedTime;


const SDL_Rect* srcrect = nullptr;
const SDL_Rect* dstrect = nullptr;


double STEP_DELAY = 0.2;

Collection* collection = nullptr; // global picture manager


void logSDLError(ostream& os, const string &msg, bool fatal)
{
    os << msg << " Error: " << SDL_GetError() << std::endl;
    if (fatal) {
        SDL_Quit();
        exit(1);
    }
}

void initSDL(SDL_Window* &window, SDL_Renderer* &gRenderer)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        logSDLError(cout, "SDL_Init", true);

    window = SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    //window = SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_FULLSCREEN_DESKTOP);

    if (window == nullptr)
        logSDLError(cout, "CreateWindow", true);

    gRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    //SDL_Renderer *gRenderer = SDL_CreateSoftwareRenderer(SDL_GetWindowSurface(window));
    if (gRenderer == nullptr)
        logSDLError(cout, "CreateRenderer", true);

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    SDL_RenderSetLogicalSize(gRenderer, SCREEN_WIDTH, SCREEN_HEIGHT);
}

void close(SDL_Window* window, SDL_Renderer* gRenderer)
{
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(window);
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}

void waitUntilKeyPressed()
{
    SDL_Event e;
    while (true) {
        if ( SDL_WaitEvent(&e) != 0 &&
             (e.type == SDL_KEYDOWN || e.type == SDL_QUIT) )
            return;
        SDL_Delay(100);
    }
}

float generateRandomNumber()
{
    return (float) rand() / RAND_MAX;
}



//Click funtions
bool clickStartMenu(SDL_Window* window, SDL_Renderer* gRenderer){
    SDL_Event e;
    while (true){
        while(SDL_PollEvent(&e) != 0) {
			if(e.type == SDL_QUIT) {
				close(window, gRenderer);
				exit(0);
			} else if(e.type == SDL_MOUSEBUTTONDOWN) {
                if (e.button.x >= 200 && e.button.x <= 700 && e.button.y >= 180 && e.button.y <= 360) {
                    return true;
                }
                if (e.button.x >= 300 && e.button.x <= 600 && e.button.y >= 400 && e.button.y <= 550)  {
                    return false;
                }
			}
		}
    }
}

bool clickEndMenu(SDL_Window* window,    SDL_Renderer* gRenderer){
    SDL_Event e;
    while (true){
        while(SDL_PollEvent(&e) != 0) {
			if(e.type == SDL_QUIT) {
				close(window, gRenderer);
				exit(0);
			} else if(e.type == SDL_MOUSEBUTTONDOWN) {
                if (e.button.x >= 0 && e.button.x <= 600 && e.button.y >= 280 && e.button.y <= 400) {
                    return true;
                }
                if (e.button.x >= 0 && e.button.x <= 600 && e.button.y >= 450 && e.button.y <= 550)  {
                    close(window, gRenderer);
                    exit(0);
                }
			}
		}
    }
}

int clickChooseSnake(SDL_Window* window, SDL_Renderer* gRenderer){
    SDL_Event e;
    while (true){
        while(SDL_PollEvent(&e) != 0) {
			if(e.type == SDL_QUIT) {
                return 0;
			} else if(e.type == SDL_MOUSEBUTTONDOWN) {

                if (e.button.x >= 450 && e.button.x <= 900 && e.button.y >= 200 && e.button.y <= 320) {
                    return 1;
                }
                if (e.button.x >= 450 && e.button.x <= 900 && e.button.y >= 330 && e.button.y <= 450 )  {
                    return 2;
                }
                if (e.button.x >= 450 && e.button.x <= 900 && e.button.y >= 455 && e.button.y <= 580)  {
                    return 3;
                }
			}
		}
    }

}

int clickChooseSpeed(SDL_Window* window, SDL_Renderer* gRenderer){
    SDL_Event e;
    while (true){
        while(SDL_PollEvent(&e) != 0) {
			if(e.type == SDL_QUIT) {
                return 0;
			} else if(e.type == SDL_MOUSEBUTTONDOWN) {

                if (e.button.x >= 450 && e.button.x <= 900 && e.button.y >= 160 && e.button.y <= 270) {
                    return 1;
                }
                if (e.button.x >= 450 && e.button.x <= 900 && e.button.y >= 281 && e.button.y <= 380)  {
                    return 2;
                }
                                if (e.button.x >= 450 && e.button.x <= 900 && e.button.y >= 381 && e.button.y <= 500)  {
                    return 3;
                }
                if (e.button.x >= 450 && e.button.x <= 900 && e.button.y >= 501 && e.button.y <= 590 )  {
                    return 4;
                }
			}
		}
    }

}


//Draw funtions
void drawPrePicture(Painter& painter, int left, int top)
{
    SDL_Rect dst = { 0, 0, 900, 600 };
    painter.createImage(collection->loadImage(PREPICTURE), NULL, &dst);
}

void drawSnakeOutfit(Painter& painter, int left, int top)
{
    SDL_Rect dst = { 0, 0, 900, 600 };
    painter.createImage(collection->loadImage(SNAKEOUTFITPICTURE), NULL, &dst);
}

void drawLevelPicture(Painter& painter, int left, int top)
{
    SDL_Rect dst = { 0, 0, 900, 600 };
    painter.createImage(collection->loadImage(LEVELPICTURE), NULL, &dst);
}

void drawBackGround(Painter& painter, int left, int top)
{
    SDL_Rect dst = { 0, 0, 900, 600 };
    painter.createImage(collection->loadImage(BACKGROUND), NULL, &dst);
}

void drawVerticalLine(Painter& painter, int left, int top, int cells)
{
    painter.setColor(WHITE_COLOR);
    painter.setAngle(-90);
    painter.setPosition(left, top);
    painter.moveForward(cells * CELL_SIZE);
}

void drawHorizontalLine(Painter& painter, int left, int top, int cells)
{
    painter.setColor(WHITE_COLOR);
    painter.setAngle(0);
    painter.setPosition(left, top);
    painter.moveForward(cells * CELL_SIZE);
}

void drawFood(Painter& painter, int left, int top)
{
    SDL_Rect dst = { left+1, top+1, CELL_SIZE-1, CELL_SIZE-1 };
    painter.createImage(collection->loadImage(FOOD), NULL, &dst);
}

void drawSnake(Painter& painter, int left, int top, vector<Position> pos, int snakeOutfit)
{
    for (int i = 0; i < pos.size(); i++) {
        SDL_Rect dst = { left+pos[i].x*CELL_SIZE+1, top+pos[i].y*CELL_SIZE+1, CELL_SIZE-2, CELL_SIZE-2 };
        SDL_Texture* texture = NULL;
        if( snakeOutfit==1){
            if (i > 0) {
                if (pos[i].y == pos[i-1].y)
                    texture = collection->loadImage(HORIZONTAL_NODE);
                else
                    texture = collection->loadImage(VERTICAL_NODE);
            }
            else { // snake's head
                texture = collection->loadImage(HEAD_NODE);
            }
        }

        if( snakeOutfit==2){
            if (i > 0) {
                if (pos[i].y == pos[i-1].y)
                    texture = collection->loadImage(HORIZONTAL_NODE_1);
                else
                    texture = collection->loadImage(VERTICAL_NODE_1);
            }
            else { // snake's head
                texture = collection->loadImage(HEAD_NODE);
            }
        }

        if( snakeOutfit==3){
            if (i > 0) {
                if (pos[i].y == pos[i-1].y)
                    texture = collection->loadImage(HORIZONTAL_NODE_2);
                else
                    texture = collection->loadImage(VERTICAL_NODE_2);
            }
            else { // snake's head
                texture = collection->loadImage(HEAD_NODE);
            }
        }
        painter.createImage(texture, NULL, &dst);
    }
}

void drawAfPicture(Painter& painter, int left, int top, int currentScore)
{
    SDL_Rect dst = { 0, 0, 900, 600 };
    if (currentScore <500){painter.createImage(collection->loadImage(AFPICTURE1), NULL, &dst);}
    if (currentScore >=500 && currentScore<=1500){painter.createImage(collection->loadImage(AFPICTURE2), NULL, &dst);}
    if (currentScore >1500 ){painter.createImage(collection->loadImage(AFPICTURE3), NULL, &dst);}
}




//Render
void renderSplashScreen(Painter& painter )
{
    painter.clearWithBgColor(WHITE_COLOR);
    drawPrePicture( painter, 0, 0);
    SDL_RenderPresent(painter.getRenderer());

}

void renderSnakeOutfit(Painter& painter)
{
    painter.clearWithBgColor(WHITE_COLOR);
    drawSnakeOutfit( painter, 0, 0);
    SDL_RenderPresent(painter.getRenderer());
}

void renderGameLevel(Painter& painter)
{
    painter.clearWithBgColor(WHITE_COLOR);
    drawLevelPicture( painter, 0, 0);
    SDL_RenderPresent(painter.getRenderer());
}

void renderGamePlay(Painter& painter, const PlayGround& playGround, int snakeOutfit)
{
    int top = 0, left = 0;
    int width = playGround.getWidth();
    int height = playGround.getHeight();

    drawBackGround( painter, 0, 0);

    for (int i = 0; i <= width; i++)
        drawVerticalLine(painter, left+i*CELL_SIZE, top+0, height);

    for (int i = 0; i <= height; i++)
        drawHorizontalLine(painter, left+0, top+i * CELL_SIZE, width);

    const vector<vector<CellType> >& board = playGround.getBoard();
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            if (board[i][j] == CELL_FOOD)
                drawFood(painter, left+j*CELL_SIZE, top+i*CELL_SIZE);

    vector<Position> snakePositions = playGround.getSnakePositions();
    drawSnake(painter, left, top, snakePositions, snakeOutfit);

    SDL_RenderPresent(painter.getRenderer());
}

void renderGameOver(Painter& painter)
{
    int currentScore= getCurrentScore();
    painter.clearWithBgColor(WHITE_COLOR);
    drawAfPicture( painter, 0, 0, currentScore);
    SDL_RenderPresent(painter.getRenderer());
}



UserKeyboardInput interpretEvent(SDL_Event e)
{
    if (e.type == SDL_KEYUP) {
        switch (e.key.keysym.sym) {
        case SDLK_UP: return KEY_PRESS_SURFACE_UP;
        case SDLK_DOWN: return KEY_PRESS_SURFACE_DOWN;
        case SDLK_LEFT: return KEY_PRESS_SURFACE_LEFT;
        case SDLK_RIGHT: return KEY_PRESS_SURFACE_RIGHT;
        }
    }
    return KEY_PRESS_SURFACE_DEFAULT;
}




int main(int argc, char* argv[])
{
    Mix_ResumeMusic();
    srand(time(0));
    SDL_Window* window;
    SDL_Renderer* gRenderer;
    initSDL(window, gRenderer);
    Painter painter(window, gRenderer);
    collection = new Collection(painter);

    PlayGround playGround(GROUND_WIDTH, GROUND_HEIGHT);
    renderSplashScreen(painter);
    if(clickStartMenu(window, gRenderer)==1){
        renderSnakeOutfit(painter);
        int snakeOutfit =0;
        switch (clickChooseSnake(window, gRenderer))
        {
            case 1: {    snakeOutfit =1; break;}
            case 2: {    snakeOutfit =2; break;}
            case 3: {    snakeOutfit =3; break;}
            default : {break;}
        }
        renderGameLevel(painter);
        switch (clickChooseSpeed(window, gRenderer))
        {
            case 1: {   STEP_DELAY =0.35; break;}
            case 2: {   STEP_DELAY =0.25; break;}
            case 3: {   STEP_DELAY =0.15; break;}
            case 4: {   STEP_DELAY =0.1; break;}
            default : {break;}
        }

        resetScore();
        srand(time(0));
        SDL_Event e;
        auto start = CLOCK_NOW();
        renderGamePlay(painter, playGround, snakeOutfit);
        Mix_ResumeMusic();
        loadMusic((char*)"backgroundMusic.mp3");
        while (playGround.isGameRunning()) {
            while (SDL_PollEvent(&e)) {
                UserKeyboardInput input = interpretEvent(e);
                playGround.processUserKeyboardInput(input);
            }

            auto end = CLOCK_NOW();
            ElapsedTime elapsed = end-start;
            if (elapsed.count() > STEP_DELAY) {
                playGround.nextStep();
                renderGamePlay(painter, playGround, snakeOutfit);
                start = end;
            }
            SDL_Delay(1);
        }
        Mix_HaltMusic();
        loadChunk("gameOver.wav");
        SDL_Delay(1000);

        //quitSDL(window, renderer);
        loadScore();

        renderGameOver(painter);
        if(clickEndMenu(window, gRenderer)){
                close(window, gRenderer);
                main(argc, argv);
        }
    }
    else if(clickStartMenu(window, gRenderer)==0)
    {
        loadHighScore();
        main(argc, argv);
    }

    delete collection;
    close(window, gRenderer);
    return 0;
}
