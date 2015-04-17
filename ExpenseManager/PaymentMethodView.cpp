#include "PaymentMethodView.h"


PaymentMethodView::PaymentMethodView()
{

}

PaymentMethodView::~PaymentMethodView()
{

}

void PaymentMethodView::OnCreate()
{
	//showMenu();
}

void PaymentMethodView::OnDestroy()
{

}

void PaymentMethodView::showMenu()
{
	cout << "*****MANTENIMIENTO DE METODO DE PAGO*****" << endl;
	cout << '\n';

	cout << "1. Ver Listado." << endl;
	cout << "2. Agregar categoria nueva." << endl;
	cout << "3. Editar categoria." << endl;
	cout << "4. Eliminar categoria." << endl;

	cout << "0. Salir" << endl;
}

void PaymentMethodView::listView(vector<PaymentMethod> PaymentMethods)
{
	cout << "*****MANTENIMIENTO DE METODO DE PAGO*****\n" << endl;

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
	cout << "*****MANTENIMIENTO DE METODO DE PAGO*****" << endl;
	cout << '\n';

	printf("editar categoria ID(%d): \n", PaymentMethod.getId());
	cin.clear();
	cin.sync();

	cout << "Nombre: ";
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
