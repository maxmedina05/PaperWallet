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
	printf("%8s|%10s|%10s|%10s|%10s|%10s|%10s\n",
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
		printf("%8d|%-10s|%10.2f|%-10s|%-10s|%-10s|%-10s\n",
		//printf("%10d %10s %10f %10s %10s %10s %10s\n",
		Transactions[i].getId(),
		Transactions[i].getDate().toString().c_str(),
		Transactions[i].getAmount(),
		Transactions[i].getAccount().getName().c_str(),
		Transactions[i].getCategory().getName().c_str(),
		Transactions[i].getParticular().getName().c_str(),
		Transactions[i].getPaymentMethod().getName().c_str()
		);

	cout << endl;
}

Transaction TransactionView::editView(Transaction Transaction,
	int type,
	vector<Account> accounts,
	vector<Category> categories,
	vector<PaymentMethod> methods,
	vector<Particular> particulars)
{
	string buffer;
	int value;
	double rvalue;

	cout << '\n';
	cin.clear();
	cin.sync();

	printf("editar transaction ID(%d): \n", Transaction.getId());

	AccountView::listView(accounts);
	cout << "cuenta Id:";
	cin >> value;
	Transaction.setAccount(accounts[value]);

	cout << "Monto: ";
	cin >> rvalue;
	if (rvalue != 0)
		Transaction.setAmount(rvalue);

	if (type == INCOME)
		ParticularView::listView(particulars, Payer);
	if (type == EXPENSE)
		ParticularView::listView(particulars, Payee);
	
	cout << "persona Id:";
	cin >> value;
	Transaction.setParticular(particulars[value]);

	if (type == INCOME)
	{
		
	}

	cout << "Description: ";
	getline(cin, buffer);

	if (!buffer.empty())
		Transaction.setDescription(buffer);

	buffer.clear();
	return Transaction;
}

void TransactionView::showSuccessfulMessage()
{
	cout << "Transaction created successfully!" << endl;
}
