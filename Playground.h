#ifndef PLAYGROUND_H_INCLUDED
#define PLAYGROUND_H_INCLUDED

#include <vector>

#include "mySnake.h"
#include "Position.h"

using namespace std;

enum GameStatus
{
    GAME_RUNNING = 1,
    GAME_STOP = 2,
    GAME_WON = 4 | GAME_STOP,
    GAME_LOST = 8 | GAME_STOP,
};

//Biểu diễn sân chơi
class PlayGround
{
private:
    vector<vector<CellType> > board ;   // mảng vector 2 chiều kiểu CellType tên board
                                        // Hình chữ nhật → mảng 2 chiều trạng thái
                                        // Hình chữ nhật biểu diễn sân chơi.

    Snake snake;  //Lớp thể hiện con rắn
    GameStatus status;
    int score; //Điểm số ( số quả đã ăn /độ dài rắn)
public:
    PlayGround(int width, int height);
    ~PlayGround();

    bool isGameRunning() const { return status == GAME_RUNNING; }
    void processUserKeyboardInput(UserKeyboardInput input);
    void nextStep();
    void changeCellState(Position pos, CellType type); // Thay đổi trạng thái ô để thêm cherry mới
    void addCherry();

    //Lấy chiều cao + chiều dài
    int getWidth() const
    {
        return board[0].size();
    }
    int getHeight() const
    {
        return board.size();
    }

    //Lấy giá trị board
    const vector< vector<CellType> >& getBoard() const
    {
        return board;
    }

    // Hàm lấy trạng thái ô từ vị trí x y
    CellType getCellState(Position p) const
    {
        return board[p.y][p.x];
    }

    void setGameStatus(GameStatus status);

    //Khởi tạo hàm getSnakePositions()
    vector<Position> getSnakePositions() const;
};

#endif // PLAYGROUND_H_INCLUDED
