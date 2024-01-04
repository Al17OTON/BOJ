#include <iostream>

using namespace std;

int N;

int greedy() {
	int c = 0;
	
	while (N % 5 != 0) {
		N -= 2;
		c++;

		if (N == 0) return c;
		else if (N < 0) return -1;
	}

	c += N / 5;

	return c;
}

int main() {

	cin >> N;

	cout << greedy() << endl;
}