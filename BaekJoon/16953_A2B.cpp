/*
	이전에 다른 비슷한 문제를 본 기억이나서 쉽게 해결법이 떠올랐다.
	B에서 A를 만드는 방법을 생각하는것이 해결법이다.
	마지막 글자가 1인 경우 1을 제거하고 그렇지 않다면 2로 나눈다. 이때 두 조건을 모두 만족하지 못하면 A를 만들지 못한다고 판단한다.
	너비 우선 탐색으로도 풀 수 있는것 같다.
*/
#include <iostream>
#include <string>

using namespace std;

int A, B;

int greedy()									//B에서 A를 만들어 보면 된다.
{
	int num = 0;
	string tmp;
	while (B != A)
	{
		tmp = to_string(B);
		if (tmp[tmp.length() - 1] == '1' && stoi(tmp.substr(0, tmp.length() - 1)) >= A) //마지막 글자가 1 이고 1을 제거하였을때 A보다 크거나 같아야한다.
		{
			B = stoi(tmp.substr(0, tmp.length() - 1));
		}
		else if (B / 2 >= A && B % 2 == 0)		//마지막 글자가 1이 아닐경우 나누기 2를 한다. 이때 2로 나누어 떨어져야한다.
		{
			B /= 2;
		}
		else return -1;							//위 조건을 모두 만족하지 못한다면 B에서 A를 만들지 못한다는 의미이므로 -1

		num++;									//횟수 증가
	}
	return num + 1;								//최소 횟수 + 1을 한다.
}

int main()
{
	cin >> A >> B;

	cout << greedy() << endl;
}