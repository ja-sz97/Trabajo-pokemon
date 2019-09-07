#ifndef POKE_H
#define POKE_H
#include <iostream>
#include <string.h>
// NOMBRE;NIVEL;VIDA;ATAQUE 1; 2; 3; 4; 5; 6;ATAQUE;DEFENSA
using namespace std;
typedef struct ATAQUE{
    string ATA1,ATA2,ATA3,ATA4,ATA5,ATA6;
    int POT1,POT2,POT3,POT4,POT5,POT6;
}ATAQUES[200];

class Poke
{
    public:
        Poke();
        virtual ~Poke();
        //SETTERS
        void setnumero(int);
        void setnombre(string);
        void setnivel(int);
        void setvida(int);
        void setataque1(string);
        void setpoder1(int);
        void setataque2(string);
        void setpoder2(int);
        void setataque3(string);
        void setpoder3(int);
        void setataque4(string);
        void setpoder4(int);
        void setatac(int);
        void setdefensa(int);
        //GETTERS
        int getnumero();
        string getnombre();
        int getnivel();
        string getataque1();
        int getpoder1();
        string getataque2();
        int getpoder2();
        string getataque3();
        int getpoder3();
        string getataque4();
        int getpoder4();
        int getvida();
        int getatac();
        int getdefensa();
        //FUNCIONES
        void VER();
        void Player1(Poke);
        void Player2(Poke);
        Poke ElegirPokemon(Poke[],Poke,string);
        int Dano(int,int);
        void verataques();
    private:
        string nombre,ataque1,ataque2,ataque3,ataque4;
        int numero,nivel,vida,poder1,poder2,poder3,poder4,atac,defensa;

};
void menu();
void SEPARAR(string, Poke[], ATAQUES&, int&);
void minuscula(string&);
void Mochila(Poke, Poke, Poke, Poke, Poke[]);
void mostrarPoke(Poke[]);
void elegirPoke(ATAQUES ,Poke, Poke &, string &,Poke &, string &,Poke &, string &,Poke &, string &);
//void elegir ()
void validarOpc(string &,int);
void validarOpc2(string &,int []);
void validarOpc3(string &,int []);
void SelAttac(ATAQUE,Poke &,Poke[]);
void SelAttac_pt2(ATAQUE,int &, string &, int &, int []);
void validarNombre(Poke[], string &);
void Batalla(string,Poke [],string ,Poke[]);
int seleccionA(Poke);
void Turno(Poke &,Poke &,int &);
void elegirPokeB(Poke [],int &, int []);
void menu2(string &, string);
void muertos(int [], int );
void llenar(int [],int);
void manternervida(Poke &,Poke &);
#endif // POKE_H
