#include "SettingPresenter.h"
#include "AccountPresenter.h"
#include "CategoryPresenter.h"
#include "PaymentMethodPresenter.h"
#include "ParticularPresenter.h"

SettingPresenter::SettingPresenter(IView* view)
	:IPresenter(view)
{
	_aview = static_cast<SettingView*>(_View);
}

SettingPresenter::~SettingPresenter()
{

}

void SettingPresenter::Initialize()
{
	_View->OnViewCreated();
	OptionMenuLoop();
}

void SettingPresenter::OptionMenuLoop()
{
	int option = -1;
	while (true)
	{
		_aview->showTitle();
		cout << "Seleccione una opcion: ";
		cin >> option;

		if (option == 0)
			break;

		switch (option)
		{
		case ACCOUNT:
			startAccountActivity();
			break;
		case CATEGORY:
			startCategoryActivity();
			break;
		case PARTICULAR:
			startParticularActivity();
			break;
		case PAYMENT_METHOD:
			startPaymentMethodActivity();
			break;
		}
	}
}

void SettingPresenter::startAccountActivity(){
	IView* view = new AccountView();
	AccountPresenter presenter(view);
	presenter.setAccountRepo(_factory->_accountRepo);
	presenter.Initialize();

	delete view;
}

void SettingPresenter::startCategoryActivity()
{
	IView* view = new CategoryView();
	CategoryPresenter presenter(view);
	presenter.setRepository(_factory->_categoryRepo);
	presenter.Initialize();

	delete view;
}
void SettingPresenter::startParticularActivity()
{
	IView* view = new ParticularView();
	ParticularPresenter presenter(view);
	presenter.setRepository(_factory->_particularRepo);
	presenter.Initialize();

	delete view;
}
void SettingPresenter::startPaymentMethodActivity()
{
	IView* view = new PaymentMethodView();
	PaymentMethodPresenter presenter(view);
	presenter.setRepository(_factory->_methodRepo);
	presenter.Initialize();

	delete view;
}

void SettingPresenter::Callback()
{

}