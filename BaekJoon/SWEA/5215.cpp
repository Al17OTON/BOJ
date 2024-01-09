#include<iostream>
#define MAX 20

using namespace std;
int N, L;	//재료개수, 칼로리제한

int taste[MAX + 1];
int cal[MAX + 1];

int dp[10001];

int max(int a, int b)
{
	return a > b ? a : b;
}

void makeHamburger()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = L; j > 0; j--)
		{
			if (cal[i] <= j)
			{
				dp[j] = max(dp[j], dp[j - cal[i]] + taste[i]);	//현재 들어갈 수 있는 재료의 칼로리를 뺀 곳의 최대값과 현재 넣을 재료의 가치를 합쳐서 현재 값과 비교하여 가장 좋은것을 넣기
			}
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
		cin >> N;
		cin >> L;

		for (i = 0; i < N; i++)
		{
			cin >> taste[i];
			cin >> cal[i];
		}

		makeHamburger();

		cout << "#" + test_case << " " << dp[L] << endl;

		for (i = 0; i < L; i++)
		{
			dp[i] = 0;
		}
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}