#include "Date.h"

Date::Date()
{
	time_t t = time(0);
	struct tm * now = localtime(&t);

	_year = now->tm_year + 1900;
	_month = now->tm_mon + 1;
	_day = now->tm_mday;
}


Date::~Date()
{
}

string Date::toString(){
	string str;
	
	str = to_string(_day) + "-" + to_string(_month) + "-" + to_string(_year);
	return str;
}

Date::Date(string date)
{
	int pos = 0;
	string delimiter = "-";
	string token;

	// find day
	pos = date.find(delimiter);
	token = date.substr(0, pos);
	date.erase(0, pos + delimiter.length());

	_day = atoi(token.c_str());
	
	// find month
	pos = date.find(delimiter);
	token = date.substr(0, pos);
	date.erase(0, pos + delimiter.length());

	_month = atoi(token.c_str());

	// find year
	pos = date.find(delimiter);
	token = date.substr(0, pos);
	date.erase(0, pos + delimiter.length());

	_year = atoi(token.c_str());
}