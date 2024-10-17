

#include "SendCommand.h"
using namespace std;

void SendCom(char Command[64], char talkto[64]) {
    // creating socket
    int sendSocket = socket(AF_INET, SOCK_STREAM, 0);

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

    // sending connection request if it fails we retry
    while (connect(sendSocket, (struct sockaddr*)&serverAddress,
        sizeof(serverAddress)) == -1) {
        cout << "failed connection" << endl;
    }

    // sending data
    const char* message = Command;
    send(sendSocket, message, strlen(message), 0);

    // closing socket
    close(sendSocket);
}