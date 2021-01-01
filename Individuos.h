

/* Archivo: Individuos.h
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
Clase: individuos

Atributos:
 nombre
 posición, donde está
 sano, si esta bien el individuo
 Alimento, lo que come
 

Funcionalidades:
 decir su nombre
 decir si está bien
 decir su posición
 comer a otro individuo
 cambiar de posición
 


Relaciones:
Cada individuo conoce a los individuos que le sirven de comida

*/

#ifndef INDIVIDUOS_H
#define INDIVIDUOS_H

#include <iostream>
#include <string>
using namespace std;

class Individuos 
{
  private:
    string nombre;
    bool sano; 
    string alimento; //lo que come
    string posicion; 
    
    
  public:
    /**
     * @brief construye un Individuos con nombre 
     * @param nombre
     */
    Individuos(string nombre);

    /**
     * @brief ~Individuos destruye los objetos de los que es propietario
     */
    ~Individuos();

    /**
     * @brief tuNombre
     * @return el monbre del individuo
     */
    virtual string tuNombre();

    /**
     * @brief estaSano
     * @return true si esta sano y false si esta muerto
     */
    virtual bool estaSano();

    /**
     * @brief intentarComer recibe un paramentro de clase individuos
     * @param personajeComido
     * @return true si el individuo se comio a personajeComido y false si no se lo puede comer
     */
    virtual bool intentarComer(Individuos *personajeComido);

    /**
     * @brief dondeEsta
     * @return la posicion del individuo
     */
    virtual string dondeEsta();

    /**
     * @brief cambiarPosicion recibe un string con la nueva posicion del individuo
     * @param nuevaPosicion
     */
    virtual void cambiarPosicion(string nuevaPosicion);
};
#else
class Individuos;  // Declaración adelantada
#endif