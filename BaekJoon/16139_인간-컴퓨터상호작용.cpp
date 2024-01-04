#include<iostream>
#include<string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	int N, start, end, i = 0, j = 0;	//질문수, 시작범위, 마지막범위
	int prefix[27][200001];
	char a;				//찾을 글자

	cin >> s >> N;

	prefix[s[0] - 'a'][0] = 1;

	for (i = 1; i < s.size(); i++)
	{
		for (j = 0; j < 27; j++)
		{
			prefix[j][i] = prefix[j][i - 1];
		}
		prefix[s[i] - 'a'][i]++;
	}

	for (i = 0; i < N; i++)
	{
		cin >> a >> start >> end;	//맨 앞에 띄어쓰기를 해야 공백이나 \n을 무시함
		if (start == 0)
		{
			cout << prefix[a - 'a'][end] << endl;
		}
		else
		{
			cout << prefix[a - 'a'][end] - prefix[a - 'a'][start - 1] << endl;
		}
	}
	return 0;
}