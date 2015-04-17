#pragma once
#include "IView.h"
#include "IPresenter.h"
#include "TransactionRepository.h"
#include "TransactionView.h"

class TransactionPresenter : public IPresenter{
private:
	TransactionView *_aview;
	TransactionRepository _repo;
	Transaction _currentTransaction;

public:
	TransactionPresenter(IView* view);
	void Initialize();
	void LoadList();
	void Callback();
	void OptionMenuLoop();
};