#pragma once
#include "IView.h"
#include <vector>

#define INCOME 1
#define EXPENSE 0
#include "../models/Transaction.h"

class TransactionView : public IView
{

public:
	TransactionView();
	~TransactionView();

	void OnViewCreated() override;
	void OnViewDestroyed() override;
	void showMenu();
	static void listView(vector<Transaction> transactions);

	Transaction editView(Transaction transaction,
		int type,
		vector<Account> accounts,
		vector<Category> categories,
		vector<PaymentMethod> methods,
		vector<Particular> particulars);

	void showSuccessfulMessage();
	void showTitle();
};