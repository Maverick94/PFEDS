#include <iostream>
#include "Diccionario.h"


using namespace std;


Diccionario::Diccionario(){/*No hace nada*/}

int Diccionario::size()const{
	int cont=0;
	ArbolGeneral<info>::const_iter_preorden it;
	for(it=datos.begin();it!=datos.end();++it){
		if( (*it).final )
			cont++;
	}
	return cont;
}

vector<string> Diccionario::PalabrasLongitud(int longitud)
{
	vector<string> palabras;
	ArbolGeneral<info>::iter_preorden it;
	int contador=0;
	string palabra;

	it = datos.begin();
	
	while((*it).final != true && true){}
}


bool Diccionario::Esta(string palabra){
	return mi_esta(datos.raiz(),palabra);
}

istream & operator>>(istream & is,Diccionario &D){
	Diccionario::iterator * pos=&(D.datos.raiz());
	/*ArbolGeneral<info>::nodo * pos=D.datos.raiz();
	ArbolGeneral<info>::nodo n;
	while(is){
		//Obtengo la palabra
		string pal=getLine(is);
		for(int i=0;i<pal.size();i++){
			char c=pal.at(i);
			n.etiqueta.c=c;
			if(i==pal.size()-1){
				n.etiqueta.final=true;
			}
			if(pos->izqda!=0){
				pos=pos->izqda;
				if(pos->etiqueta.c==c){
					if(pos->hizq!=0){
						pos=pos->izqda;
					}else{
						D.datos.insertar_hijomasizquierda(pos,ArbolGeneral<info>(n));
					}
				}else{
					while(pos->drcha!=0){
						pos=pos->drcha;
					}
					D.datos.insertar_hermanoderecha(pos,ArbolGeneral<info>(n));
					pos=pos->drcha;
				}
			}else{
				D.datos.insertar_hijomasizquierda(pos,ArbolGeneral<info>(n));
				pos=pos->izqda;
			}
		}
		pos=D.datos.raiz();
	}
	return is;*/
}

ostream & operator<<(ostream & os, const Diccionario &D)
{
	string pal;
	//ArbolGeneral<info> *n = &(D.datos);

	while(!D.datos.etiqueta.final)
	{
		n=n
	}
}

Diccionario::iterator::iterator(){/*No hace nada, ya se construye con el constructor por defecto*/}

string Diccionario::iterator::operator*(){
	return pal;
}

Diccionario::iterator & Diccionario::iterator::operator++(){
	
	while((*it).final == false && it!=datos.end()){
		pal.push_back((*it).c);
		++it;
	}
	++it;

	return *this;
}

bool Diccionario::iterator::operator==(const iterator &i){
	return it == i.it;
}
bool Diccionario::iterator::operator!=(const iterator &i){
	return it != i.it;
}

Diccionario::iterator Diccionario::begin(){}
Diccionario::iterator Diccionario::end(){}
