#ifndef POSITION_H_INCLUDED
#define POSITION_H_INCLUDED


// Điều hướng
enum Direction
{
    UP ,
    DOWN,
    LEFT,
    RIGHT,
};

// Quản lí vì luôn dùng x đi vs y để xđ vị trí
struct Position
{
    int x;
    int y;

    //Gán
    Position(int x_, int y_) : x(x_), y(y_) {}

    //Thay đổi vị trí
    Position move(Direction d)
    {
        const int dx[] = {0,0,-1,1};
        const int dy[] = {-1,1,0,0};
        return Position(x+dx[d],y+dy[d]);
    }

    bool isInsideBox(int left, int top, int width, int height)
    {
        return x >= left && x < left+width && y >= top && y < top+height;
    }

    // Định nghĩa lại ==
    bool operator==(Position p)
    {
        return x == p.x && y == p.y;
    }
};

#endif // POSITION_H_INCLUDED
