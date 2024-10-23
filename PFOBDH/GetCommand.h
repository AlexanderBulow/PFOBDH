#pragma once
#include <iostream>
#include <cstring>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string>
#include <arpa/inet.h>

extern char buffer[64];

char* GetCommand(int talkto);