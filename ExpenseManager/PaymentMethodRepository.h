#pragma once
#include "IRepository.h"
#include "PaymentMethod.h"
#include <vector>

class PaymentMethodRepository : public IRepository<PaymentMethod>{
private:
	vector<PaymentMethod> _paymentMethods;

public:
	PaymentMethodRepository();
	~PaymentMethodRepository();

	virtual bool add(PaymentMethod entity) override;
	virtual bool update(PaymentMethod entity) override;
	virtual PaymentMethod getById(int Id) override;
	virtual bool remove(PaymentMethod entity) override;
	virtual vector<PaymentMethod> getAll() override;

	void mockfill();
};

