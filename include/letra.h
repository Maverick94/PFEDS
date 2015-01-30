#ifndef __Letra_h__
#define __Letra_h__


class Letra{
	private:
		char letra;
		int n_veces;
		int puntuacion;

	public:

		Letra(){
			letra = '\0';
			n_veces = 0;
			puntuacion = 0;
		}

		char getLetra() const{return letra;}	

		void setLetra(char le){letra=le;}

		void setPuntuacion(int punt){puntuacion=punt;}

		int getNVeces(){return n_veces;}

		//void incrementa_n_veces(){n_veces++;}

		void setNVeces(int nVeces){n_veces=nVeces;}

		int getPuntuacion(){return puntuacion;}

		bool operator<(Letra& b){return (letra<b.letra);}

		friend ostream& operator<<(ostream& os,Letra& l);

};

ostream& operator<<(ostream& os,Letra& l){
	os<<"LETRA: "<<l.letra<<" PUNTUACION: "<<l.puntuacion;
	//os<<"LETRA: "<<l.letra<<" CANTIDAD: "<<l.n_veces<<" PUNTUACION: "<<l.puntuacion;
	//os<<"--"<<l.letra<<"--";
}

#endif
