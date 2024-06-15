#include "console.h"

void Console::setConsoleSize(int width, int height)
{
    // �ܼ� â�� �ڵ��� ������
    HWND console = GetConsoleWindow();
    // RECT ����ü ����
    RECT r;
    // �ܼ� â ���� ��ġ�� ũ�⸦ RECT ����ü�� ����
    GetWindowRect(console, &r);
    // �ܼ� â ��ġ�� ũ�� ����, r.left�� top�� �� ��ġ ����, �ʺ� ���̴� �ȼ������� ����
    MoveWindow(console, r.left, r.top, width * 10, height * 20, TRUE);
}

void Console::gotoxy(int x, int y)
{
    // �ܼ� ȭ�� ��ǥ SHORT Ÿ������ ����ü ����
    COORD coord = { (SHORT)x, (SHORT)y };
    // �ܼ� Ŀ���� ���� ��ġ �̵� ǥ�� ��� �ڵ��� ������
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Console::setCursorVisibility(bool visible)
{
    // �ܼ� ǥ�� ��� �ڵ� ������
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO cursorInfo;
    // ���� Ŀ�� ����
    GetConsoleCursorInfo(console, &cursorInfo);
    // Ŀ�� ���ü� ����
    cursorInfo.bVisible = visible;
    // ���� �� Ŀ�� ���� ����
    SetConsoleCursorInfo(console, &cursorInfo);
}
