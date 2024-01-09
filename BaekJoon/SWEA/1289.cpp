#include<iostream>
#define MAX 50
using namespace std;

char mem[MAX + 1];

int main(int argc, char** argv)
{
	int test_case, i, result;
	int T;
	char a;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		a = '1';
		result = 0;
		cin >> mem;

		for (i = 0; mem[i] != '\0'; i++)	//길이가 주어지지 않으므로 null 문자를 만날때까지만 반복한다.
		{
			if (mem[i] == a)
			{
				result++;		//반전하는 횟수 세기
				a = a == '1' ? '0' : '1';	//반전하기
			}
		}
		cout << "#" << test_case << " " << result << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}