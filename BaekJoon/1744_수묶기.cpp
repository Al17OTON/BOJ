//처음에는 우선순위 큐로 풀려고 했는데 음수일 때에는 가장 작은 값끼리 곱하는것이 크다는 점을 놓쳤다.
//다시 고민해본 결과 음수부분과 양수부분을 나눠서 계산하면 풀 수 있다고 생각해서 다시 풀어서 통과하였다.
#include <iostream>
#include <algorithm>
#define MAX 51

using namespace std;

int N, neg[MAX], pos[MAX];
int pIdx = 0, nIdx = 0;

//각 배열을 오름차순으로 정렬하여 음수와 양수 부분을 그리디를 통해 최대값을 구한다.
int greedy()
{
	int i, result = 0, a, b;
	bool flag = false;
	for (i = 0; i < nIdx; i++)	//음수 부분은 가장 작은 값 부터 계산한다. 가장 작은 음수끼리 곱하였을 때 최대값이 나오기 때문.
	{
		a = neg[i];
		if (!flag)				//flag는 곱하기 위한 두개의 수가 준비 되었는지 표시하는 역할이다.
		{
			flag = true;
			b = a;				//flag가 true인 경우 b에 값이 있어 곱하기를 할 수 있다는 의미.
		}
		else
		{
			if (a * b > a + b)
			{
				result += a * b;
				flag = false;
			}
			else				
			{
				result += b;
				b = a;
			}
		}
	}
	if (flag) result += b;		//flag가 true인 경우 b 값이 반영이 되지 않았다는 의미이므로 b 값을 반영한다.

	flag = false;
	for (i = pIdx - 1; i >= 0; i--)		//양수 부분은 가장 큰 값부터 해야 최대값이 나온다. 아래 연산은 음수부분과 같다.
	{
		a = pos[i];
		if (!flag)
		{
			flag = true;
			b = a;
		}
		else
		{
			if (a * b > a + b)
			{
				result += a * b;
				flag = false;
			}
			else
			{
				result += b;
				b = a;
			}
		}
	}
	if (flag) result += b;
	return result;
}

int main()
{
	int i, a;
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (i = 0; i < N; i++)
	{
		cin >> a;
		if (a > 0)			//음수(0포함) 양수 구분하기
		{
			pos[pIdx++] = a;
		}
		else
		{
			neg[nIdx++] = a;
		}
	}
	sort(pos, pos + pIdx);	//오름차순으로 정렬
	sort(neg, neg + nIdx);

	cout << greedy() << '\n';
}