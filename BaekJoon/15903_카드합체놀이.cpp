//아오 long long으로 처음부터 할껄,,, 알고 있었는데 괜히 객기부렸다.
#include<iostream>
#include<queue>

using namespace std;

int N, M;
priority_queue<long long, vector<long long>, greater<long long>> pq;

long long greedy()							//우선순위 큐를 이용하여 풀이, 오름차순으로 정렬하고 가장 작은 값 두 개를 뽑은 뒤 합치고 다시 큐에 삽입하는 것을 M이 0이 될때까지 반복한다.
{
	long long a, b, result = 0;
	while (M > 0)
	{
		a = pq.top(); pq.pop();
		b = pq.top(); pq.pop();

		pq.push(a + b);
		pq.push(a + b);
		M--;
	}

	while (!pq.empty())
	{
		result += pq.top(); pq.pop();
	}
	return result;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int i;
	long long a;

	cin >> N >> M;

	for (i = 0; i < N; i++)
	{
		cin >> a;
		pq.push(a);
	}

	cout << greedy() << endl;
}