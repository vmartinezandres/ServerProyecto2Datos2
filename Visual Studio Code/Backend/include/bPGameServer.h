/**
 * @file bPGameServer.h
 * @version 1.0
 * @author Andres
 * 
 */



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

    /**
     * @brief bPGameServer Es el contructor de la clase
     */
    bPGameServer();

    /**
     * @brief leerJSON Lee el contenido de la peticion en formato JSON del cliente
     * @param peticionCliente Es la peticion del cliente en JSON
     * @return respuesta del servidor 
     */
    string leerJSON(string peticionCliente);

    /**
     * @brief crearTerreno crea el terreno de juego reservando la memoria necesaria
     * 
     */
    void crearTerreno();

    /**
     * @brief verTerreno se ve en la terminal el terreno de juego
     * 
     */
    void verTerreno();

    /**
     * @brief accionAlineacion El cliente establece una alineacion para el juego
     * @return respuesta del servidor 
     */
    string accionAlineacion();

    /**
     * @brief accionCantidadBolas El cliente establece la cantidad de bolas que se van a jugar
     * @return respuesta del servidor 
     */
    string accionCantidadBolas();

    /**
     * @brief accionPathfinding Utiliza el algoritmo de pathfinding para enconrtar la ruta mas corta desde donde esta el jugador con la pelota hasta la cancha
     * @return respuesta del servidor 
     */
    string accionPathfinding();

    /**
     * @brief accionTiroCentral dispara la pelota desde el centro hacia una direccion al azar
     * @return respuesta del servidor 
     */
    string accionTiroCentral();

    /**
     * @brief accionTirar dispara la pelota desde el jugador con la pelota hacia una direccion establecida
     * @return respuesta del servidor 
     */
    string accionTirar();

    /**
     * @brief tirar proceso para hacer la funcion accionTirar
     * @param i posicion de fila
     * @param j posicion de columna
     * @param potenciala cantidad de casillas que se movera la pelota
     * @param sentido direccion de la pelota
     * @return respuesta del servidor 
     */
    string tirar(int i, int j, int potencia, string sentido);

    /**
     * @brief pathfinding proceso para hacer la funcion accionTirar
     * @param posFilaActual posicion de fila actual donde esta la pelota
     * @param posColumnaActual posicion de columna actual donde esta la pelota
     * @return respuesta del servidor 
     */
    string pathfinding(int posFilaActual, int posColumnaActual);

    /**
     * @brief agregarEnLA agregar un cuadrado a la lista abierta para el pathfinding
     * @param i posicion de fila
     * @param j posicion de columna
     */
    void agregarEnLA(int i, int j);

    /**
     * @brief eliminarEnLA eliminar un cuadrado de la lista abierta para el pathfinding
     * @param posicion posicion en la que esta en la lista abierta
     */
    void eliminarEnLA(int posicion);

private:
    struct cuadrado;
    cuadrado **terreno;
    cuadrado **listaAbierta;
    cuadrado *jugadorActual;

};

#endif //BACKEND_BPGAMESERVER_H