/*
맨처음 문제를 봤을때 스택문제라고 해서 순진하게 스택에다가 넣고 그랬다. 코드가 너무 스파게티가되어버려서 다른사람꺼를봤는데
아래 처럼 마지막 글자가 폭탄 문자의 마지막 글자와 일치하는지를 검사하여 굳이 스택으로 여러번 검사하지 않아도 
한번에 순회만으로도 모든 폭탄을 찾아내는 방법을 사용하였다.
*/
#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s, bomb, tmp = "";

	bool flag = true;

	cin >> s >> bomb;

	for (int i = 0; i < s.length(); i++)								//문자열을 앞에서 부터 하나씩 임시 변수에 넣는다.
	{
		tmp += s[i];
		if (tmp.length() >= bomb.length())								//임시변수가 폭탄문자보다 길어지면 폭탄 검사를 실시한다.
		{
			flag = true;
			for (int j = 0; j < bomb.length(); j++)						//폭탄문자 길이만큼 뒤에서 부터 검사하여 폭탄문자가 있다면 제거한다.
			{
				if (tmp[tmp.length() - bomb.length() + j] != bomb[j])
				{
					flag = false;
					break;
				}
			}
			if (flag)
			{
				tmp.erase(tmp.length() - bomb.length(), bomb.length());	//폭탄 제거
			}
		}
	}
	if (tmp.empty())
	{
		cout << "FRULA" << '\n';
	}
	else
	{
		cout << tmp << '\n';
	}
}