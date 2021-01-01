

  /* Archivo: juagador.h
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
  Clase: juagador
  Atributos:
    nombre, el nombre que le quiere asignar el usuario
    Barca un puntero a la barca del juego
    orillaIzquierda y orillaDerecha, las unicas orillas del juego
    juegoBien, confirmacion de si se puede seguir Jugando 
    personajesDelJuego, un vector con punteros a los indiviuos del juego

  Funcionalidades:
   -dar ordenes, le da ordenes a todos los individuos y lugares
    moverIndividuo, cambiar la posicion de un individuo
    seguirJugando, confirma si se puede se pude seguir Jugando
    imprimirEstado, imprime todo lo que se ve en pantalla
    recibirPersonaje, recibe puntero a los personajes del juego.
    
  relaciones
   jugador conoce a barca, conejo, Zorro, Lechuga y orilla .
*/





#ifndef JUGADOR_H      // GUARDA
#define JUGADOR_H      // GUARDA

#include <iostream>
#include <vector>
#include<string>
#include "Individuos.h"
#include "Barca.h"
#include "Lugar.h"
#include "Orilla.h"
using namespace std;
class Jugador
{

  private:
    string nombre;
    Barca *barca;
    Orilla *orillaIzquierda;
    Orilla *orillaDerecha;
    bool juegoBien;
    vector <Individuos*> personajesDelJuego;
  public:

  /**
     * @brief construye un  Jugador con nombre, barca, orillaIzquierda y orillaDerecha 
     * @param nombre
     * @param barca
     * @param orillaIzquierda
     * @param orillaDerecha
     */
  Jugador(string nombre,Barca &barca, Orilla &orillaIzquierda, Orilla &orillaDerecha);

  /**
     * @brief ~Jugador destruye los objetos de los que es propietario
     */
  ~Jugador();

  /**
     * @brief moverIndividuo recibe un string y mueve el individuo
     * @param individuoAMover
     */
  virtual void moverIndividuo(string individuoAMover);

  /**
     * @brief orden 
     */
  virtual void orden();

  /**
     * @brief imprimirEstado imprimi en la consola el estado actual del juego
     */
  virtual void imprimirEstado();

  /**
     * @brief recibirPersonaje recibe un paramentro de clase individuos
     * @param personaje
     */
  virtual void recibirPersonaje(Individuos *personaje);


  /**
     * @brief seguirJugando
     * @return true si el jugador no ha perdido y false si el jugador perdio
     */
  virtual bool seguirJugando();
   
};

#else      // GUARDA
class Jugador; // Declaración adelantada      // GUARDA
#endif      // GUARDA

