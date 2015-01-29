#ifndef __Diccionario_h__
#define __Diccionario_h__

#include "ArbolGeneral.h"
#include <vector>
#include <string>
#include "letra.h"

struct info{
	char c; ///<< caracter que se almacena en un nodo
	bool final; ///< nos indica si es final o no de palabra
	
	info(){
		c='\0';
		final=false;
	}
	
	info(char car, bool f):c(car),final(f){}
	info& operator=(info& otro);
};

bool operator==(info& a, info& b);

class Diccionario{

	private:
		ArbolGeneral<info> datos;
		
		/*bool mi_esta(ArbolGeneral<info>::nodo* n,string palabra){
			ArbolGeneral<info>::iter_preorden it;
			it.it=n;
			it.raiz=datos.raiz();
			int index=0; bool encontrado=false;
			for(it;it!=datos.end() && encontrado==false;++it){
				if( (*it).c==palabra[index] ){
					encontrado=true;
					index++;
					string newstr=palabra.substr(index,palabra.size()-1);
					mi_esta( it.it->izqda, newstr);
				}
			}
			return encontrado;
		}*/

		//void Construir (ArbolGeneral<info>::nodo* nod, int longitud, string s);

	public:

		/**
		@brief Construye un diccionario vacío.
		**/
		Diccionario();

		/**
		@brief Devuelve el numero de palabras en el diccionario
		**/
		int size() const ;



		ArbolGeneral<info>& getArbol(){
			return datos;
		}

		/**
		@brief Obtiene todas las palabras en el diccionario de un longitud dada
		@param longitud: la longitud de las palabras de salida
		@return un vector con las palabras de
		longitud especifica en el parametro de entrada
		**/
		vector<string> PalabrasLongitud(int longitud);
		/**

		@brief Indica si una palabra está en el diccionario o no
		@param palabra: la palabra que se quiere buscar
		@return true si la palabra esta en el diccionario. False en caso contrario
		**/
		bool Esta(string palabra);
		
		/**
		@brief Lee de un flujo de entrada un diccionario
		@param is:flujo de entrada
		@param D: el objeto donde se realiza la lectura.
		@return el flujo de entrada
		**/
		friend istream & operator>>(istream & is,Diccionario &D);

		/**
		@brief Escribe en un flujo de salida un diccionario
		@param os:flujo de salida
		@param D: el objeto diccionario que se escribe
		@return el flujo de salida
		**/
		friend ostream & operator<<(ostream & os, Diccionario &D);

		void palabrasConEstasLetras(ArbolGeneral<info>::nodo* desde, vector<Letra> letras, vector<string>& palabras);

		string formarPalabraDesde(ArbolGeneral<info>::nodo* desde);

		class iterator{
			
			private:
			ArbolGeneral<info>::iter_preorden it;
			string cad; //mantiene los caracteres desde el nivel 1 hasta donde se encuentra it.
			
			public:
			iterator ();
			string operator *();
			iterator & operator ++();
			bool operator ==(const iterator &i);
			bool operator !=(const iterator &i);
			friend class Diccionario;
		};

		iterator begin();
		iterator end();
};
#include "Diccionario.cpp"
#endif