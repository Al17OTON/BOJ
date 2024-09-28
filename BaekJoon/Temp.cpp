#include <iostream>

using namespace std;

class Test {
public:
	int data[2];
	int* p;
};

void call(Test a) {
	int tmp = -99;
	*(a.data) = 11;
	*(a.p) = tmp;
	cout << a.data << ", " << *(a.p) << endl;
}

void callarr(int arr[]) {
	arr[0] = -20;
	cout << arr[0] << endl;
}

int main() {
	/*int arr[2][3] = { 1,2,3,4,5,6 };
	int(*p)[3] = NULL;
	
	p = arr;
	printf("%d, ", *(p[0] + 1) + *(p[1] + 2));
	printf("%d", *(*(p + 1) + 0) + *(*(p + 1) + 1));
	cout << endl;

	cout << p[0][0] << " " << p[1][0] << endl;*/
	int tmp = 99;
	Test a;
	a.data[0] = 10;
	a.p = &tmp;

	cout << a.data << ", " << *(a.p) << endl;

	call(a);
	cout << a.data << ", " << *(a.p) << endl;


	cout << endl;

	int arr[2] = { 1,2 };

	cout << arr[0] << endl;
	callarr(arr);
	cout << arr[0] << endl;
}