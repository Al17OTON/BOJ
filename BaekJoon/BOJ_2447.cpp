#include <iostream>
#define MAX 2187
using namespace std;

bool map[MAX][MAX] = {};
int N;
int dirX[] = {-1, 1, 0, 0, -1, -1, 1, 1}; //ªÛ«œ¡¬øÏ øﬁ¿ß ø¿¿ß øﬁæ∆ ø¿æ∆
int dirY[] = {0, 0, -1, 1, -1, 1, -1, 1};

void setStar(int x, int y, int lev, bool isStar) {
	if (lev == 1) {
		map[x][y] = isStar;
		return;
	}
	if (!isStar) {
		return;
	}
	lev /= 3;

	for (int i = 0; i < 8; i++) {  //8πÊ≈Ωªˆ
		setStar(x + dirX[i] * lev, y + dirY[i] * lev, lev, isStar);
	}

	setStar(x, y, lev, false);  //¡ﬂæ”¿∫ ∫Ûƒ≠

}

int main() {
	
	cin >> N;

	setStar(N / 2, N / 2, N, true);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j]) printf("*");
			else printf(" ");
		}
		printf("\n");
	}
}
