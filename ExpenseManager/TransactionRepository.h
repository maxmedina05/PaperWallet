#pragma once
#include "IRepository.h"
#include "Transaction.h"
#include <vector>

class TransactionRepository : public IRepository<Transaction>{
private:
	vector<Transaction> _transactions;

public:
	TransactionRepository();
	~TransactionRepository();

	virtual bool add(Transaction entity) override;
	virtual bool update(Transaction entity) override;
	virtual Transaction getById(int Id) override;
	virtual bool remove(Transaction entity) override;
	virtual vector<Transaction> getAll() override;

	void mockfill();
};

