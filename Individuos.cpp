
/* Archivo: Individuos.h
  Autores: 

   alejandro zamorano Arango
   Email: alejandro.zamorano@correounivalle.edu.co

   J. David T. montoya 
   Email: juan.david.tovar@correounivalle.edu.co y 
   
   lina M. Rivas (rivas.lina@correounivalle.edu.co)


  Fecha creación: 2020-10-03
  Fecha última modificación: 2020-12-09
  Versión: 0.1
  Licencia: GNU-GPL
*/



#include "Individuos.h"
using namespace std;
Individuos::Individuos(string nombre)
{

  this->nombre=nombre;
  this->sano=true;
  this->posicion="";
  this->alimento="";
  if( this->nombre=="conejo")
  {
    this->alimento="lechuga";
  }
  else if( this->nombre=="zorro")
  {
    this->alimento="conejo";
  }

};

Individuos::~Individuos(){}

string Individuos::tuNombre()
{
  return nombre;
}


bool Individuos::estaSano()
{
  if(sano == true)
  {
    return true;
  }
  else
    return false;
}


bool Individuos::intentarComer(Individuos *personajeComido)
{

  if("conejo"== nombre)
  {
    if(personajeComido->tuNombre()== "lechuga")
    {
      personajeComido->sano = false;
      return true;
    }
    else return false;
  }
  else if("zorro"== nombre)
  {
    if(personajeComido->tuNombre()== "conejo")
    {
      personajeComido->sano = false;
      return true;
    }
    else return false;
  }
return false;

}


string Individuos::dondeEsta()
{
  return posicion;
}

void Individuos::cambiarPosicion(string nuevaPosicion)
{
  posicion=nuevaPosicion;
}