#pragma once
#include "IEntity.h"

// Implements interface
class Account : public IEntity
{
private:
	string _name;
	string _description;

public:
	Account();
	Account(string name, string description);

	~Account();

	void setName(string name);
	string getName();
	void setDescription(string description);
	string getDescription();

	string toString();
};

