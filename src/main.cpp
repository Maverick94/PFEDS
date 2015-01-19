#include <iostream>
#include <ArbolGeneral.h>

void Recorrer (const ArbolGeneral<char> &t)
{
	ArbolGeneral<char>::const_iter_preorden itc;

	for(itc = t.begin(); itc != t.end(); ++itc)
		cout << *itc<< " ";

	cout << *itc << endl;
}

int main ()
{

	ArbolGeneral<char> tree1,tree2;
	ArbolGeneral<char>::iter_preorden itree;


	cout << "Introduce un Arbol" << endl;
	cin >> tree1;

	cout << "Introduce otro arbol"<<endl;
	cin >> tree2;

	
	cout << "Arbol 1"<<endl;
	cout <<tree1<< endl;

	cout << "Arbol 2"<<endl;
	cout <<tree2<< endl;

	tree1.asignar_subarbol(tree2,tree2.hijomasizquierda(tree2.raiz()));

	cout<<"Arbol 1 tiene "<<tree1.size()<<" nodos"<<endl;

	cout<<"Ahora ARBOL 1 vale: "<<endl;
	cout << tree1 << endl;

	/*for (itree = tree1.begin(); itree!=tree1.end(); ++itree){
		cout << (*itree) << " ";
	}
	cout<<(*itree)<<endl;*/

	/*cout << tree1;*/

	Recorrer(tree1);
	Recorrer(tree2);
	//treeconst=tree;



	/*cout << "Tu Arbol Introducido deberia ser: " << endl;
	cout << tree << endl;*/

	/*cout << "Inserta otro" << endl;
	cin >> tree2;

	/*cout << "Inserta otro para hacerlo hermano a la derecha" << endl;
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

	/*cout<<"ARBOL 1: "<<endl;
	for (itree = tree1.begin(); itree!=tree1.end(); ++itree){
		cout << (*itree) << " ";
	}
	cout<<(*itree)<<endl;

	cout<<"ARBOL 2: "<<endl;
	for (itree = tree2.begin(); itree!= tree2.end(); ++itree){
		cout << (*itree) << " ";
	}
	cout<<(*itree)<<endl;

	cout<<"--------------------------------------------"<<endl;*/


	/*tree1.asignar_subarbol(tree2,tree2.hermanoderecha(tree2.hijomasizquierda(tree2.raiz())));

	cout<<"Arbol 1 tiene "<<tree1.size()<<" nodos"<<endl;

	cout<<"Ahora ARBOL 1 vale: "<<endl;
	
	for (itree = tree1.begin(); itree!=tree1.end(); ++itree){
		cout << (*itree) << " ";
	}
	cout<<(*itree)<<endl;*/

}
