#ifndef __Diccionario_h__
#define __Diccionario_h__

#include <iostream>
#include "letra.h"
#include <set>

using namespace std;

class Conjuto_letras
{
	private:
		set<letra> conjletras;

	public:

		/**
		@brief Construye un conjunto de letras vacio
		**/

		Conjuto_letras();

		/**
		@brief Construye un conjuto de letras con la letra que se le pase
		@param l: letra que se pasa
		**/

		Conjuto_letras(letra l);

		/**
		@brief Inserta una letra en el conjunto
		@param l: Letra que se inserta
		**/

		void InsertarLetra(letra l);

		/**
		@brief Devuelve el conjuto del TDA Conjuto_Letras
		@return devuelve el conjuto
		**/

		set <letra> & getConjunto();

		/**
		@brief Muestra todas las letras del conjunto una a una.
	
		**/

		//void MostrarConjuto();
		friend ostream& operator<<(ostream& os, Conjunto_letras& cl);



};

#include "Conjunto_letras.cpp"

#endif