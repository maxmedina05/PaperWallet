#pragma once
#include "IEntity.h"

class Category : public IEntity
{
private:
	string _name;
public:
	Category();
	~Category();
	Category(int Id, string name);
	Category(string name);

	void setName(string name);
	string getName();

	string toString();
};

