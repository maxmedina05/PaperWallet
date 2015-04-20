#pragma once
#include "IView.h"

#define CHANGE_ACCOUNT 1
#define ADD_INCOME 2
#define ADD_EXPENSE 3
#define VIEW_HISTORY 4
#define SETTINGS 5

class HomeView : public IView
{
public: 
	HomeView();
	~HomeView();

	void showTitle() override;
	void OnViewCreated() override;
	void OnViewDestroyed() override;
	void showMenu();
	void showResume(double balance, double incomes, double expenses);
};

