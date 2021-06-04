#include <iostream>
#include <string>

#include "jsonHandler.h"

using namespace std;

void jsonHandler::cargar(string archivo) {
    archivoJSON = archivo;

}

string jsonHandler::buscarEnJSON(string parametro) {
    string palabra = recortarComillas(parametro, 0);
    return palabra;

}
string jsonHandler::recortarComillas(string parametro, int inicio) {

    for (int i = inicio; i < archivoJSON.length(); i++){

        if (archivoJSON[i] == '"') {
            if (inicio == final) {
                inicio = i;
            }
            else {
                final = i - 1;
            }
        }
        
        if (final > inicio) {
            palabra = archivoJSON.substr(inicio + 1, final - inicio);


            if (isRespuesta == true) {
                isRespuesta =  false;
                final = 0;

                return palabra;
            }
            else {

                if (palabra == parametro) {
                    isRespuesta = true;
                    final += 2;
                    return recortarComillas(parametro, final);
                }
                else {

                    for (int i = final + 1; i < archivoJSON.length(); i++) {
                        if (archivoJSON[i] == ',') {
                            final = i + 1;
                            return recortarComillas(parametro, final);
                        }
                    }
                    
                }
            }
        }       
        
    }

    return NULL;

    
    // cout << "1" << endl;
    // int final = archivoJSON.find("\"",0);
    // cout << "2" << endl;

    // int inicio = 0;
    // cout << "3" << endl;

    // string palabra = archivoJSON.substr(inicio, final - inicio);
    // cout << "4" << endl;

    // cout << palabra << endl;
    // cout << "5" << endl;

    return "palabra";

}
