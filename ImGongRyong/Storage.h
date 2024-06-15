#pragma once

#include "Dashboard.h"
#include <algorithm>
#include <fstream>
#include <vector>
#include <string>
#include <utility>
#include <conio.h>


using namespace std;

class Storage : public Dashboard
{
protected:
	const string HighScoresFile = "HighScore.txt";
public:
	// ���� ���� ����
	void askSaveScore(int score);
	// ���� ���� �ϱ�
	void saveScore(int score);
	// ��ŷ ����
	int displayRanking();
};