#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "Diccionario.h"
#include "bolsa_letras.h"

int main(int argc, char * argv[]){

	/*if(argc != 5){
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
	let>>bl;*/

	//Diccionario D;
	//dic>>D;


	/*
  if (argc!=2) {
  	cout<<"Los parametros son:" << endl;
  	cout<<"1.- El fichero con las palabras" << endl;
    return 0;
  }
    
  ifstream f(argv[1]);
*/
  ifstream f("datos/spanish");
  info ii(' ', false);
  cout << "Cargando diccionario...." << endl;
  Diccionario D;
  f >> D;
  cout << "Leido el diccionario..." << endl;
  cout << D << endl;


  int longitud;
 
  cout<<"Dime la longitud de las palabras que quieres ver";
  cin>>longitud;
  vector<string> v=D.PalabrasLongitud(longitud);
  
  cout<<"Palabras de Longitud "<<longitud<<endl;
  for (unsigned int i=0;i<v.size();i++)
    cout<<v[i]<<endl;

 
 /*
  string p;
  do {
    cout<<"\nDime una palabra: ";
    cin>>p;
    if (D.Esta(p)){
      cout<<"Sí esa palabra existe" << endl;
    }
    else
      cout<<"Esa palabra no existe" << endl;
  } while (true);
  */
  string p;
  do {
    cout<<"\nDime un conjunto de letras: ";
    cin>>p;

    vector<Letra> letras;
    Letra l;
    for (int i=0; i<p.size(); i++){
    	l.setLetra(p.at(i));
    	letras.push_back(l);
    }

    vector<string> palabras;
    D.palabrasConEstasLetras(D.getArbol().raiz(), letras, palabras);

    vector<string>::iterator it;
    for (it=palabras.begin(); it!=palabras.end(); ++it)
      cout << *it << ", ";
    cout << endl;

  } while (true);


}