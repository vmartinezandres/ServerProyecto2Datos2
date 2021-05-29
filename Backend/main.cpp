#include <iostream>

#include "include/server.h"

using namespace std;

int main() {
    server myServer = server(54000, "0.0.0.0");
    myServer.inicarServidor();
    return 0;
}