#include "ParticularView.h"


ParticularView::ParticularView()
{

}

ParticularView::~ParticularView()
{

}

void ParticularView::showTitle()
{
	cout << "*****MANTENIMIENTO DE PERSONA*****" << endl;
	cout << '\n';
}


void ParticularView::OnViewCreated()
{
	showTitle();
}

void ParticularView::OnViewDestroyed()
{

}

void ParticularView::showMenu()
{
	cout << "1. Ver Listado." << endl;
	cout << "2. Agregar persona nueva." << endl;
	cout << "3. Editar persona." << endl;
	cout << "4. Eliminar persona." << endl;

	cout << "0. Salir" << endl;
}

void ParticularView::listView(vector<Particular> Particulars, ParticularType type)
{
	cout << "Listado de personas: \n";
	printf("%10s | %-20s\n",
		"ID",
		"Name");

	for (int i = 0; i < 80; i++)
		printf("-");

	for (int i = 0; i < Particulars.size(); i++){
		if (Particulars[i].getType() == type)
			printf("%10d | %-20s\n",
			Particulars[i].getId(),
			Particulars[i].getName().c_str());
	}
}

Particular ParticularView::editView(Particular Particular)
{
	string buffer;
	showTitle();

	printf("editar persona ID(%d): \n", Particular.getId());
	cin.clear();
	cin.sync();

	cout << "Nombre: ";
	getline(cin, buffer);

	if (!buffer.empty())
		Particular.setName(buffer);

	buffer.clear();
	return Particular;
}

void ParticularView::showSuccessfulMessage()
{
	cout << "Particular created successfully!" << endl;
}
