#include <iostream>

using namespace std;

struct DIV {
	int x, y, len;
};

int N, M, K, A[100][100], B[100][100], result[100][100];

void divideConquer(DIV d) {

	if (d.len == 1) {
		
	}

}

int main() {
	
	int i, j;

	cin >> N >> M;

	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			cin >> A[i][j];
		}
	}

	cin >> M >> K;

	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			cin >> B[i][j];
		}
	}


}