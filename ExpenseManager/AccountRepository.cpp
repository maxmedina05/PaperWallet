#include "AccountRepository.h"

 AccountRepository::AccountRepository()
{

}
 AccountRepository::~AccountRepository()
{

}

 bool AccountRepository::add(Account entity)
{
	static int idseed = 0;
	entity.setId(idseed++);

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