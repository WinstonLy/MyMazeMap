#pragma once
#include "MazeMap.h"
#ifndef __CMAZEPERSON__H__
#define __CMAZEPERSON__H__


//******* �����ٶȵı�ʶ�� *******//
constexpr int NORMAL = 0;
constexpr int FAST = 1;


//******* ���Թ����˵��� *******//
class CMazePerson
{
public:
	CMazePerson();					            // ���캯��
	~CMazePerson();					            // ��������
	void SetPersonAttr(char _person, char _direction, int _speed);// �������Թ��˵����ԣ��ַ��������ٶ�
	void SetCurrentPosition(int _x, int _y);	// ���õ�ǰλ��
	void SetPreviousPosition(int _x, int _y);	// ����ǰһλ��
	void GetCurrentPosition();					// ��ȡ��ǰλ��
	void GetPreviousPosition();					// ��ȡǰһλ��
	void PersonMove();							// �������Թ������ƶ�
	void Gotoxy(int _x, int _y);				// ȷ������̨���ַ������λ��

private:
	char m_cPerson;					// �˵��ַ�
	char m_cDirection;				// �˵ĳ��򣬼�ǰ������
	int m_iCurrentPositionX;		// ��ǰλ�õĺ�����
	int m_iCurrentPositionY;		// ��ǰλ�õ�������
	int m_iPreviousPositionX;		// ǰһλ�õĺ�����
	int m_iPreviousPositionY;		// ǰһλ�õ�������
	int m_iSpeed;					// �ƶ��ٶ�
	static int count;						// �ƶ�����
};

#endif       //__CMAZEPERSON__H__