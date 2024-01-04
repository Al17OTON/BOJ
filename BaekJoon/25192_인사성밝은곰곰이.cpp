#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <set>
#define MAX 20

using namespace std;

int N;

int main()
{
	int result = 0;
	set<string> log;
	char tmp[MAX + 1];
	string t;
	pair<set<string>::iterator, bool> r;	//set에 삽입 결과를 받을 임시 변수
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%s", &tmp);	//공백이 주어지지 않으므로 이렇게 받아도 괜찮음.... string 으로 입력받으려면 scanf로 하면 안됨. char[] 을 사용해야함
		t = tmp;
		if (t == "ENTER")
		{
			log.clear();	//새로운 사람이 들어오면 기존 로그 초기화
		}
		else
		{
			r = log.insert(t);
			if (r.second)	//중복을 허용하지 않는 set에 삽입이 성공했다는 의미는 현재 로그에서 첫 대화라는 의미
			{
				result++;
			}
		}
	}
	cout << result << endl;
}