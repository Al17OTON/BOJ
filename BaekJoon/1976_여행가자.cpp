/*
	틀릴줄알고 일단 제출했는데 맞았다.
	유니온 파인드의 성질을 사용해서 연결된 도시들을 집합으로 구분하고
	마지막에 주어진 여행계획에서 시작 도시의 find와 나머지 도시의 find가 같아야한다. (즉, 모두 같은 집합이여야한다.)
	라는 생각으로 풀었다.
*/

#include <iostream>
#define MAX 200

using namespace std;

int N, M, uni[MAX + 1];

int find(int x)
{
	if (uni[x] == x) return x;
	return uni[x] = find(uni[x]);
}

void setuni(int x, int y)
{
	x = find(x); y = find(y);

	uni[x] = y;
}

int main()
{
	int i, j, a, startsetnum;
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (i = 0; i <= N ; i++) uni[i] = i;

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			cin >> a;
			if (a == 1)
			{
				setuni(j + 1, i + 1);	//도시 연결
			}
		}
	}

	cin >> a;
	
	startsetnum = find(a);		//시작 도시의 집합과 여행 계획에 속한 나머지 도시의 집합이 모두 같아야한다.

	for (i = 1; i < M; i++)
	{
		cin >> a;
		if (startsetnum != find(a))
		{
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
}