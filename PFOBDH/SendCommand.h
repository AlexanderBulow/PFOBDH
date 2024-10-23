#pragma once
#include <iostream>
#include <cstring>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string>
#include <arpa/inet.h>

void SendCom(char Command[64], int talkto);