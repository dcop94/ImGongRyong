// ���� �̸�: Draw.cpp
// ����: �� ������ Draw Ŭ������ ������ �����ϰ� �ֽ��ϴ�.
// �ۼ���: 
// �ۼ� ��¥: 
// ���� �̷�:
//		- 2024-xx-xx: [		����	] (�ۼ���: )

#include "Draw.h"
#include "Consol.h"
#include <cstring>
#include <iostream>
#include <Windows.h>

using namespace std;

// Draw Ŭ���� draw �Լ� ���� const�� ���� �������� �ʰ�
// �����, ������, ���� ��ü
// ��������, �ְ�����, ȭ�� ������, �����ũ��, �Ͻ�����
void Draw::draw
(const Object::Plane& plane, const std::vector<Object::Pipe>& pipes, const std::vector<Object::Coin>& coins, int score, int highScore, int width, int height, int gapSize, bool paused)
{
    // ����� ����, ���� ���� ���ڸ� ����
    const char CoinChar = '$';
    const char TopBottomWall = '-';
    const char SideWall = '|';

    // ����� ����, �ʺ� ���� ���ڿ� �迭 �ʱ�ȭ
    const int PLANE_WIDTH = 3;
    const int PLANE_HEIGHT = 3;
    const char* PlaneGraphic[PLANE_HEIGHT] =
    {
        " > ",
        ">>^",
        " > "
    };

    // �ܼ� �ڵ� (�ܼ� ����� ����)
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // COORD ����ü bufferSize �������� �ܼ� ȭ��ũ�� ���� +2�� ���� ���� �߰�
    COORD bufferSize;
    bufferSize.X = static_cast<SHORT>(width + 2);
    bufferSize.Y = static_cast<SHORT>(height + 2);

    // ���� �Ҵ� (���� ����)
    CHAR_INFO* buffer = new CHAR_INFO[(width + 2) * (height + 2)];

    // �ֿܼ� �ؽ�Ʈ ��� ���� ����
    SMALL_RECT writeRegion;
    writeRegion.Left = 0;
    writeRegion.Top = 0;
    writeRegion.Right = static_cast<SHORT>(width + 1);
    writeRegion.Bottom = static_cast<SHORT>(height + 1);

    // ���� �ʱ�ȭ�Ͽ� ���� �����Ͱ� �������� �ʰ�
    memset(buffer, 0, sizeof(CHAR_INFO) * (width + 2) * (height + 2));

    // ���� ���ڷ� �ʱ�ȭ
    for (int i = 0; i < (width + 2) * (height + 2); ++i)
    {
        buffer[i].Char.AsciiChar = ' ';
        buffer[i].Attributes = 0x0F;
    }

    // ��� �� ����
    for (int x = 0; x < width + 2; ++x)
    {
        buffer[x].Char.AsciiChar = TopBottomWall;
    }

    // ���� �� ����
    for (int y = 0; y < height; ++y)
    {
        buffer[(y + 1) * (width + 2)].Char.AsciiChar = SideWall;

        // ��ü�� ȭ�鿡 �׸�

        // x : ���� ���� ��ġ, width : ȭ��ʺ�
        for (int x = 0; x < width; ++x)
        {
            bool isPipe = false;

            // ������ ��ü ����Ʈ
            for (const Object::Pipe& pipe : pipes)
            {
                // ������ ���� ���� ��ġ �� �� ��ġ �� �� �������� �׸�
                if ((x == pipe.pipeX || x == pipe.pipeX + 1 || x == pipe.pipeX + 2) && (y < pipe.pipeY || y >= pipe.pipeY + gapSize))
                {
                    buffer[(y + 1) * (width + 2) + (x + 1)].Char.AsciiChar = '|';
                    isPipe = true;
                    break;
                }
            }

            if (!isPipe) // �������� ���� ���
            {
                bool isCoin = false;

                // ������ �׸� �׸��� �Ͱ� ����
                for (const Object::Coin& coin : coins)
                {

                    if (x == coin.coinX && y == coin.coinY)
                    {
                        buffer[(y + 1) * (width + 2) + (x + 1)].Char.AsciiChar = CoinChar;
                        isCoin = true;
                        break;
                    }
                }

                if (!isCoin) // �������� ������ ���� ���
                {
                    if (y >= plane.planeY && y < plane.planeY + PLANE_HEIGHT && x >= plane.planeX && x < plane.planeX + PLANE_WIDTH)
                    {
                        buffer[(y + 1) * (width + 2) + (x + 1)].Char.AsciiChar = PlaneGraphic[y - plane.planeY][x - plane.planeX];
                    }
                }
            }
        }
        buffer[(y + 1) * (width + 2) + (width + 1)].Char.AsciiChar = SideWall;
    }

    // ���� �ϴ� �� ����
    for (int x = 0; x < width + 2; ++x)
    {
        buffer[(height + 1) * (width + 2) + x].Char.AsciiChar = TopBottomWall;
    }

    // ���� �� ������ ���� �ֿܼ� �׸�
    WriteConsoleOutput(hConsole, buffer, bufferSize, { 0, 0 }, &writeRegion);

    // ���� �Ҵ� ����
    delete[] buffer;

}
