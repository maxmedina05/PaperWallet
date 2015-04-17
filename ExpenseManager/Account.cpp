#include "Account.h"

Account::Account()
{
	_Id = 0;
}


Account::~Account()
{
}

Account::Account(string name, string description){
	_name = name;
	_description = description;
}

void Account::setName(string name){
	_name = name;
}

string Account::getName(){
	return _name;
}

void Account::setDescription(string description){
	_description = description;
}

string Account::getDescription(){
	return _description;
}

string Account::toString(){
	string str = "";
	str += "Name: " + _name + "\n";
	str += "Description: " + _description + "\n";
	return str;
}

