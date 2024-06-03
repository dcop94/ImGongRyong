#include "Graphic.h"

// ��ü �׷��� ����

char* make_pillar(int phase)
{
	/*---------------------------------------*/
	// 1. ó���� �Ա����� ��� ����
	/*---------------------------------------*/

	// ������ 20*200 ���Թ� ����
	int pillar_Size = DINO_WIDTH * CONSOLE_Y;
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
	int Ypos = (rand()*rand()-2*rand()) % Yscope;


	/*---------------------------------------*/
	// 4. ������ ��ǥ���� ������ ���̸�ŭ �Ա� ����
	/*---------------------------------------*/


	for (int y = Ypos; y < Ypos + voidHeight; y++)
	{
		for (int x = 0; x < 20; x++)
		{
			pillar[y * 20 + x] = ' '; // ������� �����̽� ��;
		}
	}

	return pillar;
}

char* make_dino(long sequence)
{
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
        strncpy(write_begin, "        *           ", 20); write_begin += 20;
        strncpy(write_begin, "     * **********   ", 20); write_begin += 20;
        strncpy(write_begin, "    ****O*********  ", 20); write_begin += 20;
        strncpy(write_begin, "    *********** **  ", 20); write_begin += 20;
        strncpy(write_begin, "    ******** **     ", 20); write_begin += 20;
        strncpy(write_begin, "    ********        ", 20); write_begin += 20;
        strncpy(write_begin, "     ******** * *   ", 20); write_begin += 20;
        strncpy(write_begin, "     ***   *****    ", 20); write_begin += 20;
        strncpy(write_begin, "      ***           ", 20); write_begin += 20;
        strncpy(write_begin, "      ******        ", 20); write_begin += 20;
        strncpy(write_begin, "      ********      ", 20); write_begin += 20;
        strncpy(write_begin, "      ******  ***   ", 20); write_begin += 20;
        strncpy(write_begin, "      * ** ***      ", 20); write_begin += 20;
        strncpy(write_begin, "*     ******  **    ", 20); write_begin += 20;
        strncpy(write_begin, "*     *    *        ", 20); write_begin += 20;
        strncpy(write_begin, "*  *********        ", 20); write_begin += 20;
        strncpy(write_begin, "*  **  ** **        ", 20); write_begin += 20;
        strncpy(write_begin, "*****  ** **        ", 20); write_begin += 20;
        strncpy(write_begin, " **    **  ***      ", 20); write_begin += 20;
        strncpy(write_begin, "       ****         ", 20); write_begin += 20;
    }
    else
    {
        strncpy(write_begin, "        *           ", 20); write_begin += 20;
        strncpy(write_begin, "     * **********   ", 20); write_begin += 20;
        strncpy(write_begin, "    ****O*********  ", 20); write_begin += 20;
        strncpy(write_begin, "    *********** **  ", 20); write_begin += 20;
        strncpy(write_begin, "    ******** **     ", 20); write_begin += 20;
        strncpy(write_begin, "    ********        ", 20); write_begin += 20;
        strncpy(write_begin, "     ******** * *   ", 20); write_begin += 20;
        strncpy(write_begin, "     ***   *****    ", 20); write_begin += 20;
        strncpy(write_begin, "      ***           ", 20); write_begin += 20;
        strncpy(write_begin, "      ******        ", 20); write_begin += 20;
        strncpy(write_begin, "      **********    ", 20); write_begin += 20;
        strncpy(write_begin, "      ******    *   ", 20); write_begin += 20;
        strncpy(write_begin, "      * ** ****     ", 20); write_begin += 20;
        strncpy(write_begin, "*     ******  *     ", 20); write_begin += 20;
        strncpy(write_begin, "*     *    *        ", 20); write_begin += 20;
        strncpy(write_begin, "*  *********        ", 20); write_begin += 20;
        strncpy(write_begin, "*  **  ** **        ", 20); write_begin += 20;
        strncpy(write_begin, "***** **    **      ", 20); write_begin += 20;
        strncpy(write_begin, " **  **      ***    ", 20); write_begin += 20;
        strncpy(write_begin, "     ****          ", 20); write_begin += 20;
    }

    *write_begin = '\0'; // Null �߰�

    return dino;
}