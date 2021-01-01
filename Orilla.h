/* Archivo: Orilla.h
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
Atributos:
   tripulantes :vectorde punteros, los individuos que se encuentran en la orilla
   numeroDeTripulantes: entero
   posicion: string, derecha o izquierda
   maximoDeTrpulantes: int
   
    
Funcionalidades:
    -decir la posicion en la que está
    -montar un individuo
    -bajar un individuo 
     buscar un tripulante por su nombre 
    -alguienMurio() que verifica que los indivuos esten bien
    numeroDeTripulantes() retorna el numero de tripulantes

relaciones:
  orilla es un lugar
  oerilla contiene un vector de punteros a individuos
  orilla conoce indivuduos
 
  
*/
#ifndef ORILLA_H      // GUARDA
#define ORILLA_H      // GUARDA

#include "Lugar.h"

class Orilla : public Lugar
{
  protected:
    
  public:
    Orilla(string nombre);

    virtual ~Orilla();

    virtual bool alguienMurio();

    int numeroTripulantes();

  
};

#else      // GUARDA
class Orilla; // Declaración adelantada      // GUARDA
#endif      // GUARDA 