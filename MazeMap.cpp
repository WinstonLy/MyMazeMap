#include <iostream>
#include <stdlib.h>
//#include <stdio.h>
#include "MazeMap.h"

using namespace std;

//******* 静态成员变量初始化 *******//
int CMazeMap::m_iMazeCol = g_iScreenHeight;
int CMazeMap::m_iMazeRow = g_iScreenWidth;
int CMazeMap::m_iMazeMapArray[g_iScreenHeight][g_iScreenWidth] = { 0 };

//******* 构造函数，初始化各个参数，主要用来绘制默认地图 *******//
CMazeMap::CMazeMap():m_cMazeWall('#'), m_cMazeRoad(' ')
{
	//m_iMazeCol = _x;    //迷宫行数，高度
	//m_iMazeRow = _y;   //迷宫列数，宽度
	//m_iMazeMapArray[g_iScreenHeight][g_iScreenWidth] = { 0 };
}

//******** 析构函数 *******//
CMazeMap::~CMazeMap()
{

}

//******* 设置墙的构成字符 *******//
void CMazeMap::SetWall(char _wall)
{
	m_cMazeWall = _wall;
}

//******* 获取墙的组成字符 *******//
char CMazeMap::GetWall()
{
	return m_cMazeWall;
}

//******* 设置路的组成字符 ******//
void CMazeMap::SetRoad(char _pathway)
{
	m_cMazeRoad = _pathway;
}

//******* 获取路的组成字符 *******//
char CMazeMap::GetRoad()
{
	return m_cMazeRoad;
}

//****** 构建默认迷宫的组成数组 *******//
//****** 将迷宫的第15列设为路，其余地方全是墙 *******//
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

//******* 自定义迷宫 *******//
//******* 传入迷宫数组，行、列，并赋值给类中的成员变量m_iMazeArray ******//
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

//******* 当找到死胡同时将mazemap中该处的值设为WALL *******//
void CMazeMap::SetMazeArray(int _x, int _y)
{
	m_iMazeMapArray[_x][_y] = WALL;
}

//******* 根据传入的迷宫数组，用cout的方式画出迷宫 *******//
void CMazeMap::DrawMap()
{
	for (int col = 0; col < CMazeMap::m_iMazeCol; col++)
	{
		for (int row = 0; row < CMazeMap::m_iMazeRow; row++)
		{
			if (CMazeMap::m_iMazeMapArray[col][row] == WALL)
			{
				cout << CMazeMap::m_cMazeWall;   // 当数组值为WALL(1)时输出墙的字符
			}
			else if (CMazeMap::m_iMazeMapArray[col][row] == ROAD)
			{
				cout << CMazeMap::m_cMazeRoad;   // 当数组值为ROAD(0)时输出路的字符
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

//****** 根据四个不同的移动方向检查下一个位置是否是通路 *******//
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


//******* 找到迷宫出口 *******//
int CMazeMap::Success(int _x, int _y)
{
	if (_x == 0 || _y == CMazeMap::m_iMazeRow)
		return HI_TRUE;
	else
		return HI_FALSE;
}