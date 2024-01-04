/*
	도저히 어떻게 풀어야하는지 몰랐는데, 힌트를 찾아보니까 S 에서 T를 만들지 말고, T 에서 S를 만들으라는 힌트덕분에 풀었다.
	T의 뒤부터 글자를 보면서 T가 만들어지는 과정을 역순으로 해체하면서 하였더니 풀렸다.
*/

#include <iostream>
#include <algorithm>

using namespace std;

string S, T;

int greedy()
{
	while (S.length() < T.length())
	{
		if (T.back() == 'A')
		{
			T.erase(T.length() - 1, 1);
		}
		else
		{
			T.erase(T.length() - 1, 1);
			reverse(T.begin(), T.end());
		}
	}
	if (T == S) return 1;
	return 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> S >> T;

	cout << greedy() << endl;
}