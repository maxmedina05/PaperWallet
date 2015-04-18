#include "Transaction.h"


Transaction::Transaction()
{
	_Id = 0;
}


Transaction::~Transaction()
{
}

//void Transaction::setId(int Id){
//	_Id = Id;
//}
//int Transaction::getId(){
//	return _Id;
//}

void Transaction::setAmount(double amount){
	_amount = amount;
}

double Transaction::getAmount(){
	return _amount;
}

void Transaction::setDate(Date date){
	_date = date;
}
Date Transaction::getDate(){
	return _date;
}

void Transaction::setDescription(string description){
	_description = description;
}
string Transaction::getDescription(){
	return _description;
}

void Transaction::setAccount(Account account){
	_account = account;
}

Account Transaction::getAccount(){
	return _account;
}

void Transaction::setCategory(Category category){
	_category = category;
}
Category Transaction::getCategory(){
	return _category;
}

void Transaction::setParticular(Particular particular){
	_particular = particular;
}

Particular Transaction::getParticular(){
	return _particular;
}

void Transaction::setPaymentMethod(PaymentMethod method){
	_method = method;
}
PaymentMethod Transaction::getPaymentMethod(){
	return _method;
}