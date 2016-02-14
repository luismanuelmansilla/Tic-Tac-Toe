#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
using namespace std;

char tabla[3][3];
char jugador = 'X';
void cabezera(string , string );
void inicio();
void desplegarTabla();
void tictactoe();
bool ganador();
bool empate();
string jugadorActual();
string nombreJugador1="";
string nombreJugador2="";
string mensajeGanador="";


int main(){

    int opcionMenu;
    string temp;
    do {
        cabezera(nombreJugador1,nombreJugador2);
        cout << "1. Jugar Tic Tac Toe\n";
        cout << "2. Salir\n";
        cout << "=> ";
        cin >> temp;
        if(temp.size() > 1 || temp[0]-'0' > 2 || temp[0]-'0' < 1){
                cout << "\n\nOpcion Invalida! Enter para continuar...\n";
                system("PAUSE>null");
                system("cls");
                continue;
            } else{
                opcionMenu = temp[0] - '0';
            }
        switch (opcionMenu) {
            case 1: tictactoe();
            break;
            case 2: cout << "\nGracias por usar el programa, hasta la proxima!\n";
            break;
        }
        system("PAUSE>null");
        system("cls");
    }while(opcionMenu !=2);
    return 0;
}

void cabezera(string nombreJugador1, string nombreJugador2){
    cout << "\n\n\tTic Tac Toe\n\n";
	cout << "Jugador 1: " << nombreJugador1 << " (X)  -  Jugador 2: " << nombreJugador2 << " (O)\n" << endl;
}

void inicio(){
    for(int i = 0 ; i < 3; i++){
            for(int j = 0 ; j < 3; j++){
            tabla[i][j] = ' ';
            }
     }
}

void desplegarTabla(){
    system("cls");
    cabezera(nombreJugador1,nombreJugador2);
    cout << "\n";
    cout << "       " << tabla[0][0] << "  |  " << tabla[0][1] << "  |  " << tabla[0][2] << endl;
    cout << "     -----+-----+-----" << endl;
	cout << "       " << tabla[1][0] << "  |  " << tabla[1][1] << "  |  " << tabla[1][2] << endl;
	cout << "     -----+-----+-----" << endl;
	cout << "       " << tabla[2][0]  << "  |  " << tabla[2][1] << "  |  " << tabla[2][2] << endl;
}

void tictactoe(){
    system("cls");
    inicio();
    int fila=0;
    int columna=0;
    string error;
    nombreJugador1="";
    nombreJugador2="";
    jugador='X';
    cabezera(nombreJugador1,nombreJugador2);

    cout << "Nombre Jugador 1: ";
    cin >> nombreJugador1;
    if(nombreJugador1.length() < 1){
        cout << "Error, ingrese un nombre!";
    }
    cout << "Nombre Jugador 2: ";
    cin >> nombreJugador2;
    if(nombreJugador2.length() <1){
        cout << "Error, ingrese un nombre!";
    }

    do{
        desplegarTabla();
        cout << error;
        error = "";
        cout << "\n";
        string temp;

        //Leer la fila
        cout << jugadorActual() << ", en que fila quieres jugar?: ";
        cin >> temp;
            if(temp.size() > 1 || temp[0]-'0' > 3 || temp[0]-'0' < 1){
                error= "\n\nError casilla inexistente, intente de nuevo!\n";
                continue;
            } else{
                fila = temp[0] - '0';
            }
        //Leer la columna
        cout << jugadorActual() << ", en que columna quieres jugar?: ";
        cin >> temp;
            if(temp.size() > 1 || temp[0]-'0' > 3 || temp[0]-'0' < 1){
                error= "\n\nError casilla inexistente, intente de nuevo!\n";
                continue;
            } else{
                columna = temp[0] - '0';
            }
        fila = fila - 1;
        columna = columna - 1;
            if(tabla[fila][columna] != ' '){
                error= "\n\nError casilla ocupada, intente de nuevo!\n";
            }else{
                tabla[fila][columna] = jugador;
                if(!ganador()){
                    if(jugador == 'X'){
                        jugador  = 'O';
                    }else{
                        jugador = 'X';
                    }
                }
            }

    }while(!ganador() && !empate());

    cout << endl;
    desplegarTabla();
    cout << "\n" << endl;
    cout << mensajeGanador << endl;
    cout << "\n" << endl;
}

bool ganador(){
    char jugadorGanador;
    string temp;

    //Verificar desplazamiento horizontal
    for(int i=0; i<3; i++){
        if(tabla[i][0] != ' '){
            if (tabla[i][0] == tabla[i][1] && tabla[i][1] == tabla[i][2]){
                jugadorGanador = tabla[i][0];
                temp+= jugadorGanador;
                mensajeGanador = "El jugador (" + temp + "): " + jugadorActual() + ", ha ganado el juego!";
                return true;
            }
        }
    }

    //Verificar desplazamiento vertical
    for(int i=0; i<3; i++){
        if(tabla[0][i] != ' '){
            if (tabla[0][i] == tabla[1][i] && tabla[1][i] == tabla[2][i]){
                jugadorGanador = tabla[0][i];
                temp+= jugadorGanador;
                mensajeGanador = "El jugador (" + temp + "): " + jugadorActual() + ", ha ganado el juego!";
                return true;
                }
            }
    }

    //Verificar Diagonal de izquierda a derecha y derecha a izquierda
    if(tabla[1][1] != ' '){
        if ((tabla[0][0] == tabla[1][1] && tabla[1][1] == tabla[2][2]) || (tabla[0][2] == tabla[1][1] && tabla[1][1] == tabla[2][0])){
            jugadorGanador = tabla[1][1];
            temp+= jugadorGanador;
            mensajeGanador = "El jugador (" + temp + "): " + jugadorActual() + ", ha ganado el juego!";
            return true;
            }
    }
    return false;
}

bool empate(){
    //Verificar que todas las casillas esten llenas
    for(int i = 0 ; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(tabla[i][j] == ' '){
                return false;
            }
        }
    }
    mensajeGanador = "El juego ha quedado empate!!\n";
    return true;
}

string jugadorActual(){

    if (jugador == 'X'){
        return nombreJugador1;
    }else{
        return nombreJugador2;
    }
}
