#include <iostream>

using namespaces std;


Diccionario::Diccionario(){/*No hace nada*/}

int Diccionario::size() const 
{
	return datos.size();//Esto sólo devuelve las letras 
}


vector<string> Diccionario::PalabrasLongitud(int longitud)
{
	vector<string> palabras;
	ArbolGeneral<info>::iter_preorden it;
	int contador=0;
	string palabra;

	it = datos.begin();
	
	while((*it)->final != true && )
}