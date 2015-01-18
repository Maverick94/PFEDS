#include <iostream>

using namespace std;

//Procedimientos Privados

template <class Tbase>

void ArbolGeneral<Tbase>::destruir(nodo *n){
	if(n != 0){
		destruir(n->izqda);
		destruir(n->drcha);
		delete n;
	}
}

template <class Tbase>

void ArbolGeneral<Tbase>::copiar(nodo *& dest, nodo * orig){
	if(orig == 0){
		dest=0;
	}
	else{
		dest = new nodo;
		dest->etiqueta = orig->etiqueta;
		copiar(dest->izqda, orig->izqda);
		copiar(dest->drcha, orig->drcha);

		if(dest->izqda != 0)
			dest->izqda->padre = dest;

		if(dest->drcha != 0)
			dest->drcha->padre = dest->padre;
	}
}

template <class Tbase>

int ArbolGeneral<Tbase>::contar(const nodo * n) const{
	int cuenta_nodos = 0;
	if(n != 0)
		cuenta_nodos = 1 + contar(n->izqda) + contar(n->drcha);
	return cuenta_nodos;
}

template <class Tbase>
bool ArbolGeneral<Tbase>::soniguales(const nodo * n1, const nodo * n2) const{
	bool iguales = true;
	if(n1 == 0 && n2 != 0 || n2 == 0 && n1 != 0)
		iguales = false;
	else if(n1 != 0 && n2 != 0){
		if(n1->etiqueta != n2->etiqueta)
			iguales = false;
		else
			iguales = soniguales(n1->izqda,n2->izqda) && soniguales(n1->drcha,n2->drcha);
	}
	return iguales;
}


template <class Tbase>
void ArbolGeneral<Tbase>::escribe_arbol(std::ostream& out, nodo * nod) const{
	if(nod == 0)
		out << "x ";
	else{
		out<<"n" << nod->etiqueta<<" ";
		escribe_arbol(out,nod->izqda);
		escribe_arbol(out,nod->drcha);
	}
}

template <class Tbase>
void ArbolGeneral<Tbase>::lee_arbol(std::istream& in, nodo *& nod){
	destruir(nod);
	char c;
	Tbase etq;
	if(in){
		in >> c;
		if(c=='x')
			nod=0;
		else{
			nod = new nodo;
			in  >> etq;
			//cout << "Leido etiqueta '"<< etq<<"'" << endl;
			nod -> etiqueta = etq;
			nod->izqda = 0;
			nod->drcha = 0;
			if(c != 'x'){
				lee_arbol(in,nod->izqda);
				if(nod->izqda)
					nod->izqda->padre = nod;
			}

			if(c != 'x'){
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
ArbolGeneral<Tbase>::~ArbolGeneral(){
	destruir(laraiz);
}

template <class Tbase>
ArbolGeneral<Tbase>& ArbolGeneral<Tbase>::operator = (const ArbolGeneral<Tbase> &v){
	if(this != &v){
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
	destruir(laraiz);
  	copiar(laraiz,nod);
  	if (laraiz!=0){
    	laraiz->padre=0;
    }
}

template <class Tbase>
void ArbolGeneral<Tbase>::podar_hijomasizquierda(Nodo n, ArbolGeneral<Tbase>& dest){
	assert(n!=0);
	destruir(dest.laraiz);
	dest.laraiz = n->izqda;
	if(dest.laraiz != 0){
		if(n->izqda->drcha != 0){
			n->izqda = dest.laraiz->drcha;
			dest.laraiz->drcha = 0;
		}
		else
			n->izqda = 0;
		dest.laraiz->padre = 0;
	}
}

template <class Tbase>
void ArbolGeneral<Tbase>::podar_hermanoderecha(Nodo n, ArbolGeneral<Tbase>& dest){
	assert(n!=0);
	destruir(dest.laraiz);
	dest.laraiz = n -> drcha;
	if(dest.laraiz->drcha != 0){
		n->drcha = dest.laraiz->drcha;
		dest.laraiz->drcha = 0;
	}
	else
		n->drcha = 0;
	dest.laraiz->padre = 0;
}

template <class Tbase>
void ArbolGeneral<Tbase>::insertar_hijomasizquierda(Nodo n, ArbolGeneral<Tbase>& rama){
	assert(n!=0);
	if(n->izqda != 0)
		rama.laraiz->drcha=n->izqda;
	n->izqda=rama.laraiz;
	rama.laraiz->padre=n;
}	

template <class Tbase>
void ArbolGeneral<Tbase>::insertar_hermanoderecha(Nodo n, ArbolGeneral<Tbase>& rama){
	assert(n!=0);

	if(n->drcha != 0) 
		rama.laraiz->drcha = n->drcha;
	rama.laraiz->padre = n->padre; 
	n->drcha = rama.laraiz;
}

template <class Tbase>
void ArbolGeneral<Tbase>::clear(){
	destruir(laraiz);
	laraiz=0;
}

template <class Tbase>
int ArbolGeneral<Tbase>::size() const{
	return contar(laraiz);
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
/*END PUBLIC*/

/*FUERA DE LA CLASE*/

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




				/*ITERADOR NO CONSTANTE*/

				template <class Tbase>
				ArbolGeneral<Tbase>::iter_preorden::iter_preorden(){
					it = raiz = 0;//laraiz;
					level = 0;
				}

				template <class Tbase>
				Tbase & ArbolGeneral<Tbase>::iter_preorden::operator*(){
					return it->etiqueta;
				}

				template <class Tbase>
				int ArbolGeneral<Tbase>::iter_preorden::getlevel()const{
					return level;
				}

				template <class Tbase>
				typename ArbolGeneral<Tbase>::iter_preorden & ArbolGeneral<Tbase>::iter_preorden::operator ++(){ //AQUI FALLA!!
					if(it->izqda!=0){
						it=it->izqda;
						level++;
					}
					else if(it->drcha!=0){
						it=it->drcha;
					}
					else{
						it=it->padre;
						level--;
						it=it->drcha;
					}
					return *this;
				}

				template <class Tbase>
				bool ArbolGeneral<Tbase>::iter_preorden::operator == (const iter_preorden &i){
					bool iguales = true;
					if(raiz != i.raiz || it != i.it)
						iguales = false;
					return iguales;
				}

				template <class Tbase>
				bool ArbolGeneral<Tbase>::iter_preorden::operator != (const iter_preorden &i){
					return !(*this==i);
				}






template <class Tbase>
typename ArbolGeneral<Tbase>::iter_preorden ArbolGeneral<Tbase>::begin(){
	iter_preorden it;
	it.it = it.raiz = laraiz;
	return it;
}

template <class Tbase>
typename ArbolGeneral<Tbase>::iter_preorden ArbolGeneral<Tbase>::end(){
	iter_preorden it;
	it.raiz=laraiz;
	it.it=it.raiz;
    while(it.it->izqda!=0){
        it.it=it.it->izqda;
        while(it.it->drcha!=0)
            it.it=it.it->drcha;
    }
    while(it.it->drcha!=0){
    	it.it=it.it->drcha;
    	while(it.it->izqda!=0)
    		it.it=it.it->izqda;
    }
    return it;
}

