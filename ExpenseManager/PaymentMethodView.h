#pragma once
#include "IView.h"
#include <vector>
#include "PaymentMethod.h"

class PaymentMethodView : public IView
{
public:
	PaymentMethodView();
	~PaymentMethodView();

	void OnCreate() override;
	void OnDestroy() override;
	void showMenu();
	static void listView(vector<PaymentMethod> methods);

	PaymentMethod editView(PaymentMethod method);
	void showSuccessfulMessage();
};