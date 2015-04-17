#pragma once
#include "IEntity.h"
#include "Date.h"
#include "Account.h"
#include "Category.h"
#include "Particular.h"
#include "PaymentMethod.h"

class Transaction : public IEntity
{
private:
	Date _date;
	double _amount;
	string _description;
	Account _account;
	Category _category;
	Particular _particular;
	PaymentMethod _method;

public:
	Transaction();
	~Transaction();

	void setAmount(double amount);
	double getAmount();

	void setDate(Date date);
	Date getDate();
	
	void setDescription(string description);
	string getDescription();

	void setAccount(Account account);
	Account getAccount();

	void setCategory(Category category);
	Category getCategory();

	void setParticular(Particular particular);
	Particular getParticular();

	void setPaymentMethod(PaymentMethod method);
	PaymentMethod getPaymentMethod();
};

