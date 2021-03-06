#include "TransactionPresenter.h"

TransactionPresenter::TransactionPresenter(TransactionView* view)
	:IPresenter(view)
{
}

void TransactionPresenter::Initialize()
{
	OptionMenuLoop();
}

void TransactionPresenter::OptionMenuLoop()
{
	cin.clear();
	cin.sync();

	int option = -1;
	while (true)
	{
		_view->showMenu();
		// Wait for user option;
		cin >> option;
		if (option == 0)
			break;

		switch (option){
		case LIST:
			_view->listView(_repo->getAll());
			break;

		case ADD:
			cout << "1 - INGRESOS | 0 - GASTOS: ";
			cin >> option;
			if (option == INCOME)
				_repo->add(_view->editView(Transaction(), INCOME, _accounts, _categories, _methods, _particulars));
			else if (option == EXPENSE)
				_repo->add(_view->editView(Transaction(), EXPENSE, _accounts, _categories, _methods, _particulars));

			_view->showSuccessfulMessage();
			break;

		case EDIT:{
			cout << "ID de la transaction: ";
			cin >> option;
			Transaction transaction = _repo->getById(option);
			_repo->update(_view->editView(transaction,
				(transaction.getAmount() > 0) ? INCOME : EXPENSE,
				_accounts, _categories, _methods, _particulars));
			_view->showSuccessfulMessage();
		}
			break;

		case REMOVE:
			cout << "ID de la transaction: ";
			cin >> option;

			cout << "Esta seguro ? (SI - 1 NO - 0)";
			cin >> option;

			if (option == 1){
				_repo->remove(_repo->getById(option));
				_view->showSuccessfulMessage();
			}
			break;
		}
	}

	option = -1;
}

void TransactionPresenter::Callback()
{

}

void TransactionPresenter::LoadList(){

}

void TransactionPresenter::setTransactionRepo(TransactionRepository * repo)
{
	_repo = repo;
}

void TransactionPresenter::set_accounts(const vector<Account>& accounts)
{
	_accounts = accounts;
}

void TransactionPresenter::set_particulars(const vector<Particular>& particulars)
{
	_particulars = particulars;
}

void TransactionPresenter::set_payment_methods(const vector<PaymentMethod>& payment_methods)
{
	_methods = payment_methods;
}

void TransactionPresenter::set_categories(const vector<Category>& categories)
{
	_categories = categories;
}
