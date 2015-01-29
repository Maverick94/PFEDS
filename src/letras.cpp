#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "Diccionario.h"
#include "bolsa_letras.h"

int main(int argc, char * argv[]){

	if(argc != 5){
		cerr<<"Uso: letras <nombre_fichero_diccionario> <nombre_fichero_letras> <numero_letras_a_generar> <modalidad_juego(L/P)>"<<endl;
		return -1;
	}

	ifstream dic(argv[1]);
	if(!dic)
		cerr<<"Error al abrir "<<argv[1]<<endl;
	ifstream let(argv[2]);
	if(!let)
		cerr<<"Error al abrir "<<argv[2]<<endl;
	
	Bolsa_Letras bl;
	let>>bl;

	Diccionario D;
	dic>>D;

	vector<Letra> letras=bl.getBolsa();
	ArbolGeneral<info> arbol=D.getArbol();
	for(int i=0;i<letras.size();i++){


	}
}