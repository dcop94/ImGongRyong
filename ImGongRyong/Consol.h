// ���� �̸�: Gravity.h
// ����: - �߷� ����� ���õ� ����� �����մϴ�.
// �ۼ���: �̵�ȯ
// �ۼ� ��¥: 24.06.02
// ���� �̷�:
//		- 2024-xx-xx: [		����	] (�ۼ���: )

#pragma once
#ifndef CONSOL_H
#define CONSOL_H

#include <windows.h>

class Consol
{
public:
    static void setConsoleSize(int width, int height);
    static void gotoxy(int x, int y);
    static void setCursorVisibility(bool visible);

};

#endif
