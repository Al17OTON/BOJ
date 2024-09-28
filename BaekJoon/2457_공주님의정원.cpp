#define _CRT_SECURE_NO_WARNINGS
#define MAX 100001
#define YEAR 365
#include <iostream>
#include <algorithm>

/*
DP(Memoization) and Greedy?
개화시점 and 꽃이 피어있는 기간(지는 날)을 기준으로 정렬한 후 
첫 꽃을 선택하고 테이블에 꽃이 핀기간 동안 1로 채우고
그 다음 꽃을 선택할때 이전 꽃 기간에 포함되지 않는 꽃을 찾은다음 (정렬되어있으므로 그냥 순회)
그 이후의 테이블을 이전 꽃 개화시점테이블의 값 + 1로 지는 기간까지 채우기
를 반복해서 마지막 날 11월 30일의 값을 출력

* 1초 
오늘은 공주님이 태어난 경사스러운 날이다. 왕은 이 날을 기념하기 위해 늘 꽃이 피어있는 작은 정원을 만들기로 결정했다.

총 N개의 꽃이 있는 데, 꽃은 모두 같은 해에 피어서 같은 해에 진다. 하나의 꽃은 피는 날과 지는 날이 정해져 있다. 예를 들어, 5월 8일 피어서 6월 13일 지는 꽃은 5월 8일부터 6월 12일까지는 꽃이 피어 있고, 6월 13일을 포함하여 이후로는 꽃을 볼 수 없다는 의미이다. (올해는 4, 6, 9, 11월은 30일까지 있고, 1, 3, 5, 7, 8, 10, 12월은 31일까지 있으며, 2월은 28일까지만 있다.)

이러한 N개의 꽃들 중에서 다음의 두 조건을 만족하는 꽃들을 선택하고 싶다.

공주가 가장 좋아하는 계절인 3월 1일부터 11월 30일까지 매일 꽃이 한 가지 이상 피어 있도록 한다.
정원이 넓지 않으므로 정원에 심는 꽃들의 수를 가능한 적게 한다.
N개의 꽃들 중에서 위의 두 조건을 만족하는, 즉 3월 1일부터 11월 30일까지 매일 꽃이 한 가지 이상 피어 있도록 꽃들을 선택할 때, 선택한 꽃들의 최소 개수를 출력하는 프로그램을 작성하시오.

입력
첫째 줄에는 꽃들의 총 개수 N (1 ≤ N ≤ 100,000)이 주어진다. 다음 N개의 줄에는 각 꽃이 피는 날짜와 지는 날짜가 주어진다. 하나의 날짜는 월과 일을 나타내는 두 숫자로 표현된다. 예를 들어서, 3 8 7 31은 꽃이 3월 8일에 피어서 7월 31일에 진다는 것을 나타낸다.

출력
첫째 줄에 선택한 꽃들의 최소 개수를 출력한다. 만약 두 조건을 만족하는 꽃들을 선택할 수 없다면 0을 출력한다.


4
1 1 5 31
1 1 6 30
5 15 8 31
6 10 12 10

> 2

10
2 15 3 23
4 12 6 5
5 2 5 31
9 14 12 24
6 15 9 3
6 3 6 15
2 28 4 25
6 15 9 27
10 5 12 31
7 14 9 1

> 5
*/

int dateArr[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; //1 ~ 12 월

struct Flower {
	int startMonth, startDay;
	int endMonth, endDay;
};

//월과 일을 365일 중 인덱스로 변환
int date2Index(int month, int day) {
	int idx = day - 1;
	for (int i = 1; i < month; i++) {
		idx += dateArr[i - 1];
	}
	return idx;
}

//정렬을 위한 함수
//가장 빨리 피면서 가장 늦게 지는 꽃 순서로 정렬한다.
bool compare(const Flower& a, const Flower& b) {
	if (a.startMonth == b.startMonth && a.startDay == b.startDay) {	//시작일이 같은경우
		if (a.endMonth == b.endMonth) return a.endDay > b.endDay;	//꽃이 지는 날 기준으로 정렬
		return a.endMonth > b.endMonth;
	}
	if (a.startMonth == b.startMonth) return a.startDay < b.startDay;
	return a.startMonth < b.startMonth;
}

int N, counter = YEAR - (dateArr[0] + dateArr[1] + dateArr[11]); // 365일 중 1, 2, 12월 제외
Flower flowers[MAX];
int timeTable[YEAR] = { 0 };	//메모이제이션을 위한 DP 테이블, 1 년 = 365 문제에서 윤년을 고려하지 않는다.

int dp();

int main() {
	scanf("%d", &N);

	//입력을 받는다. 이때 3월부터 11월까지만 피는 꽃들만 계산하면 되므로 연산의 편의를 위해 1, 2, 12월의 날짜는 3월과 11월로 변환한다.
	for (int n = 0; n < N; n++) {
		scanf("%d %d %d %d", &flowers[n].startMonth, &flowers[n].startDay, &flowers[n].endMonth, &flowers[n].endDay);
		if (flowers[n].startMonth <= 2) {
			flowers[n].startMonth = 3;
			flowers[n].startDay = 1;
		}
		if (flowers[n].endMonth == 12) {
			flowers[n].endMonth = 12;
			flowers[n].endDay = 1;
		}
	}

	std::sort(flowers, flowers + N, compare);	//가장 빨리 개화하면서 가장 늦게 지는 꽃 순서로 정렬 (그리디?)


	//정렬 결과 출력
	/*printf("\nSORTED\n");
	for (int i = 0; i < N; i++) {
		printf("%d %d %d %d\n", flowers[i].startMonth, flowers[i].startDay, flowers[i].endMonth, flowers[i].endDay);
	}*/

	
	printf("%d\n", dp());
	return 0;
}

int dp() {
	//현재 메모이제이션의 가장 최근 기록(메모이제이션 테이블에서 가장 마지막에 방문한 인덱스)
	int curIdx = date2Index(3, 1);

	//정렬했는데도 3월 1일이 첫 개화시기에 포함되지 않는다면 불가능한 경우로 판단
	if (flowers[0].startMonth != 3 && flowers[0].startDay != 1) {
		return 0;
	}

	// 메모이제이션을 활용하여 해결
	for (int n = 0; n < N; n++) {

		//꽃이 피고 지는 시점을 365일 중 인덱스로 변환
		int startIdx = date2Index(flowers[n].startMonth, flowers[n].startDay);
		int endIdx = date2Index(flowers[n].endMonth, flowers[n].endDay);

		if (startIdx > curIdx) return 0;	//중간에 꽃이 안피는 시기가 존재하면 0
		if (endIdx <= curIdx) continue;		//꽃을 최소한으로 해야하니 이미 꽃이 피어있다면 제외
		
		//개화시점에서 꽃이 피어있는 숫자에 1을 더하여 메모하기
		for (; curIdx < endIdx; curIdx++) {
			timeTable[curIdx] = timeTable[startIdx - 1] + 1;
			counter--;	//최적화를 위한 카운터
		}

		//카운터가 0이 된다면 이미 꽃이 3월부터 11월까지 모두 핀다는 의미이므로 더이상의 연산은 무의미하다.
		if (counter <= 0) break;
	}

	//메모이제이션에서 11월 30일의 기록이 해다.
	return timeTable[date2Index(11, 30)];
}