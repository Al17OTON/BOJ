#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>

using namespace std;

//힙 정렬을 사용하여 문제를 풀었습니다.
//가장 작은 두 값을 더하여 검사한 카드 수를 result에 더하고 두 값을 더해서 나온 결과를 힙에 다시 넣어서
//정렬을 시키는 것을 반복하여 더 이상 정렬할 카드가 없을 때 결과를 출력하도록 하였습니다.
int main()
{
	priority_queue<int, vector<int>, greater<int>> q;	//오름차순으로 정렬
	int N, tmp, i, a, b, result = 0;
	scanf("%d", &N);

	for (i = 0; i < N; i++)
	{
		scanf("%d", &tmp);
		q.push(tmp);
	}

	while (!q.empty())
	{
		a = q.top(); q.pop();
		if (q.empty())
		{
			break;
		}
		else
		{
			b = q.top(); q.pop();
		}

		tmp = a + b;
		result += tmp;
		q.push(tmp);
	}

	cout << result << endl;
}