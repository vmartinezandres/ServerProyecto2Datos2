#include <iostream>

#include "../include/server.h"

using namespace std;

int main() {
    server myServer = server();
    myServer.inicarServidor();
    return 0;
}