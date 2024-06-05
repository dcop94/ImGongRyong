// ���� �̸�: System.h
// ����: �� ������ System Ŭ������ ������ �����ϰ� �ֽ��ϴ�. System Ŭ������ ���ӿ��� �ð��� ����, �Ͻ������� ���� �մϴ�.
// �ۼ���: ���ι�
// �ۼ� ��¥: 2024-06-04
// ���� �̷�:
//		- 2024-06-05 ['calculateTimeScore', 'isgamePaused' �߰�] (�ۼ���: ���ι�)


#pragma once

class System
{
protected:
	int startTime; // ���� �ð�
	int currentTime; // ���� �ð� (���� �÷��� �ð�)
	int timeScore; // �ð� ����
	int coinScore; // ���� ����
	int totalScore; // �� ����
	bool isPaused; // ������ �Ͻ����� �������� Ȯ��

public:
	System(); // ������

	// �ð� ���� �޼���
	void startTimer(); // Ÿ�̸� ����
	void updateTime(); // ���� �ð� ������Ʈ
	void calculateTimeScore(); // �ð� ���� ���

	// ���� ���� �޼���
	void addCoinScore(int coins); // ���� ���� �߰�

	// �� ���� ���
	void calculateTotalScore(); // ���� ����� �� ���� ���

	// ���� ��ȯ �޼���
	int getTotalScore(); // �� ���� ��ȯ

	// �Ͻ� ���� ���� �޼���
	void pauseGame(); // ���� �Ͻ� ����
	void resumeGame(); // ���� �簳
	bool isGamePaused(); //���� �Ͻ� ���� ���� ��ȯ
};