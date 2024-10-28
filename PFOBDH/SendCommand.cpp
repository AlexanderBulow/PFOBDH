#include "SendCommand.h"
using namespace std;


void SendCom(char Command[64], int talkto) {
    // creating socket
    int sendSocket = socket(AF_INET, SOCK_STREAM, 0);
    int opt = 1;
    //allows you to use the socket even though the socket might not have been closed yet
    setsockopt(sendSocket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET; //Internet domain sockets
    if (talkto == 1) {
        serverAddress.sin_port = htons(1200); //port we connect to
    }
    else if (talkto == 2) {
        serverAddress.sin_port = htons(2000); //port we connect to
    }
    else {
        cout << "code no work" << endl;
    }
    //wsl1 address = 127.0.0.1 wsl2 address = 172.23.240.9
    serverAddress.sin_addr.s_addr = inet_addr("127.0.0.1"); //binding socket to address for wsl
    cout << "1" << endl;
    // sending connection request if it fails we retry
    while (connect(sendSocket, (struct sockaddr*)&serverAddress,
        sizeof(serverAddress)) == -1) {
        cout << "failed connection" << endl;
        sleep(1);
    }
    cout << "2" << endl;
    // sending data
    const char* message = Command;
    send(sendSocket, message, strlen(message), 0);

    // closing socket
    close(sendSocket);
}