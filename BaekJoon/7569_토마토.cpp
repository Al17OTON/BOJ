//3차원 토마토 문제
#include <iostream>
#include <queue>
#define MAX 100

using namespace std;

struct TOMATO
{
	int x, y, z;
};

int n, m, h, need = 0;
int box[MAX][MAX][MAX];
queue<TOMATO> q;
int dirX[6] = { -1, 1, 0, 0, 0, 0 };	//상하좌우,윗층 아랫층
int dirY[6] = { 0, 0, -1, 1, 0, 0 };
int dirZ[6] = { 0, 0, 0, 0, -1, 1 };

int max(int a, int b)
{
	return a > b ? a : b;
}

int bfs()
{
	TOMATO t;
	int i, xx, yy, zz, maxi = 1;
	while (!q.empty())
	{
		t = q.front(); q.pop();
		for (i = 0; i < 6; i++)
		{
			xx = t.x + dirX[i]; yy = t.y + dirY[i]; zz = t.z + dirZ[i];
			if (xx >= 0 && xx < m && yy >= 0 && yy < n && zz >= 0 && zz < h && box[zz][xx][yy] == 0)	//좌표가 범위를 벗어나지 않으면서, 익지 않은 토마토일때만
			{
				box[zz][xx][yy] = box[t.z][t.x][t.y] + 1;	//최소 일을 파악하기 위해 영향을 받은 토마토에 1을 더하여 시간 계산
				q.push({ xx, yy, zz });
				maxi = max(maxi, box[zz][xx][yy]);	//가장 일수가 큰 토마토 기록
				need--;							//박스를 채우기 위해 필요한 토마토 줄이기
			}
		}
	}
	return maxi;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> h;

	need = n * m * h;	//박스를 가득 채우기 위해 필요한 익은 토마토 수

	for (int z = 0; z < h; z++)
	{
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> box[z][i][j];
				if (box[z][i][j] == 1)
				{
					q.push({ i,j,z });	//익은 토마토 기록
				}
				if (box[z][i][j] != 0) need--;	//이미 익었거나, 빈 공간이면 필요한 토마토수를 그만큼 줄인다.
			}
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