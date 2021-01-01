/* Archivo: Orilla.cpp
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
#include "Orilla.h"

Orilla::Orilla(string nombre):Lugar(nombre)
{

}

Orilla:: ~Orilla()
{

}


bool Orilla::alguienMurio()
{
  bool ceno = false;
  for(int numero = 0; numero < tripulantes.size(); numero++)
  { 
    for(int numeroN = 0; numeroN < tripulantes.size(); numeroN++)
    {
      if(tripulantes[numero] -> intentarComer(tripulantes[numeroN]))
      { 
        ceno = true;
      }
    }
  }
  return ceno;
}


int Orilla::numeroTripulantes()
{
  return tripulantes.size();
}

