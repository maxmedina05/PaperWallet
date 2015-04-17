#pragma once
#include "IRepository.h"
#include "Account.h"
#include <vector>

class AccountRepository : public IRepository<Account>{
private:
	vector<Account> _accounts;

public:
	AccountRepository();
	~AccountRepository();

	virtual bool add(Account entity) override;
	virtual bool update(Account entity) override;
	virtual Account getById(int Id) override;
	virtual bool remove(Account entity) override;
	virtual vector<Account> getAll() override;

};

