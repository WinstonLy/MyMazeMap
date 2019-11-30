#pragma once
#include "MazeMap.h"
#ifndef __CMAZEPERSON__H__
#define __CMAZEPERSON__H__


//******* 定义速度的标识符 *******//
constexpr int NORMAL = 0;
constexpr int FAST = 1;


//******* 走迷宫的人的类 *******//
class CMazePerson
{
public:
	CMazePerson();					            // 构造函数
	~CMazePerson();					            // 析构函数
	void SetPersonAttr(char _person, char _direction, int _speed);// 设置走迷宫人的属性：字符、方向、速度
	void SetCurrentPosition(int _x, int _y);	// 设置当前位置
	void SetPreviousPosition(int _x, int _y);	// 设置前一位置
	void GetCurrentPosition();					// 获取当前位置
	void GetPreviousPosition();					// 获取前一位置
	void PersonMove();							// 控制走迷宫的人移动
	void Gotoxy(int _x, int _y);				// 确定控制台中字符的输出位置

private:
	char m_cPerson;					// 人的字符
	char m_cDirection;				// 人的朝向，即前进方向
	int m_iCurrentPositionX;		// 当前位置的横坐标
	int m_iCurrentPositionY;		// 当前位置的纵坐标
	int m_iPreviousPositionX;		// 前一位置的横坐标
	int m_iPreviousPositionY;		// 前一位置的纵坐标
	int m_iSpeed;					// 移动速度
	static int count;						// 移动次数
};

#endif       //__CMAZEPERSON__H__