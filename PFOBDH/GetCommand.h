#pragma once
#include <iostream>
#include <cstring>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string>
void GetCommand(char* receiving, char talkto[64]);