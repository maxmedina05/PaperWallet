#include "ParticularRepository.h"

ParticularRepository::ParticularRepository()
{

}

ParticularRepository::~ParticularRepository()
{

}

bool ParticularRepository::add(Particular entity)
{
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