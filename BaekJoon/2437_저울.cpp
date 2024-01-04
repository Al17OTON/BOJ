/*
	https://aerocode.net/392
	처음에는 어떻게 풀어야할지 몰랐다.
	그래서 우선순위큐에 중복되지 않도록 더한값들을 다 넣어서 나중에 하나씩 빼다가 순서가 어긋나는 부분을 찾아내는 방법을 썻는데,
	사실상 완전탐색이랑 같았다. 그래서 그리디한 방법이 아니라고 생각했다.
	분명 예제와 같이 벗어나는 값을 찾아내는 것이 핵심인거 같았는데 머리로 잘 그려지지 않았다.
	그래서 해설을 봤는데, 잘 설명되어 있었고 참고해서 쉽게 코드를 작성할 수 있었다.
	손으로 어느정도 푸는 연습을 해야할 것 같다.
*/
#include <iostream>
#include <algorithm>
#define MAX 1000

using namespace std;

int N, arr[MAX];

int greedy()
{
	pair<int, int> range = { 0,0 }, temp;

	for (int i = 0; i < N; i++)
	{
		temp = { range.first + arr[i], range.second + arr[i] };
		if (temp.first <= range.second + 1)
		{
			range = { 0, temp.second };
		}
		else
		{
			break;
		}
	}
	return range.second + 1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int n = 0; n < N; n++)
	{
		cin >> arr[n];
	}

	sort(arr, arr + N);	//오름차순으로 정렬

	cout << greedy() << endl;
}