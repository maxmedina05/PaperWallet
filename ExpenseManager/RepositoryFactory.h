#pragma once
#include "AccountRepository.h"
#include "CategoryRepository.h"
#include "ParticularRepository.h"
#include "PaymentMethodRepository.h"
#include "TransactionRepository.h"

class RepositoryFactory
{
public:
	AccountRepository* _accountRepo;
	CategoryRepository* _categoryRepo;
	ParticularRepository* _particularRepo;
	PaymentMethodRepository* _methodRepo;
	TransactionRepository* _transactionRepo;

public:
	RepositoryFactory();
	~RepositoryFactory();
};