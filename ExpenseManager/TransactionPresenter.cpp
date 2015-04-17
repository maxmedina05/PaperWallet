#include "TransactionPresenter.h"

TransactionPresenter::TransactionPresenter(IView* view)
	:IPresenter(view)
{
	_aview = static_cast<TransactionView*>(_View);

	LoadList();

	_View->OnCreate();
	OptionMenuLoop();
}

void TransactionPresenter::OptionMenuLoop()
{
	int option = -1;
	while (true)
	{
		_aview->showMenu();
		// Wait for user option;
		cin >> option;
		if (option == 0)
			break;

		switch (option){
		case LIST:
			_aview->listView(_repo.getAll());
			break;
		case ADD:
			_repo.add(_aview->editView(Transaction()));
			_aview->showSuccessfulMessage();
			break;

		case EDIT:
			cout << "ID de la transaction: ";
			cin >> option;
			_repo.update(_aview->editView(_repo.getById(option)));
			_aview->showSuccessfulMessage();
			break;

		case REMOVE:
			cout << "ID de la transaction: ";
			cin >> option;

			cout << "Esta seguro ? (SI - 1 NO - 0)";
			cin >> option;

			if (option == 1){
				_repo.remove(_repo.getById(option));
				_aview->showSuccessfulMessage();
			}
			break;
		}
	}
}

void TransactionPresenter::Callback()
{

}

void TransactionPresenter::LoadList(){
	Transaction transaction;
	transaction.setId(1);
	transaction.setAccount(Account("Max's Account", "Personal"));
	transaction.setAmount(1000);
	transaction.setCategory(Category("Income"));
	transaction.setDescription("Stuff i buy");
	transaction.setParticular(Particular("Max", Payer));
	transaction.setPaymentMethod(PaymentMethod("Cash"));
	transaction.setDate(Date());
	_repo.add(transaction);

}
