//
// Created by martinezandres on 5/28/21.
//
#include <iostream>

#include "../include/bPGameServer.h"

using namespace std;

char* bPGameServer::leerPeticion(string) {

    return "{ \"respuesta\" : \"Error\", \"tipoError\" : \"Juego o peticion desconocida\"}";
}
