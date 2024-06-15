#include "Object.h"

void Object::Plane::update(float gravity, float jumpSpeed, bool moveUp, bool moveDown)
{
    // �ӵ� ������ ���� �ӵ� ����
    static const float MAX_DOWN_SPEED = 1.5f;
    static const float MAX_UP_SPEED = -1.5f;

    if (moveUp) // ���
    {
        velocity = jumpSpeed; // �ӵ��� �����ӵ��� ����
    }
    else if (moveDown)
    {
        velocity = -jumpSpeed;
    }
    else
    {
        velocity = velocity + gravity;
    }

    // �ӵ� ����
    if (velocity > MAX_DOWN_SPEED) velocity = MAX_DOWN_SPEED;
    if (velocity < MAX_UP_SPEED) velocity = MAX_UP_SPEED;

    // ��ġ ������Ʈ
    planeY = planeY + velocity;

    // ����� ȭ�� ��Ż üũ
    if (planeY < 0) planeY = 0; // Y��ǥ�� 0���� �۾����� �ʵ���, ȭ�� ���� ��Ż ����
    if (planeY > 20 - 3) planeY = 20 - 3; // 20�� ȭ�� ����, 3�� ����� ���� ȭ�� �Ʒ��� ��Ż ����
}

