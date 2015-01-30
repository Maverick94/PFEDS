#include "Conjunto_letras.h"
#include <iostream>

using namespace std;

Conjuto_letras::Conjuto_letras(){/*No hace nada*/}

Conjuto_letras::Conjuto_letras(letra l){
	conjletras.insert(l);
}

void Conjuto_letras::InsertarLetra(letra l){
	conjletras.insert(l);
}

set <letra> & getConjuto(){
	return conjletras;
}

void MostrarConjuto(){
	set<letra>::iterator it;

	for(it = conjletras.begin(); it != conjletras.end(); ++it)
	{
		cout << (*it).getLetra() << ", "; 
	}	

	cout << endl;
}


