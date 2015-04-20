#include "repositories/RepositoryFactory.h"
#include "views/HomeView.h"
#include "presenters/HomePresenter.h"

#include "API/PaperDatabase.h"

using namespace std;

int main(){

	RepositoryFactory factory;
	PaperDatabase db;
	db.setFactory(&factory);
	db.OnCreate();

	HomeView* view = new HomeView();
	HomePresenter presenter(view);

	presenter.setFactory(&factory);

	presenter.Initialize();

	db.OnDestroy();
	delete view;

	return 0;
}
