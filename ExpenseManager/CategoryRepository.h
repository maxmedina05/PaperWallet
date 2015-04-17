#pragma once
#include "IRepository.h"
#include "Transaction.h"
#include <vector>

class CategoryRepository : public IRepository<Category>{
private:
	vector<Category> _categories;

public:
	CategoryRepository();
	~CategoryRepository();

	virtual bool add(Category entity) override;
	virtual bool update(Category entity) override;
	virtual Category getById(int Id) override;
	virtual bool remove(Category entity) override;
	virtual vector<Category> getAll() override;

};

