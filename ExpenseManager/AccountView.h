#pragma once
#include "IView.h"
#include <vector>
#include "Account.h"

class AccountView : public IView
{
public:
	AccountView();
	~AccountView();

	void OnCreate() override;
	void OnDestroy() override;
	void showMenu();
	static void listView(vector<Account> accounts);
	Account editView(Account account);
	void showSuccessfulMessage();
};