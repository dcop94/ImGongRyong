// ���� �̸�: Character.h
// ����: �� ������ Character Ŭ������ ������ �����ϰ� �ֽ��ϴ�. Character Ŭ������ ���ӿ��� [	ĳ���� 	] �� ���� �մϴ�.
// �ۼ���: �̵�ȯ
// �ۼ� ��¥: 24.06.01
// ���� �̷�:
//		- 2024-xx-xx: [		����	] (�ۼ���: )

#pragma once
#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <vector>

using namespace std;

class Character
{

protected:
	// ĳ���� ������ǥ
	int character_x;
	int character_y;

	// ĳ���� ũ��
	int c_width;
	int c_height;

	// ĳ���� �׷���
	vector<string> shape_character;

public :
	// ĳ���� Ŭ���� ������ ���� �� �ʱ�ȭ
	Character(int ch_x, int ch_y, int ch_width, int ch_height, vector<string> ch_shape) 
		: character_x(ch_x), character_y(ch_y), c_width(ch_width), c_height(ch_height), shape_character(ch_shape) {}

	// ĳ���� �̵�
	void moveUp();
	void moveDown();
	void moveDefault();

	// ĳ���� ������ǥ �ޱ�
	int getCharacter_x() const;
	int getCharacter_y() const;

	// ĳ���� �׷��� �ޱ�
	const vector<string>& getShpaeCh() const;
};


#endif // !CHARACTER_H
