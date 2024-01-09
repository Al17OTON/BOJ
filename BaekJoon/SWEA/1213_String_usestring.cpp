//string 객체를 활용해서 풀어보기 둘다 별 차이는 없는것 같다.
#include<iostream>

using namespace std;

int result;

int main(int argc, char** argv)
{
	int test_case, i;
	int T = 10, N;
	string key, s;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		result = 0;
		cin >> N;
		cin >> key;	//검색할 문자
		cin >> s;	//문자열
		
		i = s.find(key);
		while (i != string::npos)
		{
			result++;
			s.erase(0, key.length() + i);
			i = s.find(key);
		}

		cout << "#" << test_case << " " << result << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}