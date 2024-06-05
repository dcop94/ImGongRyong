// ���� �̸�: Object.h
// ����: �� ������ Object Ŭ������ ������ �����ϰ� �ֽ��ϴ�. Object Ŭ������ ���ӿ��� ��ü�� ���¸� ���� �մϴ�.
// �ۼ���: ���ι�
// �ۼ� ��¥: 2024-06-02
// ���� �̷�:
//		- 2024-xx-xx: [] (�ۼ���: )

#pragma once

#include <string>

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
	Object(int objX, int objY, int objWidth, int objHeight, std::string& objShpae);

	// ��ǥ ������
	void setPosition(int objX, int objY);

	// ũ�� ������
	void setSize(int objWidth, int objHeight);

	// ��� ������
	void setShape(std::string& objShape);

	// ��ǥ ������
	int getObj_x(); 
	int getObj_y(); 

	// ũ�� ������
	int getObj_Width(); 
	int getObj_Height(); 

	// ��� ������
	std::string getObj_Shape(); 

};