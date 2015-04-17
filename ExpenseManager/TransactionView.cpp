#include "TransactionView.h"


TransactionView::TransactionView()
{

}

TransactionView::~TransactionView()
{

}

void TransactionView::OnCreate()
{
	//showMenu();
}

void TransactionView::OnDestroy()
{

}

void TransactionView::showMenu()
{
	cout << "*****MANTENIMIENTO DE TRANSACCION*****" << endl;
	cout << '\n';

	cout << "1. Ver Listado." << endl;
	cout << "2. Agregar transacion." << endl;
	cout << "3. Editar transacion." << endl;
	cout << "4. Eliminar transacion." << endl;

	cout << "0. Salir" << endl;
}

void TransactionView::listView(vector<Transaction> Transactions)
{
	cout << "*****MANTENIMIENTO DE TRANSACCION*****\n" << endl;

	cout << "Listado de transacciones: \n";
	printf("%10s %10s %10s %10s %10s %10s %10s\n",
		"ID",
		"Date",
		"Amount",
		"Account",
		"Category",
		"Payers",
		"Payment");

	for (int i = 0; i < 80; i++)
		printf("-");

	for (int i = 0; i < Transactions.size(); i++)
		printf("%10d %10s %10f %10s %10s %10s %10s\n",
		Transactions[i].getId(),
		Transactions[i].getDate().toString().c_str(),
		Transactions[i].getAmount(),
		Transactions[i].getAccount().getName().c_str(),
		Transactions[i].getCategory().getName().c_str(),
		Transactions[i].getParticular().getName().c_str(),
		Transactions[i].getPaymentMethod().getName().c_str()
		);

	cout << "0. Salir" << endl;
}

Transaction TransactionView::editView(Transaction Transaction)
{
	string buffer;
	cout << "*****MANTENIMIENTO DE CATEGORIA*****" << endl;
	cout << '\n';
	cin.clear();
	cin.sync();

	printf("editar categoria ID(%d): \n", Transaction.getId());

	cout << "Nombre: ";
	getline(cin, buffer);

	buffer.clear();
	return Transaction;
}

void TransactionView::showSuccessfulMessage()
{
	cout << "Transaction created successfully!" << endl;
}
