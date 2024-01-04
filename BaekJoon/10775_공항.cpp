/*
	비행기가 들어오면 게이트 번호와 함께 들어오는데 해당 게이트 번호보다 작거나 같은 번호의 게이트 중 한 곳에 도킹한다고 해서 이용할 수 있는 가장 큰 게이트에
	도킹하는 것이 최적해임을 금방 알 수 있었다.
	하지만 반복문으로 주어진 게이트에서 가장 큰 게이트를 검색하는 것이 너무 느려 시간초과가 나왔다. (72%)
	그래서 고민을 해보니 게이트가 도킹되면 바로 다음 게이트를 가리키도록 할려고 했는데 반복문하고 뭐가 다른지 모르겠어서 지웠다. 알고봤더니 이게 유니온 파인드의 원리였는데 
	내가 생각한 방법에서 조금만 더 생각했으면 되었을것같다.
	유니온 파인드의 방법을 사용하였더니 빠르게 통과할 수 있었다.
*/

#include <iostream>
#define MAX 100000

using namespace std;

int G, P;
int port[MAX + 1] = { 0 };

int find(int x)					//집합에서 루트노드 찾기
{
	if (port[x] == x) return x;
	return port[x] = find(port[x]);	//이게 핵심인데 검색하면서 루트 노드를 가리키도록 변경한다.
}

void makeUnion(int x, int y)	//집합으로 묶어버리기
{
	x = find(x); y = find(y);
	
	if (x == y) return;			//이미 같은 집합이면 탈출, 근데 없어도 되는 기능인것 같다. 이미 같은 집합이라고 해도 아래 연산을 해도 문제가 없다. 오히려 연산이 1줄 늘어난것
	port[x] = y;				
}

int main()
{
	int result = 0, i, a;
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> G >> P;

	for (i = 0; i <= G; i++) port[i] = i;

	for (i = 0; i < P; i++)
	{
		cin >> a;
		a = find(a);

		if (a == 0) break;

		makeUnion(a, a - 1);

		result++;
	}

	cout << result << endl;
}