#pragma once
#include "IView.h"
#include "IPresenter.h"
#include "TransactionRepository.h"
#include "TransactionView.h"

class TransactionPresenter : public IPresenter{
private:
	TransactionView *_aview;
	TransactionRepository *_repo;
	Transaction _currentTransaction;

	vector<Account> _accounts;
	vector<Particular> _particulars;
	vector<PaymentMethod> _methods;
	vector<Category> _categories;

public:
	TransactionPresenter(IView* view);
	void Initialize();
	void LoadList();
	void Callback();
	void OptionMenuLoop();

	void set_accounts(const vector<Account>& accounts);
	void set_particulars(const vector<Particular>& particulars);
	void set_payment_methods(const vector<PaymentMethod>& payment_methods);
	void set_categories(const vector<Category>& categories);

	void setTransactionRepo(TransactionRepository * repo);
	void OnStart();
};