#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#define MAX 1000000

using namespace std;

int arr[MAX];
int B, C, N;

int main()
{
	long long result = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}
	scanf("%d %d", &B, &C);

	for (int i = 0; i < N; i++)
	{
		arr[i] -= B;	//일단 총감독 추가, 예제 보면 총감독은 무조건 있어야함
		result++;	//1명 추가
		if (arr[i] > 0) //총감독으로 커버불가능하다면
		{
			result += arr[i] / C;	//부감독으로 나누어서 필요한 부감독 구하기
			if (arr[i] % C != 0)
			{
				result++;	//나누어 떨어지지 않는다면 1명더 추가
			}
		}
	}
	printf("%lld", result);	//결과가 int의 범위를 넘기때문에 lld로 출력하기
}