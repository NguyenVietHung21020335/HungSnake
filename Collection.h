#ifndef COLLECTION_H_INCLUDED
#define COLLECTION_H_INCLUDED

#include <vector>
#include <SDL.h>
#include "painter.h"

using namespace std;

enum PictureID
{
    PREPICTURE,
    BACKGROUND,
    FOOD,
    VERTICAL_NODE,
    HORIZONTAL_NODE,
    HEAD_NODE,
    AFPICTURE,
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

