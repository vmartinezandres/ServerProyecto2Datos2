#ifndef BACKEND_BPGAMESERVER_H
#define BACKEND_BPGAMESERVER_H

#include <string>
#include <pthread.h>
#include <unistd.h>
#include <cmath>
#include <cstdlib>
#include <ctime>

#include "jsonHandler.h"

using namespace std;

class bPGameServer{

// Atributos
private:
    string accion;
    string direccion;
    string trayectoria;
    int veces = 1;
    int nFilas = 15;
    int nColumnas = 25;
    int numJugadores;
    int tipoAlineacion;
    int numBolas;
    int golesEquipoRojo = 0;
    int golesEquipoAzul = 0;
    int numCuadrado = 1;
    int posFilaFinal, posColumnaFinal;
    int numListaAbierta = 0;
    int posMenorF = 0;
    int potenciaCliente;
    int numAleatorio;
    bool isEsquinaPar = false;
    jsonHandler JH;

// Metodos
public:
    bPGameServer();
    string leerJSON(string);
    void crearTerreno();
    void verTerreno();
    string accionAlineacion();
    string accionCantidadBolas();
    string accionPathfinding();
    string accionTiroCentral();
    string accionTirar();
    string tirar(int, int, int, string);
    string pathfinding(int, int);
    void agregarEnLA(int, int);
    void eliminarEnLA(int);

private:
    struct cuadrado;
    cuadrado **terreno;
    cuadrado **listaAbierta;
    cuadrado *jugadorActual;

};

#endif //BACKEND_BPGAMESERVER_H