//DFS나 우선순위 큐로 풀면 안된다...
//다른사람 해법을 봤는데 입력 받는 부분에서 입력을 받을때마다 이전 기록에 더해서 입력을 다 받는 시점에서 이미 모든 경우의 수를 구해서 구한다.
//파이썬에서는 Set으로도 풀수있는듯...
#include<iostream>
#define MAX 100

using namespace std;

int arr[MAX];
int result, N;
bool visit[MAX * MAX];

int main(int argc, char** argv)
{
	int test_case, i, j;
	int T, sum;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		memset(visit, false, sizeof(visit));	//점수 경우의 수 초기화
		result = 0;
		sum = 0;	//만점 점수 기록용
		cin >> N;

		visit[0] = true;//0점은 방문처리

		for (i = 0; i < N; i++)	//N번 입력을 받는다.
		{
			cin >> arr[i];
			
			sum += arr[i];	//만점 점수를 갱신
			visit[sum] = true;	//방문처리
			j = sum - 1;	//현재 최고점 미만에 경우의 수 갱신
			while (j >= 0)	//sum ~ 0점 까지
			{
				if (visit[j])	//방문한 곳이라면 현재 입력받은 점수를 더한 곳을 방문처리
				{
					visit[j + arr[i]] = true;
				}
				j--;
			}

		}

		for (i = 0; i < MAX * MAX; i++)	//점수 개수 세기
		{
			if (visit[i]) result++;
		}

		cout << "#" << test_case << " " << result << endl;

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}