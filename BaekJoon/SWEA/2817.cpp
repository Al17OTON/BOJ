#include<iostream>
#define MAX 20
using namespace std;

int N, K, result;
int arr[MAX];
bool visit[MAX];

void DFS(int n, int x)	//n은 현재 조합의 합계, x는 중복 조합을 막기 위해 몇번째 숫자부터 조합할 것인지 알려주는 역할
{
	if (n == K)
	{
		result++;
		return;
	}
	else if (n > K) return;

	for (int i = x; i < N; i++)
	{
		if (!visit[i])	//방문하지 않은 곳이라면 pick하고 보기
		{
			visit[i] = true;
			DFS(n + arr[i], i + 1);
			visit[i] = false;
		}
	}
}

int main(int argc, char** argv)
{
	int test_case, i;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		result = 0;
		cin >> N;
		cin >> K;

		for (i = 0; i < N; i++)
		{
			cin >> arr[i];
			visit[i] = false;
		}

		DFS(0, 0);

		cout << "#" << test_case << " " << result << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}