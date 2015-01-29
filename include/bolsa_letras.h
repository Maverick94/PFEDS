#ifndef __BLETRAS__
#define __BLETRAS__
#include <vector>
#include <fstream>
#include <set>
#include <algorithm>
#include "letra.h"

using namespace std;

class Bolsa_Letras{
	private:
		vector<Letra> letras;
	public:
		Bolsa_Letras(){}
		friend istream& operator>>(istream& is,Bolsa_Letras& bl);
		vector<Letra>& getBolsa(){return letras;}
};

istream& operator>>(istream& is,Bolsa_Letras& bl){
	Letra le;
	char c;
	while(is.get(c)){
		le.setLetra(c);
		bl.getBolsa().push_back(le);
	}
	random_shuffle(bl.getBolsa().begin(),bl.getBolsa().end());
	return is;
}

#endif