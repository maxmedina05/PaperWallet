#include "AccountRepository.h"

 AccountRepository::AccountRepository()
{

}
 AccountRepository::~AccountRepository()
{

}

 bool AccountRepository::add(Account entity)
{
	entity.setId(getSeed());
	_accounts.push_back(entity);
	return true;
}

 bool AccountRepository::update(Account entity)
{
	for (int i = 0; i < _accounts.size(); i++)
	{
		if (_accounts[i].getId() == entity.getId()){
			_accounts[i].setName(entity.getName());
			_accounts[i].setDescription(entity.getDescription());
			return true;
		}
	}

	return false;
}

Account AccountRepository::getById(int Id)
{
	for (Account account: _accounts)
	{
		if (account.getId() == Id)
			return account;
	}
}

bool AccountRepository::remove(Account entity)
{
	vector<Account>::iterator it;
	for (it = _accounts.begin(); it != _accounts.end(); ++it){
		if (it->getId() == entity.getId())
		{
			_accounts.erase(it);
			return true;
		}
	}

	return false;
}

vector<Account> AccountRepository::getAll()
{
	return _accounts;
}

void AccountRepository::mockFill()
 {
	 this->add(Account("Personal Account", "My Personal Account."));
	 this->add(Account("Credit Card", "My Credit Card."));
	 this->add(Account("Car's loan", "The loan I had to take to by a car."));
 }

int AccountRepository::getSeed(){
	string filepath = "API//account_seed.data";

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
	outstream << to_string(seed+1);
	outstream.close();
	return seed;
}

Account AccountRepository::getFirst()
{
	if (_accounts.size() > 0)
		return _accounts[0];

	return Account();
}

void AccountRepository::fill(vector<Account> accounts)
{
	_accounts = accounts;
}
