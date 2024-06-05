// ���� �̸�: Collision.h
// ����: �� ������ Collision Ŭ������ ������ �����ϰ� �ֽ��ϴ�. Collision Ŭ������ ���ӿ��� ��ü�� �浹�� ���� �մϴ�.
// �ۼ���: ���ι�
// �ۼ� ��¥: 2024-06-03
// ���� �̷�:
//		- 2024-06-03: ['isPassingThrough' �߰�] (�ۼ���: ���ι�)
//		- 2024-06-04: ['isCollisionCoin' �߰�] (�ۼ���: ���ι�)

#pragma once

#include "Object.h"

class Collision : public Object
{
public:
	// ����(obj1)�� ��ֹ�(obj2)�� �浹�ϴ��� Ȯ��
	bool isCollision(Object& dino, Object& Obstacle);

	// ��ֹ��� 2��(��, �Ʒ�)�� �ֱ� ������ �ΰ��� ��ü�� ������, �� ��ü�� ���� �浹 �˻�
	bool isPassingThrough(Object& dino, Object& upperObstacle, Object& lowerObstacle);

	// ����� ������ �浹�ϴ��� Ȯ��
	bool isCollisionCoin(Object& dino, Object& coin);
};