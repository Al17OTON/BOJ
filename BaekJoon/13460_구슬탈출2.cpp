#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define MAX 10

using namespace std;

char map[MAX][MAX];
int N, M, result = 100;

int min(int a, int b)
{
	return a > b ? b : a;
}

char up(char a[][MAX])	//return R = 빨간공 탈출, B = 파란공탈출, N = 탈출X
{
	bool red = false, blue = false; //각 구슬의 이동여부
	bool goalR = false, goalB = false; //구슬 탈출 여부
	int i, j, x;
	for (i = 1; i < M - 1; i++)
	{
		for (j = 2; j < N - 1; j++)
		{
			if (a[j][i] == 'R')
			{
				red = true;
				for (x = j; x >= 0; x--)
				{
					if (a[x][i] == 'B' || a[x][i] == '#')	//장애물 충돌시
					{
						a[j][i] = '.';
						a[x + 1][i] = 'R';	//충돌지점 전에 구슬 위치하기
						break;
					}
					if (a[x][i] == 'O')	//구멍이 있다면
					{
						a[j][i] = '.';	//구슬 제거
						goalR = true;
						break;
					}
				}
			}
			else if (a[j][i] == 'B')
			{
				blue = true;
				for (x = j; x >= 0; x--)
				{
					if (a[x][i] == 'R' || a[x][i] == '#')	//장애물 충돌시
					{
						a[j][i] = '.';
						a[x + 1][i] = 'B';	//충돌지점 전에 구슬 위치하기
						break;
					}
					if (a[x][i] == 'O')	//구멍이 있다면
					{
						a[j][i] = '.';	//구슬 제거
						goalB = true;
						break;
					}
				}

			}
			if (blue && red) break;
		}
		if (blue && red) break;
	}
	if (goalB) return 'B';
	if (goalR) return 'R';
	return 'N';
}

char down(char a[][MAX])
{
	bool red = false, blue = false; //각 구슬의 이동여부
	bool goalR = false,goalB = false; //구슬 탈출 여부
	int i, j, x;
	for (i = 1; i < M - 1; i++)
	{
		for (j = N - 3; j > 0; j--)
		{
			if (a[j][i] == 'R')
			{
				red = true;
				for (x = j; x < N; x++)
				{
					if (a[x][i] == 'B' || a[x][i] == '#')	//장애물 충돌시
					{
						a[j][i] = '.';
						a[x - 1][i] = 'R';	//충돌지점 전에 구슬 위치하기
						break;
					}
					if (a[x][i] == 'O')	//구멍이 있다면
					{
						a[j][i] = '.';	//구슬 제거
						goalR = true;
						break;
					}
				}
			}
			else if (a[j][i] == 'B')
			{
				blue = true;
				for (x = j; x < N; x++)
				{
					if (a[x][i] == 'R' || a[x][i] == '#')	//장애물 충돌시
					{
						a[j][i] = '.';
						a[x - 1][i] = 'B';	//충돌지점 전에 구슬 위치하기
						break;
					}
					if (a[x][i] == 'O')	//구멍이 있다면
					{
						a[j][i] = '.';	//구슬 제거
						goalB = true;
						break;
					}
				}

			}
			if (blue && red) break;
		}
		if (blue && red) break;
	}
	if (goalB) return 'B';
	if (goalR) return 'R';
	return 'N';
}

char left(char a[][MAX])
{
	bool red = false, blue = false; //각 구슬의 이동여부
	bool goalR = false, goalB = false; //구슬 탈출 여부
	int i, j, x;
	for (i = 1; i < N - 1; i++)
	{
		for (j = 2; j < M - 1; j++)
		{
			if (a[i][j] == 'R')
			{
				red = true;
				for (x = j; x >= 0; x--)
				{
					if (a[i][x] == 'B' || a[i][x] == '#')	//장애물 충돌시
					{
						a[i][j] = '.';
						a[i][x + 1] = 'R';	//충돌지점 전에 구슬 위치하기
						break;
					}
					if (a[i][x] == 'O')	//구멍이 있다면
					{
						a[i][j] = '.';	//구슬 제거
						goalR = true;
						break;
					}
				}
			}
			else if (a[i][j] == 'B')
			{
				blue = true;
				for (x = j; x >= 0; x--)
				{
					if (a[i][x] == 'R' || a[i][x] == '#')	//장애물 충돌시
					{
						a[i][j] = '.';
						a[i][x + 1] = 'B';	//충돌지점 전에 구슬 위치하기
						break;
					}
					if (a[i][x] == 'O')	//구멍이 있다면
					{
						a[i][j] = '.';	//구슬 제거
						goalB = true;
						break;
					}
				}

			}
			if (blue && red) break;
		}
		if (blue && red) break;
	}
	if (goalB) return 'B';
	if (goalR) return 'R';
	return 'N';
}

char right(char a[][MAX])
{
	bool red = false, blue = false; //각 구슬의 이동여부
	bool goalR = false, goalB = false; //구슬 탈출 여부
	int i, j, x;
	for (i = 1; i < N - 1; i++)
	{
		for (j = M - 3; j > 0; j--)
		{
			if (a[i][j] == 'R')
			{
				red = true;
				for (x = j; x < M; x++)
				{
					if (a[i][x] == 'B' || a[i][x] == '#')	//장애물 충돌시
					{
						a[i][j] = '.';
						a[i][x - 1] = 'R';	//충돌지점 전에 구슬 위치하기
						break;
					}
					if (a[i][x] == 'O')	//구멍이 있다면
					{
						a[i][j] = '.';	//구슬 제거
						goalR = true;
						break;
					}
				}
			}
			else if (a[i][j] == 'B')
			{
				blue = true;
				for (x = j; x < M; x++)
				{
					if (a[i][x] == 'R' || a[i][x] == '#')	//장애물 충돌시
					{
						a[i][j] = '.';
						a[i][x - 1] = 'B';	//충돌지점 전에 구슬 위치하기
						break;
					}
					if (a[i][x] == 'O')	//구멍이 있다면
					{
						a[i][j] = '.';	//구슬 제거
						goalB = true;
						break;
					}
				}

			}
			if (blue && red) break;
		}
		if (blue && red) break;
	}
	if (goalB) return 'B';
	if (goalR) return 'R';
	return 'N';
}

void copyArr(char a[][MAX], char b[][MAX])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			b[i][j] = a[i][j];
		}
	}
}

void debug(char a[][MAX])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void dfs(char a[][MAX], int n, int dir)
{
	if (n == 11 || n > result)
	{
		return;
	}
	char copyA[MAX][MAX];
	char tmp;
	copyArr(a, copyA);

	if (dir != 1)
	{
		tmp = up(copyA);
		if (tmp == 'R')	//만약 빨간공만탈출이라면
		{
			result = min(result, n + 1);
		}
		else if(tmp == 'N')
		{
			dfs(copyA, n + 1, 1);	//탈출하지 않으면 다음 행동하기
		}
		copyArr(a, copyA);
	}
	if (dir != 2)
	{
		tmp = down(copyA);
		if (tmp == 'R')	//만약 빨간공만탈출이라면
		{
			result = min(result, n + 1);
		}
		else if(tmp == 'N')
		{
			dfs(copyA, n + 1, 2);	//탈출하지 않으면 다음 행동하기
		}
		copyArr(a, copyA);
	}
	if (dir != 3)
	{
		tmp = left(copyA);
		if (tmp == 'R')	//만약 빨간공만탈출이라면
		{
			result = min(result, n + 1);
		}
		else if(tmp == 'N')
		{
			dfs(copyA, n + 1, 3);	//탈출하지 않으면 다음 행동하기
		}
		copyArr(a, copyA);
	}
	if (dir != 4)
	{
		tmp = right(copyA);
		if (tmp == 'R')	//만약 빨간공만탈출이라면
		{
			result = min(result, n + 1);
		}
		else if(tmp == 'N')
		{
			dfs(copyA, n + 1, 4);	//탈출하지 않으면 다음 행동하기
		}
		//copyArr(a, copyA);
	}
}

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf(" %c", &map[i][j]);	// 꿀팁 띄어쓰기를 하면 공백이나 \n 등을 무시해준다고함. https://velog.io/@mttw2820/scanfc%EC%9D%98-%EB%AC%B8%EC%A0%9C

		}
	}
	
	dfs(map, 0, 0);

	if (result >= 11) result = -1;

	cout << result << endl;
}

/*
5 5
#####
#...#
#...#
#R.B#
#####
*/