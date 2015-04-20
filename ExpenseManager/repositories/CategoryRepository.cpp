#include "CategoryRepository.h"

CategoryRepository::CategoryRepository()
{

}

CategoryRepository::~CategoryRepository()
{
	     
}

bool CategoryRepository::add(Category entity)
{
	entity.setId(getSeed());

	_categories.push_back(entity);
	return true;
}

bool CategoryRepository::update(Category entity)
{
	for (Category category : _categories){
		if (category.getId() == entity.getId()){
			category.setName(entity.getName());
			return true;
		}
	}
	return false;
}

Category CategoryRepository::getById(int Id)
{
	for (Category category : _categories)
	{
		if (category.getId() == Id)
			return category;
	}
}

bool CategoryRepository::remove(Category entity)
{
	vector<Category>::iterator it;
	for (it = _categories.begin(); it != _categories.end(); ++it){
		if (it->getId() == entity.getId())
		{
			_categories.erase(it);
			return true;
		}
	}

	return false;
}

vector<Category> CategoryRepository::getAll()
{
	return _categories;
}

void CategoryRepository::mockfill()
{
	this->add(Category("Income"));
	this->add(Category("Household"));
	this->add(Category("Loan"));
}

int CategoryRepository::getSeed(){
	string filepath = "API//category_seed.data";

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

Category CategoryRepository::getFirst()
{
	if (_categories.size() > 0)
		return _categories[0];

	return Category();
}


void CategoryRepository::fill(vector<Category> collecion)
{
	_categories = collecion;
}
