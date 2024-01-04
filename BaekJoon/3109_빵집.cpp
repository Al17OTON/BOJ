/*
	처음 봤을 때, 매우 쉬워보였다. 머리속으로 dfs가 스쳐갔지만 그리디한 방법이 있을거라 생각하여 규칙을 찾아냈다.
	규칙은 다음과 같다. 파이프 연결을 무조건 오른쪽 위로 하는 것이 유리하다는 것이다.
	그걸 이용하여 코드를 작성하였지만 틀린 코드였다. 이유는 dfs로 풀지 않았기에 오른쪽으로 올라가기만 하다가 막히면 다른 방향으로 갈 생각 없이 종료해버렸기 때문이다.
	인터넷에 검색하여 코드는 보지않고 규칙을 참고하였는데, dfs로 풀라는 말이 있어서 다시 dfs로 풀어보았다.
	처음에는 시간초과가 나왔는데, 한번 방문한 곳을 방문해제하는 바람에 생긴 문제였다. 
	이미 한번 방문한 곳은 파이프가 완성되었거나 완성되지 못함을 이미 확인한 곳이기 때문에 백트래킹을 해야했는데 그러지 못했다.
	다시 수정한 결과 해결하였다.
*/

#include <iostream>
#include <stack>

using namespace std;

int R, C;
char map[10000][500];
bool visit[10000][500] = { false };

int dirX[3] = { -1, 0, 1 };	//위쪽 오른쪽 아래쪽 순서로 우선순위 부여

bool dfs(pair<int, int> pos)
{
	if (pos.second == C - 1)	//종점에 도착하면 true반환
	{
		return true;
	}

	pair<int, int> next;

	for (int i = 0; i < 3; i++)
	{
		next = pos;
		next.first += dirX[i]; next.second += 1;
		if (next.first >= 0 && next.first < R && map[next.first][next.second] != 'x' && !visit[next.first][next.second])
		{
			visit[next.first][next.second] = true;
			if (dfs(next))    //종점이면 탐색 종료
			{
				return true;
			}
			//visit[next.first][next.second] = false;//주석이 있어야 시간초과가 안나옴.
			//그 이유는 방문한 지점은 파이프가 완성된 라인이거나 파이프 완성이 불가능임을 이미
			//확인한 곳이기 때문에 방문 해제를 하지 않아야 다음 방문에서 백트래킹이 가능하다.
		}
	}
	return false;	//위 세 경우 모두 갈 수 없는 경로라면 false
}


int main()
{
	int result = 0;
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> R >> C;

	for (int r = 0; r < R; r++)
	{
		for (int c = 0; c < C; c++)
		{
			cin >> map[r][c];
		}
	}

	for (int r = 0; r < R; r++)
	{
		if (dfs({ r, 0 }))
		{
			result++;
		}
	}

	cout << result << endl;

}