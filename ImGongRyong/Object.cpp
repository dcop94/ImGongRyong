// ���� �̸�: Object.cpp
// ����: �� ������ Object Ŭ������ ������ �����ϰ� �ֽ��ϴ�. (��ü)
// �ۼ���: ���ι�
// �ۼ� ��¥: 2024-06-02
// ���� �̷�:
//		- 2024-xx-xx: [	] (�ۼ���:)

#include <iostream>
#include "Object.h"

using namespace std;

	// �Ű������� �ִ� ������
	Object::Object(int objX, int objY, int objWidth, int objHeight, string& shape)
	{
		this->objX = objX;
		this->objY = objY;
		this->objWidth = objWidth;
		this->objHeight = objHeight;
		this->objShape = objShape;
	}
	
	// ��ǥ ������
	void Object::setPosition(int objX, int objY)
	{
		this->objX = objX;
		this->objY = objY;
	}

	// ũ�� ������
	void Object::setSize(int objWidth, int objHeight)
	{
		this->objWidth = objWidth;
		this->objHeight = objHeight;
	}

	// ��� ������
	void Object::setShape(string& shape)
	{
		this->objShape = objShape;
	}

	// ��ǥ ������
	int Object::getObj_x()
	{
		return this->objX;
	}
	int Object::getObj_y()
	{
		return this->objY;
	}

	// ũ�� ������
	int Object::getObj_Width()
	{
		return this->objWidth;
	}
	int Object::getObj_Height()
	{
		return this->objHeight;
	}

	// ��� ������
	string Object::getObj_Shape()
	{
		return this->objShape;
	}
