#include<iostream>
#define MAX 8

using namespace std;

int code[MAX];
int result[MAX];

void calc()
{
	int i, start = 0, min = code[1];
	bool flag = false, w  = false;
	
	for (i = 1; i < MAX; i++)	//가장 작은 값 찾기
		min = min > code[i] ? code[i] : min;

	if (min % 15 == 0) w = true;

	min /= 15;	//N번째 사이클 구하기

	min *= 15;
	
	if (w) min -= 15;	//만약 15로 나누어 떨어지는 곳이 있다면 8사이클 전인 15를 뺴준다.

	for (i = 0; i < MAX; i++)
	{
		code[i] %= min;
	}
	
	while (1) //위에서 최종 코드의 근사한 값(앞으로 8회 연산이내로 정답이 나옴)을 만들었으므로 최종 값을 이곳에서 계산
	{
		for (i = 1; i < 6; i++)	//1 ~ 5 만큼 감소	1 cycle
		{
			code[(start + i - 1) % MAX] -= i;
			if (code[(start + i - 1) % MAX] <= 0)
			{
				code[(start + i - 1) % MAX] = 0;
				flag = true; 
				break;
			}
		}
		if (flag) break;
		start+=5;
	}

	start = (start + i - 1) % MAX;


	for (i = 1; i <= MAX; i++)	//위에서 나온 결과를 순서에 맞게 정렬
	{
		result[i - 1] = code[(start + i) % MAX];
	}
}

int main(int argc, char** argv)
{
	int test_case, i, j;
	int T = 10, N;

	//cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N;

		for (i = 0; i < MAX; i++)
		{
			cin >> code[i];
		}

		calc();
		cout << "#" << test_case << " " << result[0] << " " << result[1] << " " << result[2] << " " << result[3] << " " << result[4] << " " << result[5] << " " << result[6] << " " << result[7] << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}