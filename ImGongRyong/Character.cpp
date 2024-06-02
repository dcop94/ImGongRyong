// ���� �̸�: Character.cpp
// ����: �� ������ Character Ŭ������ ������ �����ϰ� �ֽ��ϴ�. (ĳ����)
// �ۼ���: �̵�ȯ
// �ۼ� ��¥: 24.06.01
// ���� �̷�:
//		- 2024-06-01: [		����	] (�ۼ���: �̵�ȯ )

#include "Character.h"

using namespace std;

void Character::moveUp()
{
	character_y = character_y - 3;
}

void Character::moveDown()
{
	character_y = character_y + 3;
}

void Character::moveDefault()
{
	character_y = character_y + 1;
}

int Character::getCharacter_x() const
{
	return character_x;
}

int Character::getCharacter_y() const
{
	return character_y;
}

const vector<string> Character::getShpaeCh() const
{
	return shape_character;
}