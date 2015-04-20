#pragma once

#include "IPresenter.h"
#include "../views/SettingView.h"
#include "../repositories/RepositoryFactory.h"

#define ACCOUNT  1
#define CATEGORY  2
#define PARTICULAR  3
#define PAYMENT_METHOD 4


class SettingPresenter : public IPresenter<SettingView>{
private:
	RepositoryFactory *_factory;

public:
	SettingPresenter(SettingView* view);
	~SettingPresenter();

	void Initialize();
	void Callback();
	void startAccountActivity();
	void startCategoryActivity();
	void startParticularActivity();
	void startPaymentMethodActivity();

	void OptionMenuLoop();
	void setFactory(RepositoryFactory *factory);
};

