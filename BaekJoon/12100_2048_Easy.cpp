//백준에 내가 제출한 것에 주석달았으니 참고
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define MAX 20

using namespace std;

int arr[MAX][MAX];
int N, result;

int max(int a, int b)
{
	return a > b ? a : b;
}

void up(int a[][MAX])
{
	bool colide[MAX][MAX] = { false };
	int i, j, x;

	for (i = 0; i < N; i++)
	{
		for (j = 1; j < N; j++)
		{
			if (a[j][i] != 0)
			{
				for (x = j - 1; x >= 0; x--)
				{
					if (a[x][i] != 0)
					{
						if (a[x][i] == a[j][i] && !colide[x][i])
						{
							a[x][i] *= 2;
							a[j][i] = 0;
							colide[x][i] = true;
							//result = max(a[i][x], result);
							break;
						}
						else if(x + 1 != j)	//움직였는데 그자리인경우가 아니라면
						{
							a[x + 1][i] = a[j][i];
							a[j][i] = 0;
							break;
						}
						break;
					}
					else if (x == 0)
					{
						a[x][i] = a[j][i];
						a[j][i] = 0;
					}
				}
			}
		}
	}
}

void down(int a[][MAX])
{
	bool colide[MAX][MAX] = { false };
	int i, j, x;

	for (i = N - 1; i >= 0; i--)
	{
		for (j = N - 2; j >= 0; j--)
		{
			if (a[j][i] != 0)
			{
				for (x = j + 1; x < N; x++)
				{
					if (a[x][i] != 0)
					{
						if (a[x][i] == a[j][i] && !colide[x][i])
						{
							a[x][i] *= 2;
							a[j][i] = 0;
							//result = max(a[i][x], result);
							colide[x][i] = true;
							break;
						}
						else if (x - 1 != j)	//움직였는데 그자리인경우가 아니라면
						{
							a[x - 1][i] = a[j][i];
							a[j][i] = 0;
							break;
						}
						break;
					}
					else if (x == N - 1)
					{
						a[x][i] = a[j][i];
						a[j][i] = 0;
					}
				}
			}
		}
	}
}

void left(int a[][MAX])
{
	bool colide[MAX][MAX] = { false };
	int i, j, x;

	for (i = 0; i < N; i++)
	{
		for (j = 1; j < N; j++)
		{
			if (a[i][j] != 0)
			{
				for (x = j - 1; x >= 0; x--)
				{
					if (a[i][x] != 0)
					{
						if (a[i][x] == a[i][j] && !colide[i][x])
						{
							a[i][x] *= 2;
							a[i][j] = 0;
							//result = max(a[i][x], result);
							colide[i][x] = true;
							break;
						}
						else if (x + 1 != j)	//움직였는데 그자리인경우가 아니라면
						{
							a[i][x + 1] = a[i][j];
							a[i][j] = 0;
							break;
						}
						break;
					}
					else if (x == 0)
					{
						a[i][x] = a[i][j];
						a[i][j] = 0;
					}
				}
			}
		}
	}
}

void right(int a[][MAX])
{
	bool colide[MAX][MAX] = { false };
	int i, j, x;

	for (i = N - 1; i >= 0; i--)
	{
		for (j = N - 2; j >= 0; j--)
		{
			if (a[i][j] != 0)
			{
				for (x = j + 1; x < N; x++)
				{
					if (a[i][x] != 0)
					{
						if (a[i][x] == a[i][j] && !colide[i][x])
						{
							a[i][x] *= 2;
							a[i][j] = 0;
							//result = max(a[i][x], result);
							colide[i][x] = true;
							break;
						}
						else if (x - 1 != j)	//움직였는데 그자리인경우가 아니라면
						{
							a[i][x - 1] = a[i][j];
							a[i][j] = 0;
							break;
						}
						break;
					}
					else if (x == N - 1)
					{
						a[i][x] = a[i][j];
						a[i][j] = 0;
					}
				}
			}
		}
	}
}

void copyArr(int a[][MAX], int b[][MAX])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			b[i][j] = a[i][j];
		}
	}
}

void debug(int a[][MAX])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	cout << endl;
}

int getLarge(int a[][MAX])
{
	int result = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			result = max(result, a[i][j]);
		}
	}
	return result;
}

void dfs(int n, int a[][MAX])
{
	if (n == 5) {
		result = max(getLarge(a), result);
		return;
	}
	int current[MAX][MAX];
	copyArr(a, current);

	up(current);
	dfs(n + 1, current);
	copyArr(a, current);

	down(current);
	dfs(n + 1, current);
	copyArr(a, current);

	left(current);
	dfs(n + 1, current);
	copyArr(a, current);

	right(current);
	dfs(n + 1, current);
}

int main()
{
	while (1) {
		int c = 0;
		result = 0;
		scanf("%d", &N);

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				scanf("%d", &arr[i][j]);
				result = max(arr[i][j], result);
				if (arr[i][j] != 0) c++;
			}
		}

		if (c != 1)
			dfs(0, arr);

		while (0)
		{
			int input;
			cin >> input;

			if (input == 0) break;
			else if (input == 1)
			{
				up(arr);
			}
			else if (input == 2)
			{
				down(arr);
			}
			else if (input == 3)
			{
				left(arr);
			}
			else if (input == 4)
			{
				right(arr);
			}
			debug(arr);
		}

		cout << result << endl;
	}
}

/*
5
2 2 2 2 2
2 2 2 2 2
2 2 2 2 2
2 2 2 2 2
2 2 2 2 2
*/