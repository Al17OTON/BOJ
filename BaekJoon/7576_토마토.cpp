// 다른 사람들은 20ms으로도 해결하던디 어떻게하는걸까

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#define MAX 1000

using namespace std;

struct TOMATO
{
	int x, y;
};

int n, m, need = 0;
int box[MAX][MAX];
queue<TOMATO> q;
int dirX[4] = { -1, 1, 0, 0 };	//상하좌우
int dirY[4] = { 0, 0, -1, 1 };

int max(int a, int b)
{
	return a > b ? a : b;
}

int bfs()
{
	TOMATO t;
	int i, xx, yy, maxi = 1;
	while (!q.empty())
	{
		t = q.front(); q.pop();
		for (i = 0; i < 4; i++)
		{
			xx = t.x + dirX[i]; yy = t.y + dirY[i];
			if (xx >= 0 && xx < m && yy >= 0 && yy < n && box[xx][yy] == 0)	//좌표가 범위를 벗어나지 않으면서, 익지 않은 토마토일때만
			{
				box[xx][yy] = box[t.x][t.y] + 1;	//최소 일을 파악하기 위해 영향을 받은 토마토에 1을 더하여 시간 계산
				q.push({ xx, yy });
				maxi = max(maxi, box[xx][yy]);	//가장 일수가 큰 토마토 기록
				need--;							//박스를 채우기 위해 필요한 토마토 줄이기
			}
		}
	}
	return maxi;
}

int main()
{
	scanf("%d %d", &n, &m);

	need = n * m;	//박스를 가득 채우기 위해 필요한 익은 토마토 수

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &box[i][j]);
			if (box[i][j] == 1)
			{
				q.push({ i,j });	//익은 토마토 기록
			}
			if (box[i][j] != 0) need--;	//이미 익었거나, 빈 공간이면 필요한 토마토수를 그만큼 줄인다.
		}
	}

	int result = bfs();

	if (need == 0)	//모든 토마토를 익게 만듬
	{
		cout << result - 1 << endl;	//1일 부터 시작하므로 걸린 시간을 계산하기 위해 -1을 해야함.
	}
	else
	{
		cout << -1 << endl;
	}
}