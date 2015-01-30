#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "Diccionario.h"
#include "bolsa_letras.h"
#include <stdlib.h>
#include <time.h>
//#include "Conjunto_letras.h"



int main(int argc, char * argv[]){
  srand(time(NULL));

  ifstream f(argv[1]); //ARGV[1]
  cout << "Cargando diccionario...." << endl;
  Diccionario D;
  f >> D;
  cout << "Leido el diccionario..." << endl;

  ifstream let(argv[2]);//ARGV[2]
  cout<<"Llenando la bolsa de letras...."<<endl;
  Bolsa_Letras bl;
  let>>bl;
  cout<<"La bolsa de letras esta llena."<<endl;
  if(argv[4][0]=='P') //Compruebo que estamos en modo puntuacion
    cout<<bl<<endl;

  bool rendirse=false;
  string solucion;
  char continuar;
  while(!rendirse){
    int letrasAleat=atoi(argv[3]); //ARGV[3]
    vector<Letra> letras;
    for(int i=0;i<letrasAleat;i++){
      letras.push_back(bl.sacarLetra());
    }

    cout<<"Tus letras: ";
    for(int i=0;i<letrasAleat;i++){
      cout<<letras.at(i).getLetra()<<"   ";
    }
    cout<<endl;

    //cout<<"Calculando las soluciones optimas...."<<endl;
    vector<string> palabras;
    D.palabrasConEstasLetras(D.getArbol().raiz(), letras, palabras);

    vector<string>::iterator it;
    int maximaLong=0,puntuacionActual=0,maximaPunt=0;
    vector<string> palMayorPuntuacion, palMayorLongitud;

    for (it=palabras.begin(); it!=palabras.end(); ++it){
      if( (*it).size()>maximaLong ){
        maximaLong=(*it).size();
      }
      puntuacionActual=D.calcularPuntuacion((*it),bl);
      if(puntuacionActual>maximaPunt){
        maximaPunt=puntuacionActual;
      }
      puntuacionActual=0;
    }

      //cout<<"La mayor es longitud es: "<<maximaLong<<" y la maxima puntuacion es: "<<maximaPunt<<endl;
      /*Ya tengo la mayor puntuacion y la mayor longitud en terminos numericos, ahora tengo que buscar todas las palabras que
      cumplan esas condiciones y meterlas en un vector.*/

    for(it=palabras.begin(); it!=palabras.end(); ++it){
        if( D.calcularPuntuacion( (*it),bl ) == maximaPunt ){
          palMayorPuntuacion.push_back( (*it) );
        }
        if( (*it).size()==maximaLong ){
          palMayorLongitud.push_back( (*it) );
        }
    }

      //cout<<"Soluciones calculadas."<<endl;


      /*cout<<"Palabras de mayor longitud: ";
      for(int i=0;i<palMayorLongitud.size();i++){
        cout<<palMayorLongitud.at(i)<<endl;
      }

      cout<<"Palabras de mayor puntuacion: ";
      for(int i=0;i<palMayorPuntuacion.size();i++){
        cout<<palMayorPuntuacion.at(i)<<endl;
      }*/
    
    
    cout<<"Dime tu solucion: ";
    cin>>solucion;

    bool encontrado=false;
    for(int i=0;i<palabras.size() && !encontrado;i++){
      if(palabras.at(i)==solucion){
        encontrado=true;
      }
    }


    if(!encontrado){
      cout<<"Tu palabra no existe"<<endl;
      do{
        cout<<"¿Quieres probar de nuevo? (S/N)";
        cin>>continuar;
        if(continuar=='S' || continuar=='s'){
          rendirse=false;
        }else if(continuar=='N' || continuar=='n'){
          rendirse=true;
        }else{
          cout<<"No te entiendo."<<endl;
        }
      }while(continuar!='S' && continuar!='N' && continuar!='s' && continuar!='n');
    




    /*ARGV[4] MODO DE JUEGO LONGITUD*/
    }else if(argv[4][0]=='L'){
      //Encontrado es true. Podemos utilizar esa misma variable para encontrar en el subconjunto de las palabras de mayor longitud
      encontrado=false;
      for(int j=0;j<palMayorLongitud.size() && !encontrado;j++){
        if(palMayorLongitud.at(j)==solucion){
          encontrado=true;
        }
      }
      if(encontrado){
        cout<<"Enhorabuena, has encontrado una de las palabras de mayor longitud."<<endl;
        rendirse=true;
      }else{
        cout<<"Tu palabra: "<<solucion<<". Longitud: "<<solucion.size()<<endl;
        cout<<"Mi(s) solucion(es): "<<endl;
        for(int k=0;k<palMayorLongitud.size();k++){
          cout<<palMayorLongitud.at(k)<<". Longitud: "<<palMayorLongitud.at(k).size()<<endl;
        }
        cout<<"¿Quieres probar de nuevo? (S/N)";
        cin>>continuar;
        do{
          if(continuar=='S' || continuar=='s'){
            rendirse=false;
          }else if(continuar=='N' || continuar=='n'){
            rendirse=true;
          }else{
            cout<<"No te entiendo."<<endl;
          }
        }while(continuar!='S' && continuar!='N' && continuar!='s' && continuar!='n');
      }
    



    /*ARGV[4] MODO DE JUEGO PUNTUACION*/
    }else if(argv[4][0]=='P'){

      encontrado=false;
      for(int j=0;j<palMayorPuntuacion.size() && !encontrado;j++){
        if(palMayorPuntuacion.at(j)==solucion){
          encontrado=true;
        }
      }
      if(encontrado){
        cout<<"Enhorabuena, has encontrado una de las palabras de mayor puntuacion."<<endl;
        rendirse=true;
      }else{
        cout<<"Tu palabra: "<<solucion<<". Puntuacion: "<<D.calcularPuntuacion(solucion,bl)<<endl;
        cout<<"Mi(s) solucion(es): "<<endl;
        for(int k=0;k<palMayorPuntuacion.size();k++){
          cout<<palMayorPuntuacion.at(k)<<". Puntuacion: "<<D.calcularPuntuacion(palMayorPuntuacion.at(k),bl)<<endl;
        }
        cout<<"¿Quieres probar de nuevo? (S/N)";
        cin>>continuar;
        do{
          if(continuar=='S' || continuar=='s'){
            rendirse=false;
          }else if(continuar=='N' || continuar=='n'){
            rendirse=true;
          }else{
            cout<<"No te entiendo."<<endl;
          }
        }while(continuar!='S' && continuar!='N' && continuar!='s' && continuar!='n');
      }
    


    /*ARGV[4] NO ES RECONOCIDO COMO MODO DE JUEGO*/
    }else{
      cerr<<argv[4]<<" no es un modo de juego.";
      return -1;
    }
  }
}


/*MAIN ORIGINAL DEL DICCIONARIO*/
/*
if (argc!=2){
  cout<<"Los parametros son:"<<endl;
  cout<<"1.- El fichero con las palabras";
  
  return 0;
  }
  
  ifstream f(argv[1]);
  info ii(' ', false);
  cout<<"Cargando diccionario...."<<endl;
  Diccionario D;
  f>>D;
  cout<<"Leido el diccionario..."<<endl;
  cout<<D;
  
  int longitud;
 
  cout<<"Dime la longitud de las palabras que quieres ver";
  cin>>longitud;
  vector<string> v=D.PalabrasLongitud(longitud);
  
  cout<<"Palabras de Longitud "<<longitud<<endl;
  for (unsigned int i=0;i<v.size();i++)
    cout<<v[i]<<endl;
 
 string p;
 cout<<"Dime una palabra: ";
 cin>>p;
 if (D.Esta(p)){
    cout<<"Sí esa palabra existe";
 }
 else
    cout<<"Esa palabra no existe";
*/