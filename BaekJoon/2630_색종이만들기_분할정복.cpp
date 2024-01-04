/*
	DFS와 비슷해보이지만 결과를 병합하도록 하는 방식을 사용함. 아마도...
	DFS에 비해 조금 느리다는 점이 단점. pair때문인가?
*/

#include <iostream>
#define MAX 128

using namespace std;

struct DIV {
	int x, y, len;
};

int N, arr[MAX][MAX];

pair<int, int> divideConquer(DIV d) {

	pair<int, int> result = { 0, 0 }, tmp;
	int b = 0, w = 0;

	for (int i = d.x; i < d.x + d.len; i++) {
		for (int j = d.y; j < d.y + d.len; j++) {
			if (arr[i][j] == 1) b++;
			else w++;

			if (b > 0 && w > 0) break;
		}
	}
	if (b == 0 || w == 0) {
		if (b == 0) return { 1, 0 };
		else return { 0, 1 };
	}

	d.len /= 2;					//색종이 반으로 가르기

	tmp = divideConquer({ d.x, d.y, d.len });
	result = { result.first + tmp.first, result.second + tmp.second };
	tmp = divideConquer({ d.x + d.len, d.y, d.len });
	result = { result.first + tmp.first, result.second + tmp.second };
	tmp = divideConquer({ d.x, d.y + d.len, d.len });
	result = { result.first + tmp.first, result.second + tmp.second };
	tmp = divideConquer({ d.x + d.len, d.y + d.len, d.len });
	result = { result.first + tmp.first, result.second + tmp.second };

	return result;
}


int main() {

	pair<int, int> p;

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	p = divideConquer({0,0,N});

	cout << p.first << endl << p.second << endl;
}