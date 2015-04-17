#pragma once
#include "IEntity.h"

class Category : public IEntity
{
private:
	string _name;
public:
	Category();
	~Category();
	Category(string name);

	void setName(string name);
	string getName();

	string toString();
};

