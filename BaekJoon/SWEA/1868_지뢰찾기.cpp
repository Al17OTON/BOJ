////왜 안되지... 내가볼떈 checkMine이 잘못된거같음
#include<iostream>
#include<queue>
#define MAX 300

using namespace std;

int result, N;
char map[MAX][MAX];
bool visit[MAX][MAX];

struct A
{
	int x, y;
};

bool checkMine(int x, int y)	//8방향에 폭탄이 존재하면 true
{
	int i = x - 1 >= 0 ? x - 1 : 0, j;	//클릭지점의 왼쪽 위
	for (; i <= x + 1 && i < N; i++)	//범위밖으로 벗어나지 않도록 하여 검색
	{
		for (j = y - 1 >= 0 ? y - 1 : 0; j <= y + 1 && j < N; j++)
		{
			if (map[i][j] == '*' && x != i && y != j) return true;
		}
	}
	return false;
}


void bfs(int x, int y)
{
	A a;
	int i, j;
	queue<A> q;
	q.push({ x,y });
	while (!q.empty())
	{
		a = q.front(); q.pop();

		if (!checkMine(a.x, a.y))	//폭탄이 있다면 스킵, 0인부분만 전부 연쇄적으로 밝히기
		{
			i = x - 1 >= 0 ? x - 1 : 0;
			for (; i <= x + 1 && i < N; i++)	//범위밖으로 벗어나지 않도록 하여 검색
			{
				for (j = y - 1 >= 0 ? y - 1 : 0; j <= y + 1 && j < N; j++)
				{
					if (map[i][j] == '.' && !visit[i][j])
					{
						visit[i][j] = true;
						q.push({ i, j });
					}
				}
			}
		}
	}
}

int main(int argc, char** argv)
{
	int test_case, i, j;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		result = 0;
		cin >> N;
		memset(visit, false, sizeof(visit));	//방문 여부 초기화
		for (i = 0; i < N; i++)
		{
			cin >> map[i];	//문자열로 받기
			for (j = 0; j < N; j++)
			{
				if (map[i][j] == '*') visit[i][j] = true;	//폭탄은 방문표시
			}
		}

		for (i = 0; i < N; i++)	
		{
			for (j = 0; j < N; j++)
			{
				if (!visit[i][j] && !checkMine(i, j))	//0인 지점을 찾아서 bfs로 밝히기
				{
					visit[i][j] = true;
					bfs(i, j);
					result++; 
				}
			}
		}
		for (i = 0; i < N; i++)	//위 bfs에서 밝혀지지 않은 곳은 개별적으로 눌러야하므로 따로 체크
		{
			for (j = 0; j < N; j++)
			{
				if (!visit[i][j]) result++;
			}
		}

		cout << "#" << test_case << " " << result << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}