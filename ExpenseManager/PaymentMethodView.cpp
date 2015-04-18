#include "PaymentMethodView.h"


PaymentMethodView::PaymentMethodView()
{

}

void PaymentMethodView::showTitle()
{
	cout << "*****MANTENIMIENTO DE METODO DE PAGO*****" << endl;
	cout << '\n';
}

PaymentMethodView::~PaymentMethodView()
{

}

void PaymentMethodView::OnViewCreated()
{
	showTitle();
}

void PaymentMethodView::OnViewDestroyed()
{

}

void PaymentMethodView::showMenu()
{
	showTitle();

	cout << "1. Ver Listado." << endl;
	cout << "2. Agregar categoria nueva." << endl;
	cout << "3. Editar categoria." << endl;
	cout << "4. Eliminar categoria." << endl;

	cout << "0. Salir" << endl;
}

void PaymentMethodView::listView(vector<PaymentMethod> PaymentMethods)
{
	cout << "Listado de categorias: \n";
	printf("%10s | %-20s\n",
		"ID",
		"Name");

	for (int i = 0; i < 80; i++)
		printf("-");

	for (int i = 0; i < PaymentMethods.size(); i++)
		printf("%10d | %-20s\n",
		PaymentMethods[i].getId(),
		PaymentMethods[i].getName().c_str());

	cout << "0. Salir" << endl;
}

PaymentMethod PaymentMethodView::editView(PaymentMethod PaymentMethod)
{
	string buffer;
	showTitle();

	printf("EDITANDO PERSONA #(%d): \n", PaymentMethod.getId());
	cin.clear();
	cin.sync();

	cout << "Introduzca el Nombre: ";
	getline(cin, buffer);

	if (!buffer.empty())
		PaymentMethod.setName(buffer);

	buffer.clear();
	return PaymentMethod;
}

void PaymentMethodView::showSuccessfulMessage()
{
	cout << "PaymentMethod created successfully!" << endl;
}
