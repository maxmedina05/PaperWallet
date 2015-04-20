#include "CategoryView.h"


CategoryView::CategoryView()
{

}

CategoryView::~CategoryView()
{

}

void CategoryView::OnViewCreated()
{
	showTitle();
}

void CategoryView::OnViewDestroyed()
{

}

void CategoryView::showTitle()
{
	cout << "*****MANTENIMIENTO DE CATEGORIA*****" << endl;
	cout << '\n';
}


void CategoryView::showMenu()
{
	cout << "1. Ver Listado." << endl;
	cout << "2. Agregar categoria nueva." << endl;
	cout << "3. Editar categoria." << endl;
	cout << "4. Eliminar categoria." << endl;

	cout << "0. Salir" << endl;
}

void CategoryView::listView(vector<Category> Categorys)
{
	cout << "Listado de categorias: \n";
	printf("%10s | %-20s\n",
		"ID",
		"Name");

	for (int i = 0; i < 80; i++)
		printf("-");

	for (int i = 0; i < Categorys.size(); i++)
		printf("%10d | %-20s\n",
			Categorys[i].getId(),
			Categorys[i].getName().c_str());
	
	cout << "0. Salir" << endl;
}

Category CategoryView::editView(Category Category)
{
	string buffer;
	cout << '\n';

	cin.clear();
	cin.sync();

	printf("editar categoria ID(%d): \n", Category.getId());

	cout << "Nombre: ";
	getline(cin, buffer);

	if (!buffer.empty())
		Category.setName(buffer);

	buffer.clear();
	return Category;
}

void CategoryView::showSuccessfulMessage()
{
	cout << "Category created successfully!" << endl;
}
