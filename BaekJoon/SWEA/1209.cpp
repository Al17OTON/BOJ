#include<iostream>
#define MAX 100
using namespace std;

int row[MAX];
int col[MAX];
int a, b; //대각선

int max(int a, int b)
{
	return a > b ? a : b;
}

void reset()
{
	for (int i = 0; i < MAX; i++)
	{
		row[i] = 0;
		col[i] = 0;
	}
	a = 0; b = 0;
}

int main(int argc, char** argv)
{
	int test_case, i, j, result, input;
	int T = 10;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> input;
		reset();
		result = 0;

		for (i = 0; i < MAX; i++)
		{
			for (j = 0; j < MAX; j++)
			{
				cin >> input;
				row[i] += input;
				col[j] += input;
				if (i == j) a += input;
				if (i + j == MAX) b += input;
			}
		}

		result = max(a, b);

		for (i = 0; i < MAX; i++)
		{
			result = max(result, max(col[i], row[i]));
		}


		cout << "#" << test_case << " " << result << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}