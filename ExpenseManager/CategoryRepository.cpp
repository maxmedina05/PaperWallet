#include "CategoryRepository.h"

CategoryRepository::CategoryRepository()
{

}

CategoryRepository::~CategoryRepository()
{
	     
}

bool CategoryRepository::add(Category entity)
{
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