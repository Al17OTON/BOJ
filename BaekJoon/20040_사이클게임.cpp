/*
	어렵게 생각할 필요 없이 병합하는 집합의 루트 노드가 서로 같다면 사이클이 완성된것으로 간주하면된다...
*/

#include <iostream>
#define MAX 500000

using namespace std;

int N, M;
int uni[MAX + 1];

int find(int x)
{
	if (uni[x] == x) return x;
	return uni[x] = find(uni[x]);
}

int main()
{
	int a, b, i, x, y;
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (i = 0; i < N; i++) uni[i] = i;
	
	for (i = 0; i < M; i++)
	{
		cin >> a >> b;

		x = find(a); y = find(b);

		if (x == y)
		{
			cout << i + 1 << endl;
			return 0;
		}
		uni[x] = y;
	}
	cout << 0 << endl;
}