#ifndef BACKEND_SERVER_H
#define BACKEND_SERVER_H

#include <string>
#include "bPGameServer.h"
#include "geneticPuzzleServer.h"
#include "jsonHandler.h"

using namespace std;

class server {

// Atributos
private:
    int puerto = 54000;
    string ip = "0.0.0.0";
    string peticionCliente;
    string respuestaServer;
    bPGameServer myBPGameServer;
    geneticPuzzleServer myGeneticPuzzleServer;
    jsonHandler JH;

//    geneticPuzzleServer myGeneticPuzzleServer;
//    bPGameServer myBPGameServer;

// Metodos
public:
    /**
     * @brief iniciarServidor iniciar el servidor para escuchar futuras peticiones
     * @return true/false si el servidor se inicio o no
     */
    bool inicarServidor();
};

#endif //BACKEND_SERVER_H