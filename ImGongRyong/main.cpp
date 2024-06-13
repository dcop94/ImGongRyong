// ���� �̸�: Main.cpp
// ����: �� ������ main.cpp �� �����մϴ�
// �ۼ���: ������
// �ۼ� ��¥: 2024-06-04
// ���� �̷�:
//		- 2024-xx-xx: [		����	] (�ۼ���: )

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <windows.h>
#include <iomanip>
#include "Object.h"
#include "Consol.h"
#include "Draw.h"
#include "Collision.h"

using namespace std;

// ����ȭ�� �ʺ� ���� ����
const int WIDTH = 110;
const int HEIGHT = 20;
// ����� x��ǥ �ʱ� ��ġ ����
const int PLANE_X = 5;
// ����� ���� ����
const int PLANE_HEIGHT = 3;
// ����� �߷� ���ӵ� ����
const float GRAVITY = 0.02f;
// ����� �����ӵ� ����
const float JUMP_SPEED = -1.0f;

// ����ȭ�� ��� ���� ���

void drawScore(int score, int highScore, bool paused);

int main()
{

    // �ܼ� â ũ�� ���� �� Ŀ�� ����
    Consol::setConsoleSize(WIDTH, HEIGHT + 2);
    // �ܼ� Ŀ�� ���ü� ����(Consol.cpp) false �϶� Ŀ���� ������ ����
    Consol::setCursorVisibility(false);

    // ����ð� ���� ���� �õ� ����
    srand(static_cast<unsigned int>(time(0)));
    // ����� y��ǥ �ʱ� ��ġ�� ȭ�� �߾����� ����
    int PLANE_Y = HEIGHT / 2;
    // ����� �ʱ� �ӵ� 0���� ����
    float velocity = 0;
    // �ʱ� ������ 0���� ����
    int score = 0;
    // �ְ� ���� 0 ���� �̰� �Ŀ� ����
    int highScore = 0;
    // ������ �̵� �ӵ�
    int pipeSpeed = 2;
    // �����
    int gapSize = PLANE_HEIGHT + 6;
    // ������ ���� ���� ȭ�� �ʺ� 1/4
    int pipeInterval = WIDTH / 4;



    // ������, ����, ����� �ʱ�ȭ
    vector<Object::Pipe> pipes = { {WIDTH, HEIGHT / 2 - gapSize / 2} };
    vector<Object::Coin> coins;
    Object::Plane plane(PLANE_X, PLANE_Y);

    // ���� ���� ����
    bool running = true;
    bool paused = false;

    DWORD startTime = GetTickCount();

    // ���� ���� ����
    while (running)
    {
        if (_kbhit())
        {
            int ch = _getch();

            if (ch == 'p' || ch == 'P')
            {
                paused = !paused;
            }

            if (!paused)
            {
                if (ch == 'w' || ch == 'W')
                {
                    plane.update(GRAVITY, JUMP_SPEED, true, false);
                }

                else if (ch == 's' || ch == 'S')
                {
                    plane.update(GRAVITY, JUMP_SPEED, false, true);
                }
            }

        }

        if (!paused)
        {
            // �߷� �������� ����� ��ġ ������Ʈ
            plane.update(GRAVITY, JUMP_SPEED, false, false);
            // ������ ������ �浹 Ȯ��, �浹 �� ��������
            if (Collision::checkCollision(plane, pipes, gapSize, PLANE_HEIGHT))
            {
                running = false;
            }

            // ������ ���� �浹 Ȯ��, �浹 �� ���� ����
            Collision::checkCoinCollision(plane, coins, score, PLANE_HEIGHT);

            // ��� �������� x ��ǥ�� �ٿ� �̵� (�����ʿ��� �����̵�)
            for (Object::Pipe& pipe : pipes)
            {
                pipe.pipeX -= pipeSpeed;
            }

            // ��� ������ x ��ǥ�� �ٿ� �̵� (�������� ����)
            for (Object::Coin& coin : coins)
            {
                coin.coinX -= pipeSpeed;
            }

            // ������ �������� Ư�� ��ġ ���� �� �� ������ �߰�
            if (pipes.back().pipeX < WIDTH - pipeInterval)
            {
                pipes.push_back({ WIDTH, rand() % (HEIGHT - gapSize) });
            }

            // ���� Ȯ���� ���� �߰�
            if (rand() % 10 == 0)
            {
                coins.push_back({ WIDTH, rand() % HEIGHT });
            }

            // ȭ���� ��� ������ ����
            if (pipes.front().pipeX < -3)
            {
                pipes.erase(pipes.begin());
            }

            DWORD currentTime = GetTickCount();
            if (currentTime - startTime >= 100)
            {
                score++;
                startTime = currentTime;
            }

            if (score > highScore)
            {
                highScore = score;
            }
        }


        // ���� ȭ�� �׸���
        drawScore(score, highScore, paused);

        Draw::draw(plane, pipes, coins, score, highScore, WIDTH, HEIGHT, gapSize, paused);


        // 50ms���� ��� ���Ӽӵ� ����
        Sleep(50);
    }
    // Ŀ���� ���� ��ġ�� �̵� (Consol.cpp ����)
    Consol::gotoxy(WIDTH / 2 - 5, HEIGHT / 2);
    std::cout << "Game Over!" << std::endl;
    Sleep(3000);
    return 0;
}


void drawScore(int score, int highScore, bool paused)
{
    Consol::gotoxy(1, 23);
    cout << "�Ͻ����� : 'P'" << setw(20) << "�ְ����� : " << highScore << setw(20) << "���� ���� :" << score;

    if (paused)
    {
        Consol::gotoxy(WIDTH / 2 - 5, HEIGHT / 2);
        cout << "�Ͻ�����";
    }
}
