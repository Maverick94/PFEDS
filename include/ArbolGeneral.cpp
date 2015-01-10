#include <iostream>

using namespace std;

//Procedimientos Privados

template <class Tbase>

void ArbolGeneral<Tbase>::destruir(nodo * n)
{
	if(n != 0)
	{
		destruir(n->izqda);
		destruir(n->drcha);

		delete n;
	}
}

template <class Tbase>

void ArbolGeneral<Tbase>::copiar(nodo *& dest, nodo * orig)
{
	if(orig == 0)
	{
		dest=0;
	}
	else
	{
		dest = new nodo (orig->etiqueta);
		copiar(orig->izqda, dest->izqda);
		copiar(orig->drcha, dest->drcha);

		if(dest->izqda != 0)
			dest->izqda->padre = dest;

		if(dest->drcha != 0)
			dest->drcha->padre = dest->padre;
	}
}

template <class ArbolGeneral>

int ArbolGeneral<Tbase>::contar(const nodo * n) const
{
	int cuenta_nodos = 0;
	
	if(n != 0)
		cuenta_nodos = 1 + contar(n->izqda) + contar(n->drcha);
	

	return cuenta_nodos;
}

template <class ArbolGeneral>

bool ArbolGeneral<Tbase>::soniguales(const nodo * n1, const nodo * n2) const
{
	bool iguales = true;

	if(n1 == 0 && n2 != 0 || n2 == 0 && n1 != 0)
		iguales = false;

	else if(n1 != 0 && n2 != 0)
	{
		if(n1->etiqueta != n2->etiqueta)
			iguales = false;
		else
		{	
			iguales = soniguales(n1->izqda,n2->izqda) && soniguales(n1->drcha,n2->drcha);
		}
	}

	return iguales;
}



//Métodos públicos

template <class Tbase>

void ArboGeneral<Tbase>::podar_hijomasizquierda(Nodo n, ArbolGeneral<Tbase>& dest)
{
	
}