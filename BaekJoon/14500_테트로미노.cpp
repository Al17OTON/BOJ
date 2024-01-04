#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define MAX 500

using namespace std;

int map[MAX][MAX];
int N, M;

int main()
{
	int i, j;
	scanf("%d %d", &N, &M);

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}
}