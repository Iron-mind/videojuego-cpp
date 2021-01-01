/* Archivo: Lugar.cpp
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


#include "Lugar.h"

Lugar::Lugar(string nombre)
{
  this->nombre=nombre;
  this->tripulantes={}; 
  this->numeroDeTripulantes=tripulantes.size();
  
  
}

Lugar::~Lugar()
{

}
 bool Lugar::estaElIndividuo(string nombreDeIndividuo)
{
  if(tripulantes.size()==0)
  {
    return false;
  }
  
  for(int i=0;i<tripulantes.size();i++ )
  {
    if(tripulantes.at(i)->tuNombre()==nombreDeIndividuo)
    {
      return true;
    }
  }
  return false;
}


bool Lugar::recibirIndividuo(Individuos *personaje)
{
  personaje->cambiarPosicion(nombre);
  tripulantes.push_back(personaje);
  return true;
}

Individuos *Lugar::sacarIndividuo(string nombreDeIndividuo)
{ 

    Individuos *sacado = nullptr;
    for(int numero = 0; numero < tripulantes.size(); numero++)
    {
  
      if(tripulantes[numero]->tuNombre() == nombreDeIndividuo)
        {
          sacado = tripulantes[numero];
          tripulantes.erase (tripulantes.begin()+numero);

        }
    }
  //sacado->cambiarPosicion("");
  return sacado;
}
