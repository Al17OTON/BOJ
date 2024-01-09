#include<iostream>
#include<queue>
#define MAX 9

using namespace std;

struct COM
{
	int x, y, c;	//위치, 색
};

int map[MAX][MAX];
queue<COM> q;
int N, M, black, white;
int dirX[8] = { -1,1,0,0,-1,-1,1,1 };	//상하좌우 좌상 우상 좌하 우하
int dirY[8] = { 0,0,-1,1,-1,1,-1,1 };

void putRock(COM c)
{
	if ((c.c == 1 && black == 0) || (c.c == 2 && white == 0)) return;	//같은 색 돌이 판에 존재하지 않으면 종료
	queue<COM> change;
	map[c.x][c.y] = c.c;
	c.c == 1 ? black++ : white++;	//놓는 돌 색 개수 증가
	for (int i = 0; i < 8; i++)
	{
		for (int x = c.x + dirX[i], y = c.y + dirY[i]; x >= 0 && x < N && y >= 0 && y < N; x += dirX[i], y += dirY[i])
		{
			if (map[x][y] == c.c)
			{
				while (!change.empty())
				{
					COM tmp = change.front(); change.pop();
					map[tmp.x][tmp.y] = tmp.c;
					if (tmp.c == 1)
					{
						black++; white--;
					}
					else
					{
						black--; white++;
					}
				}
				break;
			}
			else if (map[x][y] == 0)
			{
				break;
			}
			else
			{
				change.push({ x,y,c.c });
			}
		}
		while (!change.empty()) change.pop();
	}
	return;
}

int main(int argc, char** argv)
{
	int test_case, i, j, x,y,c;
	int T;
	COM tmp;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		memset(map, 0, sizeof(map));
		black = 2; white = 2;

		cin >> N; 
		cin >> M;

		map[N / 2 - 1][N / 2 - 1] = 2;	//가운데 초기값 생성
		map[N / 2 - 1][N / 2] = 1;
		map[N / 2][N / 2 - 1] = 1;
		map[N / 2][N / 2] = 2;

		for (i = 0; i < M; i++)
		{
			cin >> x;
			cin >> y;
			cin >> c;
			q.push({ x - 1,y - 1,c });
		}

		while (!q.empty())
		{
			tmp = q.front(); q.pop();
			putRock(tmp);
			if (white + black == N * N) break;	//놓을 곳이 없다면 종료
		}
		while (!q.empty()) q.pop();

		cout << "#" << test_case << " " << black << " " << white << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}