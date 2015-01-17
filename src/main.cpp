#include <iostream>
#include <ArbolGeneral.h>


int main ()
{
	ArbolGeneral<char> tree, othertree, hermanoderecha, rama;
	ArbolGeneral<char>::iter_preorden it;

	cout << "Introduce un Arbol" << endl;
	cin >> tree;

	/*cout << "Tu Arbol Introducido deberia ser: " << endl;
	cout << tree << endl;

	cout << "Inserta otro para añadirlo al nodo mas izquierda" << endl;
	cin >> othertree;

	cout << "Inserta otro para hacerlo hermano a la derecha" << endl;
	cin >> hermanoderecha;

	tree.insertar_hijomasizquierda(tree.raiz(), othertree);

	cout  << "Solo con hijo izquierda: " <<endl;
	cout << tree << endl;

	tree.insertar_hermanoderecha(tree.hijomasizquierda(tree.raiz()), hermanoderecha);

	cout  << "Añadido hijo derecha: " <<endl;
	cout << tree << endl;

	cout << "El nuevo arbol tiene " << tree.size() <<" elementos" << endl;
	//cout << "Ahora vamos a podar el hijo mas izquierda: " << endl;
	cout << "Ahora vamos a podar el hermanoderecha: " << endl;
	//tree.podar_hijomasizquierda(tree.raiz(), rama);
	tree.podar_hermanoderecha(tree.hijomasizquierda(tree.raiz()),rama);
	cout <<"Después de podar: "<<endl;
	cout << tree << endl;
	cout <<"La rama que hemos guardado" << endl;
	cout << rama << endl;

	cout << "Comparamos si arbol y rama son iguales: " <<endl;
	cout << (tree == rama);

	cout << "Comprobamos si tree está vacio: " << endl;
	cout << tree.empty();

	cout << "La rama que hemos podado la vamos a igualar al arbol viejo: "<<endl;
	tree = rama;

	//cout << tree << endl;
	cout << "Borramos el arbol: "<<endl;
	tree.clear();
	cout << tree << endl;
	cout << tree.empty();*/

	for (it = tree.begin(); it!= tree.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << tree.end();


	cout << "\nHa compilado" << endl;

}
