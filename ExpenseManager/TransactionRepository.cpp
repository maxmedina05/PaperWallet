#include "TransactionRepository.h"

TransactionRepository::TransactionRepository()
{

}
TransactionRepository::~TransactionRepository()
{

}

bool TransactionRepository::add(Transaction entity)
{
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