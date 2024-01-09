//DFS 를 사용해서 푼 방법
//도달할수있는 모든 범위를 간 후 방문한 곳 갯수를 세서 결과를 도출
//DFS 특성상 방문여부만 체크하면 더 짧은 루트로 이미 방문한 노드로 왔을때 더이상 진행하지 않아 오답이 나옴.
//이러한 문제를 해결하기 위해 방문했을때 소요 시간을 기록해서 짧은 루트만 기록하도록 하였고 더 소요시간이 긴 루트로 왔을경우 백트래킹하도록함.
//BFS로 푸는게 더 좋다고함
#include<iostream>
#define MAX 50

using namespace std;

int map[MAX][MAX];		//맵
int visit[MAX][MAX];	//방문한 곳 표시
int N, M, R, C, L, result;
bool mov[][4] = {	//상하좌우 1~7번 수도관 이동가능 여부 표시
    { true, true, true, true},
    { true, true, false, false},
    { false, false, true, true},
    { true, false, false, true},
    { false, true, false, true},
    { false, true, true, false},
    { true, false, true, false}
};
int dirX[] = { -1, 1, 0, 0 };	//상하좌우에 따른 높이 변화
int dirY[] = { 0, 0, -1, 1 };	//좌우 
int connect[] = { 1, 0, 3, 2 };   //하수도관이 연결되려면 어느 지점의 인덱스와 연결되어야하는지 표시 각각 상하좌우

int MIN(int a, int b)
{
    return a < b ? a : b;
}

void DFS(int time, int x, int y)
{
    if (x < 0 || x >= N || y < 0 || y >= M) return; //만약 좌표가 인덱스를 벗어났을경우
    if (time == L || map[x][y] == 0 || visit[x][y] <= time)	//시간을 전부 소모하면 종료 또는 이미 왔던 곳이면 또는 하수관이 없는곳이라면 종료
    {
        return;
    }
    int tmpX, tmpY;

    visit[x][y] = time;	//방문한 곳 표시

    for (int i = 0; i < 4; i++)
    {
        if (mov[map[x][y] - 1][i])	//현재 상수도관의 종류에 따라 이동여부 표시
        {
            tmpX = x + dirX[i]; tmpY = y + dirY[i];
            if (map[tmpX][tmpY] != 0 && mov[map[tmpX][tmpY] - 1][connect[i]])    //다음 하수도관이 연결되어있는지 체크
                DFS(time + 1, tmpX, tmpY);
        }
    }
}

int SW1953()
{
    int test_case, i, j;
    int T;

    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case)
    {
        result = 0;
        cin >> N;
        cin >> M;
        cin >> R;
        cin >> C;
        cin >> L;

        for (i = 0; i < N; i++)
        {
            for (j = 0; j < M; j++)
            {
                cin >> map[i][j];
                visit[i][j] = 9999;
            }
        }
        DFS(0, R, C);

        for (i = 0; i < N; i++)
        {
            for (j = 0; j < M; j++)
            {
                if (visit[i][j] < L)
                    result++;
            }
        }

        cout << "#" << test_case << " " << result << endl;
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}