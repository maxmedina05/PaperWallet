#pragma once
#include "IView.h"
#include "IPresenter.h"
#include "CategoryRepository.h"
#include "CategoryView.h"

class CategoryPresenter : public IPresenter{
private:
	CategoryView *_aview;
	CategoryRepository _repo;
	Category _currentCategory;

public:
	CategoryPresenter(IView* view);
	void Initialize();
	void LoadList();
	void Callback();
	void OptionMenuLoop();
};