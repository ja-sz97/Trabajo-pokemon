#include <iostream>
#include "Poke.h"
#include <string.h>
#include <string>
#include <fstream>
#include <sstream>

// NOMBRE;NIVEL;VIDA;ATAQUE 1; 2; 3; 4; 5; 6;ATAQUE;DEFENSA;RESISTENCIA
using namespace std;


int main()
{
    cout << "\t\t\t\t\t:: BATALLA DE POKEMONES :: \t\t\t\t" << endl << endl;
    cout << "\tInstrucciones" << endl << endl;
    cout << "Cada jugador podra elegir cuatro pokemones de los ciento cincuente y uno que estan disponibles, estos pueden repetirse." << endl;
    cout << "Los cuatro pokemones elegidos NO podran ser cambiados durante la batalla." << endl;
    cout << "Cada pokemon tendra seis ataques a disposicion, pero solo se podran elegir cuatro y sin repetirse."<< endl;
    cout << endl << "En la batalla:"<< endl;
    cout << "Para cada jugador se mostrara un menu con sus pokemones ya elegidos, en este tendras que senalar con cual comenzar, esto"<< endl << "solo pasara en el primer turno para cada jugador." << endl;
    cout << "Despues de esto cada jugador tendra dos opciones, atacar o cambiar el pokemon."<< endl;
    cout << "Si elige la primera de desplegaran los ataques que el pokemon elegido puede utilizar, si elige la segunda podra cambiar" << endl;
    cout << "el pokemon pero perdera su turno."<< endl;
    cout << "Si alguno de los jugadores pierde un pokemon se desplagara un menu con los pokemones que le quedan disponibles, y podra" << endl;
    cout << "atacar en el mismo turno." << endl;
    cout << "La batalla termina cuando uno de los jugadores pierda a sus cuatro pokemones." << endl << endl;
    cout << "\t\t\t\t\t-------------------------- \t\t\t\t" << endl << endl;
    menu();



}
