// ���� �̸�: System.cpp
// ����: �� ������ System Ŭ������ ������ �����ϰ� �ֽ��ϴ�. (�ý���)
// �ۼ���: ���ι�
// �ۼ� ��¥: 2024-06-04
// ���� �̷�:
//		- 2024-06-05 ['calculateTimeScore', 'isgamePaused' �߰�] (�ۼ���: ���ι�)

#include <ctime>
#include "System.h"

// ������
System::System()
{
	this->startTime = 0;
	this->currentTime = 0;
	this->timeScore = 0;
	this->coinScore = 0;
	this->totalScore = 0;
	this->isPaused = false;
}

// ������ ������ ���� ���� �ð��� ���� �ð����� ����
void System::startTimer()
{
	startTime = clock();
}


// ���� �ð� ������Ʈ
void System::updateTime()
{
	if (isPaused) 
	{
		currentTime = clock();
	}
}

// �ð� ���� ���
void System::calculateTimeScore()
{
	updateTime();
	double overedTime = double(currentTime - startTime) / CLOCKS_PER_SEC; // ��� �ð��� �� ������ ���

	// ����� ���������� ��ȯ.(�Ҽ��� ���ϴ� �������� 10�� ���� 0.1�� ���� ��� ����) 
	timeScore = static_cast<long>(overedTime * 10); // 0.1�ʴ� 1������ ���
}

// ���� ���� �߰�
void System::addCoinScore(int coins)
{
	coinScore += coins;
}

// �Ͻ� ����
void System::pauseGame()
{
	if (isPaused)
	{
		currentTime = clock() - startTime;
		isPaused = true;
	}
}

// ���� �簳
void System::resumeGame()
{
	if (!isPaused) 
	{
		startTime = clock() - currentTime;
		isPaused = false;
	}
}

// ���� ������ �� ������ ���(�ð� ���� + ���� ����)
void System::calculateTotalScore()
{
	if (!isPaused)
	{
		calculateTimeScore(); // timeScore�� ���
	}
	totalScore = timeScore + coinScore;
}

// ������ �� ������ ��ȯ
int System::getTotalScore()
{
	return totalScore;
}

// ���� ������ �Ͻ� ���� �������� ���θ� ��ȯ
bool System::isGamePaused()
{
	return isPaused;
}