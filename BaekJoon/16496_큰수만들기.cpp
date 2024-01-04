#include <iostream>
#include <string>
#include <algorithm>
#define MAX 1000

using namespace std;

bool cmp(string a, string b)	//sort에서 사용할 비교 함수
{
	string ab, ba;
	if (a == b) return false;	//둘이 같다면 내버려 두기

	ab = a + b;	
	ba = b + a;
	if (ab > ba) return true;	//위치를 바꾸는것이 값을 크게 만든다면 바꾸기
	
	return false;
}	

int N;
string arr[MAX];

int main()
{
	string input;
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	cin.ignore();

	for (int n = 0; n < N; n++)
	{
		cin >> arr[n];
	}

	sort(arr, arr + N, cmp);
	
	if (arr[0] == "0") cout << 0 << endl;
	else
	{
		for (int n = 0; n < N; n++)
		{
			cout << arr[n];
		}
		cout << endl;
	}
}