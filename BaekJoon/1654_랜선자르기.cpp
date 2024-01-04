/*
	unsigned int로 해야 풀림
*/

#include <iostream>
#define MAX 10000

using namespace std;

unsigned int N, K, arr[MAX];

unsigned int binarysearch(unsigned int m) {

	unsigned int result = 0, left = 1 ,right = m, mid, maxresult = 0;

	while (left <= right) {

		mid = (right + left) / 2;
		result = 0;

		for (int i = 0; i < K; i++) {
			result += arr[i] / mid;
		}

		if (result >= N) {
			left = mid + 1;
			if (mid > maxresult) maxresult = mid;
		}
		else {
			right = mid - 1;
		}
	}

	return maxresult;
}

int main()
{
	unsigned int max = 0;
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> K >> N;

	for (int i = 0; i < K; i++)
	{
		cin >> arr[i];
		if (max < arr[i]) max = arr[i];
	}

	cout << binarysearch(max) << endl;
}