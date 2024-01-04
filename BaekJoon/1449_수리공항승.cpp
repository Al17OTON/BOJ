/*
	오름차순으로 정렬한 후 소모되는 테이프 길이를 계산하여 소모된 테이프 출력
*/
#include <iostream>
#include <algorithm>
#define MAX 1000

using namespace std;

int N, L, arr[MAX];

int greedy()
{
	int result = 0, i = 1;
	bool flag = true;
	float l = L - 1;
	while (i < N)
	{
		if (flag)
		{
			l -= arr[i] - arr[i - 1];
			if (l < 0)
			{
				result++;
				l = L - 1;
			}
			else if (l == 0)
			{
				result++;
				l = L - 1;
				flag = false;
			}
		}
		else
		{
			flag = true;
		}
		i++;
	}
	if (flag) return result + 1;
	return result;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> L;

	for (int n = 0; n < N; n++)
	{
		cin >> arr[n];
	}

	sort(arr, arr + N);

	cout << greedy() << endl;
}