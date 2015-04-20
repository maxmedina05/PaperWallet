#include "SettingPresenter.h"
#include "AccountPresenter.h"
#include "CategoryPresenter.h"
#include "PaymentMethodPresenter.h"
#include "ParticularPresenter.h"
#include "../views/TransactionView.h"
#include "TransactionPresenter.h"

SettingPresenter::SettingPresenter(SettingView* view)
	:IPresenter(view){
}

SettingPresenter::~SettingPresenter()
{

}

void SettingPresenter::Initialize()
{
	//_view->OnViewCreated();
	OptionMenuLoop();
}

void SettingPresenter::OptionMenuLoop()
{
	int option = -1;
	while (true)
	{
		_view->showMenu();
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
		case TRANSACTION:
			startPaymentMethodActivity();
			break;
		}
	}
}

void SettingPresenter::startAccountActivity(){
	AccountView* view = new AccountView();
	AccountPresenter presenter(view);
	presenter.setAccountRepo(_factory->_accountRepo);
	presenter.Initialize();

	delete view;
}

void SettingPresenter::startCategoryActivity()
{
	CategoryView* view = new CategoryView();
	CategoryPresenter presenter(view);
	presenter.setRepository(_factory->_categoryRepo);
	presenter.Initialize();

	delete view;
}
void SettingPresenter::startParticularActivity()
{
	ParticularView* view = new ParticularView();
	ParticularPresenter presenter(view);
	presenter.setRepository(_factory->_particularRepo);
	presenter.Initialize();

	delete view;
}
void SettingPresenter::startPaymentMethodActivity()
{
	PaymentMethodView* view = new PaymentMethodView();
	PaymentMethodPresenter presenter(view);
	presenter.setRepository(_factory->_methodRepo);
	presenter.Initialize();

	delete view;
}


void SettingPresenter::startTransactionActivity()
{
	TransactionView* view = new TransactionView();
	TransactionPresenter presenter(view);
	presenter.setTransactionRepo(_factory->_transactionRepo);
	presenter.Initialize();

	delete view;
}

void SettingPresenter::Callback()
{

}


void SettingPresenter::setFactory(RepositoryFactory *factory)
{
	_factory = factory;
}
