#include <iostream>
#include <stdio.h>
#include <string>
#include "Transaction.h"
#include "AccountPresenter.h"
#include "AccountView.h"
#include "TransactionView.h"
#include "TransactionPresenter.h"

using namespace std;

void PrintHeaderTransaction();
void PrintTransaction(Transaction transaction);

int main(){

	TransactionView* view = new TransactionView();
	TransactionPresenter transaction(view);

	delete view;

	return 0;
}

void PrintHeaderTransaction(){
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
}

void PrintTransaction(Transaction transaction){
	printf("%10d %10s %10f %10s %10s %10s %10s\n",
		transaction.getId(),
		transaction.getDate().toString(),
		25.0f,
		//transaction.getAmount(),
		transaction.getAccount().getName(),
		transaction.getCategory().getName(),
		transaction.getParticular().getName(),
		transaction.getPaymentMethod().getName()
		);
}