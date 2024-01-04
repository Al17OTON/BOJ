//머리아프다... 
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define MAPMAX 20
#define KMAX 1000
using namespace std;

int DICE[7] = { 0 };

/*
  2
4 1 3
  5
  6
*/

int map[MAPMAX][MAPMAX];
int com[KMAX];

int N, M, x, y, K;

int dirX[5] = {0, 0, 0, -1, 1 }; //동서북남
int dirY[5] = {0, 1, -1, 0, 0 };

void north()
{
	int temp[7];
	temp[0] = 0;
	temp[1] = DICE[5];
	temp[2] = DICE[1];
	temp[3] = DICE[3];
	temp[4] = DICE[4];
	temp[5] = DICE[6];
	temp[6] = DICE[2];

	for (int i = 0; i < 7; i++)
		DICE[i] = temp[i];
}

void south()
{
	int temp[7];
	temp[0] = 0;
	temp[1] = DICE[2];
	temp[2] = DICE[6];
	temp[3] = DICE[3];
	temp[4] = DICE[4];
	temp[5] = DICE[1];
	temp[6] = DICE[5];

	for (int i = 0; i < 7; i++)
		DICE[i] = temp[i];
}

void west()
{
	int temp[7];
	temp[0] = 0;
	temp[1] = DICE[3];
	temp[2] = DICE[2];
	temp[3] = DICE[6];
	temp[4] = DICE[1];
	temp[5] = DICE[5];
	temp[6] = DICE[4];

	for (int i = 0; i < 7; i++)
		DICE[i] = temp[i];
}
void east()
{
	int temp[7];
	temp[0] = 0;
	temp[1] = DICE[4];
	temp[2] = DICE[2];
	temp[3] = DICE[1];
	temp[4] = DICE[6];
	temp[5] = DICE[5];
	temp[6] = DICE[3];

	for (int i = 0; i < 7; i++)
		DICE[i] = temp[i];
}

void move(int n)
{
	switch (n)
	{
	case 1 :
		east();
		break;
	case 2:
		west();
		break;
	case 3 :
		north();
		break;
	case 4:
		south();
		break;
	}
}

void sim()
{
	int k = 0, xx, yy, c;
	while (k < K)
	{
		c = com[k++];
		xx = x + dirX[c]; yy = y + dirY[c];	//이동좌표

		if (xx >= 0 && xx < N && yy >= 0 && yy < M)	//범위를 벗어나지 않음.
		{
			move(c);
			x = xx; y = yy;
			if (map[x][y] == 0) map[x][y] = DICE[6];
			else
			{
				DICE[6] = map[x][y];
				map[x][y] = 0;
			}
			printf("%d\n", DICE[1]);
		}
	}
}

int main()
{
	int i, j;
	scanf("%d %d %d %d %d", &N, &M, &x, &y, &K);

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}
	for (i = 0; i < K; i++)
	{
		scanf("%d", &com[i]);
	}

	sim();
}