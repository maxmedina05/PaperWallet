#include "PaymentMethodPresenter.h"

PaymentMethodPresenter::PaymentMethodPresenter(IView* view)
	:IPresenter(view)
{
	_aview = static_cast<PaymentMethodView*>(_View);
}

void PaymentMethodPresenter::Initialize()
{
	_View->OnViewCreated();
	OptionMenuLoop();
}


void PaymentMethodPresenter::OptionMenuLoop()
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
			_aview->listView(_repo->getAll());
			break;
		case ADD:
			_repo->add(_aview->editView(PaymentMethod()));
			_aview->showSuccessfulMessage();
			break;

		case EDIT:
			cout << "ID de la metodo de pago: ";
			cin >> option;
			_repo->update(_aview->editView(_repo->getById(option)));
			_aview->showSuccessfulMessage();
			break;

		case REMOVE:
			cout << "ID de la metodo de pago: ";
			cin >> option;

			cout << "Esta seguro ? (SI - 1 NO - 0)";
			cin >> option;

			if (option == 1){
				_repo->remove(_repo->getById(option));
				_aview->showSuccessfulMessage();
			}
			break;
		}
	}
}

void PaymentMethodPresenter::Callback()
{

}

void PaymentMethodPresenter::LoadList(){
	_repo->add(PaymentMethod("Efectivo"));
	_repo->add(PaymentMethod("Credito"));
	_repo->add(PaymentMethod("Transferencia"));
}

void PaymentMethodPresenter::setRepository(PaymentMethodRepository* repo)
{
	_repo = repo;
}
