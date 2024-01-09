#include<iostream>
#include<queue>
#define MAX 50

using namespace std;
typedef struct VEC
{
    int x, y;
    int time;
};
queue<VEC> q;

int map[MAX][MAX];		//맵
bool visit[MAX][MAX];	//방문한 곳 표시
int N, M, R, C, L;
bool mov[][4] = {	//상하좌우 1~7번 수도관 이동가능 여부 표시
    { false, false, false, false},
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
int connect[] = {1, 0, 3, 2};   //하수도관이 연결되려면 어느 지점의 인덱스와 연결되어야하는지 표시 각각 상하좌우

void BFS()
{
    VEC n = { R, C , 0}, tmp;   //시작점
    if (!q.empty()) while (!q.empty()) q.pop(); //큐가 빌때까지 pop 반복
    
    q.push(n);

    while (!q.empty())  //큐가 빌때까지
    {
        n = q.front();
        q.pop();
        visit[n.x][n.y] = true; //방문여부 표시

        for (int i = 0; i < 4; i++)
        {
            if (mov[map[n.x][n.y]][i] && n.time < L - 1)  //파이프 유형에 따라 이동 여부 결정
            {
                tmp.x = n.x + dirX[i]; tmp.y = n.y + dirY[i]; tmp.time = n.time + 1;   //다음 노드의 좌표 계산
                if ((tmp.x >= 0 && tmp.x < N && tmp.y >= 0 && tmp.y < M)  && !visit[tmp.x][tmp.y] && map[tmp.x][tmp.y] != 0) //방문하지 않은 곳이여야함, 파이프가 없는 곳 제외, 좌표도 인덱스 벗어나지 않은곳
                {
                    if (mov[map[tmp.x][tmp.y]][connect[i]])  //파이프가 연결되어 있어야함.
                    {
                        q.push(tmp);
                    }
                }
            }
        }
    }
    
}

int main(int argc, char** argv)
{
    int test_case, i, j, result;
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
                visit[i][j] = false;
            }
        }
        BFS();
        for (i = 0; i < N; i++)
        {
            for (j = 0; j < M; j++)
            {
                if (visit[i][j]) result++;
            }
        }

        cout << "#" << test_case << " " << result << endl;
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}