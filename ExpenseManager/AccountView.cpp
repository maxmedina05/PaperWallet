#include "AccountView.h"


AccountView::AccountView()
{
	
}

AccountView::~AccountView()
{
	
}

void AccountView::OnCreate()
{
	//showMenu();
}

void AccountView::OnDestroy()
{
	
}

void AccountView::showMenu()
{
	cout << "*****MANTENIMIENTO DE CUENTAS*****" << endl;
	cout << '\n';

	cout << "1. Ver Listado." << endl;
	cout << "2. Agregar cuenta nueva." << endl;
	cout << "3. Editar cuenta." << endl;
	cout << "4. Eliminar cuenta." << endl;

	cout << "0. Salir" << endl;

}

void AccountView::listView(vector<Account> accounts)
{
	cout << "*****MANTENIMIENTO DE CUENTAS*****" << endl;
	cout << '\n';
	// std::cout << std::right << std::setw(13) << "foobar" << std::endl;
	cout << "Listado de cuentas: \n";
	printf("%10s | %-20s | %-30s\n",
		"ID",
		"Name",
		"Description");


	for (int i = 0; i < 80; i++)
		printf("-");

	for (int i = 0; i < accounts.size(); i++){

		printf("%10d | %-20s | %-30s\n",
			accounts[i].getId(),
			accounts[i].getName().c_str(),
			accounts[i].getDescription().c_str());
	}

	cout << "0. Salir" << endl;

}

Account AccountView::editView(Account account)
{
	string buffer;
	cout << "*****MANTENIMIENTO DE CUENTAS*****" << endl;
	cout << '\n';

	cin.clear();
	cin.sync();

	printf( "editar cuenta ID(%d): \n", account.getId());

	cout << "Nombre: ";
	getline(cin, buffer);

	if (!buffer.empty())
		account.setName(buffer);

	cout << "Description: ";
	getline(cin, buffer);

	if (!buffer.empty())
		account.setDescription(buffer);

	buffer.clear();
	return account;
}

void AccountView::showSuccessfulMessage()
{
	cout << "Account created successfully!" << endl;
}
