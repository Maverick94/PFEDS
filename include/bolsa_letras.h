#ifndef __BLETRAS__
#define __BLETRAS__
#include <vector>
#include <fstream>
#include <set>
#include <algorithm>
#include "letra.h"
#include <ctype.h> //tolower



using namespace std;

class Bolsa_Letras{
	private:
		vector<Letra> letras;
	public:
		Bolsa_Letras(){}
		vector<Letra>& getBolsa(){return letras;}
		int getPuntuacion(char let){
			vector<Letra>::iterator it=letras.begin();
			for(it;it!=letras.end();++it){
				if( (*it).getLetra() == let ){
					return (*it).getPuntuacion();
				}
			}
			return 0;
		}
		Letra sacarLetra(){
			vector<Letra>::iterator it;
			do{
				int pos = rand()%letras.size(); //NUMERO entre 0 y size - 1
				it=letras.begin()+pos; //Ahora hay un iterador apuntando a la posicion pos
			}while((*it).getNVeces()<=0 && !vacia());
			Letra l;
			//if((*it).getNVeces()>0){ //Esa letra esta en la bolsa
			l.setLetra((*it).getLetra());
			l.setPuntuacion((*it).getPuntuacion());
			l.setNVeces(1);
			(*it).setNVeces( (*it).getNVeces()-1 );
			/*if((*it).getNVeces()==0){
				it=letras.erase(it);
			}*/
			return l;
		}
		bool vacia(){
			for(int i=0;i<letras.size();i++){
				if(letras.at(i).getNVeces()>0)
					return false;
			}
			return true;
		}
		friend istream& operator>>(istream& is,Bolsa_Letras& bl);
		friend ostream& operator<<(ostream& os,Bolsa_Letras& bl);
};

istream& operator>>(istream& is,Bolsa_Letras& bl){
	Letra le;
	char c;
	int p;
	string linea;
	getline(is,linea,'\n'); //Ignoro la primera linea
	while(is>>c){
		//cout<<"LETRA: "<<c<<" ";
		le.setLetra(tolower(c));
		is>>p;
		//cout<<"CANTIDAD: "<<p<<" ";
		le.setNVeces(p);
		is>>p;
		//cout<<"PUNTUACION: "<<p<<" ";
		le.setPuntuacion(p);
		//cout<<endl;
		bl.letras.push_back(le);
	}
	random_shuffle(bl.getBolsa().begin(),bl.getBolsa().end());
	return is;
}

ostream& operator<<(ostream& os,Bolsa_Letras& bl){
	for(int i=0;i<bl.letras.size();i++){
		os<<bl.letras.at(i)<<endl;
	}
	return os;
}

#endif