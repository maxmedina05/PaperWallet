#include "CategoryPresenter.h"


CategoryPresenter::CategoryPresenter(CategoryView* view)
	:IPresenter(view){
}

void CategoryPresenter::Initialize()
{
	//_view->OnViewCreated();
	OptionMenuLoop();
}


void CategoryPresenter::OptionMenuLoop()
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
			_repo->add(_view->editView(Category()));
			_view->showSuccessfulMessage();
			break;

		case EDIT:
			cout << "ID de la categoria: ";
			cin >> option;
			_repo->update(_view->editView(_repo->getById(option)));
			_view->showSuccessfulMessage();
			break;

		case REMOVE:
			cout << "ID de la categoria: ";
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