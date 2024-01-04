/*
	자꾸 구현으로 풀어볼려고 하니까 안된다,,, 생각보다 간단한 풀이방법이 있었다.
*/

#include <iostream>

using namespace std;

int N, M;

int main()
{
	cin >> N >> M;

	if (N == 1) cout << 1 << endl;
	else if (N == 2)	//1, 4번 이동을 못함
	{
		if ((M + 1) / 2 > 4) cout << 4 << endl;
		else cout << (M + 1) / 2 << endl;
	}
	else if (M < 7)		//높이는 충분하지만 길이가 충분하지 못해 4 방법을 모두 사용하지 못함
	{
		if (M > 4) cout << 4 << endl;
		else cout << M << endl;
	}
	else
	{
		cout << M - 2 << endl;	//모든 방법을 사용해야하므로 2칸 손해를 본다.
	}
}