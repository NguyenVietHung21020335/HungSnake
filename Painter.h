#pragma once

#include <string>
#include <SDL.h>

using namespace std;

const SDL_Color CYAN_COLOR = {0, 255, 255};
const SDL_Color BLUE_COLOR = {0, 0, 255};
const SDL_Color ORANGE_COLOR = {255, 165, 0};
const SDL_Color YELLOW_COLOR = {255, 255, 0};
const SDL_Color LIME_COLOR = {0, 255, 0};
const SDL_Color PURPLE_COLOR = {128, 0, 128};
const SDL_Color RED_COLOR = {255, 0, 0};
const SDL_Color WHITE_COLOR = {255, 255, 255};
const SDL_Color BLACK_COLOR = {0, 0, 0};
const SDL_Color GREEN_COLOR = {0, 128, 0};

const SDL_Color DEFAULT_COLOR = BLACK_COLOR;

class Painter
{
    //x, y là vị trí đặt bút vẽ
    float x;
    float y;
    float angle; // Góc hay hướng vẽ ( góc của tờ giấy)
    int width;
    int height;
    SDL_Color color; //Màu đang dùng
    SDL_Renderer* gRenderer;
public:
    Painter(SDL_Window* window, SDL_Renderer* gRenderer);

    // Chọn vị trí + góc vẽ
    void setPosition(float x, float y);
    float getX() const
    {
        return x;
    }
    float getY() const
    {
        return y;
    }

    void setAngle(float angle);
    float getAngle() const
    {
        return angle;
    }

    int getWidth() const
    {
        return width;
    }
    int getHeight() const
    {
        return height;
    }

    // Thiết lập màu mình vẽ
    void setColor(SDL_Color color);
    SDL_Color getColor() const
    {
        return color;
    }

    // Lấy renderer
    SDL_Renderer* getRenderer() const
    {
        return gRenderer;
    }
    // Xóa màn hình với màu
    void clearWithBgColor(SDL_Color color);

    // basic drawing functions
    void moveForward(float length);
    void jumpForward(float length);
    void moveBackward(float length)
    {
        moveForward(-length);
    }
    void jumpBackward(float length)
    {
        jumpForward(-length);
    }
     // Xoay giấy
    void turnLeft(float angle)
    {
        setAngle(this->angle+angle);
    }
    void turnRight(float angle)
    {
        turnLeft(-angle);
    }

    SDL_Texture* loadTexture( string path ); //slide 73 file lec7-8 course
    bool createImage( SDL_Texture* texture,
        SDL_Rect* srcrect = nullptr, SDL_Rect* dstrect = nullptr );
};

