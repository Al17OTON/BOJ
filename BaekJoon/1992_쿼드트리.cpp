/*
	이건 쉽다.
*/
#include <iostream>
#define MAX 64

using namespace std;

struct DIV {
	int x, y, len;
};

int N;
char arr[MAX][MAX];

bool isClear(DIV d) {		//선택된 역영이 하나의 색으로 통일되었는지 체크

	char check = arr[d.x][d.y];

	for (int i = d.x; i < d.x + d.len; i++) {
		for (int j = d.y; j < d.y + d.len; j++) {
			if (check != arr[i][j]) return false;
		}
	}
	return true;
}

string divideConquer(DIV d) {
	
	string result = "";
	if (isClear(d)) {
		return result + arr[d.x][d.y];
	}

	result += '(';

	d.len /= 2;

	result += divideConquer({ d.x, d.y, d.len });
	result += divideConquer({ d.x, d.y + d.len, d.len });
	result += divideConquer({ d.x + d.len, d.y, d.len });
	result += divideConquer({ d.x + d.len, d.y + d.len, d.len });

	return result + ')';
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

	cout << divideConquer({0, 0, N}) << endl;
}