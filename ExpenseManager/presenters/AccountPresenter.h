#pragma once
#include "IPresenter.h"
#include "../views/AccountView.h"
#include "../repositories/AccountRepository.h"

class AccountPresenter : public IPresenter<AccountView>{
private:
	AccountRepository *_repo;
	Account _currentAccount;

public:
	AccountPresenter(AccountView* view);
	void Initialize();
	void LoadList();
	void Callback();
	void OptionMenuLoop();
	void setAccountRepo(AccountRepository *repo);
	
};