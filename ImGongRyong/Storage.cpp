#include "Storage.h"

// ���� ����
void Storage::saveScore(int score)
{
	// ���� ������ �б� ���� ifstream ��ü ����
	ifstream recordFile("HighScores.txt");

	// ������ �̸��� ����
	vector<pair<int, string>> highScores;

	// ���� ��ŷ �����͸� ���Ͽ��� �о�� ���Ϳ� ����
	int currentScore;
	string initials;

	while (recordFile >> currentScore >> initials)
	{
		highScores.push_back({ currentScore, initials });
	}
	recordFile.close();

	// �̸� �Է� �ޱ�
	Dashboard::printCenteredText("�̸��� �Է��ϼ���: ");
	string name;
	cin >> name;

	// ���ο� ������ �̸��� ���Ϳ� �߰�
	highScores.push_back({ score, name });

	// ���͸� ������ ���� ������ ����
	sort(highScores.begin(), highScores.end(), greater<pair<int, string>>());
	
	// ��ŷ 10�������� �����ϵ��� ������ ũ�� ����
	highScores.resize(min(highScores.size(), static_cast<size_t>(10)));

	// ���Ͽ� ���ο� ��ŷ ������ ����
	ofstream recordOutFile("HighScores.txt");
	for (const auto& entry : highScores)
	{
		// ���ĵ� ��ŷ �����͸� ���Ͽ� ����
		recordOutFile << entry.first << " " << entry.second << endl;
	}
	recordOutFile.close();
}

// ��ŷ ȭ�� ���
int Storage::displayRanking()
{
	ifstream recordFile("HighScores.txt");

	// ������ ������ ������ ���
	if (!recordFile)
	{
		Dashboard::printCenteredText("���: ���� ��ŷ�� �����ϴ�. ������ �÷����ؼ� �������ּ���.");
		cout << endl << endl;
		Dashboard::printCenteredText("�ƹ� Ű�� ������ ���� ȭ������ ���ư��ϴ�...");

		// Windows API�� ����Ͽ� Ű �Է��� ���� ������ ���
		while (!_kbhit()) {}

		// Ű �Է� �ޱ�
		char key = _getch();

		return 0;
	}

	vector<pair<int, string>> highScores;

	int currentScore;
	string initials;
	
	// ���Ͽ��� ��ŷ �����͸� �о�� ���Ϳ� ����
	while (recordFile >> currentScore >> initials)
	{
		highScores.push_back({ currentScore, initials });
	}
	recordFile.close();

	system("cls"); // ȭ�� �����

	const std::string redColor = "\033[31m"; // ������
	const std::string greenColor = "\033[32m"; // �ʷϻ�
	const std::string yellowColor = "\033[33m"; // �Ķ���
	const std::string whiteColor = "\033[0m"; // ���
	
	// ��ŷ ��� ���
	printCenteredText("********* Ranking *********", yellowColor);
	cout << endl;
	printCenteredText("***************************", greenColor);
	cout << endl;

	// ���� 10���� ��ŷ�� ���
	int rank = 1;
	for (const auto& entry : highScores)
	{
		string scoreLine = to_string(rank) + ". �̸�: " + entry.second + ", ����: " + to_string(entry.first) + "��";
		printCenteredText(scoreLine, whiteColor); 
		cout << endl;
		rank++;
	}
	printCenteredText("***************************", greenColor);
	cout << endl;
	printCenteredText("***************************", yellowColor);
	cout << endl;

	// ��µ� ��ŷ �� ��ȯ
	return highScores.size();
}

// ������ �������� ����
void Storage::askSaveScore(int score)
{
	while (true)
	{
		cout << "������ �����Ͻðڽ��ϱ�?(Y/N): ";
		char saveChoice;
		cin >> saveChoice;
		cin.ignore(); // �Է� ���� ����

		// �Է��� �ҹ��ڷ� ��ȯ�Ͽ� ó��
		saveChoice = tolower(saveChoice);

		if (saveChoice == 'y')
		{
			ifstream recordFile("HighScores.txt");

			// ������ ���ٸ� ����
			if (!recordFile)
			{

				// �� ���� ����
				ofstream newFile("HighScores.txt");
				newFile.close();

				// ������ ���� �ٽ� ����
				recordFile.open("HighScores.txt");
				if (!recordFile)
				{
					Dashboard::printCenteredText("���: 'HighScores.txt' ������ �������� �ʽ��ϴ�.");
					return;
				}
				Dashboard::printCenteredText("����: ");
				cout << score << endl;

				// saveScore ȣ���Ͽ� ���� ����
				saveScore(score);

				return;
			}

			recordFile.close();

			if (displayRanking()) // ��ŷ ������ ǥ��
			{
				Dashboard::printCenteredText("����: ");
				cout << score << endl;

				// saveScore ȣ���Ͽ� ���� ����
				saveScore(score);
			}
			break; // ���� �Ϸ� �� �ݺ��� ����
		}
		else if (saveChoice == 'n')
		{
			// n �� �Է����� �� ���� ȭ������ ���ư���
			return;
		}
		else
		{
			// �߸��� �Է� ó��
			cout << "���: �߸��� �Է��Դϴ�. 'y' �Ǵ� 'n'�� �Է����ּ���." << endl;
		}
	}
}
