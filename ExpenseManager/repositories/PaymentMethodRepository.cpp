#include "PaymentMethodRepository.h"

PaymentMethodRepository::PaymentMethodRepository()
{

}
PaymentMethodRepository::~PaymentMethodRepository()
{

}

bool PaymentMethodRepository::add(PaymentMethod entity)
{
	entity.setId(getSeed());
	_paymentMethods.push_back(entity);

	return true;
}

bool PaymentMethodRepository::update(PaymentMethod entity)
{
	for (PaymentMethod method : _paymentMethods){
		if (method.getId() == entity.getId()){
			method.setName(entity.getName());
			return true;
		}
	}

	return false;
}

PaymentMethod PaymentMethodRepository::getById(int Id)
{
	for (PaymentMethod method : _paymentMethods)
	{
		if (method.getId() == Id)
			return method;
	}
}

bool PaymentMethodRepository::remove(PaymentMethod entity)
{
	vector<PaymentMethod>::iterator it;
	for (it = _paymentMethods.begin(); it != _paymentMethods.end(); ++it){
		if (it->getId() == entity.getId())
		{
			_paymentMethods.erase(it);
			return true;
		}
	}

	return false;
}

vector<PaymentMethod> PaymentMethodRepository::getAll()
{
	return _paymentMethods;
}

void PaymentMethodRepository::mockfill()
{
	this->add(PaymentMethod("Efectivo"));
	this->add(PaymentMethod("Credito"));
	this->add(PaymentMethod("Transferencia"));
}


int PaymentMethodRepository::getSeed(){
	string filepath = "API//method_seed.data";

	ifstream instream(filepath);
	string buffer;
	int seed = 0;
	if (instream.is_open())
	{
		instream >> buffer;
		seed = atoi(buffer.c_str());
	}
	instream.close();

	ofstream outstream(filepath);
	outstream << to_string(seed + 1);
	outstream.close();
	return seed;
}

void PaymentMethodRepository::fill(vector<PaymentMethod> methods)
{
	_paymentMethods = methods;
}
