/*
	지난 문제 랜선 자르기에서 배운 이분 탐색으로 풀었다.
	알고리즘은 쉽게 만들 수 있었지만 2%에서 틀렸다고 나왔다. 다른 반례도 찾아서 while문의 조건식이 right > left가 아닌 right >= left인 것을 알아냈지만
	그래도 여전히 틀렸다. 
	계속 찾아본 결과 int를 long이상으로 변경하라는 말이 있었고 문제의 조건을 유심히 보니 cut의 합이 int값의 범위를 넘어가는 문제가 있었다.
	가장 M에 가까우면서 높이를 최대로 높이기 위해 0일때는 초기값을 넣을 수 있도록 변경하였더니 통과하였다.

*/

#include <iostream>
#define MAX 1000000

using namespace std;

int N, M, arr[MAX], maxi = 0;

int binarySolution() {

	int right = maxi, left = 0, mid;		//left가 0이건 1이건 통과함.
	long long cut;
	pair<int, long long> result = { 0, 0 };	//최적의 결과값 저장

	while (right >= left) {
		cut = 0;
		mid = (right + left) / 2;

		for (int i = 0; i < N; i++) {

			cut += arr[i] - mid > 0 ? arr[i] - mid : 0;		//잘랐을때 음수나 0이라면 절단기의 높이가 나무보다 높으므로 자를 수 있는 것은 없다.

		}

		if (cut < M) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
			if ((result.second >= cut || result.second == 0) && result.first < mid) {
				result = { mid, cut };
			}
		}
	}

	return result.first;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {

		cin >> arr[i];

		if (maxi < arr[i]) maxi = arr[i];
	}

	cout << binarySolution() << endl;
}

