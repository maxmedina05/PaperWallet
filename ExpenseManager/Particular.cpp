#include "Particular.h"


Particular::Particular(){
}

Particular::~Particular(){
}

Particular::Particular(string name, ParticularType type){
	_name = name;
	_particularType = type;
}

void Particular::setName(string name){
	_name = name;
}

string Particular::getName(){
	return _name;
}

void Particular::setType(ParticularType type){
	_particularType = type;
}

ParticularType Particular::getType(){
	return _particularType;
}

string Particular::toString(){
	string str = "";
	str += "Name: " + _name + "\n";
	str += "Type: " + TypeName(_particularType) + "\n";
	return str;
}

string Particular::TypeName(ParticularType type){
	if (type == Payee)
		return "Payee";
	else if (type == Payer)
		return "Payer";

}