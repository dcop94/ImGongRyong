// ���� �̸�: Collision.h
// ����: - �浹 �˻翡 �ʿ��� �Լ��� �����մϴ�.
// �ۼ���: ���ι�
// �ۼ� ��¥: 2024-06-03
// ���� �̷�:
//		- 2024-06-03: ['isPassingThrough' �߰�] (�ۼ���: ���ι�)
//		- 2024-06-04: ['isCollisionCoin' �߰�] (�ۼ���: ���ι�)

#pragma once
#ifndef COLLISION_H
#define COLLISION_H

#include <vector>
#include "Object.h"

class Collision
{
public:
    static bool checkCollision(const Object::Plane& plane, const std::vector<Object::Pipe>& pipes, int gapSize, int planeHeight);
    static bool checkCoinCollision(Object::Plane& plane, std::vector<Object::Coin>& coins, int& score, int planeHeight);
};

#endif
