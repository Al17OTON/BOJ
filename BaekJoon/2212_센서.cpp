/*
	진짜 집중이 안되서 못푸는듯... 갭을 구해서 작은 갭만 더하면 되는건디
*/
#include <iostream>
#include <algorithm>
#define MAX 10000
using namespace std;

int N, K, arr[MAX], gap[MAX] = { 0 };

int greedy()
{
	int result = 0;
	for (int i = 1; i < N; i++)
	{
		gap[i - 1] = arr[i] - arr[i - 1];
	}
	sort(gap, gap + N - 1);

	for (int k = 0; k < N - K; k++)
	{
		result += gap[k];
	}
	return result;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;

	for (int n = 0; n < N; n++)
	{
		cin >> arr[n];
	}
	
	sort(arr, arr + N);

	cout << greedy() << endl;
}