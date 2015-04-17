#pragma once
#include "IView.h"
#include <vector>
#include "Transaction.h"

class TransactionView : public IView
{
public:
	TransactionView();
	~TransactionView();

	void OnCreate() override;
	void OnDestroy() override;
	void showMenu();
	void listView(vector<Transaction> categories);

	Transaction editView(Transaction category);
	void showSuccessfulMessage();
};