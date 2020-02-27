
#include "TXLib.h"

void BallMove(double x, double y);
void DrawBall(double x, double y);

const int BOARD_HEIGHT = 600;
const int BOARD_WIDTH = 700;

int main()
    {
    txCreateWindow (BOARD_WIDTH, BOARD_HEIGHT);
    BallMove(0, 0);
    }

void DrawBall(double x, double y)
    {
    txSetColor(RGB(rand()%255, rand()%255, rand()%255));
    txSetFillColor(RGB(rand()%255, rand()%255, rand()%255));
    txCircle(x, y, rand()%30);
    Sleep(1);
    txSetFillColor(RGB(rand()%255, rand()%255, rand()%255));
    txCircle(x, y, rand()%30);
    }
void BallMove(double x, double y)
        {
        int i = x;
        int j = y;
        int dx = 1;
        int dy = 1;
        while (txMouseButtons() != 1)
            {
            DrawBall(i, j);
            if (i > BOARD_WIDTH)
                {
                dx = -rand()%5;
                }
            else if (i < 0)
                {
                dx = rand()%5;
                }
            if (j > BOARD_HEIGHT)
                {
                dy = -rand()%5;
                }
            else if (j < 0)
                {
                dy = rand()%5;
                }
            i += dx;
            j += dy;
            Sleep(0.3);

            }
        }

