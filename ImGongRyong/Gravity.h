// ���� �̸�: Gravity.h
// ����: - �߷� ����� ���õ� ����� �����մϴ�.
// �ۼ���: �̵�ȯ
// �ۼ� ��¥: 24.06.02
// ���� �̷�:
//		- 2024-xx-xx: [		����	] (�ۼ���: )

#pragma once
#ifndef GRAVITY_H
#define GRAVITY_H

#include "Character.h"
#include <iostream>

using namespace std;


class Gravity
{
public:
	void isGravity(Character &character)
	{
		character.moveDefault();
	}
};


#endif // !GRAVITY_H
