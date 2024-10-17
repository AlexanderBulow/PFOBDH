#pragma once
#include <iostream>
#include <cstring>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string>

void SendCom(char Command[64], char talkto[64]);