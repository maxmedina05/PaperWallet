#pragma once
#include <time.h>
#include <string>

using namespace std;

class Date
{
private:
	int _day;
	int _month;
	int _year;

public:
	Date();
	Date(int day, int month, int year);
	~Date();

	string toString();
};

