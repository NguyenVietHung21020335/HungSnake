#include "Collection.h"

Collection::Collection(Painter& painter_)
    : painter(painter_)
{
    loadGamePictures();
}

Collection::~Collection()
{
    for (SDL_Texture* texture : pictures)
        SDL_DestroyTexture(texture);
}

void Collection::loadGamePictures()
{
    pictures.push_back(painter.loadTexture("pre_picture.jpg"));
    pictures.push_back(painter.loadTexture("snake_outfit.jpg"));
    pictures.push_back(painter.loadTexture("level_picture.jpg"));
    pictures.push_back(painter.loadTexture("back_ground.jpg"));
    pictures.push_back(painter.loadTexture("food.jpg"));
    pictures.push_back(painter.loadTexture("vertical_node.jpg"));
    pictures.push_back(painter.loadTexture("horizontal_node.png"));
    pictures.push_back(painter.loadTexture("yeji1.jpg"));
    pictures.push_back(painter.loadTexture("yeji2.png"));
    pictures.push_back(painter.loadTexture("mina1.png"));
    pictures.push_back(painter.loadTexture("mina2.jpg"));
    pictures.push_back(painter.loadTexture("head_node.jpg"));
    pictures.push_back(painter.loadTexture("af_picture1.jpg"));
    pictures.push_back(painter.loadTexture("af_picture2.jpg"));
    pictures.push_back(painter.loadTexture("af_picture3.jpg"));
}

/*
#include "Collection.h"

Collection::Collection(Painter& painter_)
    : painter(painter_)
{
    loadGamePictures();
}

Collection::~Collection()
{
    for (SDL_Texture* texture : pictures)
        SDL_DestroyTexture(texture);
}

void Collection::loadGamePictures()
{
    pictures.push_back(painter.loadTexture("pre_picture.jpg"));
    pictures.push_back(painter.loadTexture("level_picture.jpg"));
    pictures.push_back(painter.loadTexture("back_ground.jpg"));
    pictures.push_back(painter.loadTexture("food.jpg"));
    pictures.push_back(painter.loadTexture("vertical_node.jpg"));
    pictures.push_back(painter.loadTexture("horizontal_node.png"));
    pictures.push_back(painter.loadTexture("head_node.jpg"));
    pictures.push_back(painter.loadTexture("af_picture1.jpg"));
    pictures.push_back(painter.loadTexture("af_picture2.jpg"));
    pictures.push_back(painter.loadTexture("af_picture3.jpg"));
}
*/
