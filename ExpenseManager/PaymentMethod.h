#pragma once
#include "IEntity.h"

class PaymentMethod : public IEntity
{
private:
	string _name;
public:
	PaymentMethod();
	~PaymentMethod();
	PaymentMethod(string name);
	void setName(string name);
	string getName();

	string toString();
};

