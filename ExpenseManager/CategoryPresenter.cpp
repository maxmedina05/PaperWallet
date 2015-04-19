#include "CategoryPresenter.h"


CategoryPresenter::CategoryPresenter(IView* view)
	:IPresenter(view)
{
	_aview = static_cast<CategoryView*>(_View);
}

void CategoryPresenter::Initialize()
{
	//_View->OnViewCreated();
	OptionMenuLoop();
}


void CategoryPresenter::OptionMenuLoop()
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
			_repo->add(_aview->editView(Category()));
			_aview->showSuccessfulMessage();
			break;

		case EDIT:
			cout << "ID de la categoria: ";
			cin >> option;
			_repo->update(_aview->editView(_repo->getById(option)));
			_aview->showSuccessfulMessage();
			break;

		case REMOVE:
			cout << "ID de la categoria: ";
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

void CategoryPresenter::Callback()
{

}

void CategoryPresenter::LoadList(){
	_repo->add(Category("Income"));
	_repo->add(Category("Household"));
	_repo->add(Category("Loan"));
}

void CategoryPresenter::setRepository(CategoryRepository* repo)
{
	_repo = repo;
}