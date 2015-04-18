#pragma once
#include "IView.h"
#include <vector>
#include "Transaction.h"
#include "AccountView.h"
#include "ParticularView.h"
#include "Particular.h"

#define INCOME 1
#define EXPENSE 0

class TransactionView : public IView
{

public:
	TransactionView();
	~TransactionView();

	void OnViewCreated() override;
	void OnViewDestroyed() override;
	void showMenu();
	void listView(vector<Transaction> transactions);

	Transaction editView(Transaction transaction,
		int type,
		vector<Account> accounts,
		vector<Category> categories,
		vector<PaymentMethod> methods,
		vector<Particular> particulars);

	void showSuccessfulMessage();
};