#ifndef __Letra_h__
#define __Letra_h__


class Letra
{
	private:
		char letra;
		int n_veces;
		int puntuacion;

	public:

		Letra()
		{
			letra = '\0';
			n_veces = 0;
			puntuacion = 0;
		}
		char getLetra() const
		{
			return letra;
		}	

		void setLetra(char letra)
		{
			this->letra=letra;
		}

		int getN_veces()
		{
			return n_veces;
		}

		void incrementa_n_veces()
		{
			n_veces++;
		}

		int getPuntuacion()
		{
			return puntuacion;
		}

		bool operator<(Letra& b){
			return (letra<b.letra);
		}

};

#endif
