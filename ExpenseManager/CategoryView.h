#pragma once
#include "IView.h"
#include <vector>
#include "Category.h"

class CategoryView : public IView
{
public:
	CategoryView();
	~CategoryView();

	void OnCreate() override;
	void OnDestroy() override;
	void showMenu();
	static void listView(vector<Category> categories);

	Category editView(Category category);
	void showSuccessfulMessage();
};