#ifndef COLLECTION_H_INCLUDED
#define COLLECTION_H_INCLUDED

#include <vector>
#include <SDL.h>
#include "painter.h"

using namespace std;

enum PictureID
{
    PREPICTURE,
    SNAKEOUTFITPICTURE,
    LEVELPICTURE,
    BACKGROUND,
    FOOD,
    VERTICAL_NODE,
    HORIZONTAL_NODE,
    VERTICAL_NODE_1,
    HORIZONTAL_NODE_1,
    VERTICAL_NODE_2,
    HORIZONTAL_NODE_2,
    HEAD_NODE,
    AFPICTURE1,
    AFPICTURE2,
    AFPICTURE3,
};

class Collection
{
    vector<SDL_Texture*> pictures; ////mảng chứa hình ảnh rắn+ quả
    Painter& painter;
public:
    Collection(Painter& painter_);
    ~Collection();

    void loadGamePictures();
    SDL_Texture* loadImage(PictureID id) const
    {
        return pictures[id];
    }
};

#endif // COLLECTION_H_INCLUDED
