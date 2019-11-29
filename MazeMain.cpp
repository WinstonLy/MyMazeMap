#include <iostream>
#include <stdio.h>
#include "MazeMap.h"
#include "MazePerson.h"

using namespace std;
//#define WALL 1
//#define ROAD 0

constexpr int HI_SUCCESS = 0;
int main()
{
	int mazeMap[8][16] =
	{
		{WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, ROAD, WALL},
		{WALL, WALL, WALL, WALL, WALL, WALL, WALL, ROAD, ROAD, ROAD, ROAD, ROAD, ROAD, ROAD, ROAD, WALL},
		{WALL, WALL, WALL, WALL, WALL, WALL, ROAD, ROAD, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL},
		{WALL, WALL, WALL, WALL, WALL, WALL, ROAD, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL},
		{WALL, WALL, ROAD, ROAD, ROAD, WALL, ROAD, ROAD, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL},
		{WALL, WALL, ROAD, WALL, ROAD, ROAD, ROAD, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL},
		{WALL, ROAD, ROAD, WALL, WALL, ROAD, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL},
		{WALL, ROAD, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL}
	};

	CMazeMap maze(8,16);
	//cout << maze.GetWall() << " " << maze.GetRoad() << endl;
	//maze.DefaultMap();
	maze.SetWall('#');
	maze.SetRoad(' ');
	maze.SetMap(&mazeMap[0][0], 8, 16);
	maze.DrawMap();

	CMazePerson mazer;
	mazer.SetPersonAttr('T', 'w', NORMAL);
	mazer.SetCurrentPosition(7, 2);
	mazer.SetPreviousPosition(7, 2);
	mazer.PersonMove();
	mazer.Gotoxy();


	system("pause");
	return HI_SUCCESS;
}