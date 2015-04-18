#pragma once
#include "IView.h"
#include "IPresenter.h"
#include "AccountRepository.h"
#include "AccountView.h"

class AccountPresenter : public IPresenter{
private:
	AccountView *_aview;
	AccountRepository *_repo;
	Account _currentAccount;

public:
	AccountPresenter(IView* view);
	void Initialize();
	void LoadList();
	void Callback();
	void OptionMenuLoop();
	void setAccountRepo(AccountRepository *repo);
	
};