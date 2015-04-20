#include "PaymentMethod.h"

PaymentMethod::PaymentMethod()
{
}

PaymentMethod::~PaymentMethod()
{
}

PaymentMethod::PaymentMethod(string name){
	_name = name;
	_Id = 0;
}

void PaymentMethod::setName(string name){
	_name = name;
}
string PaymentMethod::getName(){
	return _name;
}