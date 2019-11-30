#pragma once
#ifndef __CMAZEMAP__H__
#define __CMAZEMAP__H__


//******* 定义整个窗口大小 20x30 *******//
constexpr int g_iScreenWidth = 30;
constexpr int g_iScreenHeight = 20;

//******* 定义返回值类型 *******//
constexpr int HI_TRUE = 1;
constexpr int HI_FALSE = 0;

//******* 定义墙和路的判断名称 *******//
constexpr int WALL = 1;
constexpr int ROAD = 0;

//******* 定义人的四个移动方向 *******//
constexpr char w = 'w';
constexpr char s = 's';
constexpr char a = 'a';
constexpr char d = 'd';

//******* 定义进入死胡同的返回值 *******//
constexpr char f = 'f';
//******* 创建迷宫类 *******//
class CMazeMap
{
public:
	CMazeMap();                      // 构造函数
	~CMazeMap();                     // 析构函数
	void SetWall(char _wall);        // 设置墙的字符
	char GetWall();					 // 获取墙的字符
	void SetRoad(char _road);        // 设置路的字符
	char GetRoad();                  // 获取路的字符
	void DefaultMap();               // 默认迷宫数组
	void SetMap(int *mazeMap, int _col, int _row); // 自定义迷宫数组
	void DrawMap();                  // 绘制迷宫
	static void SetMazeArray(int _x, int _y);
	static int Success(int _x, int _y);    // 找到迷宫出口函数
	static char CheckNext(int _x, int _y, char _direction);  // 检测边界函数

private:
	char m_cMazeWall;        // 墙的字符
	char m_cMazeRoad;	     // 路的字符
	static int m_iMazeCol;          // 迷宫高度
	static int m_iMazeRow;          // 迷宫宽度
	static int m_iMazeMapArray[g_iScreenHeight][g_iScreenWidth];   // 迷宫数组
};

#endif   //__CMAZEMAP__H__