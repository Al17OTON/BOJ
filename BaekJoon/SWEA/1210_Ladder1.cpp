#include<iostream>
#define MAX 100

using namespace std;

int map[MAX][MAX];
int result;
int goal;

int sim()	//x인 지점에서부터 사다리를 타고 올라가면 정답이다.
{
	int left, right;
	int j = goal;
	for (int i = MAX - 1; i >= 0; i--)	//아래서부터 사다리타기
	{
		if (j > 0) left = map[i][j - 1];	//좌로 이동할수있는지
		else left = 0;

		if (j < MAX - 1) right = map[i][j + 1];	//우
		else right = 0;

		if (left == 1)	//이동할 수 있다면 이동하기
		{
			for (; map[i][j - 1] != 0 && j != 0; j--);	//다음 사다리까지 이동
		}
		else if (right == 1)
		{
			for (; map[i][j + 1] != 0 && j != MAX - 1; j++);	//다음 사다리까지 이동
		}
	}
	return j;	//결과 반환 i가 0인 지점의 j가 정답
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
			for (j = 0; j < MAX; j++)
			{
				cin >> map[i][j];
				if (map[i][j] == 2) goal = j;	//x 지점이 어느 좌표에 있는지
			}
		}

		result = sim();

		cout << "#" << test_case << " " << result << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}