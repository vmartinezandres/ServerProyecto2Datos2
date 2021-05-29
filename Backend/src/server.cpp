
#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>

#include "../library/json.hpp"
#include "../include/server.h"


using namespace std;

server::server(int puerto, string ip) {
    this->puerto = puerto;
    this->ip = ip;
}

bool server::inicarServidor(){
    // Crear un socket
    int listening = socket(AF_INET, SOCK_STREAM, 0);
    if (listening == -1) {
        cout << "Error al crear el socket" << endl;
        return false;
    }

    // Agregar el IP y puerto al socket
    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(puerto);
    inet_pton(AF_INET, ip.c_str(), &hint.sin_addr);

    bind(listening, (sockaddr*)&hint, sizeof(hint));

    // Decirle a Winsock que el socket es para escuchar
    listen(listening, SOMAXCONN);

    // Esperar para la conexion...
    sockaddr_in client;
    socklen_t clientSize = sizeof(client);

    int clientSocket = accept(listening, (sockaddr*)&client, &clientSize);

    char host[NI_MAXHOST]; // Client's remote name
    char service[NI_MAXSERV]; // Service (i.e. port) the client is connect on

    memset(host, 0, NI_MAXHOST);
    memset(service, 0, NI_MAXSERV);

    if (getnameinfo((sockaddr*)&client, sizeof(client), host, NI_MAXHOST, service, NI_MAXSERV, 0) == 0) {
        cout << host << " conectado al puerto:  " << service << endl;
    }
    else {
        inet_ntop(AF_INET, &client.sin_addr, host, NI_MAXHOST);
        cout << host << " conectado al puerto: " << ntohs(client.sin_port) << endl;
    }

    // Cerrar el socket que escucha
    close(listening);

    // Ciclo infinito, acepta el mensaje del cliente y le devuelve una respuesta
    char buf[4096];

    while (true)
    {
        memset(buf, 0, 4096);

        // Esperando a que el cliente envie su informacion
        int bytesReceived = recv(clientSocket, buf, 4096, 0);
        if (bytesReceived == -1) {
            cout << "Error en recv(). Saliendo" << endl;
            break;
        }

        else if (bytesReceived == 0) {
            cout << "Client disconnected " << endl;
            break;
        }

        // Mensaje entrante parseado
        json::JSON request_body = json::JSON::Load(string(buf, 0, bytesReceived));
        string juego = request_body["juego"].ToString();
        string peticion = request_body["peticion"].ToString();

        if (juego == "BPGame" && peticion != "") {
            myBPGameServer.leerPeticion(peticion);
        }
        else if (juego == "geneticPuzzle" && peticion != "") {

        }
        else {
            char mensajeServer[] = "{ \"respuesta\" : \"Error\", \"tipoError\" : \"Juego o peticion desconocida\"}";
            send(clientSocket, mensajeServer, strlen(mensajeServer), 0);
        }
    }

    // Cerrar el socket del cliente
    close(clientSocket);
}