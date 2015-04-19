#include "HomePresenter.h"
#include "SettingView.h"
#include "SettingPresenter.h"

HomePresenter::HomePresenter(IView* view)
	:IPresenter(view){
	_aview = static_cast<HomeView*>(_View);
}

HomePresenter::~HomePresenter(){
}

void HomePresenter::UpdateDisplayValues()
{
	_balance = ComputeBalance();
	_incomes = ComputeIncome();
	_expenses = ComputeExpense();
}

void HomePresenter::Initialize()
{
	//_View->OnViewCreated();

	_currentAccount = _factory->_accountRepo->getById(0);
	UpdateDisplayValues();

	OptionMenuLoop();
}

void HomePresenter::OptionMenuLoop()
{
	int option = -1;
	while (true){
		_aview->showTitle();
		_aview->showResume(_balance, _incomes, _expenses);
		_aview->showMenu();
		cout << "Seleccione una opcion: ";
		cin >> option;
		if (option == 0)
			break;

		switch (option){

		case CHANGE_ACCOUNT:
			changeAccount();
			break;

		case ADD_INCOME:
			addIncomes();
			break;

		case ADD_EXPENSE:
			addExpense();
			break;
		
		case VIEW_HISTORY:
			viewHistory();
			break;

		case SETTINGS:
			startSettingsActivity();
			break;
		}

		cout << endl;
	}
}

void HomePresenter::Callback()
{

}

void HomePresenter::setFactory(RepositoryFactory *factory)
{
	_factory = factory;
}

void HomePresenter::changeAccount(){
	int option;

	AccountView::listView(_factory->_accountRepo->getAll());
	cout << "Selecione el codigo de la cuenta: ";

	cin >> option;

	_currentAccount = _factory->_accountRepo->getById(option);
	UpdateDisplayValues();
}

void HomePresenter::startSettingsActivity()
{
	IView* view = new SettingView();
	SettingPresenter presenter(view);
	presenter.setFactory(_factory);
	presenter.Initialize();

	delete view;
}

void HomePresenter::addIncomes()
{
	TransactionView* view = new TransactionView();

	Transaction transaction;
	transaction = view->editView(transaction, INCOME,
		_factory->_accountRepo->getAll(),
		_factory->_categoryRepo->getAll(),
		_factory->_methodRepo->getAll(),
		_factory->_particularRepo->getAll());

	_factory->_transactionRepo->add(transaction);
	UpdateDisplayValues();
	delete view;
}


void HomePresenter::addExpense(){
	TransactionView* view = new TransactionView();

	Transaction transaction;
	transaction = view->editView(transaction, EXPENSE,
		_factory->_accountRepo->getAll(),
		_factory->_categoryRepo->getAll(),
		_factory->_methodRepo->getAll(),
		_factory->_particularRepo->getAll());

	_factory->_transactionRepo->add(transaction);

	UpdateDisplayValues();
	delete view;
}

void HomePresenter::viewHistory(){
	cout << "Ultimas Transacciones: " << endl;
	cout << '\n';

	TransactionView::listView(_factory->_transactionRepo->getAll());
}

double HomePresenter::ComputeBalance()
{
	vector<Transaction> transactions = _factory->_transactionRepo->getAll();

	double result = 0;
	for (Transaction transaction : transactions){
		if (transaction.getAccount().getId() == _currentAccount.getId())
			result += transaction.getAmount();
	}

	return result;
}

double HomePresenter::ComputeIncome()
{
	vector<Transaction> transactions = _factory->_transactionRepo->getAll();

	double result = 0;
	for (Transaction transaction : transactions){
		if (transaction.getAmount() > 0 && transaction.getAccount().getId() == _currentAccount.getId())
		result += transaction.getAmount();
	}

	return result;
}

double HomePresenter::ComputeExpense()
{
	vector<Transaction> transactions = _factory->_transactionRepo->getAll();

	double result = 0;
	for (Transaction transaction : transactions){
		if (transaction.getAmount() < 0 && transaction.getAccount().getId() == _currentAccount.getId())
		result += transaction.getAmount();
	}


	return 1*result;
}