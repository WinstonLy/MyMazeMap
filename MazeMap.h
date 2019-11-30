#pragma once
#ifndef __CMAZEMAP__H__
#define __CMAZEMAP__H__


//******* �����������ڴ�С 20x30 *******//
constexpr int g_iScreenWidth = 30;
constexpr int g_iScreenHeight = 20;

//******* ���巵��ֵ���� *******//
constexpr int HI_TRUE = 1;
constexpr int HI_FALSE = 0;

//******* ����ǽ��·���ж����� *******//
constexpr int WALL = 1;
constexpr int ROAD = 0;

//******* �����˵��ĸ��ƶ����� *******//
constexpr char w = 'w';
constexpr char s = 's';
constexpr char a = 'a';
constexpr char d = 'd';

//******* �����������ͬ�ķ���ֵ *******//
constexpr char f = 'f';
//******* �����Թ��� *******//
class CMazeMap
{
public:
	CMazeMap();                      // ���캯��
	~CMazeMap();                     // ��������
	void SetWall(char _wall);        // ����ǽ���ַ�
	char GetWall();					 // ��ȡǽ���ַ�
	void SetRoad(char _road);        // ����·���ַ�
	char GetRoad();                  // ��ȡ·���ַ�
	void DefaultMap();               // Ĭ���Թ�����
	void SetMap(int *mazeMap, int _col, int _row); // �Զ����Թ�����
	void DrawMap();                  // �����Թ�
	static void SetMazeArray(int _x, int _y);
	static int Success(int _x, int _y);    // �ҵ��Թ����ں���
	static char CheckNext(int _x, int _y, char _direction);  // ���߽纯��

private:
	char m_cMazeWall;        // ǽ���ַ�
	char m_cMazeRoad;	     // ·���ַ�
	static int m_iMazeCol;          // �Թ��߶�
	static int m_iMazeRow;          // �Թ����
	static int m_iMazeMapArray[g_iScreenHeight][g_iScreenWidth];   // �Թ�����
};

#endif   //__CMAZEMAP__H__