#include <iostream>
#define MAX 10
using namespace std;

char map[MAX][MAX];
int dirX[5] = { -1, 1, 0, 0, 0 };
int dirY[5] = { 0, 0, -1, 1, 0 };
int light = 0;

pair<int, int> searchMany()
{
	int i, j, x, xx, yy, maxi = 0, temp;
	pair<int, int> result = { 0,0 };

	for (i = 0; i < MAX; i++)
	{
		for (j = 0; j < MAX; j++)
		{
			temp = 0;
			for(x = 0; x < 5; x++)
			{
				xx = i + dirX[x]; yy = j + dirY[x];
				if (xx >= 0 && xx < MAX && yy >= 0 && yy < MAX)
				{
					if (map[xx][yy] == 'O') temp++;
				}
			}
			if (temp > maxi)
			{
				maxi = temp;
				result = { i,j };
			}
		}
	}
	return result;
}

int greedy()
{
	int x, y, i, pre, result = 0;
	pair<int, int> many;
	while (light)
	{
		result++;
		pre = light;
		many = searchMany();
		for (i = 0; i < 5; i++)
		{
			x = many.first + dirX[i]; y = many.second + dirY[i];
			if (x >= 0 && x < MAX && y >= 0 && y < MAX)
			{
				if (map[x][y] == 'O')
				{
					map[x][y] = '#';
					light--;
				}
				else
				{
					map[x][y] = 'O';
					light++;
				}
			}
		}
		if (light > pre) return -1;
	}
	return result;
}

int main()
{
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 'O') light++;
		}
	}

	cout << greedy() << endl;
}