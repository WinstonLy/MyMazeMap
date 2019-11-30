#include <iostream>
#include <Windows.h>
#include "MazePerson.h"
#include "MazeMap.h"

using namespace std;

int CMazePerson::count = -1;

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
	Gotoxy(m_iCurrentPositionX, m_iCurrentPositionY);
	cout << m_cPerson;
	Sleep(1000);
}

//******* ����ǰһλ�õĺᡢ������ *******//
void CMazePerson::SetPreviousPosition(int _x, int _y)
{
	m_iPreviousPositionX = _x;
	m_iPreviousPositionY = _y;
	Gotoxy(0, 50);
	cout << count;
	Gotoxy(m_iCurrentPositionX, m_iCurrentPositionY);
	count++;
	if (count != 0)
	{
		cout << ' ';
	}
	Sleep(1000);
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
	int tempX = 0;
	int tempY = 0;
	char  tempDirection;

	int successFlag = HI_FALSE;
	while (!successFlag)
	{
		// �ж����ĸ������ƶ�
		tempDirection = m_cDirection;

		m_cDirection = CMazeMap::CheckNext(m_iCurrentPositionX, m_iCurrentPositionY, m_cDirection);
		if (m_iSpeed == NORMAL)
		{
			switch (m_cDirection)
			{
			// �����ƶ�
			case w:
				if ((m_iCurrentPositionX != m_iPreviousPositionX + 1) &&(m_cDirection != f) )
				{
					SetPreviousPosition(m_iCurrentPositionX, m_iCurrentPositionY);
					SetCurrentPosition(m_iCurrentPositionX - 1, m_iCurrentPositionY);
				}
				else
					m_cDirection = '1';
				break;
			// �����ƶ�
			case s:
				if ((m_iCurrentPositionX != m_iPreviousPositionX - 1) &&(m_cDirection != f))
				{
					SetPreviousPosition(m_iCurrentPositionX, m_iCurrentPositionY);
					SetCurrentPosition(m_iCurrentPositionX + 1, m_iCurrentPositionY);
				}	
				else
					m_cDirection = '2';
				break;
			// �����ƶ�
			case a:
				if ((m_iCurrentPositionY != m_iPreviousPositionY + 1) && (m_cDirection != f))
				{
					SetPreviousPosition(m_iCurrentPositionX, m_iCurrentPositionY);
					SetCurrentPosition(m_iCurrentPositionX, m_iCurrentPositionY - 1);
					
				}
				else
					m_cDirection = '3';
				break;
			// �����ƶ�
			case d:
				if ((m_iCurrentPositionY != m_iPreviousPositionY - 1) &&(m_cDirection != f))
				{
					SetPreviousPosition(m_iCurrentPositionX, m_iCurrentPositionY);
					SetCurrentPosition(m_iCurrentPositionX, m_iCurrentPositionY + 1);
				}
				else
					m_cDirection = '4';
				break;
			case f:
				tempX = m_iPreviousPositionX;
				tempY = m_iPreviousPositionY;
				SetPreviousPosition(m_iCurrentPositionX, m_iCurrentPositionY);
				CMazeMap::SetMazeArray(m_iPreviousPositionX, m_iPreviousPositionY);
				SetCurrentPosition(tempX, tempY);
				if (tempDirection == w)
					m_cDirection = '1';
				if (tempDirection == s)
					m_cDirection = '2';
				if (tempDirection == a)
					m_cDirection = '3';
				if (tempDirection == d)
					m_cDirection = '4';
				//m_cDirection = f;
				break;
			//��������
			default:
				cout << "input error" << endl;
				break;
			}
		}
		// �ж��Ƿ��ҵ�����
		successFlag = CMazeMap::Success(m_iCurrentPositionX, m_iCurrentPositionY);
		if (successFlag)
		{
			Gotoxy(2, 50);
			cout << "Success, you go out maze!" << endl;
		}
	}
}

//******* ���ƹ���ڿ���̨����ʾλ�� *******//
void CMazePerson::Gotoxy(int _x, int _y)
{
	COORD cd;
	cd.X = _y;
	cd.Y = _x;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cd);
};
