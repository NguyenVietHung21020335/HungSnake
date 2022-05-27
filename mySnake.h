#ifndef MYSNAKE_H_INCLUDED
#define MYSNAKE_H_INCLUDED

#include <queue>

#include "Position.h"

using namespace std;

class PlayGround;

enum UserKeyboardInput
{
    KEY_PRESS_SURFACE_DEFAULT,
    KEY_PRESS_SURFACE_UP,
    KEY_PRESS_SURFACE_DOWN,
    KEY_PRESS_SURFACE_LEFT,
    KEY_PRESS_SURFACE_RIGHT,
};

enum CellType
{
    CELL_EMPTY ,
    CELL_SNAKE,
    CELL_FOOD,
};
// Xử lí đốt rắn mới
struct SnakeNode
{
    Position position;
    SnakeNode* next;

    //Tạo một đốt mới có dữ liệu p và nối tới một đốt cũ - Gán
    SnakeNode(Position p, SnakeNode* n = nullptr) : position(p), next(n) {}

    //slide
    static SnakeNode* insertHead(SnakeNode* head, Position p)
    {
        SnakeNode* newHead = new SnakeNode(p, head);
        return newHead;
    }
};
//Thay đổi con rắn sau khi ăn và điều hướng
class Snake
{
    SnakeNode* head;
    PlayGround* playGround;
    Direction direction;
    queue<UserKeyboardInput> inputQueue;// Hàng đợi kiểu dữ liệu "UserInput" tên inputQueue

    int food;
public:
    Snake(PlayGround* playGround);
    ~Snake();

    void processUserKeyboardInput(UserKeyboardInput input);//xử lí hàng đợi
    void nextStep(); //Bước tiếp theo
    bool checkPosition(Position pos); //Ktra xem hợp lệ k ( thua hay chưa)
    SnakeNode* getHead() const
    {
        return head;
    }
private:
    Direction changeDirection(UserKeyboardInput input);//Thay đổi điều hướng
    void changePlayGroundState(CellType type);//Thay đổi trạng thái sân
};

int getScore();
void resetScore();
vector<int> getArrScore();

#endif // MYSNAKE_H_INCLUDED

