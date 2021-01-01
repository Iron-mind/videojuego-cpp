/* Archivo: Barca.cpp
  Autores: 

   alejandro zamorano Arango
   Email: alejandro.zamorano@correounivalle.edu.co

   juan david T. montoya 
   Email: juan.david.tovar@correounivalle.edu.co y 
   
   lina M. Rivas (rivas.lina@correounivalle.edu.co)


  Fecha creación: 2020-10-03
  Fecha última modificación: 2020-12-9
  Versión: 0.1
  Licencia: GNU-GPL
*/

#include <iostream>
using namespace std;

#include <iostream>
using namespace std;
#include "Barca.h"

Barca::Barca(string nombre, string posicion):Lugar(posicion)
{
  this-> maximoDeTrpulantes=2;
  this->posicion=posicion;
}

Barca:: ~Barca()
{
// No hay que hacer nada
}




bool Barca::recibirIndividuo(Individuos *personaje)
{
  if(tripulantes.size()==maximoDeTrpulantes)
  {
    return false;
  }


  else if(posicion=="izquierda")
  {
    personaje->cambiarPosicion("barcaI");// Bi es barca al lado izquierdo
  }
  else
  {
    personaje->cambiarPosicion("barcaD");// nombre del Lugar
  }

  tripulantes.push_back(personaje);
  
  return true;
}



void Barca::cruzar()
{
  if(posicion=="izquierda")
  {
    posicion="derecha";
  }
  else
  {
    posicion="izquierda";
  }
  

  
  for(int i=0;i<tripulantes.size();i++)
  {

    if(posicion=="izquierda")
    {
      tripulantes.at(i)->cambiarPosicion("barcaI");// 
    }
    else
    {
      tripulantes.at(i)->cambiarPosicion("barcaD");// nombre del Lugar
    }
  
  }

}



string Barca::dondeEsta()
{
  return posicion;
}


