//가장 큰 회문이 될 수 있는 경우부터 아래로 쭉 훑어보는 방법
#include<iostream>
#define MAX 100

using namespace std;

int result;
char map[MAX][MAX];

bool check(int x, int y, int len, bool col)	//주어진 문자열을 반으로 나누고 양 옆이 일치하는지 체크
{
	int side = len / 2;
	for (int i = 0; i < side; i++)
	{
		if (col)
		{
			if (map[x][y + i] != map[x][len - 1 - i + y])
				return false;
		}
		else
		{
			if (map[y + i][x] != map[len - 1 - i + y][x])
				return false;
		}
	}
	return true;
}


void sim()
{
	int best = MAX;	//MAX 부터 1씩 감소하여 가장 큰 회문을 찾도록 함.
	bool flag = false;	//첫 회문 발견시 표시, 가장 큰 회문부터 찾기 때문에 true인 시점이 가장 큰 회문이다.
	int i, j, x;
	while (best > 1)	//길이가 1인 회문까지만 찾기
	{
		for (i = 0; i <= MAX - best; i++)	//best의 값이 100이라면 길이가 100인 회문만 찾으므로 1번의 반복만 하도록 함. 99라면 2번...
		{
			for (j = 0; j <= MAX - best; j++)
			{
				if (check(i, j, best, true))
				{
					flag = true;
					break;
				}
				if (check(i, j, best, false))
				{
					flag = true;
					break;
				}
			}
			if (flag) break;
		}
		if (flag) break;
		best--;
	}
	result = best;	//반복문 탈출 시점의 best값이 정답
}

int main(int argc, char** argv)
{
	int test_case, i, j;
	int T = 10, N;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		result = 0;
		cin >> N;

		for (i = 0; i < MAX; i++)
		{
			cin >> map[i];
		}
		sim();
		cout << "#" << test_case << " " << result << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}