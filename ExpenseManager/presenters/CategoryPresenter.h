#pragma once
#include "IPresenter.h"
#include "../models/Category.h"
#include "../views/CategoryView.h"
#include "../repositories/CategoryRepository.h"


class CategoryPresenter : public IPresenter<CategoryView>{
private:
	CategoryRepository* _repo;
	Category _currentCategory;

public:
	CategoryPresenter(CategoryView* view);
	void Initialize();
	void LoadList();
	void Callback();
	void OptionMenuLoop();
	void setRepository(CategoryRepository* repo);
};