#include <iostream>

using namespace std;

int N, v;
int arr[202] = { 0 };

int main() {

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> v;
		arr[v + 100]++;
	}

	cin >> v;

	cout << arr[v + 100] << endl;

	return 0;
}