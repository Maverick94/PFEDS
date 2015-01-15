#include <iostream>
#include <ArbolGeneral.h>


int main ()
{
	ArbolGeneral<char> tree, othertree;

	cout << "Introduce un Arbol" << endl;
	cin >> tree;

	cout << "Tu Arbol deberia ser: " << endl;
	cout << tree << endl;

	cout << "Inserta otro para añadirlo al nodo mas izquierda" << endl;
	cin >> othertree;

	tree.insertar_hijomasizquierda(tree.raiz(), othertree);

	cout << tree << endl;

	cout << "\nHa compilado" << endl;

}
