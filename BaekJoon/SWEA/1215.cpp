#include<iostream>
#define MAX 8

using namespace std;

int N;
char map[MAX][MAX];

char stack[MAX];
int p, len;

void reset()
{
	p = 0; len = 0;
}

void push(char item)
{
	stack[p++] = item;
	len++;
}
char pop()
{
	len--;
	p--;
	return stack[p];
}

int solution()
{
	int i, j, a, odd = N % 2 == 0 ? 0 : 1;
	bool flag;
	int result = 0;

	for(i = 0; i < MAX ; i++)	//모든 행 반복
	{
		for (j = 0; j <= MAX - N; j++)
		{
			flag = true;
			reset();
			for (a = 0; a < N / 2; a++)
			{
				push(map[i][j + a]);
			}

			for (a = 0; a < N / 2; a++)
			{
				if (pop() != map[i][j + a + (N / 2) + odd])
				{
					flag = false;
					break;
				}
			}
			if (flag) result++;

			//// 모든 열 반복 i와 j 부분을 도치하면 된다.

			flag = true;
			reset();
			for (a = 0; a < N / 2; a++)
			{
				push(map[j + a][i]);
			}

			for (a = 0; a < N / 2; a++)
			{
				if (pop() != map[j + a + (N / 2) + odd][i])
				{
					flag = false;
					break;
				}
			}
			if (flag) result++;
		}
	}
	
	return result;
}

int main(int argc, char** argv)
{
	int test_case, i, j, result;
	int T = 10;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		result = 0;
		cin >> N;

		for(i = 0; i < MAX; i++)
		{
			for (j = 0; j < MAX; j++)
			{
				cin >> map[i][j];
			}
		}

		if (N == 1)
		{
			result = MAX * MAX;
		}
		else
		{
			result = solution();
		}

		cout << "#" << test_case << " " << result << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}