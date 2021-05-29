//
// Created by martinezandres on 5/28/21.
//

#ifndef BACKEND_SERVER_H
#define BACKEND_SERVER_H

#include <string>

#include "../include/bPGameServer.h"
#include "../include/geneticPuzzleServer.h"

using namespace std;

class server {
private:
    int puerto;
    string ip;
    bPGameServer myBPGameServer;
    geneticPuzzleServer myGeneticPuzzleServer;

public:
    server(int, string);
    bool inicarServidor();

};

#endif //BACKEND_SERVER_H
