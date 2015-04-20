#include "Category.h"

Category::Category()
{
}

Category::Category(string name){
	_name = name;
	_Id = 0;
}

Category::~Category()
{
}

void Category::setName(string name){
	_name = name;
}
string Category::getName(){
	return _name;
}

string Category::toString(){
	string str = "";
	str += "Name: " + _name + "\n";
	return str;
}