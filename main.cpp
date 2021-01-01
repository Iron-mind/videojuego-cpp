/* Archivo: main.cpp
  Autores: 
   alejandro zamorano Arango
   Email: alejandro.zamorano@correounivalle.edu.co

   Juan  David Tovar montoya 
   Email: juan.david.tovar@correounivalle.edu.co y 
   
   lina M. Rivas (rivas.lina@correounivalle.edu.co)


  Fecha creación: 2020-10-03
  Fecha última modificación: 2020-12-19
  Versión: 0.1
  Licencia: GNU-GPL
*/


/*
Historia:
El juego consiste en lo siguiente: hay un robot que debe transportar un zorro, un conejo y
una lechuga desde un lado del río hasta la otra orilla, usando una barca. En la barca solo
cabe uno de los tres individuos, además del robot. El problema es que si el robot deja
solos al zorro y el conejo, el zorro se comerá el conejo. Y si deja solos al conejo y la
lechuga, el conejo se comerá la lechuga. El jugador debe controlar que órdenes dar, para
lograr que el robot transporte los tres individuos a la otra orilla, sanos y salvos.
*/

#include <iostream>
#include "Individuos.h"
#include "Barca.h"
#include "Lugar.h"
#include "Orilla.h"
#include "Jugador.h"
using namespace std;

int main() 
{
  Individuos bunny ("conejo");   // Creo un objeto, que voy a testear
  Individuos foxy("zorro");
  Individuos lettuce("lechuga");
  Individuos bot("robot");

  Barca santaMaria("BARCA","izquierda");
  Orilla Orillai("IZQUIERDA");
  Orilla orillaD("DERECHA");
  
  string nombre;
  cout<< "¿Como te llamas? \n";
  getline(cin, nombre);




  cout <<"Estos son botones del juego:\n"<<"B la Barca se mueve a la otra orilla\n"<<"R el Robot salta de/a la barca\n"<<"Z el Zorro salta de/a la barca\n"<<"C el Conejo salta de/a la barca\n"<<"L la Lechuga salta de/a la barca\n\e\n[1;107;30mLa barca solo recibe 2 Individuos \n En la barca tiene que estar el robot\e[0m\n\n";


  bool confirmacion = Orillai.recibirIndividuo(&bot);  
  bool confirmacionl = Orillai.recibirIndividuo(&lettuce);
  bool confirmacion2 = Orillai.recibirIndividuo(&bunny);
  bool confirmacion3 = Orillai.recibirIndividuo(&foxy);



  Jugador turing(nombre,santaMaria,Orillai,orillaD);
 
  turing.recibirPersonaje(&bot);
  turing.recibirPersonaje(&bunny);
  turing.recibirPersonaje(&foxy);
  turing.recibirPersonaje(&lettuce);
  turing.imprimirEstado(); 


  bool jugoEnPie=true;
  while(jugoEnPie)
  {
    turing.orden();
    turing.imprimirEstado();
    jugoEnPie = turing.seguirJugando();//confirma si seguir jugando
  }
  return 0;
}

