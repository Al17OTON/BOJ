#include<iostream>
#include<queue>
#define MAX 100

using namespace std;
typedef struct NODE
{
	int x, y;
};

int map[MAX][MAX];
int visit[MAX][MAX];
int dirX[4] = { 1, 0, -1, 0 }; //하 우 상 좌
int dirY[4] = { 0, 1, 0, -1 };
int result, N;

void bfs()
{
	queue<NODE> q;
	q.push({ 0,0});
	visit[0][0] = 0;
	while (!q.empty())
	{
		NODE t = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)	//모든 방향
		{
			int xx = t.x + dirX[i]; int yy = t.y + dirY[i];
			if (xx >= 0 && xx < N && yy >= 0 && yy < N)
			{
				if (visit[xx][yy] > visit[t.x][t.y] + map[xx][yy])	//이전 기록보다 최단 기록이면
				{
					q.push({ xx,yy });
					visit[xx][yy] = visit[t.x][t.y] + map[xx][yy];
				}
			}
		}
	}
	result = visit[N - 1][N - 1];
}

int main(int argc, char** argv)
{
	int test_case, i, j;
	int T;
	char input[MAX];

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		result = 100000;	//최단 시간을 구하기 위한 최대값 설정
		cin >> N;

		for (i = 0; i < N; i++)
		{
			cin >> input;
			for (j = 0; j < N; j++)
			{
				map[i][j] = input[j] - '0';
				visit[i][j] = 10000;
			}
		}
		bfs();
		cout << "#" << test_case << " " << result << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}