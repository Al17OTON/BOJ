/// 스택으로 모든 경우를 다 찾아보면서 했는데, 생각보다 실행속도가 느렸다. 약 2초정도 오버헤드도 충분히 줄였다고 생각했는데 아니였다 ㅠ
// 찾아보니까 가장 길이가 긴 회문을 찾아보면서 하는게 더 빠른거 같다.

#include<iostream>
#define MAX 100

using namespace std;

int result;
char map[MAX][MAX];

char stackA[MAX + 1];	//행 스택
int lenA, frontA;

char stackB[MAX + 1];	//열 스택
int lenB, frontB;

int max(int a, int b)	//최소값 구하기
{
	return a > b ? a : b;
}

bool check(int len, char* arr)	//주어진 문자열을 반으로 나누고 양 옆이 일치하는지 체크
{
	int n = len / 2;	//문자를 반으로 나누었을때, 양 변의 길이

	for (int i = 0; i < n; i++)
	{
		if (arr[i] != arr[len - i - 1])	//일치하지 않으면 탈출
			return false;
	}
	return true;
}

void pushA(char data)
{
	stackA[frontA++] = data;
	lenA++;
}
char popA()
{
	lenA--;
	return stackA[frontA-- - 1];
}
void resetA()
{
	lenA = 0;
	frontA = 0;
}

void pushB(char data)
{
	stackB[frontB++] = data;
	lenB++;
}
char popB()
{
	lenB--;
	return stackB[frontB-- - 1];
}
void resetB()
{
	lenB = 0;
	frontB = 0;
}

void sim()
{
	int A = 1, B = 1;	//현재 가장 긴 길이
	char temp[MAX];	
	for (int i = 0; i < MAX; i++)	//모든 행열에 대해서
	{
		resetA(); resetB();	//스택 초기화
		for (int j = 0; j < MAX; j++)
		{
			pushA(map[i][j]); pushB(map[j][i]);	

			if (lenA > A && lenA > B)	//스택의 길이가 충분히 길어지면, 만약 현재 가장 긴 회문의 길이가 5일때, 5 이하의 회문은 찾아볼 필요가 없으므로 제외한다.
			{
				for (int x = 0; x < lenA - A; x++)	//가장 길이가 긴 문장부터 회문여부를 판별, 이런식으로 내림차 순으로 판별하면 회문이 나왔을때 그보다 작은 회문을 찾아보지 않아도 됨.
				{
					int y = 0;
					while (lenA - x)	//x 값이 증가하면서 판별할 문장의 길이를 줄임.
					{
						temp[y++] = popA();
					}
					for (int z = y - 1; z >= 0; z--) pushA(temp[z]);	//다시 스택에 넣기
					if (check(y, temp))
					{
						A = y;
						break;
					}
				}
			}

			if (lenB > B && lenB > A)	//위 A 동작과 동일
			{
				for (int x = 0; x < lenB - B; x++)
				{
					int y = 0;
					while (lenB - x)
					{
						temp[y++] = popB();
					}
					for (int z = y - 1; z >= 0; z--) pushB(temp[z]);
					if (check(y, temp))
					{
						B = y;
						break;
					}
				}
			}
		}
	}
	result = max(A, B);	//행과 열 중 가장 큰 회문을 result에 넣기
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