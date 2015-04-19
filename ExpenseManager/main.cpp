#include <iostream>
#include <stdio.h>
#include <string>
#include "RepositoryFactory.h"
#include "IView.h"
#include "HomeView.h"
#include "HomePresenter.h"

using namespace std;

int main(){

	RepositoryFactory factory;

	IView* view = new HomeView();
	HomePresenter presenter(view);

	presenter.setFactory(&factory);

	presenter.Initialize();

	delete view;

	return 0;
}
