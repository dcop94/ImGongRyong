// ���� �̸�: Object.h
// ����: �� ������ Object Ŭ������ ������ �����ϰ� �ֽ��ϴ�. Object Ŭ������ ���ӿ��� [	 	] �� ���� �մϴ�.
// �ۼ���: ���ι�
// �ۼ� ��¥: 2024-06-02
// ���� �̷�:
//		- 2024-xx-xx: [] (�ۼ���: )

#pragma once

#include <string>
using namespace std;

class Object
{
protected:
	int objX; // ��ü�� x ��ǥ
	int objY; // ��ü�� y ��ǥ
	int objWidth; // ��ü�� �ʺ�
	int objHeight; // ��ü�� ����
	std::string objShape; // ��ü�� ���� ����� ��Ÿ���� ���ڿ� (ex: "Dino" )
	

public:
	// ������
	Object(int x, int y, int width, int height, string& shpae);

	// ��ǥ ������
	void setPosition(int x, int y);

	// ũ�� ������
	void setSize(int width, int height);

	// ��� ������
	void setShape(string& shape);

	// ��ǥ ������
	int getObj_x(); 
	int getObj_y(); 

	// ũ�� ������
	int getObj_Width(); 
	int getObj_Height(); 

	// ��� ������
	std::string getObj_Shape(); 

};