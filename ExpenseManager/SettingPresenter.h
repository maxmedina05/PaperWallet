#pragma once
#include "IView.h"
#include "IPresenter.h"
#include "SettingView.h"
#include "RepositoryFactory.h"

#define ACCOUNT  1
#define CATEGORY  2
#define PARTICULAR  3
#define PAYMENT_METHOD 4

class SettingPresenter : public IPresenter{
private:
	SettingView* _aview;
	RepositoryFactory *_factory;

public:
	SettingPresenter(IView* view);
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

