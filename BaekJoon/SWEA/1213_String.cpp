#include<iostream>
#include<cstring>
#define MAX 1001

using namespace std;

int result;
char s[MAX];
char key[11];

int main(int argc, char** argv)
{
	int test_case, i, j;
	int T = 10, N;
	char a;
	bool flag;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		result = 0;
		cin >> N;
		cin >> key;	//검색할 문자
		cin >> s;	//문자열
		i = 0;
		j = 0;
		a = s[i];
		while (a != '\0')
		{
			if (a == key[j])
			{
				flag = true;
				j = 1;
				i += 1;
				while (key[j] != '\0')
				{
					if (key[j] != s[i])
					{
						flag = false; break;
					}
					j++; i++;
				}
				if (flag) result++;
				j = 0;
				i -= 1;
			}
			a = s[++i];
		}

		cout << "#" << test_case << " " << result << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}