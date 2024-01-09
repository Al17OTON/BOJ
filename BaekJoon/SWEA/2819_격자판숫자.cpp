//memset 없으면 83 에서 500으로 시간이 올라감... memset이 일반적인 초기화방식보다는 빠른듯
#include<iostream>
#include<cstring>
#define MAX 4

using namespace std;

int map[MAX][MAX];	//맵
bool h[10000000];	//중복 체크를 위한 배열 최대 9999999
int result;
int dirX[4] = { 0,0,1,-1 }; //동서남북
int dirY[4] = { 1,-1,0,0 };

bool check(int a[8], int n)	//주어진 숫자가 중복된 숫자인지 체크
{
	int result = 0;
	int pow = 1000000;
	for (int i = 0; i < n; i++)
	{
		result += a[i] * pow;
		pow /= 10;
	}
	if (h[result]) return false;	//중복된 수
	
	h[result] = true;
	return true;	//중복되지 않음
}

int dfs(int n, int a[8], int x, int y)
{
	if (n == 7)	//7자리 수가 되었을때 종료
	{
		if (check(a, n)) return 1;	//중복되지 않았다면 1 반환
		return 0;
	}

	int result = 0, xx, yy;

	for (int i = 0; i < 4; i++)	//동서남북
	{
		xx = x + dirX[i]; yy = y + dirY[i];	//이동 예정 좌표
		if (xx >= 0 && xx < MAX && yy >= 0 && yy < MAX)	//좌표가 맵을 벗어나지 않았다면
		{
			a[n] = map[xx][yy];	//배열에 넣고
			result += dfs(n + 1, a, xx, yy);	//다음 번호 찾으러가기
		}
	}
	return result;	//결과 반환
}

int main(int argc, char** argv)
{
	int test_case, i, j;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int arr[8] = { 0 };
		result = 0;

		for (i = 0; i < MAX; i++)	//맵 정보 입력 받기
		{
			for (j = 0; j < MAX; j++)
			{
				cin >> map[i][j];
			}
		}
		
		for (i = 0; i < MAX; i++)	//맵의 모든 위치에서 시작
		{
			for (j = 0; j < MAX; j++)
			{
				result += dfs(0, arr, i, j);
			}
		}

		cout << "#" << test_case << " " << result << endl;
		memset(h, false, sizeof(h));	//초기화
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}