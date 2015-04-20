#include "PaperDatabase.h"


PaperDatabase::PaperDatabase()
{
}

PaperDatabase::~PaperDatabase()
{
}

void PaperDatabase::saveAccounts(vector<Account> accounts){
	JSONObject root;
	JSONArray jsonArray;

	for (Account account : accounts){
		JSONObject jobject;
		jobject["id"] = account.getId();
		jobject["name"] = account.getName();
		jobject["description"] = account.getName();
		jsonArray.append(jobject);
	}

	root[TABLE_NAME_ACCOUNT] = jsonArray;
	saveTable(TABLE_NAME_ACCOUNT, root);
}

vector<Account> PaperDatabase::loadAccounts()
{
	vector<Account> accounts;
	string JsonString = loadTable(TABLE_NAME_ACCOUNT);
	Json::Reader reader;

	JSONObject root;
	JSONArray jarray;

	bool parsingSuccessful = reader.parse(JsonString, root);
	if (parsingSuccessful){
		jarray = root[TABLE_NAME_ACCOUNT];
		for (JSONObject object : jarray){
			Account account;
			account.setId(object["id"].asInt());
			account.setName(object["name"].asString());
			account.setDescription(object["description"].asString());
			accounts.push_back(account);
		}
	}
	return accounts;
}

void PaperDatabase::saveParticulars(vector<Particular> particulars)
{
	JSONObject root;
	JSONArray jsonArray;

	for (Particular particular : particulars){
		JSONObject jobject;
		jobject["id"] = particular.getId();
		jobject["name"] = particular.getName();
		jobject["type"] = particular.getType();
		jsonArray.append(jobject);
	}

	root[TABLE_NAME_PARTICULAR] = jsonArray;
	saveTable(TABLE_NAME_PARTICULAR, root);
}

vector<Particular> PaperDatabase::loadParticulars()
{
	vector<Particular> particulars;
	string JsonString = loadTable(TABLE_NAME_PARTICULAR);
	Json::Reader reader;

	JSONObject root;
	JSONArray jarray;

	bool parsingSuccessful = reader.parse(JsonString, root);
	if (parsingSuccessful){
		jarray = root[TABLE_NAME_PARTICULAR];
		for (JSONObject object : jarray){
			Particular entity;
			entity.setId(object["id"].asInt());
			entity.setName(object["name"].asString());
			entity.setType((ParticularType)object["type"].asInt());
			particulars.push_back(entity);
		}
	}
	return particulars;
}

void PaperDatabase::savePaymentMethods(vector<PaymentMethod> methods)
{
	JSONObject root;
	JSONArray jsonArray;

	for (PaymentMethod entity : methods){
		JSONObject jobject;
		jobject["id"] = entity.getId();
		jobject["name"] = entity.getName();
		jsonArray.append(jobject);
	}

	root[TABLE_NAME_PAYMENT_METHOD] = jsonArray;
	saveTable(TABLE_NAME_PAYMENT_METHOD, root);
}

vector<PaymentMethod> PaperDatabase::loadPaymentMethods()
{
	vector<PaymentMethod> collection;
	string JsonString = loadTable(TABLE_NAME_PAYMENT_METHOD);
	Json::Reader reader;

	JSONObject root;
	JSONArray jarray;

	bool parsingSuccessful = reader.parse(JsonString, root);
	if (parsingSuccessful){
		jarray = root[TABLE_NAME_PAYMENT_METHOD];
		for (JSONObject object : jarray){
			PaymentMethod entity;
			entity.setId(object["id"].asInt());
			entity.setName(object["name"].asString());

			collection.push_back(entity);
		}
	}
	return collection;
}

void PaperDatabase::saveTransactions(vector<Transaction> transactions)
{
	JSONObject root;
	JSONArray jsonArray;

	for (Transaction entity : transactions){
		JSONObject jobject;
		JSONObject jaccount;
		JSONObject jcategory;
		JSONObject jparticular;
		JSONObject jmethod;

		jaccount["id"] = entity.getAccount().getId();
		jaccount["name"] = entity.getAccount().getName();
		jaccount["description"] = entity.getAccount().getName();

		jcategory["id"] = entity.getCategory().getId();
		jcategory["name"] = entity.getCategory().getName();

		jparticular["id"] = entity.getParticular().getId();
		jparticular["name"] = entity.getParticular().getName();
		jparticular["type"] = entity.getParticular().getType();

		jmethod["id"] = entity.getPaymentMethod().getId();
		jmethod["name"] = entity.getPaymentMethod().getName();

			jobject["id"] = entity.getId();
			jobject["date"] = entity.getDate().toString();
			jobject["amount"] = entity.getAmount();
			jobject["description"] = entity.getDescription();
			jobject["account"] = jaccount;
			jobject["category"] = jcategory;
			jobject["particular"] = jparticular;
			jobject["payment_method"] = jmethod;

		jsonArray.append(jobject);
	}

	root[TABLE_NAME_TRANSACTION] = jsonArray;
	saveTable(TABLE_NAME_TRANSACTION, root);
}

vector<Transaction> PaperDatabase::loadTransactions()
{
	vector<Transaction> transactions;
	string JsonString = loadTable(TABLE_NAME_TRANSACTION);
	Json::Reader reader;

	JSONObject root;
	JSONArray jarray;

	bool parsingSuccessful = reader.parse(JsonString, root);
	if (parsingSuccessful){
		jarray = root[TABLE_NAME_TRANSACTION];
		for (JSONObject object : jarray){
			Transaction transaction;
			JSONObject jaccount = object["account"];
			JSONObject jcategory = object["category"];
			JSONObject jparticular = object["account"];
			JSONObject jmethod = object["payment_method"];

			Account account;
			account.setId(jaccount["id"].asInt());
			account.setName(jaccount["name"].asString());
			account.setDescription(jaccount["description"].asString());

			Category category;
			category.setId(jcategory["id"].asInt());
			category.setName(jcategory["name"].asString());

			Particular particular;
			particular.setId(jparticular["id"].asInt());
			particular.setName(jparticular["name"].asString());
			particular.setType((ParticularType)jparticular["type"].asInt());

			PaymentMethod method;
			method.setId(jmethod["id"].asInt());
			method.setName(jmethod["name"].asString());

			transaction.setId(object["id"].asInt());
			transaction.setDate(Date(object["date"].asString()));
			transaction.setAmount(object["amount"].asDouble());
			transaction.setDescription(object["description"].asString());
			transaction.setAccount(account);
			transaction.setCategory(category);
			transaction.setParticular(particular);
			transaction.setPaymentMethod(method);

			transactions.push_back(transaction);
		}
	}
	return transactions;
}

void PaperDatabase::saveCategories(vector<Category> categories){
	JSONObject root;
	JSONArray jsonArray;

	for (Category category : categories){
		JSONObject jobject;
		jobject["id"] = category.getId();
		jobject["name"] = category.getName();
		jsonArray.append(jobject);
	}

	root["categories"] = jsonArray;
	saveTable(TABLE_NAME_CATEGORY, root);
}

vector<Category> PaperDatabase::loadCategories(){
	vector<Category> categories;
	string JsonString = loadTable(TABLE_NAME_CATEGORY);
	Json::Reader reader;

	JSONObject root;
	JSONArray jarray;

	bool parsingSuccessful = reader.parse(JsonString, root);
	if (parsingSuccessful){
		jarray = root["categories"];
		for (JSONObject object : jarray){
			Category category;
			category.setId(object["id"].asInt());
			category.setName(object["name"].asString());
			categories.push_back(category);
		}
	}
	return categories;
}

void PaperDatabase::saveTable(string tableName, JSONObject jsonObject)
{
	string filename = "database\\"+ tableName + JSON_EXT;
	Json::FastWriter writer;
	
	ofstream outstream;
	outstream.open(filename);
	outstream << writer.write(jsonObject);
	
	outstream.close();
}

string PaperDatabase::loadTable(string tableName)
{
	string buffer = "";
	string line;
	string filename = "database\\" + tableName + JSON_EXT;
	
	ifstream instream;
	instream.open(filename);

	if (instream.is_open()){
		while (getline(instream, line))
			buffer.append(line);
	}

	instream.close();

	return buffer;
}

void PaperDatabase::setFactory(RepositoryFactory* factory)
{
	_factory = factory;
}

void PaperDatabase::OnCreate(){
	vector<Account> accounts = loadAccounts();
	vector<Category> categories = loadCategories();
	vector<Particular> particulars = loadParticulars();
	vector<PaymentMethod> methods = loadPaymentMethods();
	vector<Transaction> transactions = loadTransactions();

	_factory->_accountRepo->fill(accounts);

	_factory->_categoryRepo->fill(categories);

	_factory->_particularRepo->fill(particulars);
	_factory->_methodRepo->fill(methods);
	_factory->_transactionRepo->fill(transactions);
}

void PaperDatabase::OnDestroy(){

	saveAccounts(_factory->_accountRepo->getAll());
	saveCategories(_factory->_categoryRepo->getAll());
	saveParticulars(_factory->_particularRepo->getAll());
	savePaymentMethods(_factory->_methodRepo->getAll());
	saveTransactions(_factory->_transactionRepo->getAll());
}