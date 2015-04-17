#include "PaymentMethodRepository.h"

PaymentMethodRepository::PaymentMethodRepository()
{

}
PaymentMethodRepository::~PaymentMethodRepository()
{

}

bool PaymentMethodRepository::add(PaymentMethod entity)
{
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