#ifndef __ArbolGeneral_cpp__
#define __ArbolGeneral_cpp__


/*
 * FUNCIONES TDA ARBOL GENERAL
 */

template <class TBase>
void ArbolGeneral<TBase>::destruir(nodo * n) {
  if(n != 0){
		destruir(n->izqda);
		destruir(n->drcha);
		delete n;
	}
}


template <class TBase>
void ArbolGeneral<TBase>::copiar(nodo*& dest, nodo* orig) {
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

template <class TBase>
int ArbolGeneral<TBase>::contar(const nodo* n) const {
  int cuenta_nodos = 0;
	if(n != 0)
		cuenta_nodos = 1 + contar(n->izqda) + contar(n->drcha);
	return cuenta_nodos;
}

template <class TBase>
bool ArbolGeneral<TBase>::soniguales(const nodo* n1, const nodo* n2) const {
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

template <class TBase>
void ArbolGeneral<TBase>::escribeArbol(std::ostream& out, nodo* nod) const {
  if(nod == 0)
		out << "x ";
	else{
		out<<"n" << nod->etiqueta<<" ";
		escribe_arbol(out,nod->izqda);
		escribe_arbol(out,nod->drcha);
	}
}


// Soluci´on no recursiva
template <class TBase>
void ArbolGeneral<TBase>::leeArbol(std::istream& in, nodo*& nod) {
  destruir(nod);
	char c;
	TBase etq;
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

template <class TBase>
ArbolGeneral<TBase>::ArbolGeneral() {
  laraiz= new nodo;
	//laraiz=0;
}

template <class TBase>
ArbolGeneral<TBase>::ArbolGeneral(const TBase& e) {
  	laraiz=new nodo;
	laraiz->etiqueta=e;
	laraiz->padre=laraiz->izqda=laraiz->drcha=0;
}

template <class TBase>
ArbolGeneral<TBase>::ArbolGeneral (const ArbolGeneral<TBase>& v) {
  //copiar(v);
  copiar(laraiz, v.laraiz);
}

template <class TBase>
ArbolGeneral<TBase>::~ArbolGeneral() {
  //destruir(laraiz);
	clear();
}

template <class TBase>
ArbolGeneral<TBase>& ArbolGeneral<TBase>::operator= (const ArbolGeneral<TBase> &v) {
  if(this != &v){
		clear();
		copiar(laraiz,v.raiz());
	}
	return *this;
}

template <class TBase>
void ArbolGeneral<TBase>::asignaRaiz(const TBase& e) {
  laraiz->etiqueta=e;
}

template <class TBase>
typename ArbolGeneral<TBase>::Nodo& ArbolGeneral<TBase>::raiz() {
  return laraiz;
}
template <class TBase>
typename ArbolGeneral<TBase>::Nodo& ArbolGeneral<TBase>::hijoMasIzquierda(const Nodo n) const {
  return n->izqda;
}
template <class TBase>
typename ArbolGeneral<TBase>::Nodo& ArbolGeneral<TBase>::hermanoDerecha(const Nodo n) const {
  return n->drcha;
}
template <class TBase>
typename ArbolGeneral<TBase>::Nodo& ArbolGeneral<TBase>::padre(const Nodo n) const {
  return n->padre;
}

template <class TBase>
TBase& ArbolGeneral<TBase>::etiqueta(const Nodo n) {
  return n->etiqueta;
}
template <class TBase>
const TBase& ArbolGeneral<TBase>::etiqueta(const Nodo n) const {
  return n->etiqueta;
}


template <class TBase>
void ArbolGeneral<TBase>::asignarSubarbol(const ArbolGeneral<TBase>& orig, const Nodo nod) {
  clear();
  	copiar(laraiz,nod);
  	if (laraiz!=0)
    	laraiz->padre=0;
}


template <class TBase>
void ArbolGeneral<TBase>::podarHijoMasIzquierda(Nodo n, ArbolGeneral<TBase>& dest) {
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


template <class TBase>
void ArbolGeneral<TBase>::podarHermanoDerecha(Nodo n, ArbolGeneral<TBase>& dest) {
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


template <class TBase>
void ArbolGeneral<TBase>::insertarHijoMasIzquierda(Nodo n, ArbolGeneral<TBase>& rama) {
  assert(n!=0);
  /*nodo* tmp= n->izq;
  n->izq= 0;
  copiar(n->izq, rama.laraiz);
  n->izq->der= tmp;*/
	if(n->izqda != 0)
		rama.laraiz->drcha=n->izqda;
	n->izqda=rama.laraiz;
	rama.laraiz->padre=n;
}


template <class TBase>
void ArbolGeneral<TBase>::insertarHermanoDerecha(Nodo n, ArbolGeneral<TBase>& rama) {
  assert(n!=0);
  /*nodo* tmp= n->der;
  n->der= 0;
  copiar(n->der, rama.laraiz);
  n->der->der= tmp;*/
	if(n->drcha != 0) 
		rama.laraiz->drcha = n->drcha;
	rama.laraiz->padre = n->padre; 
	n->drcha = rama.laraiz;
}


template <class TBase>
bool ArbolGeneral<TBase>::hijoConEtiqueta(Nodo padre, TBase& e, nodo*& hijo) const {
  bool encontrado= false;

  hijo= padre->izqda;  
  if (!hijo)
    return false;

  while (true) {
    if (hijo->etiqueta==e) {
      encontrado= true;
      break;
    }

    if (hijo->drcha)
        hijo= hijo->drcha;
    else
      break;
  }
  return encontrado;
}


template <class TBase>
void ArbolGeneral<TBase>::clear() {
 	destruir(laraiz);
	laraiz=0;
}

template <class TBase>
int ArbolGeneral<TBase>::size() const {
  return contar(laraiz);
}

template <class TBase>
bool ArbolGeneral<TBase>::empty() const {
  return laraiz==0;
}

template <class TBase>
bool ArbolGeneral<TBase>::operator == (const ArbolGeneral<TBase>& v) const {
  return soniguales(laraiz,v.laraiz);
}

template <class TBase>
bool ArbolGeneral<TBase>::operator != (const ArbolGeneral<TBase>& v) const {
 return !soniguales(laraiz,v.laraiz);
}

template<class T> 
std::istream& operator>>(std::istream& in, ArbolGeneral<T>& v) {
 	v.lee_arbol(in,v.laraiz);
	return in;
}
template<class T>
std::ostream& operator<< (std::ostream& out, const ArbolGeneral<T>& v) {
	v.escribe_arbol(out,v.laraiz);
 	return out;
}


/*
 * FUNCIONES ITERADOR PREORDEN DEL TDA ARBOL GENERAL
 */

template <class TBase>
ArbolGeneral<TBase>::iter_preorden::iter_preorden() {
	it = raiz = 0;//laraiz;
	level = 0;
}

template <class TBase>
TBase& ArbolGeneral<TBase>::iter_preorden::operator*() {
  return it->etiqueta;
}

template <class TBase>
int ArbolGeneral<TBase>::iter_preorden::getlevel() const {
  return level;
}

template <class TBase>
typename ArbolGeneral<TBase>::iter_preorden& ArbolGeneral<TBase>::iter_preorden::operator++() {
	if (it->izqda) {
    it= it->izqda;
    level++;
  }
  else if (it->drcha)
    it= it->drcha;
  else {
    bool encontrado= false;
    while(!encontrado && it!=0) {
      it= it->padre;
      level--;
      if (!it)
        break;
      if (it->drcha) {
        it= it->drcha;
        encontrado= true;
      }
    }
  }
  return *this;
	/*if(it->izqda!=0){
		it=it->izqda;
		level++;
	}else if(it->drcha!=0){
		it=it->drcha;
	}else{
		it=it->padre;
		level--;
		it=it->drcha;
	}
	return *this;*/
}

template <class TBase>
bool ArbolGeneral<TBase>::iter_preorden::operator==(const iter_preorden &i) {
	bool iguales = true;
	if(raiz != i.raiz || it != i.it)
		iguales = false;
	return iguales;
}

template <class TBase>
bool ArbolGeneral<TBase>::iter_preorden::operator!=(const iter_preorden &i) {
  return !(*this==i);
}

template <class TBase>
typename ArbolGeneral<TBase>::iter_preorden ArbolGeneral<TBase>::begin() {
  iter_preorden i;
  i.raiz= laraiz;
  i.it= laraiz;
  i.level= 0;
  return i;
}

template <class TBase>
typename ArbolGeneral<TBase>::iter_preorden ArbolGeneral<TBase>::end() {
  	iter_preorden it;
	it.it=it.raiz=laraiz;
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
    /*iter_preorden i;
  	i.raiz= laraiz;
  	i.it= 0;
  	i.level= -1;
  	return i;*/
}


/*
 * FUNCIONES ITERADOR PREORDEN CONSTANTE DEL TDA ARBOL GENERAL
 */

template <class TBase>
ArbolGeneral<TBase>::const_iter_preorden::const_iter_preorden(){
	it=raiz=0;
	level=0;
}

template <class TBase>
const TBase & ArbolGeneral<TBase>::const_iter_preorden::operator*()
{
	return it->etiqueta;
}

template <class TBase>
int ArbolGeneral<TBase>::const_iter_preorden::getlevel()const
{
	return level;
}

template <class TBase>
typename ArbolGeneral<TBase>::const_iter_preorden & ArbolGeneral<TBase>::const_iter_preorden::operator ++()
{
	if (it->izqda) {
    it= it->izqda;
    level++;
  }
  else if (it->drcha)
    it= it->drcha;
  else {
    bool encontrado= false;
    while(!encontrado) {
      it= it->padre;
      level--;
      if (!it)
        break;
      if (it->drcha) {
        it= it->drcha;
        encontrado= true;
      }
    }
  }
  return *this;
	/*if(it->izqda!=0)//Recorrido preorder
	{
		it=it->izqda;
		level++;
	}
	else if(it->drcha!=0)
	{
		it=it->drcha;
	}
	else
	{
		it=it->padre;
		level--;
		it=it->drcha;
	}

	return *this;*/
}

template <class TBase>
bool ArbolGeneral<TBase>::const_iter_preorden::operator == (const const_iter_preorden &i)
{
	bool iguales = true;

	if(raiz != i.raiz || it != i.it)
		iguales = false;

	return iguales;
}

template <class TBase>
bool ArbolGeneral<TBase>::const_iter_preorden::operator != (const const_iter_preorden &i)
{
	return !(*this==i);
}

template <class TBase>
typename ArbolGeneral<TBase>::const_iter_preorden ArbolGeneral<TBase>::begin()const{
	const_iter_preorden it;
	it.it = it.raiz = laraiz;
	return it;
}

template <class TBase>
typename ArbolGeneral<TBase>::const_iter_preorden ArbolGeneral<TBase>::end()const{
	const_iter_preorden it;
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
    /*const_iter_preorden i;
  	i.raiz= laraiz;
  	i.it= 0;
  	i.level= -1;
  	return i;*/
}




















#endif