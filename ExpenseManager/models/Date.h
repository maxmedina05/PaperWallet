#pragma once
#include <time.h>
#include <string>
#include <iostream>
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
	Date(string date);
	~Date();

	string toString();
};

