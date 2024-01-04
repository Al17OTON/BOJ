#include <iostream>
#include <queue>
#define MAX 101

using namespace std;

int N, K;
int arr[MAX];
queue<int> q;

int exchange(int item, int k)			//현재 꼿혀있는 제품 중 사용계획이 없거나 가장 나중인 제품을 찾아서 코드 제거하기
{
	int i,a, checkCounter = q.size();
	bool check[MAX] = { false };

	if (N == 1)
	{
		a = q.front(); q.pop();
		q.push(item);
		return a;
	}

	for (i = 0; i < q.size(); i++)
	{
		a = q.front(); q.pop();
		check[a] = true;
		q.push(a);
	}

	for (i = k + 1; i < K; i++)
	{
		for (int t = 0; t < q.size(); t++)
		{
			a = q.front(); q.pop();
			if (a == arr[i] && check[a])
			{
				check[a] = false;
				checkCounter--;
			}
			q.push(a);
			if (checkCounter == 1) break;
		}
		if (checkCounter == 1) break;
	}

	for (i = 0; i < q.size(); i++)
	{
		a = q.front(); q.pop();
		if (check[a])
		{
			q.push(item);
			return a;
		}
		q.push(a);
	}
}

int greedy()
{
	bool mul[MAX] = {false};
	int result = 0;

	for (int k = 0; k < K; k++)
	{
		if (!mul[arr[k]])			//현재 전기용품이 콘센트에 안꼿혀있어야함.
		{
			if (q.size() == N)		//콘센트 점유율이 100%일때
			{
				mul[exchange(arr[k], k)] = false;
				result++;
				mul[arr[k]] = true;
			} 
			else					//콘센트가 비어있다면 그냥 꼿기
			{
				mul[arr[k]] = true;
				q.push(arr[k]);
			}
		}
	}
	return result;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;

	for (int i = 0; i < K; i++)
	{
		cin >> arr[i];
	}

	cout << greedy() << '\n';
}