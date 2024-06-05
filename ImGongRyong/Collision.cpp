// ���� �̸�: Collision.cpp
// ����: �� ������ Collision Ŭ������ ������ �����ϰ� �ֽ��ϴ�. (�浹)
// �ۼ���: ���ι�
// �ۼ� ��¥: 2024-06-03
// ���� �̷�:
//		- 2024-06-03: [Crash Ŭ������ �̸��� Collision���� ����] (�ۼ���: ���ι�)
//		- 2024-06-03: ['isPassingThrough' �߰�] (�ۼ���: ���ι�)
//		- 2024-06-04: ['isCollisionCoin' �߰�] (�ۼ���: ���ι�)

#include "Collision.h"

bool Collision::isCollision(Object& dino, Object& Obstacle)
{
	// ������ ��� ���
	int Dino_left = dino.getObj_x(); // ������ ���� ���
	int Dino_right = dino.getObj_x() + dino.getObj_Width(); // ������ ������ ���
	int Dino_top = dino.getObj_y(); // ������ ��� ���
	int Dino_bottom = dino.getObj_y() + dino.getObj_Height(); // ������ �ϴ� ���
	
	// ��ֹ��� ��� ���
	int Obstacle_left = Obstacle.getObj_x(); // ��ֹ��� ���� ���
	int Obstacle_right = Obstacle.getObj_x() + Obstacle.getObj_Width(); // ��ֹ��� ������ ���
	int Obstacle_top = Obstacle.getObj_y(); // ��ֹ��� ��� ���
	int Obstacle_bottom = Obstacle.getObj_y() + Obstacle.getObj_Width(); // ��ֹ��� �ϴ� ���

	// �浹 ���� Ȯ�� (�ε����� false)
	if (Dino_right > Obstacle_left && Dino_left < Obstacle_right && Dino_bottom > Obstacle_top && Dino_top < Obstacle_bottom)
	{
		return false;
	}
	return true;
}

bool Collision::isPassingThrough(Object& dino, Object& upperObstacle, Object& lowerObstacle)
{
	// ����� ��ֹ����� �浹�� �Ͼ���� Ȯ�� (�浹���� �ʾҴٸ� true)
	return isCollision(dino, upperObstacle) && isCollision(dino, lowerObstacle);
}

bool Collision::isCollisionCoin(Object& dino, Object& coin)
{
	// ������ ��� ���
	int Dino_left = dino.getObj_x(); 
	int Dino_right = dino.getObj_x() + dino.getObj_Width();
	int Dino_top = dino.getObj_y();
	int Dino_bottom = dino.getObj_y() + dino.getObj_Height();

	// ������ ��� ���
	int Coin_left = coin.getObj_x(); // ������ ���� ���
	int Coin_right = coin.getObj_x() + coin.getObj_Width(); // ������ ������ ���
	int Coin_top = coin.getObj_y(); // ������ ��� ���
	int Coin_bottom = coin.getObj_y() + coin.getObj_Height(); // ������ �ϴ� ���

	// �浹 ���� Ȯ�� (����� ������ �浹�ϸ� true)
	if (Dino_right > Coin_left && Dino_left < Coin_right && Dino_bottom > Coin_top && Dino_top < Coin_bottom)
	{
		return true;
	}
	return false;
}
