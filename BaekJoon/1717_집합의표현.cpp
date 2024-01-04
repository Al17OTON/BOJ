#include <iostream>
#define MAX 1000000

using namespace std;

int N, M, uni[MAX + 1] = { 0 };

int find(int x)
{
	if (uni[x] == x) return x;
	return uni[x] = find(uni[x]);
}

bool isUnion(int a, int b)
{
	a = find(a); b = find(b);
	if (a == b) return true;
	return false;
}

void setUnion(int a, int b)
{
	a = find(a); b = find(b);
	uni[a] = b;
}

int main()
{
	int i, com, a, b;
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (i = 0; i <= N; i++) uni[i] = i;

	for (i = 0; i < M; i++)
	{
		cin >> com >> a >> b;
		if (com == 0)
		{
			setUnion(a, b);
		}
		else
		{
			isUnion(a, b) ? cout << "YES\n" : cout << "NO\n";
		}
	}
}