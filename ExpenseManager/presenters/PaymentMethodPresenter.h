#pragma once
#include "IPresenter.h"
#include "../views/PaymentMethodView.h"
#include "../models/PaymentMethod.h"
#include "../repositories/PaymentMethodRepository.h"

class PaymentMethodPresenter : public IPresenter<PaymentMethodView>{
private:
	PaymentMethodRepository* _repo;

public:
	PaymentMethodPresenter(PaymentMethodView* view);
	void Initialize();
	void LoadList();
	void Callback();
	void OptionMenuLoop();
	void setRepository(PaymentMethodRepository* repo);
};