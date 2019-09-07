#include "Poke.h"
#include <iostream>
#include <string.h>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctype.h>
using namespace std;
//CONSTRUCTORES
Poke::Poke()
{
    nombre="SIN NOMBRE";
    vida=0;
    ataque1="SIN ATAQUE 1";
    poder1=0;
    ataque2="SIN ATAQUE 2";
    poder2=0;

    ataque3="SIN ATAQUE 3";
    poder3=0;

    ataque4="SIN ATAQUE 4";
    poder4=0;

    atac=0;
    defensa=0;
    nivel=0;

}
Poke::~Poke()
{
    //dtor
}
//SETTERS
void Poke::setnumero(int _num)
{
    numero=_num;
}
void Poke::setnombre(string _nombre)
{
    nombre=_nombre;
}
void Poke::setnivel(int _nivel)
{
    nivel=_nivel;
}
void Poke::setvida(int _vida)
{
    vida=_vida;
}
void Poke::setataque1(string ataque)
{
    ataque1=ataque;
}
void Poke::setataque2(string ataque)
{
    ataque2=ataque;
}
void Poke::setataque3(string ataque)
{
    ataque3=ataque;
}
void Poke::setataque4(string ataque)
{
    ataque4=ataque;
}
void Poke::setpoder1(int poder)
{
    poder1=poder;
}
void Poke::setpoder2(int poder)
{
    poder2=poder;
}
void Poke::setpoder3(int poder)
{
    poder3=poder;
}
void Poke::setpoder4(int poder)
{
    poder4=poder;
}
void Poke::setatac(int _atac)
{
    atac=_atac;
}
void Poke::setdefensa(int _defensa)
{
    defensa=_defensa;
}
//GETTERS
int Poke::getnumero()
{
    return numero;
}
string Poke::getnombre()
{
    return nombre;
}
int Poke::getnivel()
{
    return nivel;
}
int Poke::getvida()
{
    return vida;
}
string Poke::getataque1()
{
    return ataque1;
}
string Poke::getataque2()
{
    return ataque2;
}
string Poke::getataque3()
{
    return ataque3;
}
string Poke::getataque4()
{
    return ataque4;
}
int Poke::getpoder1()
{
    return poder1;
}
int Poke::getpoder2()
{
    return poder2;
}
int Poke::getpoder3()
{
    return poder3;
}
int Poke::getpoder4()
{
    return poder4;
}
int Poke::getatac()
{
    return atac;
}
int Poke::getdefensa()
{
    return defensa;
}
//FUNCIONES
//FUNCION VER:  MUESTRA LOS DATOS DEL POKEMON Y SUS ATAQUES
void Poke::VER(){
    cout << "Numero del Pokemon: " << numero << endl;
    cout << "Nombre del Pokemon: " << nombre << endl;
    cout << "Vida del Pokemon: " << vida << endl;
    cout << "Nivel del Pokemon: " << nivel << endl;
    cout << "Ataque 1 del Pokemon y su potencia 1 : " <<ataque1 << " , " << poder1 << endl;
    cout << "Ataque 2 del Pokemon y su potencia 2 : " <<ataque2 << " , " << poder2 << endl;
    cout << "Ataque 3 del Pokemon y su potencia 3 : " <<ataque3 << " , " << poder3 << endl;
    cout << "Ataque 4 del Pokemon y su potencia 4 : " <<ataque4 << " , " << poder4 << endl;
    cout << "Ataque Base del Pokemon : " << atac << endl;
    cout << "Defensa Base del Pokemon : " << defensa << endl;
}
//  SEPARA EL ARCHIVO DE TEXTO "POKEDEX" Y ASIGNA A CADA INDICE DE P UN OBJETO POKEMON CON SU NOMBRE,VIDA,NIVEL,DEF,ATAC,ETC.
// GUARDA LOS ATAQUES EN UNA STRUCT PARA POSTERIORMENTE SELECCIONAR 4 DE SUS 6 ATAQUES
// ARCHIVO DE TEXTO: NUMERO;NOMBRE;NIVEL;ATAQUE;DEFENSA;PODERES DEL 1 AL 6;
void SEPARAR(string txt,Poke P[],ATAQUES &A,int &cont){
    stringstream sep(txt);
    int i=0;
    while (getline(sep,txt,';'))
    {
        if (i==0)
            P[cont].setnumero(atoi(txt.c_str()));
        if (i==1)
            P[cont].setnombre(txt);
        if (i==2)
            P[cont].setnivel(atoi(txt.c_str()));
        if (i==3)
            P[cont].setvida(atoi(txt.c_str()));
        if (i==4)
            P[cont].setatac(atoi(txt.c_str()));
        if (i==5)
            P[cont].setdefensa(atoi(txt.c_str()));
        if (i==6)
            A[cont].ATA1=txt;
        if (i==7)
            A[cont].POT1=atoi(txt.c_str());
        if (i==8)
            A[cont].ATA2=txt;
        if (i==9)
            A[cont].POT2=atoi(txt.c_str());
        if (i==10)
            A[cont].ATA3=txt;
        if (i==11)
            A[cont].POT3=atoi(txt.c_str());
        if (i==12)
            A[cont].ATA4=txt;
        if (i==13)
            A[cont].POT4=atoi(txt.c_str());
        if (i==14)
            A[cont].ATA5=txt;
        if (i==15)
            A[cont].POT5=atoi(txt.c_str());
        if (i==16)
            A[cont].ATA6=txt;
        if (i==17)
            A[cont].POT6=atoi(txt.c_str());

        i++;
    }
    cont=cont+1;
}
//Muestra los ataques seleccionados y la potencia de cada uno
void Poke::verataques(){
    cout << "\t\tAtaque 1. " << ataque1 << " con potencia: " << poder1 << endl;
    cout << "\t\tAtaque 2. " << ataque2 << " con potencia: " << poder2 << endl;
    cout << "\t\tAtaque 3. " << ataque3 << " con potencia: " << poder3 << endl;
    cout << "\t\tAtaque 4. " << ataque4 << " con potencia: " << poder4 << endl;

}
//Muestra los pokemones para que el jugador los elija
void mostrarPoke(Poke P[]){
    int cont=1;
    cout << "\t\t\t\t  ---------- Pokemones Disponibles ----------" << endl << endl;
    for (int i=0; i<151; i++)
    {
        if(i==cont*10){
            cout << endl;
            cont++;
        }
        cout << " " << i+1 << "."<< P[i].getnombre() << " ";
    }
    cout << endl << "\t\t\t\t             ---------------------           " << endl << endl;
}
//Elegir pokemon
Poke Poke::ElegirPokemon(Poke A[], Poke E, string Pokemon){
    for (int i=0; i<300; i++){
        minuscula(Pokemon); // se pasan todas las letras a minusculas para luego compararlas
        string aux;
        aux=A[i].nombre;
        minuscula(aux);
        if (Pokemon==aux){  //compara el nombre ingresado por teclado y el nombre del pokemon
            E=A[i];
            return E;
        }
    }
}
//FUNCION QUE ELIGE POKEMON E INMEDIATAMENTE SE SELECCIONA LOS ATAQUES DE LOS POKEMON
void elegirPoke(ATAQUES A,Poke P[], Poke &p1, string &n1,Poke &p2, string &n2,Poke &p3, string &n3,Poke &p4, string &n4){

    cout << "Ingresa el nombre del 1er Pokemon: ";
    cin>>n1; validarNombre(P,n1);
    p1=p1.ElegirPokemon(P,p1,n1);
    cout << endl;
    SelAttac(A[p1.getnumero()-1],p1,P);
    cout << endl << "Ingresa el nombre del 2do Pokemon: ";
    cin >> n2;
    validarNombre(P,n2);
    p2=p2.ElegirPokemon(P,p2,n2);
    SelAttac(A[p2.getnumero()-1],p2,P);
    cout << endl << "Ingresa el nombre del 3er Pokemon: ";
    cin >> n3; validarNombre(P,n3);
    p3=p3.ElegirPokemon(P,p3,n3);
    SelAttac(A[p3.getnumero()-1],p3,P);
    cout << endl << "Ingresa el nombre del 4do Pokemon: ";
    cin >> n4; validarNombre(P,n4);
    p4=p4.ElegirPokemon(P,p4,n4);
    SelAttac(A[p4.getnumero()-1],p4,P);
}
// Muestra los ataques por pantalla
void SelAttac(ATAQUE A,Poke &P, Poke L[]){
    int aux=0;
    int cont=1;
    while (cont<5)
    {
        cout << endl << "\tAtaques disponibles para " << P.getnombre() << ":" << endl << endl;
        cout << "  ATAQUE 1. '" << A.ATA1 << "' con potencia:  " << A.POT1 << endl;
        cout << "  ATAQUE 2. '" << A.ATA2 << "' con potencia:  " << A.POT2 << endl;
        cout << "  ATAQUE 3. '" << A.ATA3 << "' con potencia:  " << A.POT3 << endl;
        cout << "  ATAQUE 4. '" << A.ATA4 << "' con potencia:  " << A.POT4 << endl;
        cout << "  ATAQUE 5. '" << A.ATA5 << "' con potencia:  " << A.POT5 << endl;
        cout << "  ATAQUE 6. '" << A.ATA6 << "' con potencia:  " << A.POT6 << endl << endl;

        cout << "Seleccione solo 4 ataques, indicando el numero correspondiente."<< endl;
        string ataque; int poder;
        int K[6]; llenar(K,6);
        if (P.getpoder1()==0)
        {
            cout << "Ataque ";
            SelAttac_pt2(A,cont,ataque,poder,K);
            P.setataque1(ataque);
            P.setpoder1(poder);
        }
        if(P.getpoder2()==0)
        {
            cout << "Ataque ";
            SelAttac_pt2(A,cont,ataque,poder,K);
            P.setataque2(ataque);
            P.setpoder2(poder);
        }
        if(P.getpoder3()==0)
        {
            cout << "Ataque ";
            SelAttac_pt2(A,cont,ataque,poder,K);
            P.setataque3(ataque);
            P.setpoder3(poder);
        }
        if (P.getpoder4()==0)
        {
            cout << "Ataque ";
            SelAttac_pt2(A,cont,ataque,poder,K);
            P.setataque4(ataque);
            P.setpoder4(poder);

        }
        aux++;
        system("cls");
        mostrarPoke(L);
    }
}
//SELECCIONAR ATAQUE PT.2
void SelAttac_pt2(ATAQUE A,int &cont, string &ataq, int &pod, int K[]){
    string opc;
    cout << "(" << cont <<"): " ;
    cin>>opc; validarOpc3(opc,K);
    if(opc[0]=='1'){
        ataq=(A.ATA1);
        pod=(A.POT1);
        K[0]=1;  //en la posicion queda el numero uno para que no se vuelva a ultilizar el mismo ataque
        cont++;
    }
    if(opc[0]=='2'){
        ataq=(A.ATA2);
        pod=(A.POT2);
        K[1]=1;
        cont++;
    }
    if(opc[0]=='3'){
        ataq=(A.ATA3);
        pod=(A.POT3);
        K[2]=1;
        cont++;
    }
    if(opc[0]=='4'){
        ataq=(A.ATA4);
        pod=(A.POT4);
        K[3]=1;
        cont++;
    }
    if(opc[0]=='5'){
        ataq=(A.ATA5);
        pod=(A.POT5);
        K[4]=1;
        cont++;
    }
    if(opc[0]=='6'){
        ataq=(A.ATA6);
        pod=(A.POT6);
        K[5]=1;
        cont++;
    }
}
//VALIDA ELEGIRATAQUEPT_2
void validarOpc3(string &opc, int A[]){
    int cond=0;
    string aux=opc, A0="123456";
    while(cond==0){
        int len=aux.length();
        for(int i=0; i<6; i++){ //menu con seis opciones
            if(len==1){
                if((A0[i]==aux[0]) && (A[i]==0)){
                            cond++;
                        }
            }
        }
        if(cond==0){
                cout << "\t **ERROR!! Ingrese el numero del ataque nuevamente: ";
                cin>>aux;
        }
    }
    opc=aux;
}
//Valida el nombre del pokemon
void validarNombre(Poke P[],string &nombre){
    int cond=0;
    string aux, nom=nombre;
    minuscula(nom);
    while(cond==0){
        for(int i=0; i<=152; i++){
            aux=P[i].getnombre();
            minuscula(aux);
            if(nom==aux)   //compara cada nombre de la clase con el ingresado por teclado
                cond++;
        }
        if(cond==0){  //si no encuentra el nombre la variable cond se mantiene en cero y lo pide nuevamente
            cout << "\t **ERROR! Ingrese el nombre nuevamente: ";
            cin>>nom;
            minuscula(nom);
        }
    }
    nombre=nom;
}
//VALIDA MENU , SELATTAC_PT2 , ELEGIRPOKEB
void validarOpc(string &num, int opc){  //opc: 0 para menu, 1 para selattac_pt2, 2 para elegirPokeB
        string A0="12", A1="123456", A3="1234", aux=num;
        int cond=0, n;
        if(opc==0){n=3;} if(opc==1){n=7;} if(opc==2){n=5;} //largo de los strings segun la opc que se elija
        while(cond==0){
            int len=aux.length();
            for(int i=0; i<n; i++){
                if(len==1){ //largo igual a 1, evita que se valide una opc "12" como "1"
                    if(opc==0){  //para menu con dos opciones
                        if(A0[i]==aux[0]){
                            cond++;        //si son iguales la cond cambia y se termina el while
                        }
                    }
                    if(opc==1){ //para menu con seis opciones
                        if(A1[i]==aux[0]){
                            cond++;
                        }
                    }
                    if(opc==2){ //para menu con cuatro opciones
                        if(A3[i]==aux[0]){
                            cond++;
                        }
                    }
                }
            }
            if(cond==0){  //si la opc ingresada no esta en el menu cond igual a cero y pide nuevamente la opc
                cout << "\t **ERROR! Ingrese el numero nuevamente: "; cin>>aux;
            }
        }
        num=aux;
}
//VALIDA ELEGIRPOKEB
void validarOpc2(string &opc, int A[]){
    int cond=0;
    cout << endl << "Pokemon numero: "; cin >> opc;
    string aux=opc, A0="1234";
    while(cond==0){
        int len=aux.length();
        for(int i=0; i<4; i++){
            if(len==1){
                if((A0[i]==aux[0]) && (A[i]==0)){
                            cond++;
                        }
            }
        }
        if(cond==0){
                cout << "\t **POKEMON MUERTO!! Ingrese el numero nuevamente: ";
                cin>>aux;
        }
    }
    opc=aux;
}
// Se guardan los pokemones elejidos en la mochila de cada jugador
void Mochila(Poke p1, Poke p2, Poke p3, Poke p4, Poke mochila[]){
    mochila[1]=p1;
    mochila[2]=p2;
    mochila[3]=p3;
    mochila[4]=p4;

}
//Ingresa un string y convierte todas las letras de ella en minusculas
void minuscula(string &a){
    for  (int i=0; i<a.length(); i++){  //recorre el string
        a[i]=tolower(a[i]);
    }
}
//Calcula el daño que realiza un pokemon cuando ataca
int Poke::Dano(int  PoderAtaque, int defensita){  //"defensita" es la defensa del oponente

    int x=((0.2*nivel+1)*atac*PoderAtaque)/(25*defensita)+2;
    return x;
}
void menu(){
    Poke P[200]; //Arreglo de clase, cada pokemon es un objeto de la clase pokemon
    Poke mochila1[5],mochila2[5]; //en cada mochila se guardan los pokemones elejidos por cada jugador
    ATAQUE A[200];
    int cont=0;
    ifstream archivo;
    string texto;
    archivo.open("PokeDex.txt",ios::in);
    if (archivo.fail())
        cout <<"error";
    while (getline (archivo,texto))
    {
        stringstream Separacion (texto);
        while (getline (Separacion,texto,'\n')) //SEPARA EL TEXTO POR SALTO DE LINEA, ES DECIR, CADA LINEA ENTRA A LA FUNCION SEPARAR

        {
            SEPARAR(texto,P,A,cont);
        }
    }
    string opc, opc1; int opcexit=1; // opciones y condicion dowhile
    do{
        cout << "Menu!" << endl << endl;
        cout << "1. Comenzar." << endl << "2. Salir." << endl;
        cout << "Ingrese opcion: ";
        cin >> opc; validarOpc(opc,0);
        system("cls"); fflush(stdin);
        if(opc[0]=='1' || opc[0]=='2'){
            if(opc[0]=='1'){
                Poke p11,p12,p13,p14,p21,p22,p23,p24;  // OBJETOS DE TIPO POKEMON DE LOS 2 JUGADORES (4 PÀRA CADA UNO)
                string n11,n12,n13,n14,n21,n22,n23,n24; // STRINGS PARA INGRESAR LOS 4 POKEMON DE CADA JUGADOR
                string nombre1, nombre2; // NOMBRE DE LOS PLAYER'S
                //PLAYER1
                cout << "Player 1!   Ingresa tu nombre: "; cin >> nombre1; cout << endl;
                mostrarPoke(P);
                cout << endl << "\t"<< nombre1 << "!" << endl;
                elegirPoke(A,P,p11,n11,p12,n12,p13,n13,p14,n14); //MANDA A ELEGIR POKEMON Y ATAQUE
                Mochila(p11,p12,p13,p14,mochila1); // GUARDA EN MOCHILA1 A LOS POKEMON SELECCIONADOS
                system("cls");
                //PLAYER2
                cout << "Player 2!   Ingresa tu nombre: "; cin >> nombre2;
                mostrarPoke(P);
                cout << endl << "\t"<< nombre2 << "!" << endl;
                elegirPoke(A,P,p21,n21,p22,n22,p23,n23,p24,n24);
                Mochila(p21,p22,p23,p24,mochila2);
                cout << endl << endl << "LISTOS PARA LA BATALLA !! " << endl;
                system("cls");
                Batalla(nombre1,mochila1,nombre2,mochila2);
            }
        }
        if(opc[0]=='2')
        {
            opcexit=0;
            cout << "...";
        }
        system("pause>null");system("cls");
    }
    while(opcexit==1);
    cout << "\t\t\t BATALLA FINALIZADA. " << endl;
}
//
void elegirPokeB(Poke P[], int &n,string nombre, int D[]){
    cout << endl << " " << nombre << " tus opciones son: " << endl;
    for(int i=0; i<4;i++){
            if(D[i]==0){
                cout << "\t\t\t " << i+1 << "." << P[i+1].getnombre() << "->\tVida: " << P[i+1].getvida() << endl;
            }
            else{
                cout << "\t\t\t " << i+1 << "." << P[i+1].getnombre() << "->\tVida 0!!" << endl;
            }
    }
    string opc; validarOpc2(opc,D);
    if(opc[0]=='1'){n=1;}if(opc[0]=='2'){n=2;}if(opc[0]=='3'){n=3;}if(opc[0]=='4'){n=4;}
    cout << endl << "\t\t ----------------------------" << endl << endl;
}
//Menu de la batalla
void menu2(string &opc, string player){
    cout << " " << player << " Que haras?"<< endl;;
    cout << "\t1.Atacar." << endl << "\t2.Cambiar pokemon." << endl << endl;
    cout << "Ingresa tu opcion: ";
    cin >> opc; validarOpc(opc,0);
}
//Llena una arreglo con "0", que representa los pokemones vivos
void llenar(int A[],int n){
    for(int i=0;i<n;i++){
        A[i]=0;
    }
}
//Entra un arreglo y el numero del pokemon
void muertos(int A[], int n){  //Remplaza en el espacio correspondiente a cada pokemon el numero "1"(muerto)
    if(n==1){A[0]=1;}
    if(n==2){A[1]=1;}
    if(n==3){A[2]=1;}
    if(n==4){A[3]=1;}
}
void Batalla(string Player1,Poke P1[],string Player2,Poke P2[])
{
    system("cls");
    int contP1=4,contP2=4;
    int DP1[4], DP2[4]; llenar(DP1,4);llenar(DP2,4); //Pokemon muertos de cada jugador 0=vivo; 1=muerto
    Poke PLAYER1, PLAYER2;
    int cont=1, n1, n2;
    cout << endl << "\t\tElija el pokemon para comenzar." << endl;
    elegirPokeB(P1,n1,Player1,DP1); elegirPokeB(P2,n2,Player2,DP2);system("cls");   //SELECCIONA EL PRIMER POKEMON DE PLAYER 1 Y 2 PARA INICIAR LA BATALLA
    PLAYER1=P1[n1]; PLAYER2=P2[n2];
    cout << "Comienza la Batalla Pokemon!" << endl << endl;
    while (contP1>0 && contP2>0) //LA BATALLA DURARA HASTA QUE UNO DE LOS DOS CONTADORES LLEGUE A 0 (LOS CONTADORES CONTP1 Y CONTP2 SON LOS 4 POKEMONES VIVOS DE CADA JUGADOR)
    {                           //CADA VEZ QUE UN POKEMON MUERA, EL CONTADOR DEL JUGADOR DISMINUIRA EN 1

        //PARA VERIFICAR LOS TURNOS, EL CONTADOR AUMENTA EN 1; SI ES IMPAR EL CONTADOR, EL TURNO ES DEL PLAYER 1, SI ES PAR, EL TURNO ES DEL PLAYER 2
        if (cont%2!=0){
                cout << "\t\t\tTURNO PARA "<< Player1 <<" -----" << endl << endl;
                cout << " \t\t " <<"Pokemon "<< Player1 << ": "   << PLAYER1.getnombre() << endl;
                cout << " \t\t " <<"Vida: " << PLAYER1.getvida() << endl;
                cout << endl;
                cout <<"\t\t "<<"Pokemon " << Player2 << " : " <<PLAYER2.getnombre() << endl;
                cout << " \t\t " <<"Vida : " << PLAYER2.getvida() << endl << endl;
                cout << endl; string opc; menu2(opc,Player1);
                //OPCION PARA ATACAR O CAMBIAR POKEMON
                if(opc[0]=='1'){
                    Turno(PLAYER1,PLAYER2,contP2);
                }
                if(opc[0]=='2'){
                    manternervida(P1[n1],PLAYER1);
                    elegirPokeB(P1,n1,Player1,DP1);
                    PLAYER1=P1[n1];
                }
                cont++;
                system("cls");

        }
        else
            {
                cout << "\t\t\tTURNO PARA "<< Player2 <<" -----"<< endl << endl ;
                cout << " \t\t " <<"Pokemon "<< Player1 << " : "   << PLAYER1.getnombre() << endl;
                cout << " \t\t " <<"Vida : " << PLAYER1.getvida() << endl;
                cout << endl;
                cout <<"\t\t "<<"Pokemon " << Player2 << " : " <<PLAYER2.getnombre() << endl;
                cout << " \t\t " <<"Vida : " << PLAYER2.getvida() << endl << endl;
                cout << endl; string opc; menu2(opc,Player2);
                if(opc[0]=='1'){
                    Turno(PLAYER2,PLAYER1,contP1);
                }
                if(opc[0]=='2'){
                    manternervida(P2[n2],PLAYER2);
                    elegirPokeB(P2,n2,Player2,DP2);
                    PLAYER2=P2[n2];
                }
                cont++;
                system("cls");
            }
        //CONDICIONALES PARA VERIFICAR SI EL POKEMON MURIO (VIDA EN 0) PARA ELEGIR AL SIGUIENTE POKEMON EN LUCHA
        if(PLAYER1.getvida()==0)
        {
            cout << "//" << PLAYER1.getnombre() << " muerto!! :(" << endl;
            muertos(DP1,n1);
            if(contP1>0)
                elegirPokeB(P1,n1,Player1,DP1);
                PLAYER1=P1[n1];

        }
        if(PLAYER2.getvida()==0)
        {
            cout << "//" << PLAYER2.getnombre() << " muerto!! :(" << endl;
            muertos(DP2,n2);
            if(contP2>0)
                elegirPokeB(P2,n2,Player2,DP2);
                PLAYER2=P2[n2];
        }
    }
    //CONDICIONALES PARA VERIFICAR QUIEN GANO LA BATALLA
    if (contP1>contP2)
    {
        cout << "\t\t FELICIDADES " << Player1 << ", eres el/la GANADOR/A !!" <<endl;
        cout << "\t\t PERDEDOR\A " << Player2 << " ..Mejor suerte en la proxima batalla!!" << endl;
    }
    else
    {
        cout << "\t\t FELICIDADES " << Player2 <<  ", eres el/la GANADOR/A!!" << endl;
        cout << "\t\t PERDEDOR/A " << Player1 << ".. Mejor suerte en la proxima batalla!!" << endl;
    }
}
// INGRESA A ESTA FUNCION LOS DATOS DEL POKEMON QUE LE TOCA ATACAR
void Turno(Poke &A, Poke &B,int &cont){
    cout << endl << endl << "\tATAQUES PARA : "<< A.getnombre() << endl;
    A.verataques();
    cout << endl << endl;
    cout << endl <<"\tSeleccione un ataque para : " << A.getnombre() << endl;
    int poder=seleccionA(A);
    int def=B.getdefensa();
    int ataque=A.Dano(poder,def);

    cout << "Dano efectuado a " << B.getnombre() << " " << ataque << endl;
    //CONDICIONALES PARA VERIFICAR SI EL POKEMON MUERE O PIERDE VIDA
    if (B.getvida()-ataque>0){
        cout << "\t" << B.getvida() << " - " << ataque << " = "<< B.getvida()-ataque << endl << endl;
        B.setvida(B.getvida()-ataque);
    }
    else{
        cout << endl << "\t\tPOKEMON MUERTO.. VIDA EN 0" << endl;
        B.setvida(0);
        cont--;
    }
    system("pause");
    system("cls");
}
//SELECCIONA CUAL DE LOS 4 ATAQUES UTILIZAR
int seleccionA(Poke P)
{
    cout << "\t\tINGRESE ATAQUE : ";
    string opc; cin >> opc; validarOpc(opc,2); //VALIDA LA OPCION
    system("cls");
    int poder;
    cout << "Movimientos." << endl << endl;
    if(opc[0]=='1'){
        poder=P.getpoder1();
        cout << "\t" << P.getnombre() << " realiza un ataque con " << P.getataque1() << endl;
    }
    if(opc[0]=='2'){
        poder=P.getpoder2();
        cout << "\t" << P.getnombre() << " realiza un ataque con " << P.getataque2() << endl;
    }
    if(opc[0]=='3'){
        poder=P.getpoder3();
        cout << "\t" << P.getnombre() << " realiza un ataque con " << P.getataque3() << endl;
    }

    if(opc[0]=='4'){
        poder=P.getpoder4();
        cout << "\t" << P.getnombre() << " realiza un ataque con " << P.getataque4() << endl;
    }
    return poder;
}

void manternervida(Poke &P, Poke &A){  //MANTIENE LA VIDA DEL POKEMON AL CAMBIARLO DURANTE LA BATALLA
    P.setvida(A.getvida());

}
