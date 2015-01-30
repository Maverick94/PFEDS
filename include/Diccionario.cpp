#include <iostream>
#include <algorithm>

using namespace std;


Diccionario::Diccionario(){
	ArbolGeneral<info>::Nodo raiz;
	raiz= datos.raiz();
	raiz->etiqueta.c= '\0';
	raiz->etiqueta.final= false;
}

int Diccionario::size()const{
	ArbolGeneral<info>::const_iter_preorden it;
	int numero= 0;
	for (it=datos.begin(); it!=datos.end(); ++it)
    	if ((*it).final)
    		numero++;
  	return numero;
	/*int cont=0;
	ArbolGeneral<info>::const_iter_preorden it;
	for(it=datos.begin();it!=datos.end();++it){
		if( (*it).final )
			cont++;
	}
	return cont;*/
}

vector<string> Diccionario::PalabrasLongitud(int longitud){
	vector<string>* v= new vector<string>();
	ArbolGeneral<info>::iter_preorden it;
	for (it=datos.begin(); it!=datos.end(); ++it)
    	if (it.getlevel()==longitud)
      		if ((*it).final) {
        		string cadena;
        		ArbolGeneral<info>::nodo* pos= it.it;
        		while(pos!=datos.raiz()) {
          			char letra= pos->etiqueta.c;
          			cadena= letra + cadena;
          			pos= pos->padre;
        		}
        		v->push_back(cadena);
      		}
  return *v;
	/*vector<string> palabras;
	ArbolGeneral<info>::iter_preorden it;
	int contador=0;
	string palabra;

	it = datos.begin();
	
	while((*it).final != true && true){}*/
}


info& info::operator=(info& otro) {
  c=otro.c;
  final=otro.final;
  return *this;
}

bool operator==(info& a, info& b) {
  if (a.c==b.c)// && a.final==b.final) No es necesario que coincidan en que sean finales.
    return true;
  return false;
}

bool operator>(info& a, info& b) {
  if (a.c>b.c)// && a.final==b.final) No es necesario que coincidan en que sean finales.
    return true;
  return false;
}

/*bool operator<(info& a, info& b) {
  if (a.c<b.c)// && a.final==b.final) No es necesario que coincidan en que sean finales.
    return true;
  return false;
}*/


bool Diccionario::Esta(string palabra){
	ArbolGeneral<info>::nodo* pos= datos.raiz();
  	char letra;
  	info etiqueta;
  	for (int i=0; i<palabra.length(); i++) {
    	letra= palabra.at(i);
    	etiqueta.c= letra;
    	etiqueta.final= (i==(palabra.length()-1));
    	ArbolGeneral<info>::nodo* nuevaPos;
    	if (!datos.hijoConEtiqueta(pos, etiqueta, nuevaPos))
      		return false;
    	else
    		pos= nuevaPos;
  	}
  	if (pos->etiqueta.final)
    	return true;
  return false;
}

istream & operator>>(istream & is,Diccionario &D){
	while(is) {
	    string palabra;
	    getline(is, palabra, '\n');
	    ArbolGeneral<info>::nodo* pos= D.datos.raiz();

	    for (int i=0; i<palabra.length(); i++) {

	      // Preparamos la etiqueta para la siguiente letra
	      
	      char letra= palabra.at(i);
	      info etiqueta;
	      etiqueta.c= letra;
	      etiqueta.final= (i==(palabra.length()-1));
	      ArbolGeneral<info>::nodo* nuevaPos= 0;

	      // Buscamos la siguiente letra entre los hijos del nodo pos.

	      // Comprobamos que tenga hijos.
	      if (pos->izqda) {
	        // Si es as´i, buscamos un nodo con la etiqueta que nos interesa.

	        // Si lo encontramos, seguimos buscando la siguiente letra desde ese nodo.
	        if (D.datos.hijoConEtiqueta(pos, etiqueta, nuevaPos))
	          pos= nuevaPos;
	        
	        // Si no lo encontramos, creamos un nuevo nodo y lo ponemos como la posici´on actual.
	        else {
	          nuevaPos->drcha= new ArbolGeneral<info>::nodo();
	          nuevaPos= nuevaPos->drcha;
	          
	          nuevaPos->etiqueta= etiqueta;
	          nuevaPos->izqda= 0;
	          nuevaPos->drcha= 0;
	          nuevaPos->padre= pos;

	          pos = nuevaPos;
	        }
	      }
	      // Si no tiene hijos, entonces creamos uno nuevo
	      else {
	        pos->izqda= new ArbolGeneral<info>::nodo();
	        
	        pos->izqda->etiqueta= etiqueta;
	        pos->izqda->izqda= 0;
	        pos->izqda->drcha= 0;
	        pos->izqda->padre= pos;

	        pos= pos->izqda;
	      }

	    } // for (cada letra)

    } // while (cada palabra)
    
	//Diccionario::iterator * pos=&(D.datos.raiz());
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

ostream & operator<<(ostream & os, Diccionario &D){
	ArbolGeneral<info>::iter_preorden it;
	for (it=D.datos.begin(); it!=D.datos.end(); ++it) {
	    if ((*it).final) {
			string cadena;
			ArbolGeneral<info>::nodo* pos= it.it;
			while(pos!=D.datos.raiz()) {
	        	char letra= pos->etiqueta.c;
	        	cadena= letra + cadena;
	        	pos= pos->padre;
	      	}
	      	os << cadena << ", ";
	    }
  	}
  	return os;
}

void Diccionario::palabrasConEstasLetras(ArbolGeneral<info>::nodo* desde, vector<Letra> letras, vector<string>& palabras){
	if(!desde)
		return;
	for(int i=0;i<letras.size();i++){
		//for(int j=0;j<letras.at(i).getNVeces();j++){
			char letra=letras.at(i).getLetra();
			ArbolGeneral<info>::nodo* hijo;
			info l(letra,false);
			if(datos.hijoConEtiqueta(desde,l,hijo)){
				if(hijo->etiqueta.final){
					string plb=formarPalabraDesde(hijo);
					if( find(palabras.begin(),palabras.end(),plb)==palabras.end() ){
						palabras.push_back(formarPalabraDesde(hijo));
					}
				}
				vector<Letra> subletras(letras);
				subletras.erase(subletras.begin()+i);
				palabrasConEstasLetras(hijo,subletras,palabras);
			}
		//}
	}
}

string Diccionario::formarPalabraDesde(ArbolGeneral<info>::nodo* desde){
	string palabra ="";
	while(desde->padre){
		palabra=desde->etiqueta.c+palabra;
		desde=desde->padre;
	}
	return palabra;
}

int Diccionario::calcularPuntuacion(string palabra,Bolsa_Letras& bl){
	int puntuacion=0;
	for(int i=0;i<palabra.size();i++){
		puntuacion=puntuacion+bl.getPuntuacion(palabra.at(i));
	}
	return puntuacion;
}

Diccionario::iterator::iterator(){/*No hace nada, ya se construye con el constructor por defecto*/}

string Diccionario::iterator::operator*(){
	return cad;
}

Diccionario::iterator & Diccionario::iterator::operator++(){
	
	while((*it).final == false){
		cad.push_back((*it).c);
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