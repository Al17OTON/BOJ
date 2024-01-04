/*
	어렵다. 수학을 잘해야 풀 수 있을듯
	페르마의 소정리를 이용해서 이항계수를 나머지 연산이 용이하도록 변경하고
	분할정복을 사용한 power 함수 p^m = p^(m/2) * p^(m/2)을 사용하여 
	문제를 해결한다.
	
	*/

#include <iostream>

using namespace std;

int N, K;
long long p = 1000000007;

long long power(long long a, long long b) {
	
	long long tmp;

	if (b == 0) return 1;

	tmp = power(a, b / 2) % p;
	if (b % 2 == 1) return tmp * tmp % p * a % p;	//나머지로 하나 남을경우 (홀수인경우. A곱하기)
	return tmp * tmp % p;
}

int divideConquer() {

	int i;
	long long A = 1, B = 1;

	for (i = N; i >= N - K + 1; i--) A = (A * i) % p;
	for (i = K; i > 0; i--) B = (B * i) % p;
	
	return A * power(B, p - 2) % p;
}

int main() {

	cin >> N >> K;

	cout << divideConquer() << endl;
}