/* Archivo: Barca.h
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
#include <iostream>
using namespace std;

/*
  Clase: Barca
   Atributos:
     nombre string
     tripulantes :vector
     numeroDeTripulantes: entero
     posicion: string, derecha o izquierda
     maximoDeTrpulantes: int


Funcionalidades:
    -decir la posicion en la que está
    -montar un individuo
    -bajar un individuo 
    -moverse de izquierda a derecha y viseversa
    buscar un tripulante por su nombre 
 
relaciones:
  Barca es un lugar
  Barca contiene un vector de punteros a individuos
  Barca conoce indivuduos
  
*/



#ifndef BARCA_H      // GUARDA
#define BARCA_H      // GUARDA

#include "Lugar.h"

class Barca : public Lugar
{
  protected:
    
  int maximoDeTrpulantes;
  string posicion;

    
  public:
    /**
     * @brief construye una Barca con nombre y posicion inicial.
     * @param nombre
     * @param posicion
     */
    Barca(string nombre, string posicion);

    /**
     * @brief ~Barca destruye los objetos de los que es propietario
     */
    virtual ~Barca();

    /**
     * @brief recibirIndividuo recibe un paramentro de clase individuos
     * @param personaje
     * @return true si añadio el individuo y false si no añadio al individuo
     */
    virtual bool recibirIndividuo(Individuos *personaje);

    /**
     * @brief cruzar 
     */
    virtual void cruzar();

    /**
      * @brief dondeEsta
      * @return la posicion de la barca
      */
    virtual string dondeEsta();
  
};

#else      // GUARDA
class Barca; // Declaración adelantada      // GUARDA
#endif      // GUARDA