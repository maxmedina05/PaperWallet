#pragma once
#include "IPresenter.h"
#include "RepositoryFactory.h"
#include "HomeView.h"
#include "AccountView.h"
#include "TransactionView.h"

class HomePresenter : public IPresenter{
private:
	HomeView* _aview;
	RepositoryFactory *_factory;

	Account _currentAccount;
	double _balance;
	double _incomes;
	double _expenses;

public:
	HomePresenter(IView* view);
	~HomePresenter();
	void UpdateDisplayValues();
	void Initialize();
	void Callback() override;
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

