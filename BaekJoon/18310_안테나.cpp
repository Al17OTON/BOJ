/*
	맨 처음에는 평균을 구해서 평균에 가까운 곳을 출력하도록 하였는데 틀렸다.
	찾아보니까 중앙값으로 풀어야한다고 한다.
	중앙값은 홀수개일때와 짝수개일때가 있는데 짝수일때 가장 작은 것을 출력하면 된다.
*/
#include <iostream>
#include <algorithm>
#define MAX 200000

using namespace std;

int N, arr[MAX];

int greedy()
{
	if (N % 2 == 0) return arr[N / 2 - 1];
		
	return arr[N / 2];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int n = 0; n < N; n++)
	{
		cin >> arr[n];
	}

	sort(arr, arr + N);

	cout << greedy() << endl;
}