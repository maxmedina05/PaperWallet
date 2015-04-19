#include "AccountPresenter.h"

AccountPresenter::AccountPresenter(IView* view)
	:IPresenter(view)
{
	_aview = static_cast<AccountView*>(_View);
}

void AccountPresenter::Initialize()
{
	//_View->OnViewCreated();
	OptionMenuLoop();
}

void AccountPresenter::OptionMenuLoop()
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
			_repo->add(_aview->editView(Account()));
			_aview->showSuccessfulMessage();
			break;

		case EDIT:
			cout << "ID de la cuenta: ";
			cin >> option;
			
			_repo->update(_aview->editView(_repo->getById(option)));
			_aview->showSuccessfulMessage();
			break;

		case REMOVE:
			cout << "ID de la cuenta: ";
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

void AccountPresenter::Callback()
{

}

void AccountPresenter::LoadList(){
	_repo->add(Account("Personal Account", "My Personal Account."));
	_repo->add(Account("Credit Card", "My Credit Card."));
	_repo->add(Account("Car's loan", "The loan I had to take to by a car."));
}

void AccountPresenter::setAccountRepo(AccountRepository *repo){
	_repo = repo;
}