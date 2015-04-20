#include "TransactionRepository.h"

TransactionRepository::TransactionRepository()
{

}
TransactionRepository::~TransactionRepository()
{

}

bool TransactionRepository::add(Transaction entity)
{
	entity.setId(getSeed());
	_transactions.push_back(entity);
	return true;
}

bool TransactionRepository::update(Transaction entity)
{
	for (Transaction transaction : _transactions){
		if (transaction.getId() == entity.getId()){
			transaction.setAmount(entity.getAmount());
			transaction.setDescription(entity.getDescription());
			transaction.setAccount(entity.getAccount());
			transaction.setCategory(entity.getCategory());
			transaction.setParticular(entity.getParticular());
			transaction.setPaymentMethod(entity.getPaymentMethod());

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


int TransactionRepository::getSeed(){
	string filepath = "API//transaction_seed.data";

	ifstream instream(filepath);
	string buffer;
	int seed = 0;
	if (instream.is_open())
	{
		instream >> buffer;
		seed = atoi(buffer.c_str());
	}
	instream.close();

	ofstream outstream(filepath);
	outstream << to_string(seed + 1);
	outstream.close();
	return seed;
}

void TransactionRepository::fill(vector<Transaction> transactions)
{
	_transactions = transactions;
}
