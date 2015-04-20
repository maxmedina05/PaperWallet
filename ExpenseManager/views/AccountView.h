#pragma once
#include "IView.h"
#include <vector>
#include "../models/Account.h"

class AccountView : public IView
{
public:
	AccountView();
	~AccountView();
	void showTitle() override;
	void OnViewCreated() override;
	void OnViewDestroyed() override;
	void showMenu();
	static void listView(vector<Account> accounts);
	Account editView(Account account);
	void showSuccessfulMessage();
};