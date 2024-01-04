/*
	실버 2라 그런지 쉬웠다.
	DFS로 풀 수 있었다. 근데 분할정복은 문제를 나눈다음에 병합하면서 해결하는 방식이라고 한다. 
	그래서 다시 풀어볼려고함.
*/

#include <iostream>
#define MAX 128

using namespace std;

struct DIV {
	int x, y, len;
};

int N, arr[MAX][MAX], B = 0, W = 0;


bool isClear(DIV d) {			//색종이에 서로 다른 색이 섞였는지 체크하는 함수
	int blue = 0, white = 0;

	for (int i = d.x; i < d.x + d.len; i++) {
		for (int j = d.y; j < d.y + d.len; j++) {
			if (arr[i][j] == 1) blue++;
			else white++;

			if (blue > 0 && white > 0) return false;	//하나라도 다르다면 false
		}
	}
	if (blue > 0) B++;			//다른 색이 없다면 갯수 추가
	else W++;

	return true;
}

void divideConquer(DIV d) {
	
	if (isClear(d)) return;

	d.len /= 2;					//색종이 반으로 가르기

	divideConquer({ d.x, d.y, d.len});
	divideConquer({ d.x + d.len, d.y, d.len });
	divideConquer({ d.x, d.y + d.len, d.len });
	divideConquer({ d.x + d.len, d.y + d.len, d.len });
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
	divideConquer({ 0,0,N });

	cout << W << endl << B << endl;
}