#include<iostream>
#include<cstring>
#include<queue>
#define MAX 20

using namespace std;

struct NODE {
	int x, y, mem, dir;
};

char com[MAX][MAX];
bool visit[MAX][MAX][4][16] = { false };	//각 위치의 4방향과 메모리 상태를 저장 이렇게해야 시간초과안남
int R, C;

int dirX[4] = { -1, 1, 0, 0 };	//상하좌우
int dirY[4] = { 0, 0, -1, 1 };

bool bfs()
{
	char c;
	NODE start = { 0,0,0,3 };	//(0,0) 에서 메모리 0, 방향 오른쪽으로 시작
	queue<NODE> q;
	q.push(start);
	//visit[0][0][3][0] = true;	//방문 표시

	while (!q.empty())
	{
		start = q.front(); q.pop();
		c = com[start.x][start.y];	//현재 위치 명령어 받기
		if (!visit[start.x][start.y][start.dir][start.mem]) 	//같은 조건으로 방문했었는지 체크
		{
			visit[start.x][start.y][start.dir][start.mem] = true;	//처음 방문이라면 방문 기록

			switch (c)
			{
			case '<':
				start.dir = 2;
				break;
			case '>':
				start.dir = 3;
				break;
			case '^':
				start.dir = 0;
				break;
			case 'v':
				start.dir = 1;
				break;
			case '_':
				start.dir = start.mem == 0 ? 3 : 2;
				break;
			case '|':
				start.dir = start.mem == 0 ? 1 : 0;
				break;
			case '@':
				return true;
			case '+':
				start.mem = start.mem + 1 == 16 ? 0 : start.mem + 1;
				break;
			case '-':
				start.mem = start.mem - 1 == -1 ? 15 : start.mem - 1;
			}

			if (c >= '0' && c <= '9') start.mem = c - '0';

			if (c == '?')
			{
				for (int i = 0; i < 4; i++)
				{
					int xx = start.x + dirX[i]; int yy = start.y + dirY[i];
					if (xx == R) xx = 0;
					else if (xx < 0) xx = R - 1;
					if (yy == C) yy = 0;
					else if (yy < 0) yy = C - 1;
					q.push(
						{
							xx, yy, start.mem, i
						}
					);
				}
			}
			else
			{
				start.x = start.x + dirX[start.dir];
				start.y = start.y + dirY[start.dir];
				if (start.x == R) start.x = 0;
				else if (start.x < 0) start.x = R - 1;
				if (start.y == C) start.y = 0;
				else if (start.y < 0) start.y = C - 1;
				q.push(start);
			}
		}
	}
	return false;
}

int main(int argc, char** argv)
{
	int test_case, i, j;
	int T;
	bool flag;	//@의 존재 유무

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		flag = false;
		cin >> R;
		cin >> C;

		for (i = 0; i < R; i++)
		{
			cin >> com[i];
			for (j = 0; j < C && !flag; j++)
			{
				if (com[i][j] == '@')
				{
					flag = true;
					break;
				}
			}
		}

		if (bfs() && flag)
			cout << "#" << test_case << " " << "YES" << endl;
		else
			cout << "#" << test_case << " " << "NO" << endl;

		memset(visit, false, sizeof(visit));
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}