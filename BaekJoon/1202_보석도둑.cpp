#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define MAX 300001

using namespace std;

pair<int, int> dia[MAX];
int bag[MAX];
priority_queue<int, vector<int>, less<int>> pq;
int N, K;

long long greedy()
{
	int index = 0;
	long long result = 0;
	
	for (int i = 0; i < K; i++)
	{
		while (index < N && bag[i] >= dia[index].first)
		{
			pq.push(dia[index++].second);
		}
		if (!pq.empty())
		{
			result += pq.top();
			pq.pop();
		}
	}
	return result;
}

int main()
{
	int i;
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;

	for (i = 0; i < N; i++)
	{
		cin >> dia[i].first >> dia[i].second;
	}
	for (i = 0; i < K; i++)
	{
		cin >> bag[i];
	}

	sort(dia, dia + N);
	sort(bag, bag + K);

	cout << greedy() << '\n';
}