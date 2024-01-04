#include <iostream>

using namespace std;

struct TURRET
{
	int x, y, r;
};

TURRET jo, bae;

int greedy()	//두 원(터렛의 위치에서 적과의 거리를 반지름으로 가지는 원)의 접점의 갯수를 구하기, 두 원이 완전히 일치하면 -1
{
	int x = jo.x - bae.x, y = jo.y - bae.y, r, rr;
	x *= x; y *= y;
	int distance = x + y;	//sqr연산을 생략하여 정확한 거리를 구한다.
	r = jo.r + bae.r; rr = jo.r - bae.r;
	r *= r; rr *= rr;
	
	if (distance == 0)
	{
		if (rr == 0) return -1;
		return 0;
	}
	else if (distance == r || distance == rr) return 1;
	else if (rr < distance && r > distance) return 2;
	return 0;
}

int main()
{
	int T;
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;

	for (int t = 0; t < T; t++)
	{
		cin >> jo.x >> jo.y >> jo.r >> bae.x >> bae.y >> bae.r;

		cout << greedy() << '\n';
	}
}