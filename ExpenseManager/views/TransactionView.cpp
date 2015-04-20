#include "TransactionView.h"
#include "CategoryView.h"
#include "PaymentMethodView.h"
#include "AccountView.h"
#include "ParticularView.h"

TransactionView::TransactionView()
{

}

TransactionView::~TransactionView()
{

}

void TransactionView::OnViewCreated()
{
	//showMenu();
	showTitle();
}

void TransactionView::OnViewDestroyed()
{

}

void TransactionView::showTitle()
{
	cout << "*****MANTENIMIENTO DE TRANSACCION*****" << endl;
	cout << '\n';
}

void TransactionView::showMenu()
{
	cout << "1. Ver Listado." << endl;
	cout << "2. Agregar transacion." << endl;
	cout << "3. Editar transacion." << endl;
	cout << "4. Eliminar transacion." << endl;

	cout << "0. Salir" << endl;
}

void TransactionView::listView(vector<Transaction> transactions)
{
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

	for (int i = 0; i < transactions.size(); i++)
		printf("%8d|%-10s|%10.2f|%-10s|%-10s|%-10s|%-10s\n",
		//printf("%10d %10s %10f %10s %10s %10s %10s\n",
		transactions[i].getId(),
		transactions[i].getDate().toString().c_str(),
		transactions[i].getAmount(),
		transactions[i].getAccount().getName().c_str(),
		transactions[i].getCategory().getName().c_str(),
		transactions[i].getParticular().getName().c_str(),
		transactions[i].getPaymentMethod().getName().c_str()
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
	cout << "Introduzca el codigo de la cuenta:";
	cin >> value;

	for (Account account : accounts){
		if (account.getId() == value){
			Transaction.setAccount(account);
			break;
		}
	}

	cout << "Introduzca el monto: ";
	cin >> rvalue;

	if (rvalue > 0)
		Transaction.setAmount((type == EXPENSE) ? (-1*rvalue) : rvalue);

	if (type == INCOME){
		Transaction.setCategory(categories[0]);
	}

	else{
		CategoryView::listView(categories);
		cout << "Introduzca el codigo de la categoria: ";
		cin >> value;

		for (Category category : categories){
			if (category.getId() == value){
				Transaction.setCategory(category);
				break;
			}
		}

	}

	PaymentMethodView::listView(methods);
	cout << "Introduzca el codigo del metodo de pago: ";
	cin >> value;
	for (PaymentMethod method : methods){
		if (method.getId() == value){
			Transaction.setPaymentMethod(method);
			break;
		}
	}

	if (type == INCOME){
		ParticularView::listView(particulars, Payer);
		cout << "Introduzca el codigo del pagador: ";
	}

	if (type == EXPENSE){
		ParticularView::listView(particulars, Payee);
		cout << "Introduzca el codigo del beneficiario: ";
	}

	cin >> value;
	for (Particular particular : particulars){
		if (particular.getId() == value){
			Transaction.setParticular(particular);
			break;
		}
	}

	cin.clear();
	cin.sync();

	cout << "Introduzca una breve description: ";
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
