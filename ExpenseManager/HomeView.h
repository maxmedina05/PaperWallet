#pragma once
#include "IView.h"

class HomeView : public IView
{
public: 
	HomeView();
	~HomeView();

	void showTitle() override;
	void OnViewCreated() override;
	void OnViewDestroyed() override;
	void showMenu();
	void showResume(float balance, float incomes, float expenses);
};

