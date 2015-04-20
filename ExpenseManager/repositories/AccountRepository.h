#pragma once
#include "IRepository.h"
#include <vector>
#include "../models/Account.h"


class AccountRepository : public IRepository<Account>{
private:
	vector<Account> _accounts;
	int getSeed();
public:
	AccountRepository();
	~AccountRepository();

	virtual bool add(Account entity) override;
	virtual bool update(Account entity) override;
	virtual Account getById(int Id) override;
	virtual bool remove(Account entity) override;
	virtual vector<Account> getAll() override;


	void mockFill();
	Account getFirst();
	void fill(vector<Account> accounts);
};

