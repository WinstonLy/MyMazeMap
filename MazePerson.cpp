#include <iostream>
#include <Windows.h>
#include "MazePerson.h"
#include "MazeMap.h"

using namespace std;

//******* Ĭ�Ϲ��캯������ʼ���Գ�ʼ��λ�� *******//
CMazePerson::CMazePerson():m_cPerson('T'),m_cDirection('W')
{
	// Ĭ���Թ��ĳ�ʼλ��
	m_iCurrentPositionX = 0; 
	m_iCurrentPositionY = 15;
	m_iPreviousPositionX = 0;
	m_iPreviousPositionY = 15;
	m_iSpeed = NORMAL;
}

//******* �������� *******//
CMazePerson::~CMazePerson()
{

}

//******* �������Թ��˵�������� *******//
//******* _person:�˵��ַ� *******//
//******* _direction:�˵�ǰ������ *******//
//******* _speed:�ƶ��ٶ� *******//
void CMazePerson::SetPersonAttr(char _person, char _direction, int _speed)
{
	m_cPerson = _person;
	m_cDirection = _direction;
	m_iSpeed = _speed;
}

//******* ���õ�ǰλ�õĺᡢ������ *******//
void CMazePerson::SetCurrentPosition(int _x, int _y)
{
	m_iCurrentPositionX = _x;
	m_iCurrentPositionY = _y;
}

//******* ����ǰһλ�õĺᡢ������ *******//
void CMazePerson::SetPreviousPosition(int _x, int _y)
{
	m_iPreviousPositionX = _x;
	m_iPreviousPositionY = _y;
}

//******* ��ӡ�����ǰλ�õ�������Ϣ *******//
void CMazePerson::GetCurrentPosition()
{
	cout << "Current(" << m_iCurrentPositionX << ',' << m_iCurrentPositionY << ')' << endl;
}

//******* ��ӡ���ǰһλ�õ�������Ϣ *******//
void CMazePerson::GetPreviousPosition()
{
	cout << "Previous(" << m_iPreviousPositionX << ',' << m_iPreviousPositionY << ')' << endl;
}

//******* �����ƶ�����Ѱ���Թ����� *******//
void CMazePerson::PersonMove()
{
	// char _direction;
	int successFlag = HI_FALSE;
	while (!successFlag)
	{
		m_cDirection = getchar();
		if (m_iSpeed == NORMAL)
		{
			switch (m_cDirection)
			{
			// �����ƶ�
			case w:
				if (CMazeMap::CheckNext(m_iCurrentPositionX, m_iCurrentPositionY, m_cDirection))
				{
					m_iPreviousPositionX = m_iCurrentPositionX;
					m_iPreviousPositionY = m_iCurrentPositionY;
					m_iCurrentPositionX += 1;
					m_iCurrentPositionY += 0;
				}
				break;
			//�����ƶ�
			case s:
				if (CMazeMap::CheckNext(m_iCurrentPositionX, m_iCurrentPositionY, m_cDirection))
				{
					m_iPreviousPositionX = m_iCurrentPositionX;
					m_iPreviousPositionY = m_iCurrentPositionY;
					m_iCurrentPositionX -= 1;
					m_iCurrentPositionY += 0;
				}
				break;
			case a:
				if (CMazeMap::CheckNext(m_iCurrentPositionX, m_iCurrentPositionY, m_cDirection))
				{
					m_iPreviousPositionX = m_iCurrentPositionX;
					m_iPreviousPositionY = m_iCurrentPositionY;
					m_iCurrentPositionX += 0;
					m_iCurrentPositionY -= 1;
				}
				break;
			case d:
				if (CMazeMap::CheckNext(m_iCurrentPositionX, m_iCurrentPositionY, m_cDirection))
				{
					m_iPreviousPositionX = m_iCurrentPositionX;
					m_iPreviousPositionY = m_iCurrentPositionY;
					m_iCurrentPositionX += 0;
					m_iCurrentPositionY += 1;
				}
				break;
			default:
				cout << "input error" << endl;
				break;
			}
			successFlag = CMazeMap::Success(m_iCurrentPositionX, m_iCurrentPositionY);
		}
		cout << "Success, you go out maze!" << endl;
	}
}

void CMazePerson::Gotoxy()
{
	COORD cd;
	cd.X = m_iCurrentPositionX;
	cd.Y = m_iCurrentPositionY;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cd);
};
