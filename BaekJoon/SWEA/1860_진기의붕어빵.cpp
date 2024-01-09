#include<iostream>
#define MAX 100

using namespace std;

int result;
int N, M, K, t;
int arr[MAX];

void sort()	//손님 도착시간을 오름차순으로 정렬
{
	int temp, i ,j;
	for (i = 0; i < N; i++)
	{
		for (j = i + 1; j < N; j++)
		{
			if (arr[i] > arr[j]) 
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	t = arr[N - 1];		//가장 마지막이 최대값이므로
}

bool greedy()
{
	int index = 0;	//손님 인덱스
	int n = 0, fish = 0;	//현재시간, 붕어빵수
	while (n <= t)	//마지막 손님의 도착시간까지
	{
		if (n != 0 && n % M == 0)	//붕어빵 생산시간이면
		{
			fish += K;	//K개 붕어빵 생산
		}
			
		for (; arr[index] == n; index++)	//다음손님 도착시간까지 손님 서빙하기
		{
			fish--;	//손님이 한개 먹음
			if (fish < 0)	//붕어빵이 없다면
			{
				return false; //실패
			}
		}
		n++;	//시간 증가
	}
	return true; //마지막 손님까지 모두 서빙했다면 성공
}


int main(int argc, char** argv)
{
	int test_case, i;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		result = 0;
		t = 0;
		cin >> N;	//손님수
		cin >> M;	//M초의 시간 뒤 K개의 빵 생성
		cin >> K;

		for (i = 0; i < N; i++)
		{
			cin >> arr[i];
		}
		sort();	//손님도착시간을 오름차순으로 정렬한다

		if (greedy())
			cout << "#" << test_case << " Possible" << endl;
		else
			cout << "#" << test_case << " Impossible" << endl;
		
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}