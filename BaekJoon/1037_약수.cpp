#include <iostream>

using namespace std;

int getMAX(int a, int b)
{
	return a > b ? a : b;
}
int getMIN(int a, int b)
{
	return a > b ? b : a;
}

/*
	1과 자기자신을 제외한 모든 약수가 주어진다고 했으므로
	가장 작은 값과 가장 큰갑을 구해서 곱하면 정답이다.
*/
int main()
{
	int N, min = 1000000, max = 0, temp;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		min = getMIN(temp, min);
		max = getMAX(temp, max);
	}

	cout << min * max << endl;
}