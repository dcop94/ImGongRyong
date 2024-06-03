#include "Graphic.h"

// ��ü �׷��� ����

char* make_pillar(int phase)
{
	/*---------------------------------------*/
	// 1. ó���� �Ա����� ��� ����
	/*---------------------------------------*/

	// ������ 20*200 ���Թ� ����
	int pillar_Size = DINO_WIDTH * CONSOLE_HEIGHT;
	char* pillar = new char[pillar_Size];
	
	for (int i = 0; i < pillar_Size; i++)
	{
		pillar[i] = '*';
	}

	/*---------------------------------------*/
	// 2. ����� �´� �Ա��� ���� ���� 1~3����
	/*---------------------------------------*/
	
	// (����� �´� ����) * 20 �� ���Թ� �ϳ� ����

	srand(time(NULL));

	int voidWidth = DINO_WIDTH;
	int voidHeight;

	switch (phase)
	{
	case 1:
		voidHeight = 45;
		break;

	case 2:
		voidHeight = 35;
		break;

	case 3:
		voidHeight = 25;
		break;
	}

	/*---------------------------------------*/
	// 3. ������ ���̿� ���� �������� ��ġ�� ����
	/*---------------------------------------*/

	// y���� ����� �� �ִ� ����
	// ���� �����ǥ�� 0~199 ���⼭ ����� �´� ���̸� ���ָ� �ȴ�.

	int Yscope = 200 - voidHeight - 1;
	int Ypos = (rand()*rand()-5*rand()) % Yscope;


	/*---------------------------------------*/
	// 4. ������ ��ǥ���� ������ ���̸�ŭ �Ա� ����
	/*---------------------------------------*/


	for (int y = Ypos; y < Ypos + voidHeight; y++)
	{
		for (int x = 0; x < DINO_WIDTH; x++)
		{
			pillar[y * DINO_WIDTH + x] = ' '; // ������� �����̽� ��;
		}
	}

	return pillar;
}

char* make_dino(long sequence)
{
    // ������ 20*20 ũ��

    /*---------------------------------------*/
    // 1. �������
    /*---------------------------------------*/

    int dinoSize = DINO_WIDTH * DINO_HEIGHT;
    char* dino = new char[dinoSize + 1];
    
    char* write_begin = dino;

    /*---------------------------------------*/
    // 2. ���� �������� ���� ������ ����
    /*---------------------------------------*/

    // ��ĭ * 2 = �׸� �ϳ�
    if (sequence == 1)
    {
        strncpy(write_begin, "        *           ", DINO_WIDTH); write_begin += DINO_WIDTH;
        strncpy(write_begin, "     * **********   ", DINO_WIDTH); write_begin += DINO_WIDTH;
        strncpy(write_begin, "    ****O*********  ", DINO_WIDTH; write_begin += DINO_WIDTH;
        strncpy(write_begin, "    *********** **  ", DINO_WIDTH); write_begin += DINO_WIDTH;
        strncpy(write_begin, "    ******** **     ", DINO_WIDTH); write_begin += DINO_WIDTH;
        strncpy(write_begin, "    ********    *   ", DINO_WIDTH); write_begin += DINO_WIDTH;
        strncpy(write_begin, "     ******** * *   ", DINO_WIDTH); write_begin += DINO_WIDTH;
        strncpy(write_begin, "     ***   *****    ", DINO_WIDTH); write_begin += DINO_WIDTH;
        strncpy(write_begin, "      ***           ", DINO_WIDTH); write_begin += DINO_WIDTH;
        strncpy(write_begin, "      ******        ", DINO_WIDTH); write_begin += DINO_WIDTH;
        strncpy(write_begin, "      ********      ", DINO_WIDTH); write_begin += DINO_WIDTH;
        strncpy(write_begin, "      ******  ***   ", DINO_WIDTH); write_begin += DINO_WIDTH;
        strncpy(write_begin, "      * ** ***      ", DINO_WIDTH); write_begin += DINO_WIDTH;
        strncpy(write_begin, "*     ******  **    ", DINO_WIDTH); write_begin += DINO_WIDTH;
        strncpy(write_begin, "*     *    *        ", DINO_WIDTH); write_begin += DINO_WIDTH;
        strncpy(write_begin, "*  *********        ", DINO_WIDTH); write_begin += DINO_WIDTH;
        strncpy(write_begin, "*  **  ** **        ", DINO_WIDTH); write_begin += DINO_WIDTH;
        strncpy(write_begin, "*****  ** **        ", DINO_WIDTH); write_begin += DINO_WIDTH;
        strncpy(write_begin, " **    **  ***      ", DINO_WIDTH); write_begin += DINO_WIDTH;
        strncpy(write_begin, "       ****         ", DINO_WIDTH); write_begin += DINO_WIDTH;
    }
    else
    {
        strncpy(write_begin, "        *           ", DINO_WIDTH); write_begin += DINO_WIDTH;
        strncpy(write_begin, "     * **********   ", DINO_WIDTH); write_begin += DINO_WIDTH;
        strncpy(write_begin, "    ****O*********  ", DINO_WIDTH); write_begin += DINO_WIDTH;
        strncpy(write_begin, "    *********** **  ", DINO_WIDTH); write_begin += DINO_WIDTH;
        strncpy(write_begin, "    ******** **     ", DINO_WIDTH); write_begin += DINO_WIDTH;
        strncpy(write_begin, "    ********    *   ", DINO_WIDTH); write_begin += DINO_WIDTH;
        strncpy(write_begin, "     ******** * *   ", DINO_WIDTH); write_begin += DINO_WIDTH;
        strncpy(write_begin, "     ***   *****    ", DINO_WIDTH); write_begin += DINO_WIDTH;
        strncpy(write_begin, "      ***           ", DINO_WIDTH); write_begin += DINO_WIDTH;
        strncpy(write_begin, "      ******        ", DINO_WIDTH); write_begin += DINO_WIDTH;
        strncpy(write_begin, "      **********    ", DINO_WIDTH); write_begin += DINO_WIDTH;
        strncpy(write_begin, "      ******    *   ", DINO_WIDTH); write_begin += DINO_WIDTH;
        strncpy(write_begin, "      * ** ****     ", DINO_WIDTH); write_begin += DINO_WIDTH;
        strncpy(write_begin, "*     ******  *     ", DINO_WIDTH); write_begin += DINO_WIDTH;
        strncpy(write_begin, "*     *    *        ", DINO_WIDTH); write_begin += DINO_WIDTH;
        strncpy(write_begin, "*  *********        ", DINO_WIDTH); write_begin += DINO_WIDTH;
        strncpy(write_begin, "*  **  ** **        ", DINO_WIDTH); write_begin += DINO_WIDTH;
        strncpy(write_begin, "***** **    **      ", DINO_WIDTH); write_begin += DINO_WIDTH;
        strncpy(write_begin, " **  **      ***    ", DINO_WIDTH); write_begin += DINO_WIDTH;
        strncpy(write_begin, "     ****           ", DINO_WIDTH); write_begin += DINO_WIDTH;
    }

    *write_begin = '\0'; // Null �߰�

    return dino;
}

char* make_coin()
{
    // ������ 10*10 ũ��
    int coinSize = COIN_WIDTH * COIN_HEIGHT;

    char* coin = new char[coinSize + 1];

    char* write_begin;

    strncpy(write_begin, "**********", COIN_WIDTH); write_begin += COIN_WIDTH;
    strncpy(write_begin, "*        *", COIN_WIDTH); write_begin += COIN_WIDTH;
    strncpy(write_begin, "*   **   *", COIN_WIDTH); write_begin += COIN_WIDTH;
    strncpy(write_begin, "*   **   *", COIN_WIDTH); write_begin += COIN_WIDTH;
    strncpy(write_begin, "*   **   *", COIN_WIDTH); write_begin += COIN_WIDTH;
    strncpy(write_begin, "*   **   *", COIN_WIDTH); write_begin += COIN_WIDTH;
    strncpy(write_begin, "*   **   *", COIN_WIDTH); write_begin += COIN_WIDTH;
    strncpy(write_begin, "*   **   *", COIN_WIDTH); write_begin += COIN_WIDTH;
    strncpy(write_begin, "*        *", COIN_WIDTH); write_begin += COIN_WIDTH;
    strncpy(write_begin, "**********", COIN_WIDTH); write_begin += COIN_WIDTH;

    *write_begin = '\0';

    return coin;
}