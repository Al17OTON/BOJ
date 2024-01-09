#include<iostream>
#define MAX 100

using namespace std;

int map[MAX][MAX];
int result, N;

int countJam()	//12 패턴을 찾으면 풀리는 문제
{
	int i, j;
	bool flag;

	for (i = 0; i < MAX; i++)
	{
		flag = false;
		for (j = 0; j < MAX; j++)
		{
			if (map[j][i] != 0)
			{
				if (map[j][i] == 1)
				{
					flag = true;
				}
				else if (map[j][i] == 2 && flag)
				{
					flag = false;
					result++;
				}
			}
		}
	}
	return result;
}

int main(int argc, char** argv)
{
	int test_case, i, j;
	int T = 10;


	for (test_case = 1; test_case <= T; ++test_case)
	{
		result = 0;

		cin >> N;		//무조건 100

		for (i = 0; i < MAX; i++)
		{
			for (j = 0; j < MAX; j++)
			{
				cin >> map[i][j];
			}
		}
	
		countJam();
		cout << "#" << test_case << " " << result << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}