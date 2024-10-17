// ComTestinVS.cpp : Defines the entry point for the application.
//

#include "GetCommand.h"

using namespace std;

void GetCommand(char* receiving, char talkto[64])
{
    // creating socket
    int receivingSocket = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET; //Internet domain sockets
    if (talkto == "GNDtoPF") {
        serverAddress.sin_port = htons(1000); //port we connect to
    }
    else if (talkto == "PFtoPL") {
        serverAddress.sin_port = htons(2000); //port we connect to
    }
    else if (talkto == "PLtoPF") {
        serverAddress.sin_port = htons(3000); //port we connect to
    }
    else if (talkto == "PFtoGND") {
        serverAddress.sin_port = htons(4000); //port we connect to
    }
    else {
        cout << "code no work" << endl;
    }
    serverAddress.sin_addr.s_addr = INADDR_ANY; //binding socket to any address

    // binding socket.
    bind(receivingSocket, (struct sockaddr*)&serverAddress,
        sizeof(serverAddress));

    // listening to the assigned socket
    listen(receivingSocket, 5);

    // accepting connection request
    int sendSocket
        = accept(receivingSocket, nullptr, nullptr);

    // recieving data
    char buffer[64] = { 0 };
    recv(sendSocket, buffer, sizeof(buffer), 0);
    receiving = buffer;


    // closing the socket.
    close(receivingSocket);
}

