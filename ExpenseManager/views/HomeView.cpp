#include "HomeView.h"

HomeView::HomeView()
{
}


HomeView::~HomeView()
{
}

void HomeView::setPresenter(HomeView *presenter)
{
	_presenter = presenter;
}

void HomeView::showTitle() {
	cout << "**********OVERVIEW**********\n" << endl;
}

void HomeView::OnViewCreated() {
	showTitle();
}

void HomeView::OnViewDestroyed() {

}

void HomeView::showMenu()
{
	cout << "1. Cambiar de cuenta" << endl;
	cout << "2. Agregar Ingreso" << endl;
	cout << "3. Agregar Gasto" << endl;
	cout << "4. Ver Historial" << endl;
	cout << "5. Configuraciones" << endl;

	cout << '\n';
	cout << "0. Salir" << endl;

	for (int i = 0; i < 80; i++)
		cout << "-";

	cout << endl;
}

void HomeView::showResume(double balance, double incomes, double expenses)
{
	printf("Balance: \t\t%20.2f\n", balance);
	printf("Ingresos de este mes:   %20.2f\n", incomes);
	printf("Gastos de este mes:     %20.2f\n", expenses);

	cout << ('\n');
}