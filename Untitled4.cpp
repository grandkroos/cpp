//{============================================================================
//! @file       Untitled4.cpp
//! @brief      ������� �������� ������� ������
//}============================================================================

/*! @mainpage   ������� ���� �� ����� ������� �����

    @section    MainPage              ���������� ��� ������� �����

    @section    Description           ����������

                ���� ���� ������, ��� ������ ������� ������� � ������!

    @section    Contents              ������� ������� ������
    @par
             -  @ref DrawCar         "��������� ������"
             -  @ref DrawHelicopter  "��������� ���������"
             -  @ref DrawPerson      "��������� ��������"
             -  @ref MovePerson      "�������� ��������"
             -  @ref MoveCar         "�������� ����������"
             -  @ref MoveHelicopter  "�������� ���������"
             -  @ref DropBomb        "����� �����"
             -  @ref Boom            "�����"
             -  @ref Bullet          "����� ����"
             -  @ref Subtitles       "������� ����"
    @warning    ������ ��������� �������� ����-�������, ������� ������� ���������� � ��� � ������ ��������������
*/


#include "TXLib.h"
//��������� ����������
void DrawCar(double LeftWheelX, double LeftWheelY, double RightWheelX, double RightWheelY, double WheelRadius);

//�������� ����������
void MoveCar(double NumberOfMeters);

//��������� ��������
void DrawPerson(double x, double y, double MoveHandLeft, double MoveHandRight, double BodyLength);

//�������� ��������
void MovePerson(double NumberOfMeters);

//��������� ����
void DrawHouse(double UpLeftCornerX, double UpLeftCornerY, double DownRightCornerX, double DownRightCornerY,  double RoofHeight, COLORREF HouseColor, COLORREF RoofColor);

//��������� ���������
void DrawHelicopter(double CrossSwingX, double CrossSwingY, double HelSize);

//�������� ���������
void MoveHelicopter(double NumberOfMeters);

//����� �����
void DropBomb(double x, double y);

//�����
void Boom(double x, double y);

//��������
void Bullet();

//������� ����
void Subtitles(char* Replics);

//����� ������ � �����
void StartTitles(char* Titles);

void DrawCar(double LeftWheelX, double LeftWheelY, double RightWheelX, double RightWheelY, double WheelRadius)
    {
    txLine(LeftWheelX-WheelRadius, LeftWheelY, LeftWheelX-WheelRadius-10, LeftWheelY);
    txLine(LeftWheelX-WheelRadius-10, LeftWheelY, LeftWheelX-WheelRadius-10, LeftWheelY-30);
    txLine(LeftWheelX-WheelRadius-10, LeftWheelY-30, LeftWheelX+WheelRadius, LeftWheelY-30);
    txLine(LeftWheelX+WheelRadius, LeftWheelY-30, LeftWheelX+WheelRadius+30, LeftWheelY-70);
    txLine(LeftWheelX+WheelRadius+30, LeftWheelY-70, RightWheelX+WheelRadius, RightWheelY-70);
    txLine(RightWheelX+WheelRadius, RightWheelY-70, RightWheelX+WheelRadius+30, RightWheelY-40);
    txLine(RightWheelX+WheelRadius+30, RightWheelY-40, RightWheelX+WheelRadius+30, RightWheelY);
    txLine(RightWheelX+WheelRadius+30, RightWheelY, LeftWheelX, RightWheelY);
    txSetFillColor(TX_WHITE);
    txCircle(LeftWheelX, LeftWheelY, WheelRadius);
    txCircle(RightWheelX, RightWheelY, WheelRadius);
    }

void Subtitles(char* Replics)
    {
    txSetFillColor(TX_BLACK);
    txRectangle(0, 550, 800, 600);
    txSetColor(TX_WHITE);
    txSetTextAlign(TA_CENTER);
    txDrawText  (0, 550, 800, 600, Replics);
    }

void MoveCar(double NumberOfMeters)
    {
    int i = 0;
    while (i < NumberOfMeters)
        {
        txSetColor(TX_WHITE);
        DrawCar(370-i, 500, 470-i, 500, 20);
        Sleep(1);
        txSetColor(TX_BLACK);
        DrawCar(370-i, 500, 470-i, 500, 20);
        i++;
        Sleep(1);
        }
    txSetColor(TX_WHITE);
    DrawCar(370-i, 500, 470-i, 500, 20);
    }

void DrawPerson(double x, double y, double MoveHandLeft, double MoveHandRight, double BodyLength)
    {
    txLine(x, y, x, y + BodyLength);
    txLine(x, y, x - BodyLength, y + BodyLength + MoveHandLeft);
    txLine(x, y, x + BodyLength, y + BodyLength + MoveHandRight);
    txLine(x, y + BodyLength, x - BodyLength, y + BodyLength*2);
    txLine(x, y + BodyLength, x + BodyLength, y + BodyLength*2);
    txSetFillColor(TX_BLACK);
    txCircle(x, y - 20, 20);
    }

void MovePerson(double NumberOfMeters)
    {
    int i = 0;
    while (i < NumberOfMeters)
        {
        txSetColor(TX_WHITE);
        DrawPerson(300+i, 460, 0, 0, 20);
        Sleep(1);
        txSetColor(TX_BLACK);
        DrawPerson(300+i, 460, 0, 0, 20);
        i++;
        }
    txSetColor(TX_WHITE);
    }

void DrawHouse(double UpLeftCornerX, double UpLeftCornerY, double DownRightCornerX, double DownRightCornerY,  double RoofHeight, COLORREF HouseColor, COLORREF RoofColor)
    {
    txSetFillColor(HouseColor);
    txRectangle(UpLeftCornerX, UpLeftCornerY, DownRightCornerX, DownRightCornerY);
    txSetFillColor(RoofColor);
    POINT Roof[3] = {{UpLeftCornerX, UpLeftCornerY}, {(DownRightCornerX + UpLeftCornerX) / 2, UpLeftCornerY - RoofHeight}, {DownRightCornerX, UpLeftCornerY}};
    txPolygon(Roof, 3);
    }

void DrawHelicopter(double CrossSwingX, double CrossSwingY, double HelSize)
    {
    txLine(CrossSwingX, CrossSwingY, CrossSwingX - HelSize, CrossSwingY - HelSize/2);
    txLine(CrossSwingX, CrossSwingY, CrossSwingX - HelSize, CrossSwingY - HelSize/5);
    txLine(CrossSwingX, CrossSwingY, CrossSwingX + HelSize, CrossSwingY - HelSize/2);
    txLine(CrossSwingX, CrossSwingY, CrossSwingX + HelSize, CrossSwingY - HelSize/5);
    txSetFillColor(TX_TRANSPARENT);
    txEllipse(CrossSwingX - HelSize, CrossSwingY, CrossSwingX + HelSize, CrossSwingY + HelSize/2);
    txLine(CrossSwingX + HelSize, CrossSwingY + HelSize/5, CrossSwingX + HelSize*2, CrossSwingY);
    txLine(CrossSwingX + HelSize*2, CrossSwingY, CrossSwingX + HelSize*2 - HelSize/2, CrossSwingY - HelSize/7);
    txLine(CrossSwingX + HelSize*2, CrossSwingY, CrossSwingX + HelSize*2 + HelSize/2, CrossSwingY - HelSize/7);
    txLine(CrossSwingX + HelSize*2, CrossSwingY, CrossSwingX + HelSize*2 - HelSize/2, CrossSwingY + HelSize/7);
    txLine(CrossSwingX + HelSize*2, CrossSwingY, CrossSwingX + HelSize*2 + HelSize/2, CrossSwingY + HelSize/7);
    txLine(CrossSwingX, CrossSwingY, CrossSwingX, CrossSwingY + HelSize/4);
    txLine(CrossSwingX, CrossSwingY + HelSize/4, CrossSwingX - HelSize, CrossSwingY + HelSize/4);
    txLine(CrossSwingX, CrossSwingY + HelSize/2, CrossSwingX, CrossSwingY + HelSize/1.5);
    txLine(CrossSwingX - HelSize, CrossSwingY + HelSize/1.5, CrossSwingX + HelSize, CrossSwingY + HelSize/1.5);
    }

void MoveHelicopter(double NumberOfMeters)
    {
    int i = 0;
    while (i < NumberOfMeters)
        {
        txSetColor(TX_WHITE);
        DrawHelicopter(1000 - i, 100, 70);
        Sleep(1);
        txSetColor(TX_BLACK);
        DrawHelicopter(1000 - i, 100, 70);
        i++;
        }
    txSetColor(TX_WHITE);
    DrawHelicopter(1000 - i, 100, 70);
    }

void DropBomb(double x, double y)
    {
    int i = 0;
    while (i < 300)
        {
        txSetColor(TX_WHITE);
        txCircle(100, 200 + i, 30);
        Sleep(1);
        txSetColor(TX_BLACK);
        txCircle(100, 200 + i, 30);
        i++;
        }
    }

void Boom(double x, double y)
    {
    int i = 0;
    while (i < 130)
        {
        txSetFillColor(TX_ORANGE);
        txCircle(x, y, 30 + i);
        i++;
        Sleep(1);
        }
    txSetColor(TX_WHITE);
    }

void Bullet()
    {
    int i = 0;
    while (i < 300)
        {
        txSetColor(TX_WHITE, 3);
        txLine(500-i, 440-i, 495-i, 435-i);
        Sleep(1);
        txSetColor(TX_BLACK, 3);
        txLine(500-i, 440-i, 495-i, 435-i);
        i++;
        }

    }

void StartTitles(char* Titles)
    {
    int i = 0;
    while (i < 700)
        {
        txSetFillColor(TX_WHITE);
        txRectangle(0, 550-i, 800, 600-i);
        txSetColor(TX_BLACK);
        txSetTextAlign(TA_CENTER);
        txDrawText  (0, 550-i, 800, 600-i, Titles);
        Sleep(3);
        i++;
        }

    }

