#pragma once
#include "IView.h"
#include "IPresenter.h"
#include "PaymentMethodRepository.h"
#include "PaymentMethodView.h"

class PaymentMethodPresenter : public IPresenter{
private:
	PaymentMethodView *_aview;
	PaymentMethodRepository _repo;
	PaymentMethod _currentPaymentMethod;

public:
	PaymentMethodPresenter(IView* view);
	void Initialize();
	void LoadList();
	void Callback();
	void OptionMenuLoop();
};