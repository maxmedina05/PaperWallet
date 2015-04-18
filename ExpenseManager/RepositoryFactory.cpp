#include "RepositoryFactory.h"

RepositoryFactory::RepositoryFactory()
{
	_accountRepo = new AccountRepository();
	_categoryRepo = new CategoryRepository();
	_particularRepo = new ParticularRepository();
	_methodRepo = new PaymentMethodRepository();
	_transactionRepo = new TransactionRepository();

	_accountRepo->mockFill();
	_categoryRepo->mockfill();
	_particularRepo->mockfill();
	_methodRepo->mockfill();
	_transactionRepo->mockfill();

}

RepositoryFactory::~RepositoryFactory()
{
	delete _accountRepo;
	delete _categoryRepo;
	delete _particularRepo;
	delete _methodRepo;
	delete _transactionRepo;
}
