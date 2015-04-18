#include "ParticularPresenter.h"

ParticularPresenter::ParticularPresenter(IView* view)
	:IPresenter(view)
{
	_aview = static_cast<ParticularView*>(_View);
}

void ParticularPresenter::Initialize()
{
	_View->OnViewCreated();
	OptionMenuLoop();
}

void ParticularPresenter::setRepository(ParticularRepository* particular_repo)
{
	_repo = particular_repo;
}


void ParticularPresenter::OptionMenuLoop()
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
			cout << "PAGADOR = 1 BENEFICIARIO = 0:";
			cin >> option;
			if (option == 1)
				_aview->listView(_repo->getAll(), Payer);
			if (option == 0)
				_aview->listView(_repo->getAll(), Payee);

			break;
		case ADD:
			cout << "PAGADOR = 1 BENEFICIARIO = 0:";
			cin >> option;

			if (option == 1)
				_repo->add(_aview->editView(Particular(Payer)));
			if (option == 0)
				_repo->add(_aview->editView(Particular(Payee)));

			_aview->showSuccessfulMessage();
			break;

		case EDIT:
			cout << "ID de la persona: ";
			cin >> option;
			_repo->update(_aview->editView(_repo->getById(option)));
			_aview->showSuccessfulMessage();
			break;

		case REMOVE:
			cout << "ID de la persona: ";
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

void ParticularPresenter::Callback()
{

}

void ParticularPresenter::LoadList(){
	_repo->add(Particular("BanReservas", Payee));
	_repo->add(Particular("PUCMM", Payee));
	_repo->add(Particular("Supermercado Bravo", Payee));
	_repo->add(Particular("FARD", Payer));
}
