// ���� �̸�: Collision.cpp
// ����: �� ������ Collision Ŭ������ ������ �����ϰ� �ֽ��ϴ�. (�浹)
// �ۼ���: ���ι�
// �ۼ� ��¥: 2024-06-03
// ���� �̷�:
//		- 2024-06-03: [Crash Ŭ������ �̸��� Collision���� ����] (�ۼ���: ���ι�)
//		- 2024-06-03: ['isPassingThrough' �߰�] (�ۼ���: ���ι�)
//		- 2024-06-04: ['isCollisionCoin' �߰�] (�ۼ���: ���ι�)

#include "Collision.h"

// �����, ������, ����� ũ��, ����� ����
bool Collision::checkCollision(const Object::Plane& plane, const std::vector<Object::Pipe>& pipes, int gapSize, int planeHeight)
{
    for (const Object::Pipe& pipe : pipes)
    {
        // ����� X��ǥ�� ������ X��ǥ ������ ���ԵǴ��� �˻�
        if (plane.planeX >= pipe.pipeX && plane.planeX <= pipe.pipeX + 2)
        {
            // ����� Y��ǥ�� ������ ��ܺ��� �۰ų�, ����� �ϴ��� ������ �ϴܺ��� ū�� �˻�
            if (plane.planeY < pipe.pipeY || plane.planeY + planeHeight > pipe.pipeY + gapSize)
            {
                // �浹 ���� �Ǹ� true
                return true;
            }
        }
    }
    return false;
}

// �����, ����, ����
bool Collision::checkCoinCollision(Object::Plane& plane, std::vector<Object::Coin>& coins, int& score, int planeHeight)
{
    bool collisionDetected = false;

    for (auto it = coins.begin(); it != coins.end();)
    {
        // ���� X��ǥ�� ����� X��ǥ ���� ���ԵǴ���, Y��ǥ�� ����
        if (it->coinX >= plane.planeX && it->coinX <= plane.planeX + 2 &&
            it->coinY >= plane.planeY && it->coinY < plane.planeY + planeHeight)
        {
            // �浹 �����Ǹ� ������ ���Ϳ��� ����
            it = coins.erase(it);
            // 30�� ����
            score += 30;
            // �浹 TRUE ��ȯ
            collisionDetected = true;
        }
        else
        {
            ++it;
        }
    }
    return collisionDetected;
}

