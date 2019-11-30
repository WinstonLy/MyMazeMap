#include <iostream>
#include <Windows.h>
#include "MazePerson.h"
#include "MazeMap.h"

using namespace std;

int CMazePerson::count = -1;

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
	Gotoxy(m_iCurrentPositionX, m_iCurrentPositionY);
	cout << m_cPerson;
	Sleep(1000);
}

//******* 设置前一位置的横、纵坐标 *******//
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
	int tempX = 0;
	int tempY = 0;
	char  tempDirection;

	int successFlag = HI_FALSE;
	while (!successFlag)
	{
		// 判断向哪个方向移动
		tempDirection = m_cDirection;

		m_cDirection = CMazeMap::CheckNext(m_iCurrentPositionX, m_iCurrentPositionY, m_cDirection);
		if (m_iSpeed == NORMAL)
		{
			switch (m_cDirection)
			{
			// 向上移动
			case w:
				if ((m_iCurrentPositionX != m_iPreviousPositionX + 1) &&(m_cDirection != f) )
				{
					SetPreviousPosition(m_iCurrentPositionX, m_iCurrentPositionY);
					SetCurrentPosition(m_iCurrentPositionX - 1, m_iCurrentPositionY);
				}
				else
					m_cDirection = '1';
				break;
			// 向下移动
			case s:
				if ((m_iCurrentPositionX != m_iPreviousPositionX - 1) &&(m_cDirection != f))
				{
					SetPreviousPosition(m_iCurrentPositionX, m_iCurrentPositionY);
					SetCurrentPosition(m_iCurrentPositionX + 1, m_iCurrentPositionY);
				}	
				else
					m_cDirection = '2';
				break;
			// 向左移动
			case a:
				if ((m_iCurrentPositionY != m_iPreviousPositionY + 1) && (m_cDirection != f))
				{
					SetPreviousPosition(m_iCurrentPositionX, m_iCurrentPositionY);
					SetCurrentPosition(m_iCurrentPositionX, m_iCurrentPositionY - 1);
					
				}
				else
					m_cDirection = '3';
				break;
			// 向右移动
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
			//输入有误
			default:
				cout << "input error" << endl;
				break;
			}
		}
		// 判断是否找到出口
		successFlag = CMazeMap::Success(m_iCurrentPositionX, m_iCurrentPositionY);
		if (successFlag)
		{
			Gotoxy(2, 50);
			cout << "Success, you go out maze!" << endl;
		}
	}
}

//******* 控制光标在控制台的显示位置 *******//
void CMazePerson::Gotoxy(int _x, int _y)
{
	COORD cd;
	cd.X = _y;
	cd.Y = _x;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cd);
};
