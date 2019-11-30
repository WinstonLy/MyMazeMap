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
		{WALL, WALL, ROAD, ROAD, ROAD, WALL, ROAD, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL},
		{WALL, WALL, ROAD, WALL, ROAD, ROAD, ROAD, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL},
		{WALL, ROAD, ROAD, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL},
		{WALL, ROAD, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL}
	};

	CMazeMap maze;
	//cout << maze.GetWall() << " " << maze.GetRoad() << endl;
	//maze.DefaultMap();
	maze.SetWall('#');
	maze.SetRoad(' ');
	maze.SetMap(&mazeMap[0][0], 8, 16);
	maze.DrawMap();

	CMazePerson mazer;
	mazer.SetPersonAttr('T', 'w', NORMAL);
	mazer.SetCurrentPosition(7, 1);
	mazer.SetPreviousPosition(7, 1);
	mazer.PersonMove();
	


	system("pause");
	return HI_SUCCESS;
}