#include "SettingView.h"

SettingView::SettingView(){
	
}

SettingView::~SettingView(){

}

void SettingView::showTitle() {
	cout << "***** SETTINGS *****" << endl << endl;
}
void SettingView::OnViewCreated() {
	showTitle();
}
void SettingView::OnViewDestroyed() {

}

void SettingView::showMenu()
{
	cout << "1. Account" << endl;
	cout << "2. Category" << endl;
	cout << "3. Particular" << endl;
	cout << "4. Payment Method" << endl;
	cout << "5. Transaction" << endl;
	cout << '\n';
	cout << "0. Salir" << endl;

	for (int i = 0; i < 80; i++)
		cout << "-";
	
	cout << endl;
}
