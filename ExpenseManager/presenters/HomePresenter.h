#pragma once
#include "IPresenter.h"
#include "../views/HomeView.h"
#include "../repositories/RepositoryFactory.h"

class HomePresenter : public IPresenter<HomeView>{
private:
	RepositoryFactory *_factory;

	Account _currentAccount;
	double _balance;
	double _incomes;
	double _expenses;

public:
	HomePresenter(HomeView* view);
	~HomePresenter();
	void UpdateDisplayValues();
	void Initialize();
	void addIncomes();
	void addExpense();
	void viewHistory();
	void startSettingsActivity();
	void OptionMenuLoop();
	void setFactory(RepositoryFactory *factory);
	double ComputeBalance();
	double ComputeIncome();
	double ComputeExpense();

	void changeAccount();
};

