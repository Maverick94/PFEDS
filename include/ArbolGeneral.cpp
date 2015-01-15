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

template <class Tbase>

int ArbolGeneral<Tbase>::contar(const nodo * n) const
{
	int cuenta_nodos = 0;
	
	if(n != 0)
		cuenta_nodos = 1 + contar(n->izqda) + contar(n->drcha);
	

	return cuenta_nodos;
}

template <class Tbase>

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


template <class Tbase>
void ArbolGeneral<Tbase>::escribe_arbol(std::ostream& out, nodo * nod) const 	//Codificado por Andrés
{
	if(nod == 0)
		out << "x ";
	else
	{
		out<<"n" << nod->etiqueta<<" ";
		escribe_arbol(out,nod->izqda);
		escribe_arbol(out,nod->drcha);
	}

	/*Creo que está bien pero no estoy muy seguro*/
	/*En el bintree de Rosa hace algo parecido... Pero mete las letras con una variable char y nosotros lo estamos
	haciendo con las dobles comillas que se interpretan como un string */
}

template <class Tbase>
void ArbolGeneral<Tbase>::lee_arbol(std::istream& in, nodo *& nod)
{
	destruir(nod);

	char c;
	Tbase etq;

	if(in)
	{
		//cout << "Comprobamos si es nodo nulo o lleno" << endl;
		in >> c;
		//cout << "1º Lee el siguiente caracter '" << c << "'" << endl;
		if(c=='x')
		{
			nod=0;
		}
		else
		{
			nod = new nodo;
			in  >> etq;
			//cout << "Leido etiqueta '"<< etq<<"'" << endl;
			nod -> etiqueta = etq;
			nod->izqda = 0;
			nod->drcha = 0;

			if(c != 'x')
			{
				lee_arbol(in,nod->izqda);
				if(nod->izqda)
					nod->izqda->padre = nod;
			}

			if(c != 'x')
			{
				lee_arbol(in,nod->drcha);
				if(nod->drcha)
					nod->drcha->padre = nod;
			}
		}
	}
}

/*FIN PRIVATE*/

/*PUBLIC*/
template <class Tbase>
ArbolGeneral<Tbase>::ArbolGeneral() : laraiz(0){/*El constructor por defecto no hace nada*/}

template <class Tbase>
ArbolGeneral<Tbase>::ArbolGeneral(const Tbase& e){
	laraiz=new nodo;
	laraiz->etiqueta=e;
	laraiz->padre=laraiz->izqda=laraiz->drcha=0;
}

template <class Tbase>
ArbolGeneral<Tbase>::ArbolGeneral (const ArbolGeneral<Tbase>& v){ 
	copiar(v);
}

template <class Tbase>
ArbolGeneral<Tbase>::~ArbolGeneral()
{
	destruir(laraiz);
}

template <class Tbase>
ArbolGeneral<Tbase>& ArbolGeneral<Tbase>::operator = (const ArbolGeneral<Tbase> &v)	//Codificado por Andrés
{
	if(this != &v)
	{
		destruir(laraiz);
		copiar(laraiz,v.raiz());
	}
	
	return *this;
}

template <class Tbase>
void ArbolGeneral<Tbase>::AsignaRaiz(const Tbase& e){
	laraiz->etiqueta=e;
} 

template <class Tbase>
typename ArbolGeneral<Tbase>::Nodo ArbolGeneral<Tbase>::raiz() const{
	return laraiz;
}

template <class Tbase>
typename ArbolGeneral<Tbase>::Nodo ArbolGeneral<Tbase>::hijomasizquierda(const Nodo n) const{
	return n->izqda;
}

template <class Tbase>
typename ArbolGeneral<Tbase>::Nodo ArbolGeneral<Tbase>::hermanoderecha(const Nodo n) const{
	return n->drcha;
}

template <class Tbase>
typename ArbolGeneral<Tbase>::Nodo ArbolGeneral<Tbase>::padre(const Nodo n) const{
	return n->padre;
}

template <class Tbase>
Tbase& ArbolGeneral<Tbase>::etiqueta(const Nodo n){
	return n->etiqueta;
}

template <class Tbase>
const Tbase& ArbolGeneral<Tbase>::etiqueta(const Nodo n) const{
	return n->etiqueta;
}

template <class Tbase>
void ArbolGeneral<Tbase>::asignar_subarbol(const ArbolGeneral<Tbase>& orig, const Nodo nod){
	//VACIO
}

template <class Tbase>
void ArbolGeneral<Tbase>::podar_hijomasizquierda(Nodo n, ArbolGeneral<Tbase>& dest)		//Codificado por Andrés
{
	assert(n!=0); //El nodo tiene que apuntar apuntar a algo.
	destruir(dest.laraiz); 	//Nos aseguramos de que en el arbol donde vamos a meter la rama esté vacio.
	dest.laraiz = n->izqda; //hacemos que la nueva raiz sea el hijo de la izquierda de n.

	if(dest.laraiz != 0) //Si la raiz no es nula
	{
		
		if(n->izqda->drcha != 0) 	//Con esto hacemos que si exitiera un hermano a la derecha, pasa a ser el nuevo hijo a la izquierda 
		{
			n->izqda = dest.laraiz->drcha;
			dest.laraiz->drcha = 0;
		}
		else	//Si no existe un hermano a la derecha, simplemente desvinculamos el hijo de la izquierda.
			n->izqda = 0;

		dest.laraiz->padre = 0;	//Con esto, podamos totalmente la raiz. De total forma que ahora pasa a ser el padre.  
		
		// Con esto, estamos desvinculando la rama del arbol orginal y guardandola en el origen
	}

	
}

template <class Tbase>
void ArbolGeneral<Tbase>::podar_hermanoderecha(Nodo n, ArbolGeneral<Tbase>& dest)	//Codificado por Andrés
{
	assert(n!=0);
	destruir(dest.laraiz);
	dest.laraiz = n -> drcha; //hacemos que la nueva raiz sea el hermano de la derecha de n.

	if(dest.raiz->drcha != 0)	//si este tiene otro hermano a la derecha, el hermano de la izquierda apuntara al hermano de la derecha
	{
		n->drcha = dest.raiz->drcha;
		dest.raiz->drcha = 0;
	}
	else	//si no tiene hermano a la derecha, el hermano de la izquierda simplemente dejara de apuntarle.
		n->drcha = 0;

	dest.raiz->padre = 0;

}

template <class Tbase>
void ArbolGeneral<Tbase>::insertar_hijomasizquierda(Nodo n, ArbolGeneral<Tbase>& rama)   	//Codificado por Andrés
{
	assert(n!=0);

	if(n->izqda != 0)	//Si el nodo tiene hijo a la izquierda, este pasa a ser hermano a la derecha de la rama que insertamos
		rama.laraiz->drcha=n->izqda;
	
	n->izqda=rama.laraiz;	//Hijo a la izquierda de n pasa a ser la la raiz de la rama que insertamos.
	rama.laraiz->padre=n;	//Como deja de ser raiz, tiene que refenciar a un nuevo padre. En este caso n.

	//destruir(rama.laraiz);	//Destruimos la rama porque ya está insertada.
}

template <class Tbase>
void ArbolGeneral<Tbase>::insertar_hermanoderecha(Nodo n, ArbolGeneral<Tbase>& rama)	//Codificado por Andrés
{
	assert(n!=0);

	if(n->drcha != 0)	//Si el nodo que seleccionamos tiene un hermano a la derecha, cuando insertemos la nueva rama, esta tiene que ser hermano a la derecha 
		rama.laraiz->drcha = n->drcha;

	rama.laraiz->padre = n->padre; //Como deja de ser raiz, tiene que referenciar a un nuevo padre. En este caso n->padre.
	n->drcha = rama.laraiz;	//la rama pasa a ser hermano a la derecha de n.

	destruir(rama.laraiz);
}

template <class Tbase>
void ArbolGeneral<Tbase>::clear()	//Codificado por Andrés
{
	destruir(laraiz);
}

template <class Tbase>
int ArbolGeneral<Tbase>::size() const{
	
	int cont=1;

	if(laraiz==0)
		return 0;
	else{
		nodo *auxpadre=laraiz;
		nodo *aux;
		while(auxpadre!=0)		
			aux=auxpadre->izqda;			
			while(aux!=0){
				cont++;
				aux=aux->izda;			
			}
			auxpadre=auxpadre->izqda->drcha;			
		}
		return cont;
}

template <class Tbase>
bool ArbolGeneral<Tbase>::empty() const{
	return laraiz==0;
}

template <class Tbase>
bool ArbolGeneral<Tbase>::operator == (const ArbolGeneral<Tbase>& v) const{
	return soniguales(laraiz,v.laraiz);
}

template <class Tbase>
bool ArbolGeneral<Tbase>::operator != (const ArbolGeneral<Tbase>& v) const{
	return !soniguales(laraiz,v.laraiz);
}

template<class T> 
std::istream& operator>>(std::istream& in, ArbolGeneral<T>& v)
{
	v.lee_arbol(in,v.laraiz);
	return in;
}

template<class T>
std::ostream& operator<< (std::ostream& out, const ArbolGeneral<T>& v)
{
	v.escribe_arbol(out,v.laraiz);
 	return out;
}


/*END PUBLIC*/

/*FUERA DE LA CLASE*/
