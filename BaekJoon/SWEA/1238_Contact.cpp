#include<iostream>
#include<cstring>
#include<queue>
#define MAX 101

using namespace std;
struct NODE
{
	int a[MAX];	//방문가능한 사람들
	int n;	//위 배열에 들어간 사람 수
	bool dup[MAX];	//중복여부
};
struct CONTACT
{
	int num, time;	//번호와 연락받은 시점 기록
};

NODE p[MAX];
bool visit[MAX];	//방문여부 표시
int result, N, start;

int bfs()
{
	CONTACT latest = { start, 0 };	//시작점에서는 가장 늦게 연락받은 사람은 시작한 사람이다.
	CONTACT tmp;
	queue<CONTACT> q;
	q.push(latest);
	
	while (!q.empty())
	{
		tmp = q.front(); q.pop();
		if (!visit[tmp.num])	//방문했던곳이라면 이미 연락을 받은상태이므로 스킵
		{
			visit[tmp.num] = true;	//방문표시
			for (int i = 0; i < p[tmp.num].n; i++)	//연락가능한 사람들한테 모두 연락돌리기
			{
				if(!visit[p[tmp.num].a[i]])	//방문했던곳은 가지말기
					q.push({ p[tmp.num].a[i], tmp.time + 1 });	//시간 증가후 큐에 삽입
			}
		}
		if (tmp.time > latest.time)	//가장 늦은 사람 찾기
		{
			latest = tmp;
		}
		else if (tmp.time == latest.time)
		{
			if (tmp.num > latest.num)
			{
				latest = tmp;
			}
		}
	}
	return latest.num;
}

int main(int argc, char** argv)
{
	int test_case, i, from, to;
	int T = 10;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		memset(p, 0, sizeof(p));	//int 2개랑 bool 하나니까 이렇게 초기화해도 가능
		memset(visit, 0, sizeof(visit));
		result = 0;
		cin >> N;
		cin >> start;
		
		for (i = 0; i < N / 2; i++)
		{
			cin >> from;
			cin >> to;	//두개씩 입력받기

			if (!p[from].dup[to])	//중복된값이 아니라면
			{
				p[from].dup[to] = true;	//중복 체크
				p[from].a[p[from].n++] = to;	//연락 리스트에 올리기
			}
		}
		result = bfs();

		cout << "#" << test_case << " " << result << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}