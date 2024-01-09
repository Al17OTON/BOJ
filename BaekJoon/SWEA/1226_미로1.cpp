/*
	보자마자 BFS로 풀어야겠다는 생각이 들었다.
	최단경로를 구할 필요는 없고 도달 가능 여부만 확인하면 되는데
	그렇다면 가장 빨리 도달하는 것을 찾고 결과만 도출하면 풀린다고 생각해서
	최단경로를 찾아주는 BFS를 사용해서 풀었다.
	DFS로도 풀수있겠지만 최단 경로를 탐색해야 시간제한을 통과할수있을거라고 생각했다.

	BFS를 큐를 사용해서 푸는거 까지는 좋았는데 메모리 초과가 나서 당황했다.
	알고 봤더니 방문여부를 표시하지 않아서 무한루프에 걸린것이였다...
	그래도 빠르게 오류를 해결해서 나쁘지 않았다.
*/
#include<iostream>
#include<queue>
#define MAX 16

using namespace std;

struct NODE		//좌표를 저장할 구조체
{
	int x, y;
};

int map[MAX][MAX];		//미로
bool visit[MAX][MAX];	//방문여부 표시
int result;
NODE start;				//시작점
int dirX[4] = { -1, 1, 0 ,0 }; //상하좌우
int dirY[4] = { 0, 0, -1, 1 };

bool bfs()
{
	int i, xx, yy;
	NODE tmp;
	queue<NODE> q;
	visit[start.x][start.y] = true;	//시작점 방문 표시
	q.push(start);					//시작점 넣기

	while (!q.empty()) //q가 빌때까지
	{
		tmp = q.front();
		q.pop();

		for (i = 0; i < 4; i++)	//4방향
		{
			xx = tmp.x + dirX[i]; yy = tmp.y + dirY[i];	//이동할 좌표
			if (xx >= 1 && xx < MAX - 2 && yy >= 1 && yy < MAX - 2)	//맵을 벗어나지 않아야함
			{
				if (map[xx][yy] == 0 && !visit[xx][yy])	//이동가능하고 방문하지 않은곳이라면
				{
					q.push({ xx, yy });	//q에 넣기 bfs 니까!
					visit[xx][yy] = true;	//방문 표시
				}
				else if (map[xx][yy] == 3) //골인지점이라면
				{
					return true;	//경로를 찾았으므로 반환
				}
			}
		}
	}
	return false;	//큐가 빌때까지 못찾으면 경로가 없는것
}

int main(int argc, char** argv)
{
	int test_case, i, j;
	int T = 10, N;
	char input;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		result = 0;
		cin >> N;	//테스트 케이스 번호

		for (i = 0; i < MAX; i++)
		{
			for (j = 0; j < MAX; j++)
			{
				cin >> input;
				map[i][j] = input - '0';
				visit[i][j] = false;
				if (map[i][j] == 2)	//시작점 찾기
				{
					start.x = i;
					start.y = j;
				}
			}
		}

		if (bfs()) result = 1;

		cout << "#" << test_case << " " << result << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}