#include<iostream>
#include<cstring>
#define MAX 1000

using namespace std;

int map[MAX][MAX];
int visit[MAX][MAX][2]; //방문여부와 최대 방문가능한 방 갯수
int result, N;
int dirX[4] = { -1,1,0,0 };	//상하좌우
int dirY[4] = { 0,0,-1,1 };

int max(int a, int b)
{
	return a > b ? a : b;
}
int min(int a, int b)
{
	return a > b ? b : a;
}

int dfs(int n, int x, int y)
{
	if (visit[x][y][0] != -1) return n;	//이미 방문한 곳이라면 현재 깊이가 최대다.
	if (visit[x][y][1] != -1) return n + visit[x][y][1];	//방문하지는 않았지만 다른 dfs가 이미 탐색을 마친곳이라면 더 깊이 들어갈 필요없음  dp
	int xx, yy, result = n;
	for (int i = 0; i < 4; i++)
	{
		xx = x + dirX[i]; yy = y + dirY[i];
		if (xx >= 0 && xx < N && yy >= 0 && y < N && map[x][y] + 1 == map[xx][yy])	//맵을 벗어나지 않으면서 현재 타일보다 1커야함
		{
			visit[x][y][0] = 1;	//방문표시
			result = max(result, dfs(n + 1, xx, yy));	//방문 가능한 모든 방향 중 가장 결과값이 큰 것을 가져오기
			visit[x][y][0] = -1; //방문 해제
		}
	}
	visit[x][y][1] = result;	//현재 지점에서 방문가능한 모든곳을 탐색했으면 저장
	return result;
}

int main(int argc, char** argv)
{
	int test_case, i, j, tmp, num = 10000000;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		result = 0;
		cin >> N;
		memset(visit, -1, sizeof(visit));
		for (i = 0; i < N; i++)
		{
			for (j = 0; j < N; j++)
			{
				cin >> map[i][j];
			}
		}

		for (i = 0; i < N; i++)
		{
			for (j = 0; j < N; j++)
			{
				tmp = dfs(0, i, j);
				if (tmp > result)
				{
					result = tmp;
					num = map[i][j];//가장 작은걸로 갱신
				}
				else if (tmp == result)
				{
					num = min(map[i][j], num);	//결과가 같다면 더 작은 값으로 갱신
				}
			}
		}

		cout << "#" << test_case << " " << num << " " << result + 1 << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}