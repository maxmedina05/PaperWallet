#pragma once
#include "IEntity.h"

enum ParticularType{
	Payer,
	Payee
};

class Particular : public IEntity
{
private:
	string _name;
	ParticularType _particularType;
	string TypeName(ParticularType type);

public:
	Particular();
	~Particular();

	Particular(ParticularType type) : _particularType(type){}
	Particular(string name, ParticularType type);
	void setName(string name);
	string getName();
	void setType(ParticularType type);
	ParticularType getType();

	string toString();
};

