/* Archivo: juagador.ccp
  Autores: 

   alejandro zamorano Arango
   Email: alejandro.zamorano@correounivalle.edu.co

   juan david T. montoya 
   Email: juan.david.tovar@correounivalle.edu.co y 
   
   lina M. Rivas (rivas.lina@correounivalle.edu.co)


  Fecha creación: 2020-10-03
  Fecha última modificación: 2020-10-03
  Versión: 0.1
  Licencia: GNU-GPL
*/



#include "Jugador.h"


string stringAux(int numeroDeEspacios)
{ string espacios="";
  for(int i=0; i<numeroDeEspacios;i++)
  {
    espacios= espacios+" ";
  }
  return espacios;
}


Jugador::Jugador(string nombre,Barca &barca, Orilla &orillaIzquierda, Orilla &orillaDerecha)
{
  this-> nombre=nombre;
  this-> barca=&barca;
  this-> orillaIzquierda=&orillaIzquierda;
  this-> orillaDerecha=&orillaDerecha;
  this-> juegoBien = true;
  this-> personajesDelJuego={};
}

Jugador::~Jugador()
{
}
//esta funcion solo se hizo para comprimir codigo en la funcion de dar roden
void Jugador::moverIndividuo(string individuoAMover)
{
  Individuos *personajeMovido=nullptr;
    if(barca->estaElIndividuo(individuoAMover))
    {
      if( barca->dondeEsta()=="izquierda")
      {
        orillaIzquierda->recibirIndividuo(barca->sacarIndividuo(individuoAMover));//sacar individuo retorna un puntero a individuo y recibir individuo recibe un punteor a individuo
      }
      else if( barca->dondeEsta()=="derecha")
      { 
        orillaDerecha->recibirIndividuo(barca->sacarIndividuo(individuoAMover));//sacar individuo retorna un puntero a individuo y recibir individuo recibe un punteor a individuo  
      }

    }

    else if(orillaDerecha->estaElIndividuo(individuoAMover))
    {
      if( barca->dondeEsta()=="derecha")
      {
        personajeMovido=orillaDerecha->sacarIndividuo(individuoAMover);
        if(not barca->recibirIndividuo(personajeMovido))
        {
          orillaDerecha->recibirIndividuo(personajeMovido);
          cout<<"\n\e[1;107;30m¡LA BARCA SOLO CARGA DOS INDIVIDUOS!\e[0m\n\n";
        }
       
      }
      else if( barca->dondeEsta()=="izquierda")
      {
        cout<<"\nLa barca tiene que estar cerca de la orilla donde está el individuo \n\n";
      }
    }

    else if(orillaIzquierda->estaElIndividuo(individuoAMover))
    {
      if( barca->dondeEsta()=="izquierda")
      {
        personajeMovido=orillaIzquierda->sacarIndividuo(individuoAMover);
        if(not barca->recibirIndividuo(personajeMovido))
        {
          orillaIzquierda->recibirIndividuo(personajeMovido);
          cout<<"\n\e[1;107;30m¡LA BARCA SOLO CARGA DOS INDIVIDUOS!\e[0m\n\n";
        }
       
      }
      else if( barca->dondeEsta()=="derecha")
      {
        cout<<"\n\n\e[1;107;30mLa barca tiene que estar cerca de la orilla donde está el individuo\e[0m\n\n";
      }
    }
    else cout<<"\nNo se puede mover al individuo\n"; 
}


 void Jugador::orden()
 {
    string orden;
    cout<< "Da la orden: ";
    getline(cin, orden);

   if (orden=="b"||orden=="B")
   {
     if( barca->estaElIndividuo("robot"))
     {
       barca->cruzar();
     }
     else 
     {
       cout<< "\n\n\e[1;107;100mEl robot tiene que estar en la barca\e[0m\n\n";
     }
   }
   
   else if (orden=="r"||orden=="R")
   {
     moverIndividuo("robot");
   }

   else if (orden=="z"||orden=="Z")
   {
     moverIndividuo("zorro");
   }
   else if (orden=="c"||orden=="C")
   {
     moverIndividuo("conejo");
   }
   else if (orden=="l"||orden=="L")
   {
     moverIndividuo("lechuga");
   }
   else cout<<"\n\e[1;107;30mORDEN NO VALIDA\e[0m\n\n";

   
 }


void Jugador::imprimirEstado()
{

  if(barca->dondeEsta()=="izquierda")
  {
    cout<<"| IZQUIERDA | BARCA     |           | DERECHA   |\n";
  }
  else if(barca->dondeEsta()=="derecha")
  {
    cout<<"| IZQUIERDA |           |    BARCA  | DERECHA   |\n";

  }


   int espacioAux;
   string auxiliar="";

   for(int i=0;i<personajesDelJuego.size();i++)
   {
     espacioAux = 10-personajesDelJuego.at(i)->tuNombre().size();
     auxiliar= stringAux( espacioAux );

     if(personajesDelJuego.at(i)->dondeEsta()=="IZQUIERDA")
     {
       cout<<"| "+personajesDelJuego.at(i)->tuNombre()+auxiliar+"|           |           |           |\n";
     }
     else if(personajesDelJuego.at(i)->dondeEsta()=="DERECHA")
     {
       cout<<"|           |           |           | "+personajesDelJuego.at(i)->tuNombre()+auxiliar+"|\n";
     }
     else if(personajesDelJuego.at(i)->dondeEsta()=="barcaI")
     {
       cout<<"|           | "+personajesDelJuego.at(i)->tuNombre()+auxiliar+"|           |           |\n";
     }
     else if(personajesDelJuego.at(i)->dondeEsta()=="barcaD")
     {
       cout<<"|           |           | "+personajesDelJuego.at(i)->tuNombre()+auxiliar+"|           |\n";
     }
   }
}

void Jugador::recibirPersonaje(Individuos *personaje)
{
  personajesDelJuego.push_back(personaje);
}


bool Jugador::seguirJugando()
{

  if(orillaIzquierda->alguienMurio() and barca ->dondeEsta() == "derecha")
  {
    cout<< "\n\n\e[1;107;30m Game Over \e[0m"  << "\e[1;107;30m" << nombre <<  "\e[0m" << endl;
    juegoBien = false;
  }
  else if(orillaDerecha->alguienMurio() and barca ->dondeEsta() == "izquierda")
  {
    cout<< "\n\n\e[1;107;30m Game Over \e[0m"  << "\e[1;107;30m" << nombre <<  "\e[0m" << endl;
    juegoBien = false;
  }
  if(orillaDerecha -> numeroTripulantes() == 4)
  {
    cout<< "\n\n\e[1;107;30m ¡Felicitaciones por ganar, \e[0m"  << "\e[1;107;30m" << nombre <<  "!\e[0m" << endl;
    juegoBien = false;
  }
   return juegoBien;
}