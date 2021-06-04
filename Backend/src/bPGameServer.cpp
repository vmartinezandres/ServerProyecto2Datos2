#include <iostream>
#include <string>
#include "../include/bPGameServer.h"


using namespace std;

// Structs
struct bPGameServer::cuadrado {
    int numero, i, j;
    bool isJugadorAzul = false;
    bool isJugadorRojo = false;
    bool isCancha = false;
    bool isFuera = false;
    bool isChecked = false;
    string equipo;
    cuadrado *padre = nullptr;

    int F = 0;
    int G = 0;
    int H = 0;

};

// Constructor
bPGameServer::bPGameServer() {
    crearTerreno();

}

// Funciones

void bPGameServer::crearTerreno() {
    cout << "Reservando memoria para el terreno..." << endl;
    terreno = new cuadrado*[nFilas]; // Reservando memoria para filas
    for (int i = 0; i < nFilas ; ++i) {
        terreno[i] = new cuadrado[nColumnas]; // Reservando memoria para columnas
    }

    cout << "Marcando los bordes y las canchas..." << endl;
    // Marcando los bordes y las canchas
    for (int i = 0; i < nColumnas; i++) {
        terreno[0][i].isFuera = true;
        terreno[nFilas-1][i].isFuera = true;

    }
    for (int i = 1; i < nFilas - 1; i++) {
        if (i != 6 && i != 7 && i != 8) {
            terreno[i][0].isFuera = true;
            terreno[i][nColumnas - 1].isFuera = true;
        }
        else {
            terreno[i][0].isCancha = true;
            terreno[i][nColumnas - 1].isCancha = true;
        }
    }

    for (int i = 0; i < nFilas; i++) {
        for (int j = 0; j < nColumnas; j++) {
            terreno[i][j].i = i;
            terreno[i][j].j = j;
            terreno[i][j].numero = numCuadrado;
            numCuadrado++;
        }
    }

    listaAbierta = new cuadrado*[100];
}

string bPGameServer::leerJSON(string peticionCliente) {
    JH.cargar(peticionCliente);
    accion = JH.buscarEnJSON("accion");
    
    if (accion == "Alineacion") {
        return accionAlineacion();
    
    }
    else if (accion == "Tiempo") {

        // thread hilo = thread(accionTiempo);
        // hilo.join();
    }
    else if (accion == "Pathfinding") {

        return accionPathfinding();
    }

}

string bPGameServer::accionAlineacion() {
    numJugadores = stoi(JH.buscarEnJSON("numJugadores"));
    tipoAlineacion = stoi(JH.buscarEnJSON("tipoAlineacion"));

    switch (numJugadores) {
        // Futbol 5
        case 5:

            switch (tipoAlineacion) {
                case 1:
                    // Equipo rojo
                    terreno[7][3].isJugadorRojo = true;
                    terreno[3][6].isJugadorRojo = true;
                    terreno[11][6].isJugadorRojo = true;
                    terreno[5][14].isJugadorRojo = true;
                    terreno[9][14].isJugadorRojo = true;

                    // Equipo azul
                    terreno[7][21].isJugadorAzul = true;
                    terreno[3][18].isJugadorAzul = true;
                    terreno[11][18].isJugadorAzul = true;
                    terreno[5][10].isJugadorAzul = true;
                    terreno[9][10].isJugadorAzul = true;

                    break;
                case 2:
                    // Equipo rojo
                    terreno[7][3].isJugadorRojo = true;
                    terreno[2][7].isJugadorRojo = true;
                    terreno[12][7].isJugadorRojo = true;
                    terreno[7][13].isJugadorRojo = true;
                    terreno[7][17].isJugadorRojo = true;

                    // Equipo azul
                    terreno[7][21].isJugadorAzul = true;
                    terreno[2][17].isJugadorAzul = true;
                    terreno[12][17].isJugadorAzul = true;
                    terreno[7][11].isJugadorAzul = true;
                    terreno[7][7].isJugadorAzul = true;
                    break;
                case 3:
                    // Equipo rojo
                    terreno[7][3].isJugadorRojo = true;
                    terreno[4][6].isJugadorRojo = true;
                    terreno[10][6].isJugadorRojo = true;
                    terreno[3][15].isJugadorRojo = true;
                    terreno[11][15].isJugadorRojo = true;

                    // Equipo azul
                    terreno[7][21].isJugadorAzul = true;
                    terreno[4][18].isJugadorAzul = true;
                    terreno[10][18].isJugadorAzul = true;
                    terreno[3][9].isJugadorAzul = true;
                    terreno[11][9].isJugadorAzul = true;
                    break;
            }
            break;

        // Futbol 11
        case 11:

            switch (tipoAlineacion) {
                case 1:
                    // Equipo rojo
                    terreno[7][3].isJugadorRojo = true;
                    terreno[2][6].isJugadorRojo = true;
                    terreno[5][6].isJugadorRojo = true;
                    terreno[9][6].isJugadorRojo = true;
                    terreno[12][6].isJugadorRojo = true;
                    terreno[3][9].isJugadorRojo = true;
                    terreno[11][9].isJugadorRojo = true;
                    terreno[6][14].isJugadorRojo = true;
                    terreno[8][14].isJugadorRojo = true;
                    terreno[3][20].isJugadorRojo = true;
                    terreno[11][20].isJugadorRojo = true;

                    // Equipo azul
                    terreno[7][21].isJugadorAzul = true;
                    terreno[2][18].isJugadorAzul = true;
                    terreno[5][18].isJugadorAzul = true;
                    terreno[9][18].isJugadorAzul = true;
                    terreno[12][18].isJugadorAzul = true;
                    terreno[3][15].isJugadorAzul = true;
                    terreno[11][15].isJugadorAzul = true;
                    terreno[6][10].isJugadorAzul = true;
                    terreno[8][10].isJugadorAzul = true;
                    terreno[3][4].isJugadorAzul = true;
                    terreno[11][4].isJugadorAzul = true;
                    break;
                case 2:
                    // Equipo rojo
                    terreno[7][3].isJugadorRojo = true;
                    terreno[4][5].isJugadorRojo = true;
                    terreno[10][5].isJugadorRojo = true;
                    terreno[2][7].isJugadorRojo = true;
                    terreno[12][7].isJugadorRojo = true;
                    terreno[4][10].isJugadorRojo = true;
                    terreno[7][10].isJugadorRojo = true;
                    terreno[10][10].isJugadorRojo = true;
                    terreno[5][16].isJugadorRojo = true;
                    terreno[9][16].isJugadorRojo = true;
                    terreno[7][18].isJugadorRojo = true;

                    // Equipo azul
                    terreno[7][21].isJugadorAzul = true;
                    terreno[4][19].isJugadorAzul = true;
                    terreno[10][19].isJugadorAzul = true;
                    terreno[2][17].isJugadorAzul = true;
                    terreno[12][17].isJugadorAzul = true;
                    terreno[4][14].isJugadorAzul = true;
                    terreno[7][14].isJugadorAzul = true;
                    terreno[10][14].isJugadorAzul = true;
                    terreno[5][8].isJugadorAzul = true;
                    terreno[9][8].isJugadorAzul = true;
                    terreno[7][6].isJugadorAzul = true;
                    break;
                case 3:
                    // Equipo rojo
                    terreno[7][3].isJugadorRojo = true;
                    terreno[4][6].isJugadorRojo = true;
                    terreno[10][6].isJugadorRojo = true;
                    terreno[5][10].isJugadorRojo = true;
                    terreno[9][10].isJugadorRojo = true;
                    terreno[3][15].isJugadorRojo = true;
                    terreno[11][15].isJugadorRojo = true;
                    terreno[6][17].isJugadorRojo = true;
                    terreno[8][17].isJugadorRojo = true;
                    terreno[2][22].isJugadorRojo = true;
                    terreno[12][22].isJugadorRojo = true;

                    // Equipo azul
                    terreno[7][21].isJugadorAzul = true;
                    terreno[4][18].isJugadorAzul = true;
                    terreno[10][18].isJugadorAzul = true;
                    terreno[5][14].isJugadorAzul = true;
                    terreno[9][14].isJugadorAzul = true;
                    terreno[3][9].isJugadorAzul = true;
                    terreno[11][9].isJugadorAzul = true;
                    terreno[6][7].isJugadorAzul = true;
                    terreno[8][7].isJugadorAzul = true;
                    terreno[2][2].isJugadorAzul = true;
                    terreno[12][2].isJugadorAzul = true;
                    break;
            }
        break;

    }

    for (int i = 0; i < nFilas; i++){

        for (int j = 0; j < nColumnas; j++){
            if (terreno[i][j].isFuera) {
                cout << "[F]";
            }
            else if (terreno[i][j].isCancha) {
                cout << "[C]";
            }
            else if (terreno[i][j].isJugadorRojo) {
                cout << "[R]";
            }
            else if (terreno[i][j].isJugadorAzul) {
                cout << "[A]";
            }
            else {
                cout << "[ ]";
            }
        }
        cout << endl;
        
    }
    
    return "{ \"mensaje\" : \"Alineacion establecida\"}";
}

void bPGameServer::accionTiempo() {
    minutos = stoi(JH.buscarEnJSON("minutos"));
    usleep(minutos * 60 * 1000000);

}

string bPGameServer::accionPathfinding() {
    equipo = JH.buscarEnJSON("equipo");
    posFilaActual = stoi(JH.buscarEnJSON("posFila"));
    posColumnaActual = stoi(JH.buscarEnJSON("posColumna"));

    posFilaFinal = 7;
    if (equipo == "Rojo") {
        posColumnaFinal = nColumnas - 1;

    }
    else {
        posColumnaFinal = 0;

    }

    // Estableciendo H en los cuadrados
    for (int i = 0; i < nFilas; i++) {
        for (int j = 0; j < nColumnas; j++) {
            if(!(terreno[i][j].isJugadorAzul || terreno[i][j].isJugadorRojo)) {
                terreno[i][j].H = abs(i - posFilaFinal) + abs(j - posColumnaFinal);
            }
        }   
    }

    terreno[posFilaActual][posColumnaActual].isChecked = true;

    return pathfinding(posFilaActual, posColumnaActual);

}

string bPGameServer::pathfinding(int i, int j) {
    posFilaActual = i;
    posColumnaActual = j;
    cout << "la posicion actual es: " << posFilaActual << ", " << posColumnaActual << endl;
    terreno[posFilaActual][posColumnaActual].isChecked = true;

    // Estableciendo G y F, agregando a lista abierta y el padre en los cuadros alrededor

    if ((posFilaActual + posColumnaActual) % 2 == 0){
        isEsquinaPar = true;
    }
    else {
        isEsquinaPar = false;
    }

    cout << "La esquina es par: " << isEsquinaPar << endl;

    for (int i = posFilaActual - 1; i < posFilaActual + 2; i++) {
        for (int j = posColumnaActual - 1; j < posColumnaActual + 2; j++) {
            cout << "estamos en la fila: " << i << endl;
            cout << "estamos en la columna: " << j << endl;

            if (terreno[i][j].numero == terreno[posFilaFinal][posColumnaFinal].numero) {
                cout << "se encontro el final" << endl;

                terreno[i][j].padre = &terreno[posFilaActual][posColumnaActual];
                cuadrado *cuadradoAux = &terreno[i][j];
                string direccion;
                while (cuadradoAux != nullptr){
                    direccion.append("\"" + to_string(cuadradoAux->numero) + "\"" + ", ");
                    cuadradoAux = cuadradoAux->padre;
                } 
                return  "{ \"cuadrados\" : [" + direccion + "]";

            }
            else {
                if((!(terreno[i][j].isJugadorAzul || terreno[i][j].isJugadorRojo)) && (!terreno[i][j].isChecked)) {

                    terreno[i][j].padre = &terreno[posFilaActual][posColumnaActual];

                    if ((i + j) % 2 == 0) {
                        if (isEsquinaPar) {
                            terreno[i][j].G = terreno[i][j].padre->G + 14;
                        }
                        else {
                            terreno[i][j].G = terreno[i][j].padre->G + 10;
                        }
                        
                    }

                    else {
                        if (isEsquinaPar) {
                            terreno[i][j].G = terreno[i][j].padre->G + 10;
                        }
                        else {
                            terreno[i][j].G = terreno[i][j].padre->G + 14;
                        }
                    }
                    terreno[i][j].F = terreno[i][j].H + terreno[i][j].G;
                    agregarEnLA(i, j);
                }
            }
        }
    }
        
    // Buscar el menor F
    posMenorF = 0;
    for (int i = 1; i < numListaAbierta; i++) {
        if (listaAbierta[posMenorF]->F > listaAbierta[i]->F) {
            posMenorF = i;
        }
    }
    cout << "El menor F esta en el numero: " << listaAbierta[posMenorF]->numero << " que esta en: "<< listaAbierta[posMenorF]->i << ", " << listaAbierta[posMenorF]->j << " y es: " << listaAbierta[posMenorF]->F << endl;

    eliminarEnLA(posMenorF);

    return pathfinding(listaAbierta[posMenorF]->i, listaAbierta[posMenorF]->j);

}

void bPGameServer::agregarEnLA(int i, int j) {
    listaAbierta[numListaAbierta] = &terreno[i][j];
    numListaAbierta++;
}

void bPGameServer::eliminarEnLA(int posicion){
    for (int i = posicion; i < numListaAbierta - 1; i++) {
        listaAbierta[i] = listaAbierta[i + 1];
    }
    listaAbierta[numListaAbierta - 2] = listaAbierta[numListaAbierta - 1];
    numListaAbierta --;

}
