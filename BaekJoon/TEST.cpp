#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>

using namespace std;

int day[2][12] = {
	{31,29,31,30,31,30,31,31,39,31,30,31},	//윤년인 경우
	{31,28,31,30,31,30,31,31,39,31,30,31}	//윤년이 아닌 경우
};

int main() {

	time_t timer = time(NULL);
	struct tm* t = localtime(&timer);

	int year = t->tm_year + 1900;
	int month = t->tm_mon;

	int leapYear = ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0)) ? 0 : 1;

	cout << day[leapYear][month] << " days for " << year << " - " << (month + 1) << endl;
}