#pragma once
#include "IView.h"
#include <vector>
#include "../models/PaymentMethod.h"

class PaymentMethodView : public IView
{
public:
	PaymentMethodView();
	~PaymentMethodView();

	void OnViewCreated() override;
	void OnViewDestroyed() override;
	void showMenu();
	static void listView(vector<PaymentMethod> methods);
	void showTitle() override;
	PaymentMethod editView(PaymentMethod method);
	void showSuccessfulMessage();
};