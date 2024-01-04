#include <iostream>
#include <cstring>
#define MAX 10
using namespace std;

int N;														//입력받은 문자의 갯수 (0 ~ 10)

string arr[MAX];											//입력받은 문자열들

int alpha[28] = { 0 };										//각 알파벳의 가중치 저장공간, 자릿수에 따른 가중치를 부여, 1000의 자리면 1000을 가중치로 부여함. 
															//이렇게 하면 10의 자리 A 하나와 1의 자리 B 11개인 경우에서 B가 9가 되는 경우가 이득임을 알수있음.

int alphaNum[28] = { 0 };									//각 알파벳이 할당 받은 숫자 (9 ~ 0)

												
void sortArr()												//길이가 긴 문장 순으로 정렬, 문제에서 주어진 N의 최대값이 10이므로 N^2 으로도 할 수 있다고 생각함.
{
	string tmp;							
	for (int i = 0; i < N; i++)								//삽입 정렬
	{
		for (int j = i + 1; j < N; j++)
		{
			if (arr[i].length() < arr[j].length())
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}


int string2num(string a)									//문자열을 greedy함수를 통해 구한 숫자를 토대로 숫자로 변환하는 함수
{
	int result = 0, pow = 1, i;
	for (i = 0; i < a.length() - 1; i++)					//자릿수 계산
	{
		pow *= 10;
	}
	for (i = 0; i < a.length(); i++)						//숫자로 변환
	{
		result += alphaNum[a[i] - 'A'] * pow;
		pow /= 10;
	}
	return result;
}


void setNum(int c)											//가중치 값을 사용하여 각 알파벳에 순차적으로 숫자 (9 ~ 0) 할당
{
	int tmpCount, max, i, num = 9;
	while(c > 0)
	{
		max = 27;
		tmpCount = 0;										//현재 검색한 알파벳 수 카운터, 이 값이 alphaCount와 같다면 모든 알파벳을 찾은것이 되므로 스킵
		for (i = 0; i < 27 && tmpCount < c; i++)			
		{
			if (alpha[i] != 0)
			{
				if (alpha[i] > alpha[max])					//가장 가중치가 큰 값 검색
				{
					max = i;
				}
				tmpCount++;
			}
		}
		alpha[max] = 0;
		alphaNum[max] = num--;								//가장 큰 수 (9 ~ 0) 할당
		c--;
	}
}


int greedy()												//각 문자열의 자릿수를 계산하여 해당 자릿수들의 알파벳에 빈도와 자릿수를 통해 가중치 측정	예) AAA 의 가중치는 111이다.
{
	int idx = arr[0].length(), i, len, result = 0, pow = 1, alphaCount = 0;

	for (i = 0; i < arr[0].length() - 1; i++)				//자릿수 계산
	{
		pow *= 10;											//자릿수에 따른 가중치
	}

	while (idx > 0)
	{
		for (i = 0; i < N; i++)
		{
			len = arr[i].length();
			if (len - idx >= 0)								//현재 보고 있는 자릿수 보다 작은 경우 스킵
			{
				if (alpha[arr[i][len - idx] - 'A'] == 0) alphaCount++;	//불필요한 연산을 줄이기 위한 카운터
				alpha[arr[i][len - idx] - 'A'] += pow;		//알파벳 가중치 증가
			}
		}
		pow /= 10;											//자릿수 감소에 따른 가중치 감소
		idx--;												//자릿수 감소
	}

	setNum(alphaCount);

	for (i = 0; i < N; i++)
	{
		result += string2num(arr[i]);
	}
	return result;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sortArr();

	cout << greedy() << '\n';
}