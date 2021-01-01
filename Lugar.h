/* Archivo: Lugar.h
  Autores: 

   alejandro zamorano Arango
   Email: alejandro.zamorano@correounivalle.edu.co

   juan david T. montoya 
   Email: juan.david.tovar@correounivalle.edu.co y 
   
   lina M. Rivas (rivas.lina@correounivalle.edu.co)


  Fecha creación: 2020-10-03
  Fecha última modificación: 2020-12-09
  Versión: 0.1
  Licencia: GNU-GPL
*/
/*
Clase: Lugar

Atributos:
   tripulantes :vector con punteros a Individuos
   numeroDeTripulantes: entero
   posicion: string
   maximoDeTrpulantes: intetero
   

Funcionalidades:

   -montar un individuo,  subir un ndividuo del lugar
   -bajar un individuo quitar un ndividuo del lugar
    buscar un individuo por su nombre 

  relaciones
   lugar conoce Individuos
*/



#ifndef LUGAR_H      // GUARDA
#define LUGAR_H      // GUARDA
#include <iostream>
#include <vector>
#include "Individuos.h"
#include<string>
using namespace std;
class Lugar
{
  protected:
    vector <Individuos*>  tripulantes; 
    int numeroDeTripulantes;
    string nombre;

    
  public:

    /**
     * @brief construye un lugar con nombre
     * @param nombre
     */
    Lugar(string nombre);

    /**
     * @brief ~Lugar destruye los objetos de los que es propietario
     */ 
    virtual ~Lugar();

    
     bool estaElIndividuo(string nombreDeIndividuo);
     bool recibirIndividuo(Individuos *personaje);
     Individuos *sacarIndividuo(string nombreDeIndividuo);
   
  
};

#else      // GUARDA
class Lugar; // Declaración adelantada      // GUARDA
#endif      // GUARDA