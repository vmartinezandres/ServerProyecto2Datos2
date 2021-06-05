#ifndef BACKEND_BPGAMESERVER_H
#define BACKEND_BPGAMESERVER_H

#include <string>
#include <thread>
#include <unistd.h>
#include <cmath>

#include "jsonHandler.h"

using namespace std;

class bPGameServer{

// Atributos
private:
    string accion;
    string equipo;
    string direccion;
    string trayectoria;
    int veces = 1;
    int nFilas = 15;
    int nColumnas = 25;
    int numJugadores;
    int tipoAlineacion;
    int minutos;
    int numCuadrado = 1;
    int posFilaActual, posColumnaActual;
    int posFilaFinal, posColumnaFinal;
    int numListaAbierta = 0;
    int posMenorF = 0;
    int potencia;
    bool isEsquinaPar = false;
    jsonHandler JH;

// Metodos
public:
    bPGameServer();
    string leerJSON(string);
    void crearTerreno();
    string accionAlineacion();
    void accionTiempo();
    string accionPathfinding();
    string accionTirar();
    string pathfinding(int, int);
    void agregarEnLA(int, int);
    void eliminarEnLA(int);

private:
    struct cuadrado;
    cuadrado **terreno;
    cuadrado **listaAbierta;

};

#endif //BACKEND_BPGAMESERVER_H