#include "PaymentMethodPresenter.h"

PaymentMethodPresenter::PaymentMethodPresenter(PaymentMethodView* view)
	:IPresenter(view){
}

void PaymentMethodPresenter::Initialize()
{
	//_view->OnViewCreated();
	OptionMenuLoop();
}


void PaymentMethodPresenter::OptionMenuLoop()
{
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
			_repo->add(_view->editView(PaymentMethod()));
			_view->showSuccessfulMessage();
			break;

		case EDIT:
			cout << "ID de la metodo de pago: ";
			cin >> option;
			_repo->update(_view->editView(_repo->getById(option)));
			_view->showSuccessfulMessage();
			break;

		case REMOVE:
			cout << "ID de la metodo de pago: ";
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
