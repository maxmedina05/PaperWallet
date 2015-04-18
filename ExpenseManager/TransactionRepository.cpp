#include "TransactionRepository.h"

TransactionRepository::TransactionRepository()
{

}
TransactionRepository::~TransactionRepository()
{

}

bool TransactionRepository::add(Transaction entity)
{
	static int idseed = 0;
	entity.setId(idseed++);

	_transactions.push_back(entity);
	return true;
}

bool TransactionRepository::update(Transaction entity)
{
	for (Transaction transaction : _transactions){
		if (transaction.getId() == entity.getId()){
			//transaction.setName(entity.getName());
			return true;
		}
	}

	return false;
}

Transaction TransactionRepository::getById(int Id)
{
	for (Transaction transaction : _transactions)
	{
		if (transaction.getId() == Id)
			return transaction;
	}
}

bool TransactionRepository::remove(Transaction entity)
{
	vector<Transaction>::iterator it;
	for (it = _transactions.begin(); it != _transactions.end(); ++it){
		if (it->getId() == entity.getId())
		{
			_transactions.erase(it);
			return true;
		}
	}

	return false;
}

vector<Transaction> TransactionRepository::getAll()
{
	return _transactions;
}

void TransactionRepository::mockfill()
{
	Transaction transaction;
	transaction.setId(1);
	transaction.setAccount(Account("Max's Account", "Personal"));
	transaction.setAmount(1000);
	transaction.setCategory(Category("Income"));
	transaction.setDescription("Stuff i buy");
	transaction.setParticular(Particular("Max", Payer));
	transaction.setPaymentMethod(PaymentMethod("Cash"));
	transaction.setDate(Date());
	this->add(transaction);
}
