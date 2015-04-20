#pragma once
#include <string>
#include <fstream>
#include "../json/json.h"
#include "../models/Category.h"
#include "../models/PaymentMethod.h"
#include "../models/Particular.h"
#include "../models/Transaction.h"
#include "../repositories/RepositoryFactory.h"

using namespace std;

#define JSONObject Json::Value
#define JSONArray Json::Value

const string TABLE_NAME_ACCOUNT = "accounts";
const string TABLE_NAME_PARTICULAR = "particulars";
const string TABLE_NAME_PAYMENT_METHOD = "payment_methods";
const string TABLE_NAME_TRANSACTION = "transactions";
const string TABLE_NAME_CATEGORY = "categories";

const string JSON_EXT = ".json";

class PaperDatabase
{
private:
	RepositoryFactory* _factory;
	void saveAccounts(vector<Account> accounts);
	vector<Account> loadAccounts();

	void saveParticulars(vector<Particular> particulars);
	vector<Particular> loadParticulars();

	void savePaymentMethods(vector<PaymentMethod> methods);
	vector<PaymentMethod> loadPaymentMethods();

	void saveTransactions(vector<Transaction> tranactions);
	vector<Transaction> loadTransactions();

	void saveCategories(vector<Category> categories);
	vector<Category> loadCategories();

	void saveTable(string tableName, JSONObject jsonObject);
	string loadTable(string tableName);

public:
	PaperDatabase();
	~PaperDatabase();

	void setFactory(RepositoryFactory* factory);

	void OnCreate();
	void OnDestroy();
};

