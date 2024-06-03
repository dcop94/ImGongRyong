// ���� �̸�: Control.h
// ����: �� ������ Control Ŭ������ ������ �����ϰ� �ֽ��ϴ�. Control Ŭ������ ���ӿ��� [		] �� ���� �մϴ�.
// �ۼ���: �̵�ȯ
// �ۼ� ��¥: 24.06.02
// ���� �̷�:
//		- 2024-xx-xx: [		����	] (�ۼ���: )

#pragma once
#ifndef CONTROL_H
#define CONTROL_H

#include "Character.h"
#include <iostream>
#include <conio.h>

using namespace std;

class Control
{
public :
	void inputKey(Character& character)
	{
		while (_kbhit())
		{
			int key = _getch();

			if (key == 0 || key == 224)
			{
				key = _getch();

				switch (key)
				{
				case 72:
					character.moveUp();
					break;

				case 80:
					character.moveDown();
					break;

				default:
					break;
				}
			}
		}
	}


};

#endif // !CONTROL_H
