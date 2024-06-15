#pragma once

#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <vector>

using namespace std;

class Dashboard
{
public:
	Dashboard();

	// �ܼ�â�� �߾��� ���(����, ����)
	void printCenteredText(const string& text, const string& textColor = "");

	// ����ȭ�� ���
	void displayMainMenu();

	// ����ȭ�� ���
	int getUserChoice();

	// ���� ���۹� 
	void displayControls();
};