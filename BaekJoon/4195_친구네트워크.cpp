/*
	가중치 유니온 파인드를 사용하면 풀수있다. 유니온 배열의 크기는 모든 친구 네트워크가 다른 최악의 경우인 100000 * 2 까지로 하도록 하였다.

	유니온을 합칠때, 서로의 집합의 크기를 합치도록 하였다. 단 이때 서로 같은 집합일때 합치는 연산을 하면 안된다. 처음에는 이것땜에 틀렸다.
	딕셔너리(map)를 사용하여 유저 이름을 관리하였다.
	시간은 220ms정도 나왔는데 다른사람들은 40ms까지도 푸는것 보면 더 빠른 방법이 있는것 같다.
	해쉬 맵을 사용해서 검색 속도를 매우 빠르게 만드는 것 같다. 
*/

#include <iostream>
#include <map>
#define MAX 100000

using namespace std;

int T, F;
map<string, int> dic;
pair<int, int> uni[MAX * 2 + 1];

int find(int x)
{
	if (uni[x].first == x) return x;
	return uni[x].first = find(uni[x].first);
}

int setuniwithcount(int x, int y)
{
	x = find(x); y = find(y);

	if (x == y) return uni[y].second;	//같은 집합일경우 합치지 말것

	uni[x].first = y;
	uni[y].second += uni[x].second;
	return uni[y].second;
}

int main()
{
	int x, y, n;
	string a, b;
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;

	for (int t = 0; t < T; t++)
	{
		cin >> F;
		for (int i = 0; i <= F * 2; i++)
		{
			uni[i].first = i;
			uni[i].second = 1;
		}
		dic.clear();
		n = 1;

		for (int i = 0; i < F; i++)
		{
			cin >> a >> b;

			if (dic.find(a) == dic.end())
			{
				dic.insert({ a, n++ });
			}
			if (dic.find(b) == dic.end())
			{
				dic.insert({ b, n++ });
			}

			x = dic.find(a)->second; y = dic.find(b)->second;

			cout << setuniwithcount(x, y) << '\n';
		}
	}
}