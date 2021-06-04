#ifndef BACKEND_JSONHANDLER_H
#define BACKEND_JSONHANDLER_H

#include <iostream>
#include <string>

using namespace std;

class jsonHandler {
// Atributos
private:
    string archivoJSON;
    string palabra;
    int final = 0;
    bool isRespuesta = false;

// Metodos
public:
    void cargar(string);
    string buscarEnJSON(string);
    string recortarComillas(string, int); 

};



#endif //BACKEND_JSONHANDLER_H