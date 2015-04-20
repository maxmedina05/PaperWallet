#include "ParticularRepository.h"

ParticularRepository::ParticularRepository()
{

}

ParticularRepository::~ParticularRepository()
{

}

bool ParticularRepository::add(Particular entity)
{
	entity.setId(getSeed());

	_particulars.push_back(entity);
	return true;
}

bool ParticularRepository::update(Particular entity)
{
	for (Particular particular : _particulars){
		if (particular.getId() == entity.getId()){
			particular.setName(entity.getName());
			return true;
		}
	}

	return false;
}

Particular ParticularRepository::getById(int Id)
{
	for (Particular particular : _particulars)
	{
		if (particular.getId() == Id)
			return particular;
	}
}

bool ParticularRepository::remove(Particular entity)
{
	vector<Particular>::iterator it;
	for (it = _particulars.begin(); it != _particulars.end(); ++it){
		if (it->getId() == entity.getId())
		{
			_particulars.erase(it);
			return true;
		}
	}

	return false;
}

vector<Particular> ParticularRepository::getAll()
{
	return _particulars;
}

void ParticularRepository::mockfill()
{
	this->add(Particular("BanReservas", Payee));
	this->add(Particular("PUCMM", Payee));
	this->add(Particular("Supermercado Bravo", Payee));
	this->add(Particular("FARD", Payer));
}
int ParticularRepository::getSeed(){
	string filepath = "API//particular_seed.data";

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

void ParticularRepository::fill(vector<Particular> particulars)
{
	_particulars = particulars;
}
