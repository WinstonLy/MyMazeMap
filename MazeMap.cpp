#include <iostream>
#include <stdlib.h>
//#include <stdio.h>
#include "MazeMap.h"

using namespace std;

//******* ��̬��Ա������ʼ�� *******//
int CMazeMap::m_iMazeCol = g_iScreenHeight;
int CMazeMap::m_iMazeRow = g_iScreenWidth;
int CMazeMap::m_iMazeMapArray[g_iScreenHeight][g_iScreenWidth] = { 0 };

//******* ���캯������ʼ��������������Ҫ��������Ĭ�ϵ�ͼ *******//
CMazeMap::CMazeMap():m_cMazeWall('#'), m_cMazeRoad(' ')
{
	//m_iMazeCol = _x;    //�Թ��������߶�
	//m_iMazeRow = _y;   //�Թ����������
	//m_iMazeMapArray[g_iScreenHeight][g_iScreenWidth] = { 0 };
}

//******** �������� *******//
CMazeMap::~CMazeMap()
{

}

//******* ����ǽ�Ĺ����ַ� *******//
void CMazeMap::SetWall(char _wall)
{
	m_cMazeWall = _wall;
}

//******* ��ȡǽ������ַ� *******//
char CMazeMap::GetWall()
{
	return m_cMazeWall;
}

//******* ����·������ַ� ******//
void CMazeMap::SetRoad(char _pathway)
{
	m_cMazeRoad = _pathway;
}

//******* ��ȡ·������ַ� *******//
char CMazeMap::GetRoad()
{
	return m_cMazeRoad;
}

//****** ����Ĭ���Թ���������� *******//
//****** ���Թ��ĵ�15����Ϊ·������ط�ȫ��ǽ *******//
void CMazeMap::DefaultMap()
{
	for (int col = 0; col < g_iScreenHeight; col++)
	{
		for (int row = 0; row < g_iScreenWidth; row++)
		{
			if (row == 15)
			{
				CMazeMap::m_iMazeMapArray[col][row] = ROAD;
			}
			else
			{
				CMazeMap::m_iMazeMapArray[col][row] = WALL;
			}
		}
	}
}

//******* �Զ����Թ� *******//
//******* �����Թ����飬�С��У�����ֵ�����еĳ�Ա����m_iMazeArray ******//
void CMazeMap::SetMap(int *mazeMap, int _col, int _row)
{
	m_iMazeCol = _col;
	m_iMazeRow = _row;
	for (int col = 0; col < m_iMazeCol; col++)
	{
		for (int row = 0; row < m_iMazeRow; row++)
		{
			CMazeMap::m_iMazeMapArray[col][row] =*mazeMap;	
			mazeMap++;
		}
	}
}

//******* ���ҵ�����ͬʱ��mazemap�иô���ֵ��ΪWALL *******//
void CMazeMap::SetMazeArray(int _x, int _y)
{
	m_iMazeMapArray[_x][_y] = WALL;
}

//******* ���ݴ�����Թ����飬��cout�ķ�ʽ�����Թ� *******//
void CMazeMap::DrawMap()
{
	for (int col = 0; col < CMazeMap::m_iMazeCol; col++)
	{
		for (int row = 0; row < CMazeMap::m_iMazeRow; row++)
		{
			if (CMazeMap::m_iMazeMapArray[col][row] == WALL)
			{
				cout << CMazeMap::m_cMazeWall;   // ������ֵΪWALL(1)ʱ���ǽ���ַ�
			}
			else if (CMazeMap::m_iMazeMapArray[col][row] == ROAD)
			{
				cout << CMazeMap::m_cMazeRoad;   // ������ֵΪROAD(0)ʱ���·���ַ�
			}
			else
			{
				cout << "MazaArray input error" << endl;
				exit(0);
			}
		}
		cout << endl;
	}
}

//****** �����ĸ���ͬ���ƶ���������һ��λ���Ƿ���ͨ· *******//
char CMazeMap::CheckNext(int _x, int _y, char _direction)
{
	if (m_iMazeMapArray[_x - 1][_y] == ROAD && (_x - 1 >= 0) &&(_direction != '1'))
		return w;
	if (m_iMazeMapArray[_x + 1][_y] == ROAD && (_x + 1 < m_iMazeCol) && (_direction != '2' ))
		return s;
	if (m_iMazeMapArray[_x][_y - 1] == ROAD && (_y - 1 >= 0) && (_direction != '3'))
		return a;
	if (m_iMazeMapArray[_x][_y + 1] == ROAD && (_y + 1 < m_iMazeRow) && (_direction != '4'))
		return d;
	
	return f;
}


//******* �ҵ��Թ����� *******//
int CMazeMap::Success(int _x, int _y)
{
	if (_x == 0 || _y == CMazeMap::m_iMazeRow)
		return HI_TRUE;
	else
		return HI_FALSE;
}