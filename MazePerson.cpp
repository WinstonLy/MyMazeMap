#include <iostream>
#include <Windows.h>
#include "MazePerson.h"
#include "MazeMap.h"

using namespace std;

//******* 默认构造函数，初始化以初始化位置 *******//
CMazePerson::CMazePerson():m_cPerson('T'),m_cDirection('W')
{
	// 默认迷宫的初始位置
	m_iCurrentPositionX = 0; 
	m_iCurrentPositionY = 15;
	m_iPreviousPositionX = 0;
	m_iPreviousPositionY = 15;
	m_iSpeed = NORMAL;
}

//******* 析构函数 *******//
CMazePerson::~CMazePerson()
{

}

//******* 设置走迷宫人的相关属性 *******//
//******* _person:人的字符 *******//
//******* _direction:人的前进方向 *******//
//******* _speed:移动速度 *******//
void CMazePerson::SetPersonAttr(char _person, char _direction, int _speed)
{
	m_cPerson = _person;
	m_cDirection = _direction;
	m_iSpeed = _speed;
}

//******* 设置当前位置的横、纵坐标 *******//
void CMazePerson::SetCurrentPosition(int _x, int _y)
{
	m_iCurrentPositionX = _x;
	m_iCurrentPositionY = _y;
}

//******* 设置前一位置的横、纵坐标 *******//
void CMazePerson::SetPreviousPosition(int _x, int _y)
{
	m_iPreviousPositionX = _x;
	m_iPreviousPositionY = _y;
}

//******* 打印输出当前位置的坐标信息 *******//
void CMazePerson::GetCurrentPosition()
{
	cout << "Current(" << m_iCurrentPositionX << ',' << m_iCurrentPositionY << ')' << endl;
}

//******* 打印输出前一位置的坐标信息 *******//
void CMazePerson::GetPreviousPosition()
{
	cout << "Previous(" << m_iPreviousPositionX << ',' << m_iPreviousPositionY << ')' << endl;
}

//******* 控制移动，来寻找迷宫出口 *******//
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
			// 向上移动
			case w:
				if (CMazeMap::CheckNext(m_iCurrentPositionX, m_iCurrentPositionY, m_cDirection))
				{
					m_iPreviousPositionX = m_iCurrentPositionX;
					m_iPreviousPositionY = m_iCurrentPositionY;
					m_iCurrentPositionX += 1;
					m_iCurrentPositionY += 0;
				}
				break;
			//向下移动
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
