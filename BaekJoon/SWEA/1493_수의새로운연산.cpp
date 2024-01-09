//시간복잡도로 봤을때 p q 두개는 그냥 탐색해도 N 이라서 그냥 검색하고 결과는 좌표를 아니까 단시간에 계산할수있다고 생각해서 이렇게 풀음.
//근데 그냥 탐색하는 simple()로도 풀림. 둘이 시간차이는 약 50ms 정도
// 
//8ms 로 푼 사람걸 보니까 수식으로 푸는거 봐서는 계산식이 있나봄.
// 
//주어진 숫자 p q의 좌표를 찾는 방법은 i = 1 부터 1씩 증가하면서 i*(i + 1) / 2 < num 를 만족하지 않는 i를 구하기. i * (i + 1) / 2 = 해당 대각선 줄의 최대값을 계산하는 식 여기서 num은 p q를 나타냄
//그 다음 위에서 구한 i 를 다음 식으로 풀기 (i + 1) * (i + 2) / 2 - num + 1 가 y값이 되고		//에라 모르겠다
//x = i - y - 2로 구한다.	//왜냐면 위에서 구한 i는 해당 대각선의 첫 숫자의 x값이므로
#include<iostream>

using namespace std;

int result;
int p, q;

int simple()
{
	int px = 0, py = 0, qx = 0, qy = 0;
	int num = 1, n = 1, add = 1;	//현재까지 숫자, 이번 사이클에서 몇번까지 세야하는지, n의 값을 얼마 증가시켜야하나
	while (1)
	{
		for (int i = add, j = 1; num <= n; i--, j++, num++)	//대각선으로 좌에서 우로 내려가면서 p q 검색
		{
			if (num == p)	//p || q 만나면 좌표 기록
			{
				px = i; py = j;
			}
			if (num == q)
			{
				qx = i; qy = j;
			}
			if (px > 0 && qx > 0)
			{
				if (px + qx == i && py + qy == j)
				{
					return num;
				}
			}
		}

		add++;	//시작 x 좌표
		n += add;	//해당 대각선에 마지막 수 변경
	}
}

int calc() 
{
	int px = 0, py = 0, qx = 0, qy = 0;
	int num = 1, n = 1, add = 1;	//현재까지 숫자, 이번 사이클에서 몇번까지 세야하는지, n의 값을 얼마 증가시켜야하나
	while (1)
	{
		for (int i = add, j = 1; num <= n; i--, j++, num++)	//대각선으로 좌에서 우로 내려가면서 p q 검색
		{
			if (num == p)	//p || q 만나면 좌표 기록
			{
				px = i; py = j;
			}
			if (num == q)
			{
				qx = i; qy = j;
			}
			if (px > 0 && qx > 0) break;	//p q 둘다 찾았다면 탈출
		}

		if (px > 0 && qx > 0) break;
		add++;	//시작 x 좌표
		n += add;	//해당 대각선에 마지막 수 변경
	}

	px += qx; py += qy;	//좌표 더하기

	int a = 1;
	for (int i = 1; i < px; i++)	//px 만큼 위로 올라가기
	{
		a += i;					//1에서부터 1 2 3 4 ...씩 증가한다.
	}
	
	for (int j = 1; j < py; j++)
	{
		a += (px + j);	//px만큼 올라갔다면 px + n 씩 증가한다.
	}
	return a;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		result = 0;
		cin >> p;
		cin >> q;

		result = calc();

		cout << "#" << test_case << " " << result << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}