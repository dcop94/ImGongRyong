// ���� �̸�: Object.h
// ����: - ���ӿ� �����ϴ� �پ��� ������Ʈ�� �����մϴ�.
// �ۼ���: ���ι�
// �ۼ� ��¥: 2024-06-02
// ���� �̷�:
//		- 2024-06-05: ['string& objshpae' -> 'strint& objshape' ��Ÿ ����] (�ۼ���: ���ι�)

#pragma once
#ifndef OBJECT_H
#define OBJECT_H

class Object
{
public:
    class Plane
    {
    public:
        int planeX, planeY;
        float velocity;
        Plane(int p_startX, int p_startY) : planeX(p_startX), planeY(p_startY), velocity(0) {}
        void update(float gravity, float jumpSpeed, bool moveUp, bool moveDown);
    };

    class Pipe
    {
    public:
        int pipeX;
        int pipeY;
        Pipe(int pi_startX, int pi_StartY) : pipeX(pi_startX), pipeY(pi_StartY) {}
    };

    class Coin
    {
    public:
        int coinX;
        int coinY;
        Coin(int c_startX, int c_startY) : coinX(c_startX), coinY(c_startY) {}
    };
};




#endif // !OBJECT_H
