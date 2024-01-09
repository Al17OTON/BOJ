#include<iostream>
#define MAX 20

using namespace std;

int map[MAX][2];
bool visit[MAX];
int result, N, M;

void dfs(int start, int len)
{
	if (len > result) result = len;	//현재까지 방문한 정점의 수가 최대값보다 클때, 최대값 갱신

	for (int i = 0; i < M; i++)	//모든 노드 경로에 대해서 탐색
	{
		if (map[i][0] == start)	//현재 위치한 노드와 일치한다면 이동여부 판별
		{
			if (!visit[map[i][1]])	//연결된 노드가 방문하지 않은 곳이면 가보기
			{
				visit[map[i][1]] = true;
				dfs(map[i][1], len + 1);
				visit[map[i][1]] = false;
			}
		}
		if (map[i][1] == start)	//연결된 노드는 서로 양방향으로 이동할 수 있으므로, 이 경우도 봐야함.
		{
			if (!visit[map[i][0]])
			{
				visit[map[i][0]] = true;
				dfs(map[i][0], len + 1);
				visit[map[i][0]] = false;
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
		cin >> M;
		for (i = 0; i < M; i++)
		{
			cin >> map[i][0];
			cin >> map[i][1];
			visit[i] = false;
		}
		
		for (i = 1; i <= N; i++)	//모든 시작점에 대해서
		{
			visit[i] = true;
			dfs(i, 1);
			visit[i] = false;
		}

		if (M == 0) result = 1;

		cout << "#" << test_case << " " << result << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}