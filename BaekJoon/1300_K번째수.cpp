/*
	어렵다... 이건진짜
	못풀겠다... 나중에 다시 풀어봐야할듯
*/

#include <iostream>

using namespace std;

long long N, K;

long long countNum(long long mid) {

	long long counter = 0;
	for (long long i = 1; i <= N; i++) {
		counter += min(N, mid / i);
		if (i > mid) break;
	}
	return counter;
}

long long binarySolution() {
	long long left = 1, right = N * N, mid, result = 0;

	while (left <= right) {
		mid = (left + right) / 2;

		if (countNum(mid) < K) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
			result = mid;
		}
			
	}
	return result;
}

int main() {
	cin >> N >> K;

	cout << binarySolution() << endl;
}