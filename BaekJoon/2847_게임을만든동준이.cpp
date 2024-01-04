#include <iostream>

using namespace std;

int N, arr[101];

int greedy() {

    int result = 0;

    for (int i = N - 2; i >= 0; i--) {
        if (arr[i] >= arr[i + 1]) {
            result += arr[i] - (arr[i + 1] - 1);
            arr[i] = arr[i + 1] - 1;
        }
    }
    return result;
}

int main() {

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    cout << greedy() << endl;
}